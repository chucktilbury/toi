#undef YYBTYACC
#define YYBTYACC 1
#define YYDEBUGSTR (yytrial ? YYPREFIX "debug(trial)" : YYPREFIX "debug")
typedef short YYINT;
const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    2,    3,    3,    3,    3,
    4,    5,    8,    8,    8,    8,    7,    7,    6,    9,
    9,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   11,   12,   18,   19,   19,   19,   20,   20,   20,   20,
   20,   20,   17,   17,   17,   22,   22,   24,   24,   25,
   25,   25,   25,   25,   25,   25,   23,   23,   23,   23,
   23,   27,   27,   27,   26,   26,   26,   26,   26,   26,
   21,   21,   21,   28,   28,   28,   28,   29,   29,   29,
   29,   13,   13,   30,   30,   31,   32,   33,   33,   34,
   34,   34,   14,   15,   16,   16,   35,   35,   36,   36,
   36,   36,   36,
};
const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    3,    6,    6,    6,    6,
    3,    6,    0,    3,    3,    3,    1,    3,    3,    1,
    2,    1,    1,    1,    1,    1,    1,    1,    2,    1,
    4,    3,    6,    0,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    1,    3,    1,
    1,    1,    1,    1,    1,    1,    0,    1,    1,    6,
    4,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    1,    3,    3,    3,    1,    2,    3,    1,
    1,    6,    5,    1,    2,    5,    3,    1,    2,    1,
    2,    2,    5,    9,    7,    8,    1,    2,    5,    5,
    5,    5,    5,
};
const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    1,    3,    4,    5,
    0,    0,    0,    0,    0,    0,    2,    0,    0,    0,
    6,    0,    0,    0,    0,    0,    0,   11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,   30,    0,    0,   23,   24,   25,   26,
   27,   28,    0,    0,    0,    0,   14,   15,   16,    0,
   18,   29,    0,    0,    0,    0,    0,    0,    0,   19,
   21,    7,    8,    9,   10,    0,   69,   70,    0,   65,
   66,   67,   68,   58,   59,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   80,    0,    0,    0,
    0,   41,   42,    0,   77,   81,    0,    0,   45,   43,
   32,   12,    0,    0,    0,    0,    0,    0,    0,   78,
    0,    0,    0,    0,    0,    0,    0,    0,   31,   63,
   62,   64,    0,    0,    0,    0,   93,    0,    0,   79,
    0,    0,    0,    0,   50,    0,   55,   47,    0,    0,
   36,    0,    0,   74,   75,   76,   61,    0,   82,    0,
    0,    0,    0,   90,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   85,    0,   92,   91,   87,   89,    0,
    0,    0,   98,   49,   33,    0,   60,    0,    0,    0,
    0,    0,    0,   96,    0,   94,    0,    0,    0,    0,
    0,   86,  102,  103,   99,  100,  101,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
const YYINT yystos[] = {                           0,
  257,  258,  259,  260,  295,  305,  306,  307,  308,  309,
  288,  288,  288,  297,  279,  310,  306,  295,  295,  295,
  286,  257,  258,  259,  312,  313,  281,  311,  294,  294,
  294,  288,  288,  288,  280,  285,  261,  264,  266,  267,
  268,  295,  308,  311,  314,  315,  316,  317,  318,  319,
  320,  321,  296,  297,  277,  278,  295,  295,  295,  279,
  312,  286,  279,  279,  279,  279,  279,  294,  323,  282,
  314,  286,  286,  286,  286,  312,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  328,  331,  328,  295,  316,
  295,  277,  278,  279,  290,  295,  296,  297,  324,  325,
  326,  327,  328,  333,  334,  295,  322,  326,  327,  328,
  286,  280,  279,  280,  279,  280,  286,  280,  326,  334,
  289,  280,  285,  289,  290,  291,  292,  293,  286,  295,
  297,  328,  332,  311,  332,  281,  337,  328,  281,  280,
  277,  278,  295,  296,  297,  326,  328,  329,  330,  279,
  324,  333,  333,  334,  334,  334,  280,  265,  335,  336,
  285,  262,  263,  315,  338,  339,  286,  269,  340,  341,
  289,  324,  279,  335,  332,  286,  286,  282,  338,  326,
  279,  282,  340,  329,  280,  328,  280,  280,  277,  278,
  295,  296,  297,  336,  280,  337,  280,  280,  280,  280,
  280,  311,  311,  311,  311,  311,  311,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
const YYINT yydgoto[] = {                          6,
    7,    8,   43,   10,   16,   44,   25,   26,   45,   46,
   47,   48,   49,   50,   51,   52,  107,   69,   99,  100,
  101,  102,  103,  148,  149,   87,  133,  104,  105,  159,
  160,  137,  165,  166,  169,  170,
};
const YYINT yysindex[] = {                      -235,
 -278, -247, -226, -220, -187, -235,    0,    0,    0,    0,
 -191, -158, -136, -110,   27, -101,    0, -105,  -90,  -87,
    0,  -98,  -79,  -70, -103,  -69, -133,    0,  -84,  -82,
 -188,  -68,  -67,  -57,  -39,   27,  -61,  -38,  -29,  -28,
  -22, -274,    0,    0,    8, -133,    0,    0,    0,    0,
    0,    0,    5,    6,    7,    9,    0,    0,    0,   27,
    0,    0,  -11,  -11,   -1,    1, -132, -104,   11,    0,
    0,    0,    0,    0,    0,   18,    0,    0,   20,    0,
    0,    0,    0,    0,    0,   21,   23,   24,   12,   14,
   25,    0,    0,  -73,  -73,    0,    0,   19,   29,   22,
 -182,    0,    0,   -4,    0,    0,   17, -182,    0,    0,
    0,    0, -192, -101, -192,   31,  -11,   32, -160,    0,
  -76,   35, -132,  -73,  -73,  -73,  -73,  -73,    0,    0,
    0,    0,   36,   45,   26, -145,    0,   33,   46,    0,
    0,    0,    0,    0,    0,   34,    0,    0,   37, -132,
    0,   -4,   -4,    0,    0,    0,    0,   38,    0,   45,
 -192,   39,   41,    0,   40, -145,  -73,   42,   47,   46,
  -76,   43,  -11,    0,   48,    0,    0,    0,    0, -102,
 -202,   45,    0,    0,    0,   50,    0,   31,   51,   52,
   53,   54,   55,    0, -101,    0, -101, -101, -101, -101,
 -101,    0,    0,    0,    0,    0,    0,
};
const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -259,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   56,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -259,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   57,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -259,
    0,    0,   58,   58,    0,    0,   59,   60,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -14,    0, -131,    0, -103,
 -219,    0,    0, -129,    0,    0,    0,   61,    0,    0,
    0,    0,   58,    0,   59,    0,   60,    0,    0,    0,
 -189,    0,   59,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -250,    0,    0,    0,    0,    0,    0,
    0,    0,  -21,  -10,    0,  -75,    0,    0,  -12,   59,
    0,  -56,  -54,    0,    0,    0,    0,    0,    0, -224,
   58,    0,    0,    0,    0,   63,    0,    0,    0,   66,
 -189,    0,   58,    0,    0,    0,    0,    0,    0,    0,
    0, -194,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   62,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -170, -153,    0,    0,  -72,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -43,  -41,  -33,  -31,    0,   64,    0,    0,    0,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#endif
const YYINT yygindex[] = {                         0,
  312,    0,   30,    0,    0,  -16,   -8,    0,  274, -117,
  272,    0,    0,    0,    0,    0,    0,    0,  -96,    0,
  -65,  273,  -62,  169,    0,    0, -111,   28,  -80,  183,
  170,  163,  188,    0,  185,    0,
};
const YYINT yytable[] = {                         28,
   86,   88,  108,  135,   67,  110,   83,   83,   83,   11,
   83,   83,   83,   83,  120,   83,   83,   83,  164,   68,
   13,    1,    2,    3,    4,   13,  151,   61,  119,    9,
   83,   83,   84,   84,   84,    9,   84,   84,   84,   84,
   12,   84,   84,   84,   83,  154,  155,  156,  164,  175,
  132,   76,  132,  172,  138,  146,   84,   84,  147,    5,
   40,   13,   95,   95,   95,   40,   95,   95,   95,   95,
   84,   95,   95,   95,  189,  190,   14,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   95,   95,   55,   56,
   57,   15,  191,  192,  193,   57,   57,  134,  132,   57,
   95,  180,  130,   18,  131,  146,  124,  125,  147,    3,
  186,    1,    2,    3,    3,   37,  162,  163,   38,  140,
   39,   40,   41,    1,    2,    3,    6,   37,  124,  125,
   38,    6,   39,   40,   41,   27,   19,   77,   78,   79,
   80,   81,   82,   83,   92,   93,   94,   27,   46,   42,
   73,  152,  153,   46,   46,   73,   73,   95,   20,   73,
   73,   42,   96,   97,   98,   77,   78,   79,   80,   81,
   82,   83,   84,   85,   94,   21,   35,  188,  202,   27,
  203,  204,  205,  206,  207,   95,  124,  125,   29,   32,
  106,   97,   98,   77,   78,   79,   80,   81,   82,   83,
  141,  142,   94,   30,   56,   94,   31,    9,   33,   56,
   56,   53,    9,   95,   54,   36,   95,   34,  143,  144,
  145,  106,   97,   71,   62,   72,   57,   58,   71,   71,
   72,   72,   71,   71,   72,   72,   12,   59,   15,   60,
   63,   12,   12,   15,   15,   12,   18,   15,   21,   64,
   65,   18,   18,   21,   21,   18,   66,   21,   77,   78,
   79,   80,   81,   82,   83,   84,   85,   48,   81,   81,
   81,   81,   48,   48,   81,   81,   81,   81,   81,   80,
   80,   80,   80,   22,   23,   24,  126,  127,  128,   70,
   72,   73,   74,   89,   75,   91,  111,  112,  113,  117,
  114,  115,  129,  116,  118,   68,  123,  121,  122,  158,
  161,  136,  139,  150,  168,  157,  173,   17,  167,   71,
  181,  178,  185,  125,  176,  171,  177,  187,  182,  195,
  197,  198,  199,  200,  201,   17,   90,   57,   20,  184,
  109,    0,  174,   57,   88,   57,   44,   97,    0,    0,
  196,  194,   25,  179,  183,
};
const YYINT yycheck[] = {                         16,
   63,   64,   68,  115,  279,   68,  257,  258,  259,  288,
  261,  262,  263,  264,   95,  266,  267,  268,  136,  294,
  280,  257,  258,  259,  260,  285,  123,   36,   94,    0,
  281,  282,  257,  258,  259,    6,  261,  262,  263,  264,
  288,  266,  267,  268,  295,  126,  127,  128,  166,  161,
  113,   60,  115,  150,  117,  121,  281,  282,  121,  295,
  280,  288,  257,  258,  259,  285,  261,  262,  263,  264,
  295,  266,  267,  268,  277,  278,  297,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  281,  282,  277,  278,
  280,  279,  295,  296,  297,  285,  286,  114,  161,  289,
  295,  167,  295,  295,  297,  171,  289,  290,  171,  280,
  173,  257,  258,  259,  285,  261,  262,  263,  264,  280,
  266,  267,  268,  257,  258,  259,  280,  261,  289,  290,
  264,  285,  266,  267,  268,  281,  295,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  281,  280,  295,
  280,  124,  125,  285,  286,  285,  286,  290,  295,  289,
  290,  295,  295,  296,  297,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  286,  280,  280,  195,  281,
  197,  198,  199,  200,  201,  290,  289,  290,  294,  288,
  295,  296,  297,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  294,  280,  279,  294,  280,  288,  285,
  286,  296,  285,  290,  297,  285,  290,  288,  295,  296,
  297,  295,  296,  280,  286,  280,  295,  295,  285,  286,
  285,  286,  289,  290,  289,  290,  280,  295,  280,  279,
  279,  285,  286,  285,  286,  289,  280,  289,  280,  279,
  279,  285,  286,  285,  286,  289,  279,  289,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  280,  290,  291,
  292,  293,  285,  286,  289,  290,  291,  292,  293,  290,
  291,  292,  293,  257,  258,  259,  291,  292,  293,  282,
  286,  286,  286,  295,  286,  295,  286,  280,  279,  286,
  280,  279,  286,  280,  280,  294,  285,  289,  280,  265,
  285,  281,  281,  279,  269,  280,  279,    6,  286,   46,
  279,  282,  280,  290,  286,  289,  286,  280,  282,  280,
  280,  280,  280,  280,  280,  280,   65,  280,  282,  171,
   68,  280,  160,  285,  282,  286,  286,  282,  280,  280,
  188,  182,  289,  166,  170,
};
#if YYBTYACC
const YYINT yyctable[] = {                        -1,
   34,   57,   -1,   38,   58,   -1,   39,   59,   -1,   37,
   81,   -1,   53,   58,   -1,   54,   59,   -1,   51,   81,
   -1,   52,   80,   -1,  124,   56,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NUM","STRG","BOOL","IMPORT",
"RETURN","BREAK","CONT","IF","ELSE","WHILE","FOR","SWITCH","CASE","OR","AND",
"NOT","EQ","NEQ","MORE","LESS","TRUE","FALSE","OPAREN","CPAREN","OCURLY",
"CCURLY","OBOX","CBOX","COMMA","SCOLON","DOT","COLON","PLUS","MINUS","MULT",
"DIV","MODULO","ASSIGN","SYMBOL","NUMBER","STRING","TILDE","PIPE","AMPER",
"CARAT","END_CONTEXT","END_INPUT","$accept","module","module_element",
"import_directive","var_definition","function_definition",
"function_def_parameters","statement_group","fd_parameter_list","fd_parameter",
"statement_list","statement","var_assignment","function_call","if_statement",
"while_statement","for_statement","switch_statement","expression",
"function_call_parameters","fc_parameter_list","fc_parameter",
"arith_expression","string_expression","boolean_expression",
"string_element_list","string_element","boolean_function","boolean_factor",
"arith_term","arith_factor","else_clause_list","else_clause",
"loop_statement_group","loop_statement_list","loop_statement",
"case_clause_list","case_clause","illegal-symbol",
};
const char *const yyrule[] = {
"$accept : module",
"module : module_element",
"module : module module_element",
"module_element : import_directive",
"module_element : var_definition",
"module_element : function_definition",
"import_directive : IMPORT STRING SCOLON",
"var_definition : NUM COLON SYMBOL ASSIGN NUMBER SCOLON",
"var_definition : STRG COLON SYMBOL ASSIGN STRING SCOLON",
"var_definition : BOOL COLON SYMBOL ASSIGN TRUE SCOLON",
"var_definition : BOOL COLON SYMBOL ASSIGN FALSE SCOLON",
"function_definition : SYMBOL function_def_parameters statement_group",
"function_def_parameters : OPAREN fd_parameter_list CPAREN OPAREN fd_parameter_list CPAREN",
"fd_parameter :",
"fd_parameter : NUM COLON SYMBOL",
"fd_parameter : STRG COLON SYMBOL",
"fd_parameter : BOOL COLON SYMBOL",
"fd_parameter_list : fd_parameter",
"fd_parameter_list : fd_parameter COMMA fd_parameter_list",
"statement_group : OCURLY statement_list CCURLY",
"statement_list : statement",
"statement_list : statement statement_list",
"statement : var_definition",
"statement : var_assignment",
"statement : function_call",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : switch_statement",
"statement : RETURN SCOLON",
"statement : statement_group",
"var_assignment : SYMBOL ASSIGN expression SCOLON",
"function_call : SYMBOL function_call_parameters SCOLON",
"function_call_parameters : OPAREN fc_parameter_list CPAREN OPAREN fc_parameter_list CPAREN",
"fc_parameter_list :",
"fc_parameter_list : fc_parameter",
"fc_parameter_list : fc_parameter COMMA fc_parameter_list",
"fc_parameter : SYMBOL",
"fc_parameter : TRUE",
"fc_parameter : FALSE",
"fc_parameter : arith_expression",
"fc_parameter : string_expression",
"fc_parameter : boolean_expression",
"expression : boolean_expression",
"expression : arith_expression",
"expression : string_expression",
"string_expression : STRING",
"string_expression : STRING PLUS string_element_list",
"string_element_list : string_element",
"string_element_list : string_element PLUS string_element_list",
"string_element : STRING",
"string_element : SYMBOL",
"string_element : NUMBER",
"string_element : TRUE",
"string_element : FALSE",
"string_element : boolean_expression",
"string_element : arith_expression",
"boolean_expression :",
"boolean_expression : TRUE",
"boolean_expression : FALSE",
"boolean_expression : boolean_function OPAREN boolean_factor COMMA boolean_factor CPAREN",
"boolean_expression : NOT OPAREN boolean_factor CPAREN",
"boolean_factor : STRING",
"boolean_factor : SYMBOL",
"boolean_factor : boolean_expression",
"boolean_function : EQ",
"boolean_function : NEQ",
"boolean_function : MORE",
"boolean_function : LESS",
"boolean_function : OR",
"boolean_function : AND",
"arith_expression : arith_expression PLUS arith_term",
"arith_expression : arith_expression MINUS arith_term",
"arith_expression : arith_term",
"arith_term : arith_term MULT arith_factor",
"arith_term : arith_term DIV arith_factor",
"arith_term : arith_term MODULO arith_factor",
"arith_term : arith_factor",
"arith_factor : MINUS arith_factor",
"arith_factor : OPAREN arith_expression CPAREN",
"arith_factor : NUMBER",
"arith_factor : SYMBOL",
"if_statement : IF OPAREN boolean_expression CPAREN statement_group else_clause_list",
"if_statement : IF OPAREN boolean_expression CPAREN statement_group",
"else_clause_list : else_clause",
"else_clause_list : else_clause else_clause_list",
"else_clause : ELSE OPAREN boolean_expression CPAREN statement_group",
"loop_statement_group : OCURLY loop_statement_list CCURLY",
"loop_statement_list : loop_statement",
"loop_statement_list : loop_statement loop_statement_list",
"loop_statement : statement",
"loop_statement : CONT SCOLON",
"loop_statement : BREAK SCOLON",
"while_statement : WHILE OPAREN boolean_expression CPAREN loop_statement_group",
"for_statement : FOR OPAREN var_assignment SCOLON boolean_expression SCOLON arith_expression CPAREN loop_statement_group",
"switch_statement : SWITCH OPAREN SYMBOL CPAREN OCURLY case_clause_list CCURLY",
"switch_statement : SWITCH OPAREN SYMBOL CPAREN OCURLY case_clause_list CCURLY else_clause",
"case_clause_list : case_clause",
"case_clause_list : case_clause case_clause_list",
"case_clause : CASE OPAREN SYMBOL CPAREN statement_group",
"case_clause : CASE OPAREN NUMBER CPAREN statement_group",
"case_clause : CASE OPAREN STRING CPAREN statement_group",
"case_clause : CASE OPAREN TRUE CPAREN statement_group",
"case_clause : CASE OPAREN FALSE CPAREN statement_group",

};
#endif