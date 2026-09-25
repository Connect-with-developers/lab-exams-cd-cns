%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node { char *val; struct Node *left, *right; } Node;
Node* mk(char *v, Node *l, Node *r) {
  Node *n = malloc(sizeof(Node));
  n->val = strdup(v); n->left = l; n->right = r;
  return n;
}
void inorder(Node *t) {
  if (!t) return;
  inorder(t->left); printf("%s ", t->val); inorder(t->right);
}
%}
%union { char *s; struct Node *n; }
%token <s> ID
%type <n> E T F
%%
S : E { printf("Inorder: "); inorder($1); printf("\n"); } ;
E : E '+' T { $$ = mk("+", $1, $3); }
  | T { $$ = $1; } ;
T : T '*' F { $$ = mk("*", $1, $3); }
  | F { $$ = $1; } ;
F : '(' E ')' { $$ = $2; }
  | ID { $$ = mk($1, 0, 0); } ;
%%
int main() { printf("Enter expr:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Error\n"); return 0; }
