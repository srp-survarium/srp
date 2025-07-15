PPM_CONTEXT *__thiscall PPM_CONTEXT::cutOff(PPM_CONTEXT *this, ppmd_compressor_impl *impl, int Order)
{
  ppmd_compressor_impl *v4; // edi
  unsigned int v5; // ebx
  PPM_CONTEXT::STATE *v6; // eax
  int NumStats; // edx
  PPM_CONTEXT::STATE *v8; // edi
  PPM_CONTEXT::STATE *v9; // eax
  PPM_CONTEXT *v10; // eax
  PPM_CONTEXT::STATE *Stats; // edi
  unsigned int v13; // [esp+0h] [ebp-18h]
  ppmd_allocator *p_m_allocator; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  __int16 v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  if ( !this->NumStats )
  {
    v4 = impl;
    if ( this->Stats >= (PPM_CONTEXT::STATE *)impl->m_allocator.UnitsStart )
    {
      this->Stats = Order >= impl->MaxOrder
                  ? 0
                  : (PPM_CONTEXT::STATE *)PPM_CONTEXT::cutOff((PPM_CONTEXT *)this->Stats, impl, Order + 1);
      if ( this->Stats || Order <= 9 )
        return this;
    }
REMOVE:
    ppmd_allocator::SpecialFreeUnit((ppmd_allocator *)this, &v4->m_allocator.m_allocator);
    return 0;
  }
  v5 = (this->NumStats + 2) >> 1;
  p_m_allocator = &impl->m_allocator;
  v6 = (PPM_CONTEXT::STATE *)ppmd_allocator::MoveUnitsUp(&impl->m_allocator, &this->Stats->Symbol, v5);
  NumStats = this->NumStats;
  v8 = &v6[NumStats];
  this->Stats = v6;
  v15 = NumStats;
  if ( v8 >= v6 )
  {
    v17 = NumStats;
    do
    {
      if ( v8->Successor >= (PPM_CONTEXT *)impl->m_allocator.UnitsStart )
      {
        if ( Order >= impl->MaxOrder )
        {
          v8->Successor = 0;
        }
        else
        {
          v10 = PPM_CONTEXT::cutOff(v8->Successor, impl, Order + 1);
          NumStats = v15;
          v8->Successor = v10;
        }
      }
      else
      {
        v8->Successor = 0;
        v9 = &this->Stats[v17];
        v16 = *(_WORD *)&v8->Symbol;
        *(_WORD *)&v8->Symbol = *(_WORD *)&v9->Symbol;
        v8->Successor = v9->Successor;
        v9->Successor = 0;
        --NumStats;
        --v17;
        *(_WORD *)&v9->Symbol = v16;
        v15 = NumStats;
      }
      --v8;
    }
    while ( v8 >= this->Stats );
  }
  if ( NumStats == this->NumStats || !Order )
    return this;
  Stats = this->Stats;
  this->NumStats = NumStats;
  if ( NumStats < 0 )
  {
    ppmd_allocator::FreeUnits((ppmd_allocator *)Stats, (int)p_m_allocator, (unsigned __int8 *)v5, v13);
    v4 = impl;
    goto REMOVE;
  }
  if ( NumStats )
  {
    PPM_CONTEXT::refresh(this, v5, impl, this->SummFreq > 16 * NumStats);
  }
  else
  {
    this->Flags = (this->Flags & 0x10) + 8 * (Stats->Symbol >= 0x40u);
    this->SummFreq = *(_WORD *)&Stats->Symbol;
    this->Stats = (PPM_CONTEXT::STATE *)Stats->Successor;
    ppmd_allocator::FreeUnits((ppmd_allocator *)Stats, (int)p_m_allocator, (unsigned __int8 *)v5, v13);
    HIBYTE(this->SummFreq) = (HIBYTE(this->SummFreq) + 11) >> 3;
  }
  return this;
}
