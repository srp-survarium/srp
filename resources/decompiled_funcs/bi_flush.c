void __usercall bi_flush(internal_state *s@<eax>)
{
  int dummy; // ecx
  __int16 v2; // dx

  dummy = s[1455].dummy;
  if ( dummy == 16 )
  {
    *(_BYTE *)(s[2].dummy + s[5].dummy++) = s[1454].dummy;
    *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    ++s[5].dummy;
    LOWORD(s[1454].dummy) = 0;
    s[1455].dummy = 0;
  }
  else if ( dummy >= 8 )
  {
    *(_BYTE *)(s[2].dummy + s[5].dummy) = s[1454].dummy;
    v2 = BYTE1(s[1454].dummy);
    ++s[5].dummy;
    s[1455].dummy -= 8;
    LOWORD(s[1454].dummy) = v2;
  }
}
