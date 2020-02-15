#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>

// トークンの種類
typedef enum {
  TK_RESERVED,  // 記号
  TK_NUM,       // 整数トークン
  TK_EOF,       // 入力の終わりを表すトークン
} TokenKind;


typedef struct Token Token;
// トークン型
struct Token {
  TokenKind kind;  // トークンの型
  Token *next;     // 次の入力トークン
  int val;         // kindがTK_NUMの場合、その数値
  char *str;       // トークン文字列
  int len;         // トークンの長さ
};

// エラーを報告するための関数
// printfと同じ引数を取る
void error(char *fmt, ...);

// エラーとその場所を報告するための関数
void error_at(char *loc, char *fmt, ...);

// 次のトークンが期待している記号のときには、トークンを1つ読み進めて
// 真を返す。それ以外の場合には偽を返す。
bool consume(char *op);

// 次のトークンが期待している記号のときには、トークンを1つ読み進める。
// それ以外の場合にはエラーを報告する。
void expect(char *op);

// 次のトークンが数値の場合、トークンを1つ読み進めてその数値を返す。
// それ以外の場合にはエラーを報告する。
int expect_number();

bool at_eof();
// 新しいトークンを作成してcurにつなげる
Token *new_token(TokenKind kind, Token *cur, char *str, int len);

bool oprcmp(char *p, char *q);

// 入力文字列pをトークナイズしてそれを返す
Token *tokenize();

// 現在着目しているトークン
extern Token *token;

// 入力の先頭ポインタ
extern char *user_input;








// 抽象構文木のノードの種類
typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // 整数
} NodeKind;

typedef struct Node Node;
// 抽象構文木のノードの型
struct Node {
  NodeKind kind; // ノードの型
  Node *left;    // 左辺
  Node *right;   // 右辺
  int val;       // kindがND_NUMのとき
};

Node *new_node(NodeKind kind, Node *left, Node *right);
Node *new_node_num(int val);

// expr       = equality
// equality   = relational ("==" relational | "!=" relational)*
// relational = add ("<" add | "<=" add | ">" add | ">=" add)*
// add        = mul ("+" mul | "-" mul)*
// mul        = unary ("*" unary | "/" unary)*
// unary      = ("+" | "-")? primary
// primary    = num | "(" expr ")"
Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();


void gen(Node *node);


