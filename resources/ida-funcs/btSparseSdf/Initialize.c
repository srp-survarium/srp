void __usercall btSparseSdf<3>::Initialize(btSparseSdf<3> *this@<ecx>, int a2@<eax>)
{
  int v3; // ebx
  _DWORD *v4; // edx
  int v5; // eax
  btAlignedAllocator<btSparseSdf<3>::Cell *,16> *v6; // eax
  btSparseSdf<3> *v7; // [esp-4h] [ebp-18h]
  _DWORD *i; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 4);
  v9 = v3;
  if ( v3 <= 2383 )
  {
    if ( v3 < 2383 && *(int *)(a2 + 8) < 2383 )
    {
      v4 = btAlignedAllocInternal(0x253Cu);
      v5 = *(_DWORD *)(a2 + 4);
      this = 0;
      for ( i = v4; (int)this < v5; ++v4 )
      {
        if ( v4 )
        {
          *v4 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * (_DWORD)this);
          v3 = v9;
        }
        this = (btSparseSdf<3> *)((char *)this + 1);
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          btAlignedFreeInternal(*(void **)(a2 + 12));
          this = v7;
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = i;
      *(_DWORD *)(a2 + 8) = 2383;
    }
    if ( v3 < 2383 )
    {
      this = (btSparseSdf<3> *)(4 * v3);
      do
      {
        v6 = &this->cells.m_allocator + *(_DWORD *)(a2 + 12);
        if ( v6 )
          *(_DWORD *)v6 = 0;
        this = (btSparseSdf<3> *)((char *)this + 4);
      }
      while ( (int)this < 9532 );
    }
  }
  *(_DWORD *)(a2 + 4) = 2383;
  btSparseSdf<3>::Reset(this, a2);
}
