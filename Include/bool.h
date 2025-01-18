#ifndef CHESSY_BOOL
#define CHESSY_BOOL

#if __STDC_VERSION__ >= 199901L
#define chessy_bool _Bool
#else 
#define chessy_bool int
#endif

#define chessy_true 1
#define chessy_false 0

#endif