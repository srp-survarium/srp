void __thiscall PPM_CONTEXT::refresh(PPM_CONTEXT *this, PPM_CONTEXT *impl, unsigned int OldNU, int Scale)
{
  ppmd_allocator *v5; // eax
  int SummFreq; // esi
  char v7; // cl
  int v8; // ecx
  int v9; // esi
  unsigned int v10; // edx
  int Stamp_high; // edx
  unsigned int v12; // edx
  int i; // [esp+1Ch] [ebp+Ch]

  i = impl->NumStats;
  v5 = ppmd_allocator::ShrinkUnits((ppmd_allocator *)&this[1], (ppmd_allocator *)impl->Stats, OldNU, (i + 2) >> 1, impl);
  SummFreq = impl->SummFreq;
  v7 = impl->Flags & (4 * (Scale + 4));
  impl->Stats = (PPM_CONTEXT::STATE *)v5;
  impl->Flags = 8 * (LOBYTE(v5->m_allocator) >= 0x40u) + v7;
  v8 = BYTE1(v5->m_allocator);
  v9 = SummFreq - v8;
  v10 = (unsigned int)(v8 + Scale) >> Scale;
  BYTE1(v5->m_allocator) = v10;
  impl->SummFreq = (unsigned __int8)v10;
  do
  {
    Stamp_high = HIBYTE(v5->BList[0].Stamp);
    v5 = (ppmd_allocator *)((char *)v5 + 6);
    v9 -= Stamp_high;
    v12 = (unsigned int)(Scale + Stamp_high) >> Scale;
    BYTE1(v5->m_allocator) = v12;
    impl->SummFreq += (unsigned __int8)v12;
    impl->Flags |= 8 * (LOBYTE(v5->m_allocator) >= 0x40u);
    --i;
  }
  while ( i );
  impl->SummFreq += (unsigned int)(Scale + v9) >> Scale;
}
