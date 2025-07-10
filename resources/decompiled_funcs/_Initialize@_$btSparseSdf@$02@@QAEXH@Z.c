void __usercall btSparseSdf<3>::Initialize(btSparseSdf<3> *this@<ecx>, int a2@<esi>)
{
  int v2; // ebx
  btSparseSdf<3> *v3; // eax
  int v4; // edx
  btSparseSdf<3> *v5; // edi
  int v6; // eax
  void *v7; // eax
  btAlignedAllocator<btSparseSdf<3>::Cell *,16> *v8; // eax

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 <= 2383 )
  {
    if ( v2 < 2383 && *(int *)(a2 + 8) < 2383 )
    {
      ++gNumAlignedAllocs;
      v3 = (btSparseSdf<3> *)sAlignedAllocFunc(0x253Cu, 16);
      v4 = *(_DWORD *)(a2 + 4);
      v5 = v3;
      v6 = 0;
      if ( v4 > 0 )
      {
        this = v5;
        do
        {
          if ( this )
            *(_DWORD *)&this->cells.m_allocator = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v6);
          ++v6;
          this = (btSparseSdf<3> *)((char *)this + 4);
        }
        while ( v6 < v4 );
      }
      v7 = *(void **)(a2 + 12);
      if ( v7 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v7);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_DWORD *)(a2 + 12) = v5;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 8) = 2383;
    }
    if ( v2 < 2383 )
    {
      this = (btSparseSdf<3> *)(4 * v2);
      do
      {
        v8 = &this->cells.m_allocator + *(_DWORD *)(a2 + 12);
        if ( v8 )
          *(_DWORD *)v8 = 0;
        this = (btSparseSdf<3> *)((char *)this + 4);
      }
      while ( (int)this < 9532 );
    }
  }
  *(_DWORD *)(a2 + 4) = 2383;
  btSparseSdf<3>::Reset(this);
}
