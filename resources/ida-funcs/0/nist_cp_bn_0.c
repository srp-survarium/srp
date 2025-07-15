void __fastcall nist_cp_bn_0(int max, int top, char *buf, char *a)
{
  char *v4; // edi
  int i; // ecx
  int v7; // esi

  v4 = buf;
  for ( i = top; i; --i )
  {
    *(_DWORD *)v4 = *(_DWORD *)&v4[a - buf];
    v4 += 4;
  }
  v7 = max - top;
  if ( v7 )
    memset(v4, 0, 4 * v7);
}
