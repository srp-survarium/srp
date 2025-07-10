PPM_CONTEXT *__thiscall PPM_CONTEXT::cutOff(PPM_CONTEXT *this, ppmd_compressor_impl *impl, int Order)
{
  ppmd_compressor_impl *v4; // edi
  ppmd_allocator *p_m_allocator; // ebp
  PPM_CONTEXT::STATE *v7; // eax
  int NumStats; // ebx
  PPM_CONTEXT::STATE *v9; // edi
  __int16 v10; // dx
  PPM_CONTEXT::STATE *v11; // eax
  PPM_CONTEXT::STATE *Stats; // eax
  int v13; // ecx
  PPM_CONTEXT *v14; // edx
  int v15; // ecx
  PPM_CONTEXT *v16; // edx
  int v17; // [esp+10h] [ebp-8h]
  unsigned int tmp; // [esp+14h] [ebp-4h]

  if ( !this->NumStats )
  {
    v4 = impl;
    if ( this->Stats < (PPM_CONTEXT::STATE *)impl->m_allocator.UnitsStart )
      goto REMOVE;
    this->Stats = Order >= impl->MaxOrder
                ? 0
                : (PPM_CONTEXT::STATE *)PPM_CONTEXT::cutOff((PPM_CONTEXT *)this->Stats, impl, Order + 1);
    if ( !this->Stats && Order > 9 )
      goto REMOVE;
    return this;
  }
  p_m_allocator = &impl->m_allocator;
  tmp = (this->NumStats + 2) >> 1;
  v7 = (PPM_CONTEXT::STATE *)ppmd_allocator::MoveUnitsUp((BLK_NODE *)this->Stats, tmp, this, &impl->m_allocator);
  NumStats = this->NumStats;
  v9 = &v7[NumStats];
  this->Stats = v7;
  if ( v9 >= v7 )
  {
    v17 = NumStats;
    do
    {
      if ( v9->Successor >= (PPM_CONTEXT *)impl->m_allocator.UnitsStart )
      {
        if ( Order >= impl->MaxOrder )
          v9->Successor = 0;
        else
          v9->Successor = PPM_CONTEXT::cutOff(v9->Successor, impl, Order + 1);
      }
      else
      {
        v10 = *(_WORD *)&v9->Symbol;
        v9->Successor = 0;
        v11 = &this->Stats[v17];
        --NumStats;
        --v17;
        *(_WORD *)&v9->Symbol = *(_WORD *)&v11->Symbol;
        v9->Successor = v11->Successor;
        *(_WORD *)&v11->Symbol = v10;
        v11->Successor = 0;
      }
      --v9;
    }
    while ( v9 >= this->Stats );
  }
  if ( NumStats == this->NumStats || !Order )
    return this;
  Stats = this->Stats;
  this->NumStats = NumStats;
  if ( NumStats >= 0 )
  {
    if ( !NumStats )
    {
      this->Flags = (this->Flags & 0x10) + 8 * (Stats->Symbol >= 0x40u);
      this->SummFreq = *(_WORD *)&Stats->Symbol;
      this->Stats = (PPM_CONTEXT::STATE *)Stats->Successor;
      v15 = p_m_allocator->Indx2Units[tmp + 37];
      v16 = (PPM_CONTEXT *)p_m_allocator->Indx2Units[v15];
      *(PPM_CONTEXT **)((char *)&Stats->Successor + 2) = (PPM_CONTEXT *)p_m_allocator->BList[v15].next;
      p_m_allocator->BList[v15].next = (BLK_NODE *)Stats;
      *(_DWORD *)&Stats->Symbol = -1;
      Stats[1].Successor = v16;
      ++p_m_allocator->BList[v15].Stamp;
      HIBYTE(this->SummFreq) = (HIBYTE(this->SummFreq) + 11) >> 3;
      return this;
    }
    PPM_CONTEXT::refresh((PPM_CONTEXT *)impl, this, tmp, this->SummFreq > 16 * NumStats);
    return this;
  }
  v13 = p_m_allocator->Indx2Units[tmp + 37];
  v14 = (PPM_CONTEXT *)p_m_allocator->Indx2Units[v13];
  *(PPM_CONTEXT **)((char *)&Stats->Successor + 2) = (PPM_CONTEXT *)p_m_allocator->BList[v13].next;
  v4 = impl;
  p_m_allocator->BList[v13].next = (BLK_NODE *)Stats;
  *(_DWORD *)&Stats->Symbol = -1;
  Stats[1].Successor = v14;
  ++p_m_allocator->BList[v13].Stamp;
REMOVE:
  if ( this == (PPM_CONTEXT *)v4->m_allocator.UnitsStart )
  {
    *(_DWORD *)&this->NumStats = -1;
    v4->m_allocator.UnitsStart += 12;
  }
  else
  {
    this->Stats = (PPM_CONTEXT::STATE *)v4->m_allocator.BList[0].next;
    v4->m_allocator.BList[0].next = (BLK_NODE *)this;
    this->Suffix = (PPM_CONTEXT *)1;
    *(_DWORD *)&this->NumStats = -1;
    ++v4->m_allocator.BList[0].Stamp;
  }
  return 0;
}
