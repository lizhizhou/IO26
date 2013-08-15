/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : F6x8.C
Purpose     : Contains standard font
Height      : 8
---------------------------END-OF-HEADER------------------------------
*/

#include "Point_font.h"

GUI_CONST_STORAGE unsigned char GUI_acFont6x8[163][8] = {
  {
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

/*  !  */
 ,{
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   ________,
   __X_____,
   ________}


/*  "  */
 ,{
   _X__X___,
   _X__X___,
   _X__X___,
   ________,
   ________,
   ________,
   ________,
   ________}

/* #  */
 ,{
   _X_X____,
   _X_X____,
   XXXXX___,
   _X_X____,
   XXXXX___,
   _X_X____,
   _X_X____,
   ________}

/*  $  */
 ,{
   __X_____,
   _XXXX___,
   X_X_____,
   _XXX____,
   __X_X___,
   XXXX____,
   __X_____}

/*  %  */
 ,{
   XX______,
   XX__X___,
   ___X____,
   __X_____,
   _X______,
   X__XX___,
   ___XX___,
   ________}

/*  &  */
 ,{
   _XX_____,
   X__X____,
   X_X_____,
   _X______,
   X_X_X___,
   X__X____,
   _XX_X___,
   ________}

/*  '  */
 ,{
   _XX_____,
   __X_____,
   _X______,
   ________,
   ________,
   ________,
   ________,
   ________}

/*  (  */
 ,{
   ___X____,
   __X_____,
   _X______,
   _X______,
   _X______,
   __X_____,
   ___X____,
   ________}

/*  )  */
 ,{
   _X______,
   __X_____,
   ___X____,
   ___X____,
   ___X____,
   __X_____,
   _X______,
   ________}

/*  *  */
 ,{
   ________,
   _X_X____,
   __X_____,
   XXXXX___,
   __X_____,
   _X_X____,
   ________,
   ________}

 ,{
   ________,
   __X_____,
   __X_____,
   XXXXX___,
   __X_____,
   __X_____,
   ________,
   ________}

 ,{
   ________,
   ________,
   ________,
   ________,
   ________,
   _XX_____,
   __X_____,
   _X______}

 ,{
   ________,
   ________,
   ________,
   XXXXX___,
   ________,
   ________,
   ________,
   ________}

 ,{
   ________,
   ________,
   ________,
   ________,
   ________,
   _XX_____,
   _XX_____,
   ________}

 ,{
   ________,
   ____X___,
   ___X____,
   __X_____,
   _X______,
   X_______,
   ________,
   ________}

/* 0 */
 ,{
   _XXX____,
   X___X___,
   X__XX___,
   X_X_X___,
   XX__X___,
   X___X___,
   _XXX____,
   ________}

/* 1 */
 ,{
   __X_____,
   _XX_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

/* 2 */
 ,{
   _XXX____,
   X___X___,
   ____X___,
   __XX____,
   _X______,
   X_______,
   XXXXX___,
   ________}

/* 3 */
 ,{
   _XXX____,
   X___X___,
   ____X___,
   __XX____,
   ____X___,
   X___X___,
   _XXX____,
   ________}

/* 4 */
 ,{
   ___X____,
   __XX____,
   _X_X____,
   X__X____,
   XXXXX___,
   ___X____,
   ___X____,
   ________}

/* 5 */
 ,{
   XXXXX___,
   X_______,
   XXXX____,
   ____X___,
   ____X___,
   X___X___,
   _XXX____,
   ________}

/* 6 */
 ,{
   __XX____,
   _X______,
   X_______,
   XXXX____,
   X___X___,
   X___X___,
   _XXX____,
   ________}

/* 7 */
 ,{
   XXXXX___,
   ____X___,
   ___X____,
   __X_____,
   _X______,
   _X______,
   _X______,
   ________}

/* 8 */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   _XXX____,
   X___X___,
   X___X___,
   _XXX____,
   ________}

/* 9 */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   _XXXX___,
   ____X___,
   ___X____,
   _XX_____,
   ________}

/* ':' 3a */
 ,{
   ________,
   _XX_____,
   _XX_____,
   ________,
   _XX_____,
   _XX_____,
   ________,
   ________}

/* ';' 3b */
 ,{
   ________,
   ________,
   _XX_____,
   _XX_____,
   ________,
   _XX_____,
   __X_____,
   _X______}


/* '<' 3c */
 ,{
   ___X____,
   __X_____,
   _X______,
   X_______,
   _X______,
   __X_____,
   ___X____,
   ________}

/* '=' 3d */
 ,{
   ________,
   ________,
   XXXXX___,
   ________,
   XXXXX___,
   ________,
   ________,
   ________}

/* '>' */
 ,{
   X_______,
   _X______,
   __X_____,
   ___X____,
   __X_____,
   _X______,
   X_______,
   ________}

/* '?' */
 ,{
   _XXX____,
   X___X___,
   ____X___,
   ___X____,
   __X_____,
   ________,
   __X_____,
   ________}

/* @ */
 ,{
   _XXX____,
   X___X___,
   ____X___,
   _XX_X___,
   X_X_X___,
   X_X_X___,
   _XXX____,
   ________}

/* A */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   XXXXX___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* B */
 ,{
   XXXX____,
   X___X___,
   X___X___,
   XXXX____,
   X___X___,
   X___X___,
   XXXX____,
   ________}

/* C */
 ,{
   _XXX____,
   X___X___,
   X_______,
   X_______,
   X_______,
   X___X___,
   _XXX____,
   ________}

/* D */
 ,{
   XXX_____,
   X__X____,
   X___X___,
   X___X___,
   X___X___,
   X__X____,
   XXX_____,
   ________}

/* E */
 ,{
   XXXXX___,
   X_______,
   X_______,
   XXXX____,
   X_______,
   X_______,
   XXXXX___,
   ________}

/* 1 */
 ,{
   XXXXX___,
   X_______,
   X_______,
   XXXX____,
   X_______,
   X_______,
   X_______,
   ________}

/* 1 */
 ,{
   _XXX____,
   X___X___,
   X_______,
   X_______,
   X__XX___,
   X___X___,
   _XXXX___,
   ________}

/* 1 */
 ,{
   X___X___,
   X___X___,
   X___X___,
   XXXXX___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* I */
 ,{
   _XXX____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

/* J */
 ,{
   __XXX___,
   ___X____,
   ___X____,
   ___X____,
   ___X____,
   X__X____,
   _XX_____,
   ________}

/* K */
 ,{
   X___X___,
   X__X____,
   X_X_____,
   XX______,
   X_X_____,
   X__X____,
   X___X___,
   ________}

/* L */
 ,{
   X_______,
   X_______,
   X_______,
   X_______,
   X_______,
   X_______,
   XXXXX___,
   ________}

/* M */
 ,{
   X___X___,
   XX_XX___,
   X_X_X___,
   X_X_X___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* N */
 ,{
   X___X___,
   X___X___,
   XX__X___,
   X_X_X___,
   X__XX___,
   X___X___,
   X___X___,
   ________}

/* O */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________}

/* P */
 ,{
   XXXX____,
   X___X___,
   X___X___,
   XXXX____,
   X_______,
   X_______,
   X_______,
   ________}

/* Q */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   X___X___,
   X_X_X___,
   X__X____,
   _XX_X___,
   ________}

/* R */
 ,{
   XXXX____,
   X___X___,
   X___X___,
   XXXX____,
   X_X_____,
   X__X____,
   X___X___,
   ________}

/* S */
 ,{
   _XXX____,
   X___X___,
   X_______,
   _XXX____,
   ____X___,
   X___X___,
   _XXX____,
   ________}

/* T */
 ,{
   XXXXX___,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   ________}

/* U */
 ,{
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________}

/* V */
 ,{
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   _X_X____,
   __X_____,
   ________}

/* W */
 ,{
   X___X___,
   X___X___,
   X___X___,
   X_X_X___,
   X_X_X___,
   X_X_X___,
   _X_X____,
   ________}

/* X */
 ,{
   X___X___,
   X___X___,
   _X_X____,
   __X_____,
   _X_X____,
   X___X___,
   X___X___,
   ________}

/* Y */
 ,{
   X___X___,
   X___X___,
   X___X___,
   _X_X____,
   __X_____,
   __X_____,
   __X_____,
   ________}

/* Z */
 ,{
   XXXXX___,
   ____X___,
   ___X____,
   __X_____,
   _X______,
   X_______,
   XXXXX___,
   ________}

/* 5b */
 ,{
   _XXX____,
   _X______,
   _X______,
   _X______,
   _X______,
   _X______,
   _XXX____,
   ________}

/* 5c */
 ,{
   ________,
   X_______,
   _X______,
   __X_____,
   ___X____,
   ____X___,
   ________,
   ________}

/* 5d */
 ,{
   _XXX____,
   ___X____,
   ___X____,
   ___X____,
   ___X____,
   ___X____,
   _XXX____,
   ________}

/* 5e */
 ,{
   __X_____,
   _X_X____,
   X___X___,
   ________,
   ________,
   ________,
   ________,
   ________}

/* 5f */
 ,{
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   XXXXX___}

/* 60 */
 ,{
   _X______,
   __X_____,
   ___X____,
   ________,
   ________,
   ________,
   ________,
   ________}

/* a */
 ,{
   ________,
   ________,
   _XXX____,
   ____X___,
   _XXXX___,
   X___X___,
   _XXXX___,
   ________}

/* b */
 ,{
   X_______,
   X_______,
   X_XX____,
   XX__X___,
   X___X___,
   X___X___,
   XXXX____,
   ________}

/* c */
 ,{
   ________,
   ________,
   _XXX____,
   X_______,
   X_______,
   X___X___,
   _XXX____,
   ________}

/* d */
 ,{
   ____X___,
   ____X___,
   _XX_X___,
   X__XX___,
   X___X___,
   X___X___,
   _XXXX___,
   ________}

/* e */
 ,{
   ________,
   ________,
   _XXX____,
   X___X___,
   XXXXX___,
   X_______,
   _XXX____,
   ________}

/* f */
 ,{
   __XX____,
   _X__X___,
   _X______,
   XXX_____,
   _X______,
   _X______,
   _X______,
   ________}

/* g */
 ,{
   ________,
   ________,
   _XXXX___,
   X___X___,
   X___X___,
   _XXXX___,
   ____X___,
   _XXX____}

/* h */
 ,{
   X_______,
   X_______,
   X_XX____,
   XX__X___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* i */
 ,{
   __X_____,
   ________,
   _XX_____,
   __X_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

/* j */
 ,{
   ___X____,
   ________,
   __XX____,
   ___X____,
   ___X____,
   ___X____,
   X__X____,
   _XX_____}

/* k */
 ,{
   X_______,
   X_______,
   X__X____,
   X_X_____,
   XX______,
   X_X_____,
   X__X____,
   ________}

/* l */
 ,{
   _XX_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

/* m */
 ,{
   ________,
   ________,
   XX_X____,
   X_X_X___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* n */
 ,{
   ________,
   ________,
   X_XX____,
   XX__X___,
   X___X___,
   X___X___,
   X___X___,
   ________}

/* o */
 ,{
   ________,
   ________,
   _XXX____,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________}

/* p */
 ,{
   ________,
   ________,
   XXXX____,
   X___X___,
   X___X___,
   XXXX____,
   X_______,
   X_______}

/* q */
 ,{
   ________,
   ________,
   _XXXX___,
   X___X___,
   X___X___,
   _XXXX___,
   ____X___,
   ____X___}

/* r */
 ,{
   ________,
   ________,
   X_XX____,
   XX__X___,
   X_______,
   X_______,
   X_______,
   ________}

/* s */
 ,{
   ________,
   ________,
   _XXXX___,
   X_______,
   _XXX____,
   ____X___,
   XXXX____,
   ________}

/* t */
 ,{
   _X______,
   _X______,
   XXX_____,
   _X______,
   _X______,
   _X__X___,
   __XX____,
   ________}

/* u */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X___X___,
   X__XX___,
   _XX_X___,
   ________}

/* v */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X___X___,
   _X_X____,
   __X_____,
   ________}

/* w */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X_X_X___,
   X_X_X___,
   _X_X____,
   ________}

/* X */
 ,{
   ________,
   ________,
   X___X___,
   _X_X____,
   __X_____,
   _X_X____,
   X___X___,
   ________}

/* y */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X___X___,
   _XXXX___,
   ____X___,
   _XXX____}

/* z */
 ,{
   ________,
   ________,
   XXXXX___,
   ___X____,
   __X_____,
   _X______,
   XXXXX___,
   ________}

/* 0x7b */
 ,{
   ___X____,
   __X_____,
   __X_____,
   _X______,
   __X_____,
   __X_____,
   ___X____,
   ________}

/* 0x7c */
 ,{
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   ________}

/* 0x7d */
 ,{
   _X______,
   __X_____,
   __X_____,
   ___X____,
   __X_____,
   __X_____,
   _X______,
   ________}

/* 0x7e */
 ,{
   _XX_X___,
   X__X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}


/*  additional characters for European character set  */

#if (GUI_NOFCHARS>95)
/* small accent ague, 95*/
 ,{
   ___XX___,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>96)

/* small accent grave, 96 */
 ,{
   XX______,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>97)

/* small accent circonflex, 97 */
 ,{
   _XXX____,
   X___X___,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>98)

/* small umlaut, 98 */
 ,{
   _X_X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>99)

/* small tilde, 99 */
 ,{
   _XX_X___,
   X__X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>100)

/* i without dot, 100 */
 ,{
   ________,
   ________,
   ________,
   _XX_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>101)

/* sharps eg �, 101  */
 ,{
   ________,
   _XX_____,
   X__X____,
   XXXX____,
   X___X___,
   X___X___,
   X_XX____,
   X_______}

#endif
#if (GUI_NOFCHARS>102)

/* capital A with ring, 102 */
 ,{
   __X_____,
   ________,
   _XXX____,
   X___X___,
   XXXXX___,
   X___X___,
   X___X___,
   ________}

#endif
#if (GUI_NOFCHARS>103)

/* small a with ring, 103 */
 ,{
   __X_____,
   ________,
   _XXX____,
   ____X___,
   _XXXX___,
   X___X___,
   _XXXX___,
   ________}

#endif
#if (GUI_NOFCHARS>104)

/*  capital A diphtong, ligature, 104 */
 ,{
   __XXX___,
   _XX_____,
   X_X_____,
   X_XXX___,
   XXX_____,
   X_X_____,
   X_XXX___,
   ________}

#endif
#if (GUI_NOFCHARS>105)

/*  Icelandic eth, 105 */
 ,{
   _XXX____,
   _X__X___,
   _X__X___,
   XXX_X___,
   _X__X___,
   _X__X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>106)

/*  Icelandic Thorn, 106 */
 ,{
   XXX_____,
   _X______,
   _XXX____,
   _X__X___,
   _X__X___,
   _XXX____,
   _X______,
   XXX_____}

#endif
#if (GUI_NOFCHARS>107)

/*  small a diphtong, ligature, 107 */
 ,{
   ________,
   ________,
   XX_X____,
   __X_X___,
   _XXXX___,
   X_X_____,
   _X_XX___,
   ________}

#endif
#if (GUI_NOFCHARS>108)

/*  small Icelanic Eth, 108 */
 ,{
   X_X_____,
   _X______,
   X_X_____,
   ___X____,
   _XXXX___,
   X___X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>109)

/*  small Icelandic Thorn, 109 */
 ,{
   _XX_____,
   __X_____,
   __XX____,
   __X_X___,
   __XX____,
   __X_____,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>110)

/*  Capital O with slash, 110 */
 ,{
   _XXX____,
   X___X___,
   X__XX___,
   X_X_X___,
   XX__X___,
   X___X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>111)

/*  small o with slash, 111 */
 ,{
   ________,
   ________,
   _XXX____,
   X__XX___,
   X_X_X___,
   XX__X___,
   _XXX____,
   ________}


/*  Capital letters  */


#endif
#if (GUI_NOFCHARS>112)

/*  Little capital A, 112 */
 ,{
   ________,
   ________,
   _XXX____,
   X___X___,
   XXXXX___,
   X___X___,
   X___X___,
   ________}

#endif
#if (GUI_NOFCHARS>113)

/*  Little capital E, 113 */
 ,{
   ________,
   ________,
   XXXXX___,
   X_______,
   XXX_____,
   X_______,
   XXXXX___,
   ________}

#endif
#if (GUI_NOFCHARS>114)

/*  Little capital I, 114 */
 ,{
   ________,
   ________,
   _XXX____,
   __X_____,
   __X_____,
   __X_____,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>115)

/*  Little capital O, 115 */
 ,{
   ________,
   ________,
   _XXX____,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>116)

/*  Little capital U, 116 */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>117)

/*  Little capital N, 117 */
 ,{
   ________,
   ________,
   X___X___,
   XX__X___,
   X_X_X___,
   X__XX___,
   X___X___,
   ________}


#endif
#if (GUI_NOFCHARS>118)

/*  inverted exclamation, 118 */
 ,{
   __X_____,
   ________,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   __X_____,
   ________}

#endif
#if (GUI_NOFCHARS>119)

/*  inverted question mark, 119 */
 ,{
   __X_____,
   ________,
   __X_____,
   _X______,
   X_______,
   X___X___,
   _XXX____,
   ________}

#endif
#if (GUI_NOFCHARS>120)

/* capital accent ague, 120 */
 ,{
   ___XX___,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>121)

/* capital accent grave, 121 */
 ,{
   XX______,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>122)

/* capital accent circonflex, 122 */
 ,{
   __X_____,
   _X_X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>123)

/* capital umlaut, 123 */
 ,{
   _X_X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>124)

/* capital tilde, 124 */
 ,{
   _XX_X___,
   X__X____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>125)

/* cedilla, 125 */
 ,{
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   __X_____}

#endif

/*  additional characters for complete ISO 8859-1 character set  */

#if (GUI_NOFCHARS>126)
/* Non breaking space, ISO-Code: 160, internal code: 126  */
 ,{
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>127)
/* cent sign, ISO-Code: 162, internal code: 127  */
 ,{
   ________,
   __X_____,
   _XXX____,
   X_X_____,
   X_X_____,
   X_X_X___,
   _XXX____,
   __X_____}

#endif
#if (GUI_NOFCHARS>128)
/* pound sterling, ISO-Code: 163, internal code: 128  */
 ,{
   __XX____,
   _X______,
   _X______,
   XXX_____,
   _X______,
   _X__X___,
   X_XX____,
   ________}

#endif
#if (GUI_NOFCHARS>129)
/* general currency sign, ISO-Code: 164, internal code: 129  */
 ,{
   ________,
   ________,
   X___X___,
   _XXX____,
   _X_X____,
   _XXX____,
   X___X___,
   ________}

#endif
#if (GUI_NOFCHARS>130)
/* yen sign, ISO-Code: 165, internal code: 130  */
 ,{
   X___X___,
   _X_X____,
   XXXXX___,
   __X_____,
   XXXXX___,
   __X_____,
   __X_____,
   ________}

#endif
#if (GUI_NOFCHARS>131)
/* broken vertical bar, ISO-Code: 166, internal code: 131  */
 ,{
   __X_____,
   __X_____,
   __X_____,
   ________,
   __X_____,
   __X_____,
   __X_____,
   ________}

#endif
#if (GUI_NOFCHARS>132)
/* section sign, ISO-Code: 167, internal code: 132  */
 ,{
   __XX____,
   _X__X___,
   __X_____,
   _X_X____,
   __X_____,
   X__X____,
   _XX_____,
   ________}

#endif
#if (GUI_NOFCHARS>133)
/* umlaut (dieresis), ISO-Code: 168, internal code: 133  */
 ,{
   X___X___,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>134)
/* copyright, ISO-Code: 169, internal code: 134  */
 ,{
   XXXXX___,
   X___X___,
   X_X_X___,
   X_XXX___,
   X_X_X___,
   X___X___,
   XXXXX___,
   ________}

#endif
#if (GUI_NOFCHARS>135)
/* feminine ordinal, ISO-Code: 170, internal code: 135  */
 ,{
   _XXX____,
   ____X___,
   _XXXX___,
   X___X___,
   _XXX____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>136)
/* left angle quote, ISO-Code: 171, internal code: 136  */
 ,{
   ________,
   __X_X___,
   _X_X____,
   X_X_____,
   _X_X____,
   __X_X___,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>137)
/* not sign, ISO-Code: 172, internal code: 137  */
 ,{
   ________,
   ________,
   ________,
   XXXXX___,
   ____X___,
   ____X___,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>138)
/* soft hyphen, ISO-Code: 173, internal code: 138  */
 ,{
   ________,
   ________,
   ________,
   _XXX____,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>139)
/* rgistered trademark, ISO-Code: 174, internal code: 139  */
 ,{
   XXXXX___,
   X___X___,
   X_X_X___,
   X___X___,
   X__XX___,
   X_X_X___,
   XXXXX___,
   ________}

#endif
#if (GUI_NOFCHARS>140)
/* macron accent, ISO-Code: 175, internal code: 140  */
 ,{
   XXXXX___,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>141)
/* degree sign, ISO-Code: 176, internal code: 141  */
 ,{
   __X_____,
   _X_X____,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>142)
/* plus or minus, ISO-Code: 177, internal code: 142  */
 ,{
   ________,
   __X_____,
   _XXX____,
   __X_____,
   ________,
   _XXX____,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>143)
/* superscript two, ISO-Code: 178, internal code: 143  */
 ,{
   _XX_____,
   X__X____,
   __X_____,
   _X______,
   XXXX____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>144)
/* superscript three, ISO-Code: 179, internal code: 144  */
 ,{
   XXX_____,
   ___X____,
   _XX_____,
   ___X____,
   XXX_____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>145)
/* acute accent, ISO-Code: 180, internal code: 145  */
 ,{
   ___XX___,
   __X_____,
   ________,
   ________,
   ________,
   ________,
   ________,
   ________}


#endif
#if (GUI_NOFCHARS>146)
/* micro sign, ISO-Code: 181, internal code: 146  */
 ,{
   ________,
   ________,
   X___X___,
   X___X___,
   X___X___,
   XX__X___,
   X_XX____,
   X_______}

#endif
#if (GUI_NOFCHARS>147)
/* paragraph sign, ISO-Code: 182, internal code: 147  */
 ,{
   _XXXX___,
   X__XX___,
   X__XX___,
   _XXXX___,
   ___XX___,
   ___XX___,
   ___XX___,
   ________}

#endif
#if (GUI_NOFCHARS>148)
/* middle dot, ISO-Code: 183, internal code: 148  */
 ,{
   ________,
   ________,
   ________,
   __XX____,
   __XX____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>149)
/* superscript one, ISO-Code: 185, internal code: 149  */
 ,{
   _X______,
   XX______,
   _X______,
   _X______,
   XXX_____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>150)
/* masculine ordinal, ISO-Code: 186, internal code: 150  */
 ,{
   _XXX____,
   X___X___,
   X___X___,
   X___X___,
   _XXX____,
   ________,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>151)
/* right angle quote, ISO-Code: 187, internal code: 151  */
 ,{
   ________,
   X_X_____,
   _X_X____,
   __X_X___,
   _X_X____,
   X_X_____,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>152)
/* fraction one-fourth, ISO-Code: 188, internal code: 152  */
 ,{
   X___X___,
   X__X____,
   X_X_____,
   _X_X____,
   X_XX____,
   _X_X____,
   _XXXX___,
   ___X____}

#endif
#if (GUI_NOFCHARS>153)
/* fraction one-half, ISO-Code: 189, internal code: 153  */
 ,{
   X___X___,
   X__X____,
   X_X_____,
   _X______,
   X_XXX___,
   ____X___,
   ___X____,
   __XXX___}

#endif
#if (GUI_NOFCHARS>154)
/* fraction three-fourth, ISO-Code: 190, internal code: 154  */
 ,{
   XX______,
   _X______,
   XX______,
   _X__X___,
   XX_XX___,
   __X_X___,
   __XXX___,
   ____X___}

#endif
#if (GUI_NOFCHARS>155)
/* multiply sign, ISO-Code: 215, internal code: 155  */
 ,{
   ________,
   X___X___,
   _X_X____,
   __X_____,
   _X_X____,
   X___X___,
   ________,
   ________}

#endif
#if (GUI_NOFCHARS>156)
/* division sign, ISO-Code: 247, internal code: 156  */
 ,{
   ________,
   __X_____,
   ________,
   XXXXX___,
   ________,
   __X_____,
   ________,
   ________}

#endif

#if (GUI_NOFCHARS>157)
/* left arrow, ISO-Code: ---, internal code: 157  */
 ,{
   ___X____,
   __XX____,
   _XXX____,
   XXXXXX__,
   _XXX____,
   __XX____,
   ___X____,
   ________}
#endif

#if (GUI_NOFCHARS>158)
/* right arrow, ISO-Code: ---, internal code: 158  */
 ,{
   __X_____,
   __XX____,
   __XXX___,
   XXXXXX__,
   __XXX___,
   __XX____,
   __X_____,
   ________}
#endif

#if (GUI_NOFCHARS>159)
/* up arrow, ISO-Code: ---, internal code: 159 */
 ,{
   ________,
   __X_____,
   _XXX____,
   XXXXX___,
   __X_____,
   __X_____,
   ________,
   ________}
#endif

#if (GUI_NOFCHARS>160)
/* down arrow, ISO-Code: ---, internal code: 160  */
 ,{
   ________,
   __X_____,
   __X_____,
   XXXXX___,
   _XXX____,
   __X_____,
   ________,
   ________}
#endif

#if (GUI_NOFCHARS>161)
/* ENTER character, ISO-Code: ---, internal code: 161  */
 ,{
   ________,
   ____X___,
   __X_X___,
   _XX_X___,
   XXXXX___,
   _XX_____,
   __X_____,
   ________}
#endif

#if (GUI_NOFCHARS>162)
/* ENTER character, ISO-Code: ---, internal code: 162  */
 ,{
   ________,
   _____X__,
   _____X__,
   ____X___,
   ____X___,
   X__X____,
   _X_X____,
   __X_____}
#endif


};
