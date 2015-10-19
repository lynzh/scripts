#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SDL2/SDL.h"

#define TRUE 1
#define FALSE 0

#define S_WIDTH 720
#define S_HEIGHT 480
#define S_DEPTH 32
#define S_FREQ 60

#define X_OFFSET 15
#define Y_OFFSET 10

#define N_NODES 8192
#define NODE_SIZE 2
#define DEF_DECOUNT 100

//----------------------------------------------------------------
// Globals
int decount = DEF_DECOUNT;
int xoff = X_OFFSET;
int yoff = Y_OFFSET;

//----------------------------------------------------------------
// Structures
struct Point {
   int x;
   int y;
};

struct Color {
   Uint8 r;
   Uint8 g;
   Uint8 b;
};

struct TreeNode {
   int count;
   struct Color color;
   struct Point pos;
   struct TreeNode *right;
   struct TreeNode *left;
};

struct Program {
   int running;
   char *title;
   SDL_Window *screen;
   SDL_Renderer *renderer;
   SDL_Event event;
};

struct Program *app;

//----------------------------------------------------------------


// Returns a poitner to a TreeNode, returns NULL if fail.
struct TreeNode *newNode(struct Color color, struct Point pos);

// Adds a node to the tree
void appendNode(struct TreeNode *treeRoot, struct Color color);

// Returns a random integer between from and to
int getRandomInt(int from, int to);

// Prints a list of the sorted colors to stdout
void printSorted(struct TreeNode *node);

Uint32 u8tou32(Uint8 r, Uint8 g, Uint8 b);

//----------------------------------------------------------------
// Functions

struct TreeNode *newNode(struct Color color, struct Point pos) {
   struct TreeNode *tmp = NULL;
   if ((tmp = malloc(sizeof(struct TreeNode))) != NULL) {
      tmp->count = 1;
      tmp->color = color;
      tmp->pos = pos;
      tmp->left = NULL;
      tmp->right = NULL;
   }
   return tmp;
}

int getRandomInt(int from, int to) {
   struct timespec seed;
   clock_gettime(CLOCK_MONOTONIC, &seed);
   srand(seed.tv_nsec);

   return from + rand() % (to - from + 1);
}

void appendNode(struct TreeNode *root, struct Color color) {
   struct TreeNode *node = root;
   int nodeXPos = root->pos.x;
   int nodeYPos = root->pos.y;


   // if the color of the new node is "brighter", place it to the right
   if (u8tou32(color.r, color.g, color.b) > u8tou32(node->color.r, node->color.g, node->color.b)) {
      // If the node to the right is uninhabited, create a new node
      if (node->right == NULL) {
         node->right = newNode(color, (struct Point){nodeXPos + xoff, nodeYPos + yoff});
         if (decount == 0) {
            decount = DEF_DECOUNT;
            if (xoff > 2)
               xoff--;
            if (yoff > 2)
               yoff--;
         } else {
            decount--;
         }
      } else {
         appendNode(node->right, color);
      }
   } else if (u8tou32(color.r, color.g, color.b) < u8tou32(node->color.r, node->color.g, node->color.b)) {
      if (node->left == NULL) {
         node->left = newNode(color, (struct Point){nodeXPos - xoff, nodeYPos + yoff});
         if (decount == 0) {
            decount = DEF_DECOUNT;
            if (xoff > 2)
               xoff--;
            if (yoff > 2)
               yoff--;
         } else {
            decount--;
         }
      } else {
         appendNode(node->left, color);
      }
   } else {
      node->count++;
   }
}

void printSorted(struct TreeNode *node) {
   if (node != NULL) {
      printSorted(node->left);
      printf("#%2.0x%2.0x%2.0x \n", node->color.r, node->color.g, node->color.b);
      printSorted(node->right);
   }
}

void drawNode(struct TreeNode *node) {
      SDL_Rect fillRect = { node->pos.x, node->pos.y,NODE_SIZE ,NODE_SIZE };
      SDL_SetRenderDrawColor(app->renderer, node->color.r, node->color.g, node->color.b, 0xFF);
      SDL_RenderFillRect(app->renderer, &fillRect);
}

void drawTree(struct TreeNode *node) {
   if (node != NULL) {
      drawTree(node->left);
      drawNode(node);
      drawTree(node->right);
   }
}


Uint32 u8tou32(Uint8 r, Uint8 g, Uint8 b) {
   return (r<<16) + (g<<8) + (b<<0);

}
//----------------------------------------------------------------
// Main Entry Point
int main(int argc, const char *argv[]) {
   int i;

      struct TreeNode *root = newNode(
         (struct Color){getRandomInt(0, 255), getRandomInt(0, 255), getRandomInt(0, 255)},
         (struct Point){S_WIDTH / 2, 20}
         );

   printf(" Start Pos: (%d, %d)\n", root->pos.x, root->pos.y);
   printf(" Color: (R:%d, G:%d, B:%d)\n", root->color.r, root->color.g, root->color.b);

   /*
   for (i = 0; i < N_NODES; i++) {
      appendNode(root, (struct Color) {
            getRandomInt(0, 255),
            getRandomInt(0, 255),
            getRandomInt(0, 255)
            });
   }
   */

   if ((app = malloc(sizeof(struct Program))) != NULL) {
      app->running = TRUE;
      app->screen = SDL_CreateWindow("ColorTree",
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         S_WIDTH, S_HEIGHT,
         SDL_WINDOW_OPENGL);
      app->renderer = SDL_CreateRenderer(app->screen, -1, SDL_RENDERER_ACCELERATED);
   }

   SDL_Event event;

   while (app->running == TRUE) {

      while (SDL_PollEvent( &event ) != 0) {
         if (event.type == SDL_QUIT) {
            app->running = FALSE;
         }
      }


      SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0xFF);
      SDL_RenderClear(app->renderer);

      appendNode(root, (struct Color) {
            getRandomInt(0, 128),
            getRandomInt(0, 255),
            getRandomInt(0, 255)
            });

      drawTree(root);

      SDL_RenderPresent(app->renderer);
   }

   SDL_Quit();

   return EXIT_SUCCESS;
}
