void __usercall ppmd_allocator::ExpandTextArea(ppmd_allocator *this@<ecx>, int a2@<eax>)
{
  unsigned __int8 *v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // edx
  unsigned __int8 *v6; // ecx
  int v7; // esi
  _DWORD *v8; // eax
  unsigned __int8 dst[152]; // [esp+Ch] [ebp-20h] BYREF

  memset((int)dst, 0, sizeof(dst));
  while ( 1 )
  {
    v4 = *(_DWORD **)(a2 + 492);
    if ( *v4 != -1 )
      break;
    *(_DWORD *)(a2 + 492) = &v4[3 * v4[2]];
    v3 = &dst[4 * *(unsigned __int8 *)(v4[2] + a2 + 345)];
    ++*(_DWORD *)v3;
    *v4 = 0;
  }
  v5 = (_DWORD *)(a2 + 4);
  v6 = dst;
  v7 = 38;
  do
  {
    v8 = v5;
    while ( *(_DWORD *)v6 )
    {
      do
      {
        if ( *(_DWORD *)v8[1] )
          break;
        v8[1] = *(_DWORD *)(v8[1] + 4);
        --*v5;
      }
      while ( (*(_DWORD *)v6)-- != 1 );
      v8 = (_DWORD *)v8[1];
    }
    v5 += 2;
    v6 += 4;
    --v7;
  }
  while ( v7 );
}
