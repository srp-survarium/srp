void __fastcall nist_cp_bn_0(int max, int top, unsigned int *buf, unsigned int *a)
{
  unsigned int *v4; // edi
  int i; // ecx
  int v7; // esi

  v4 = buf;
  for ( i = top; i; --i )
  {
    *v4 = *(unsigned int *)((char *)v4 + (char *)a - (char *)buf);
    ++v4;
  }
  v7 = max - top;
  if ( v7 )
    memset(v4, 0, 4 * v7);
}
