unsigned int __fastcall vostok::strings::detail::tuples::size(vostok::strings::detail::tuples *this, unsigned int *a2)
{
  unsigned int v2; // ebx
  unsigned int v3; // ebp
  int v4; // esi
  unsigned int v5; // eax
  int v6; // edi
  _DWORD *v7; // eax
  unsigned int j; // [esp+14h] [ebp-4h]

  v2 = a2[12];
  v3 = a2[1];
  v4 = 0;
  v5 = 1;
  v6 = 0;
  if ( v2 > 1 )
  {
    this = (vostok::strings::detail::tuples *)(v2 - 1);
    if ( (int)(v2 - 1) >= 2 )
    {
      this = (vostok::strings::detail::tuples *)(((v2 - 3) >> 1) + 1);
      v7 = a2 + 5;
      j = 2 * (_DWORD)this + 1;
      do
      {
        v4 += *(v7 - 2);
        v6 += *v7;
        v7 += 4;
        this = (vostok::strings::detail::tuples *)((char *)this - 1);
      }
      while ( this );
      v3 = a2[1];
      v5 = j;
    }
    if ( v5 < v2 )
      v3 += a2[2 * v5 + 1];
    v3 += v4 + v6;
  }
  if ( v3 > 0x80000 )
    vostok::strings::detail::tuples::error_process(this);
  return v3 + 1;
}
