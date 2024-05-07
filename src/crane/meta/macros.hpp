#pragma once
#define CRANE_HEADER_CONTENTS

/// Exapnds its arguments for evaluation
#define CRANE_EVAL(...) __VA_ARGS__

/// Evaluates to the number of arguments, up to 10
#define CRANE_VARCOUNT(...) CRANE_EVAL(CRANE_VARCOUNT_I(__VA_ARGS__,10,9,8,7,6,5,4,3,2,1,))
#define CRANE_VARCOUNT_I(_,_10,_9,_8,_7,_6,_5,_4,_3,_2,X_,...) X_

/// Evaluates to the head of a tuple of elements
#define HEAD(...) CRANE_EVAL(CRANE_HEAD_I(__VA_ARGS__,))
#define CRANE_HEAD_I(X,...) X

/// Evaluates to the tail of a tuple of elements
#define CRANE_TUPLE_TAIL(...) CRANE_EVAL(CRANE_TUPLE_TAIL_I(__VA_ARGS__))
#define CRANE_TUPLE_TAIL_I(X,...) (__VA_ARGS__)

/// Indirect concatenator
#define CRANE_GLUE(A, B) CRANE_GLUE_I(A, B)
#define CRANE_GLUE_I(A, B) A ## B

/// Evaluates and concatenates up to 10 arguments
#define CRANE_CONCAT(...) CRANE_GLUE(CRANE_GLUE(CRANE_CONCAT_,CRANE_VARCOUNT(__VA_ARGS__)),_)(__VA_ARGS__)
#define CRANE_CONCAT_I_(A, B)                           CRANE_GLUE(A, B)
#define CRANE_CONCAT_1_(A)                              A
#define CRANE_CONCAT_2_(A, B)                           CRANE_CONCAT_I_(A, CRANE_CONCAT_1_(B))
#define CRANE_CONCAT_3_(A, B, C)                        CRANE_CONCAT_I_(A, CRANE_CONCAT_2_(B, C))
#define CRANE_CONCAT_4_(A, B, C, D)                     CRANE_CONCAT_I_(A, CRANE_CONCAT_3_(B, C, D))
#define CRANE_CONCAT_5_(A, B, C, D, E)                  CRANE_CONCAT_I_(A, CRANE_CONCAT_4_(B, C, D, E))
#define CRANE_CONCAT_6_(A, B, C, D, E, F)               CRANE_CONCAT_I_(A, CRANE_CONCAT_5_(B, C, D, E, F))
#define CRANE_CONCAT_7_(A, B, C, D, E, F, G)            CRANE_CONCAT_I_(A, CRANE_CONCAT_6_(B, C, D, E, F, G))
#define CRANE_CONCAT_8_(A, B, C, D, E, F, G, H)         CRANE_CONCAT_I_(A, CRANE_CONCAT_7_(B, C, D, E, F, G, H))
#define CRANE_CONCAT_9_(A, B, C, D, E, F, G, H, I)      CRANE_CONCAT_I_(A, CRANE_CONCAT_8_(B, C, D, E, F, G, H, I))
#define CRANE_CONCAT_10_(A, B, C, D, E, F, G, H, I, J)  CRANE_CONCAT_I_(A, CRANE_CONCAT_9_(B, C, D, E, F, G, H, I, J))

#undef CRANE_HEADER_CONTENTS