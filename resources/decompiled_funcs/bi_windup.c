void __usercall bi_windup(internal_state *s@<eax>)
{
  int dummy; // ecx
  int v2; // ecx
  int v3; // edx
  char v4; // bl

  dummy = s[1455].dummy;
  if ( dummy > 8 )
  {
    *(_BYTE *)(s[2].dummy + s[5].dummy++) = s[1454].dummy;
    v2 = s[5].dummy;
    v3 = s[2].dummy;
    v4 = BYTE1(s[1454].dummy);
LABEL_5:
    *(_BYTE *)(v2 + v3) = v4;
    ++s[5].dummy;
    goto LABEL_6;
  }
  if ( dummy > 0 )
  {
    v2 = s[2].dummy;
    v3 = s[5].dummy;
    v4 = s[1454].dummy;
    goto LABEL_5;
  }
LABEL_6:
  LOWORD(s[1454].dummy) = 0;
  s[1455].dummy = 0;
}
