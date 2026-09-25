# Exp 05: BNF to Yacc — Simple AST Builder

## 1. Aim (write this in exam)
Convert BNF grammar E→E+T|T, T→T*F|F, F→(E)|id to yacc, build AST with struct Node and print inorder.

## 2. Description in simple words
- BNF grammar → yacc rules directly. Each rule builds a tree node.
- `struct Node {char* val; struct Node *left,*right;}` — val = `+`/`*`/id, left/right = children.
- `mk(v,l,r)` = malloc + strdup. Leaf: `mk(id,0,0)`. Plus: `mk("+",$1,$3)`.
- `inorder` = left, print, right. For `a+b*c` tree is `+(a,*(b,c))`, inorder prints `a + b * c`.
- `%union` holds both string (`s`) and node (`n`). ID is `<s>`, E/T/F are `<n>`.

Rule to remember: **mk() builds, inorder() prints, * binds tighter (lower rule).**

## 3. Learn in small steps

**Step 1 — Node + mk + inorder (40 sec):**
```c
typedef struct Node { char *val; struct Node *left, *right; } Node;
Node* mk(char *v, Node *l, Node *r) {
  Node *n = malloc(sizeof(Node));
  n->val = strdup(v); n->left = l; n->right = r; return n;
}
void inorder(Node *t) {
  if (!t) return;
  inorder(t->left); printf("%s ", t->val); inorder(t->right);
}
```

**Step 2 — Union + tokens (20 sec):**
```c
%union { char *s; struct Node *n; }
%token <s> ID
%type <n> E T F
```

**Step 3 — Grammar + build (30 sec):**
```c
S : E { printf("Inorder: "); inorder($1); printf("\n"); } ;
E : E '+' T { $$ = mk("+", $1, $3); } | T { $$ = $1; } ;
T : T '*' F { $$ = mk("*", $1, $3); } | F { $$ = $1; } ;
F : '(' E ')' { $$ = $2; } | ID { $$ = mk($1, 0, 0); } ;
```

**Step 4 — scanner.l (20 sec):**
```c
[a-zA-Z]  { yylval.s = strdup(yytext); return ID; }
[+*()\n]  { return yytext[0]; }
```

How to practice: write Step 1 once, then Step 3 twice. 2 times = done.

## 4. Full Program
See `parser.y`, `scanner.l`. Compile & run:
```
lex scanner.l
yacc -d parser.y
gcc lex.yy.c y.tab.c -o parser
./parser
```

## 5. Expected Output
See `output.txt`. Key line for `a+b*c`:
```
Inorder: a + b * c
```
(Sample output — flex/bison not installed, this is the expected result.)

## 6. How to write in exam (3 min version)
Must write: struct + mk (5 lines) + inorder (4 lines) + grammar with mk actions. Scanner = 4 lines. Skip `%union` detail if short — mention ID passes string.

## 7. Viva — 1 line answers
1. **What is AST?** Tree of operators + operands, no brackets.
2. **Why inorder?** Gives back original order (left-root-right).
3. **What is %union?** Holds different value types (string vs node).
4. **Why T below E?** `*` has higher precedence, binds first.
5. **Leaf vs internal node?** Leaf = id (no children), internal = operator (+/*).
