int __fastcall inverse(int xin)
{
  int v2; // ebx
  int v3; // esi
  int i; // ebp
  int v5; // edi
  int v6; // ebp
  int v7; // edx

  if ( !xin )
    return 0;
  v2 = 65537;
  v3 = 1;
  for ( i = 0; ; i = v7 )
  {
    v5 = v2 % xin;
    if ( !(v2 % xin) )
      break;
    v6 = i - v3 * ((v2 - v2 % xin) / xin);
    v7 = v3;
    v2 = xin;
    v3 = v6;
    xin = v5;
  }
  return v3 + (v3 < 0 ? 0x10001 : 0);
}
