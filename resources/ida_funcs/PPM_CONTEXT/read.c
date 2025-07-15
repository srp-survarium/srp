void __userpurge PPM_CONTEXT::read(
        PPM_CONTEXT *this@<ecx>,
        unsigned int a2@<ebp>,
        ppmd_compressor_impl *impl,
        int fp,
        unsigned int PrevSym)
{
  unsigned __int8 *v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 *v10; // eax
  char v11; // cl
  char *v12; // ecx
  char v13; // al
  char SummFreq_high; // al
  PPM_CONTEXT::STATE *v15; // eax
  PPM_CONTEXT::STATE *v16; // eax
  PPM_CONTEXT::STATE *v17; // ecx
  unsigned __int8 *v18; // ebp
  char v19; // cl
  unsigned __int8 *v20; // edx
  char v21; // cl
  PPM_CONTEXT::STATE *Stats; // ebp
  int NumStats; // ecx
  unsigned __int16 v24; // ax
  int v25; // edx
  bool v26; // al
  char Freq; // al
  unsigned __int8 *HiUnit; // eax
  PPM_CONTEXT *next; // eax
  BLK_NODE *v30; // edx
  unsigned __int8 v31; // al
  int v32; // ecx
  PPM_CONTEXT::STATE *v33; // eax
  unsigned __int8 v34; // cl
  unsigned int Symbol; // [esp-8h] [ebp-14h]
  unsigned int v36; // [esp-4h] [ebp-10h]
  int EscFreq; // [esp+14h] [ebp+8h]

  while ( 1 )
  {
    this->Suffix = 0;
    v8 = *(unsigned __int8 **)(fp + 8);
    if ( (unsigned int)v8 >= *(_DWORD *)fp + *(_DWORD *)(fp + 4) )
    {
      v9 = -1;
    }
    else
    {
      v9 = *v8;
      *(_DWORD *)(fp + 8) = v8 + 1;
    }
    this->NumStats = v9;
    this->Flags = 16 * (PrevSym >= 0x40);
    if ( v9 )
      break;
    v10 = *(unsigned __int8 **)(fp + 8);
    if ( (unsigned int)v10 >= *(_DWORD *)fp + *(_DWORD *)(fp + 4) )
    {
      v11 = -1;
    }
    else
    {
      v11 = *v10;
      *(_DWORD *)(fp + 8) = v10 + 1;
    }
    HIBYTE(this->SummFreq) = v11;
    v12 = *(char **)(fp + 8);
    if ( (unsigned int)v12 >= *(_DWORD *)fp + *(_DWORD *)(fp + 4) )
    {
      v13 = -1;
    }
    else
    {
      v13 = *v12++;
      *(_DWORD *)(fp + 8) = v12;
    }
    LOBYTE(v12) = 8 * ((unsigned __int8)v13 >= 0x40u);
    LOBYTE(this->SummFreq) = v13;
    this->Flags |= (unsigned __int8)v12;
    SummFreq_high = HIBYTE(this->SummFreq);
    if ( SummFreq_high >= 0 )
    {
      this->Stats = 0;
      return;
    }
    HIBYTE(this->SummFreq) = SummFreq_high & 0x7F;
    v15 = (PPM_CONTEXT::STATE *)ppmd_allocator::AllocContext((ppmd_allocator *)v12, &impl->m_allocator);
    PrevSym = LOBYTE(this->SummFreq);
    this->Stats = v15;
    this = (PPM_CONTEXT *)v15;
  }
  v36 = a2;
  v16 = (PPM_CONTEXT::STATE *)ppmd_allocator::AllocUnits(&impl->m_allocator, (v9 + 2) >> 1);
  v17 = &v16[this->NumStats];
  this->Stats = v16;
  if ( v16 <= v17 )
  {
    do
    {
      v18 = *(unsigned __int8 **)(fp + 8);
      if ( (unsigned int)v18 >= *(_DWORD *)fp + *(_DWORD *)(fp + 4) )
      {
        v19 = -1;
      }
      else
      {
        v19 = *v18;
        *(_DWORD *)(fp + 8) = v18 + 1;
      }
      v16->Freq = v19;
      v20 = *(unsigned __int8 **)(fp + 8);
      if ( (unsigned int)v20 >= *(_DWORD *)fp + *(_DWORD *)(fp + 4) )
      {
        v21 = -1;
      }
      else
      {
        v21 = *v20;
        *(_DWORD *)(fp + 8) = v20 + 1;
      }
      v16->Symbol = v21;
      this->Flags |= 8 * ((unsigned __int8)v21 >= 0x40u);
      ++v16;
    }
    while ( v16 <= &this->Stats[this->NumStats] );
  }
  Stats = this->Stats;
  NumStats = this->NumStats;
  v24 = Stats->Freq & 0x7F;
  v25 = Stats->Freq & 0x7F;
  this->SummFreq = v24;
  EscFreq = v24;
  v26 = v24 < NumStats && v24 < 0x7Fu;
  this->Flags |= 4 * v26;
  if ( Stats <= &Stats[NumStats] )
  {
    do
    {
      Freq = Stats->Freq;
      if ( Freq >= 0 )
      {
        Stats->Successor = 0;
      }
      else
      {
        Stats->Freq = Freq & 0x7F;
        HiUnit = impl->m_allocator.HiUnit;
        if ( HiUnit == impl->m_allocator.LoUnit )
        {
          if ( impl->m_allocator.BList[0].next )
          {
            next = (PPM_CONTEXT *)impl->m_allocator.BList[0].next;
            v30 = (BLK_NODE *)next->Stats;
            --impl->m_allocator.BList[0].Stamp;
            impl->m_allocator.BList[0].next = v30;
          }
          else
          {
            next = (PPM_CONTEXT *)ppmd_allocator::AllocUnitsRare(&impl->m_allocator, 0, v36);
          }
        }
        else
        {
          next = (PPM_CONTEXT *)(HiUnit - 12);
          impl->m_allocator.HiUnit = &next->NumStats;
        }
        Symbol = Stats->Symbol;
        Stats->Successor = next;
        PPM_CONTEXT::read(next, impl, (compression::ppmd::stream *)fp, Symbol);
        v25 = EscFreq;
      }
      if ( Stats == this->Stats )
        v31 = 64;
      else
        v31 = Stats[-1].Freq - Stats->Freq;
      Stats->Freq = v31;
      this->SummFreq += v31;
      ++Stats;
    }
    while ( Stats <= &this->Stats[this->NumStats] );
  }
  if ( v25 > 32 )
  {
    v32 = this->NumStats;
    v33 = this->Stats;
    this->SummFreq = v25 >> 1;
    if ( v33 <= &v33[v32] )
    {
      do
      {
        v34 = v33->Freq - ((3 * v33->Freq) >> 2);
        v33->Freq = v34;
        this->SummFreq += v34;
        ++v33;
      }
      while ( v33 <= &this->Stats[this->NumStats] );
    }
  }
}
