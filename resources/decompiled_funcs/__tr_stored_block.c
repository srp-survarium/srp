void __cdecl _tr_stored_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int dummy; // ecx
  int v5; // edx
  int v6; // ecx
  char v7; // bl
  int v8; // edx

  dummy = s[1455].dummy;
  if ( dummy <= 13 )
  {
    s[1455].dummy = dummy + 3;
    LOWORD(s[1454].dummy) |= eof << dummy;
  }
  else
  {
    v5 = eof << dummy;
    v6 = s[2].dummy;
    LOWORD(s[1454].dummy) |= v5;
    *(_BYTE *)(v6 + s[5].dummy) = s[1454].dummy;
    v7 = BYTE1(s[1454].dummy);
    *(_BYTE *)(++s[5].dummy + s[2].dummy) = v7;
    v8 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v8 - 13;
    LOWORD(s[1454].dummy) = (unsigned __int16)eof >> (16 - v8);
  }
  copy_block(s, buf, stored_len, 1);
}
