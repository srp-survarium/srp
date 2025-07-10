void __thiscall PPM_CONTEXT::rescale(PPM_CONTEXT *this, ppmd_compressor_impl *impl, ppmd_compressor_impl *impla)
{
  ppmd_compressor_impl *v4; // edi
  PPM_CONTEXT::STATE *j; // eax
  __int16 v6; // cx
  PPM_CONTEXT *Successor; // edx
  PPM_CONTEXT::STATE *v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // ecx
  int Freq; // ecx
  unsigned int v12; // ecx
  __int16 v13; // si
  PPM_CONTEXT *v14; // edi
  PPM_CONTEXT::STATE *v15; // ecx
  unsigned int v16; // ecx
  unsigned __int8 *p_Freq; // eax
  unsigned int v18; // esi
  unsigned int v19; // eax
  unsigned __int8 v20; // cl
  __int16 *v21; // ecx
  int v22; // eax
  int v23; // edx
  ppmd_allocator *v24; // eax
  char v25; // cl
  int v26; // edi
  ppmd_allocator *v27; // esi
  PPM_CONTEXT::STATE *v28; // edx
  unsigned int Adder; // [esp+10h] [ebp-10h]
  unsigned int EscFreq; // [esp+14h] [ebp-Ch]
  unsigned int EscFreqa; // [esp+14h] [ebp-Ch]
  __int16 tmp; // [esp+18h] [ebp-8h]
  unsigned __int16 tmpa; // [esp+18h] [ebp-8h]
  int tmp_2; // [esp+1Ah] [ebp-6h]
  unsigned int i; // [esp+24h] [ebp+4h]

  v4 = impla;
  i = LOBYTE(impl->__vftable);
  for ( j = impla->FoundState; j != *(PPM_CONTEXT::STATE **)&impl->StartModelRare_first_time; --j )
  {
    v6 = *(_WORD *)&j->Symbol;
    Successor = j->Successor;
    *(_WORD *)&j->Symbol = *(_WORD *)&j[-1].Symbol;
    j->Successor = j[-1].Successor;
    *(_WORD *)&j[-1].Symbol = v6;
    j[-1].Successor = Successor;
  }
  j->Freq += 4;
  HIWORD(impl->__vftable) += 4;
  v8 = (PPM_CONTEXT::STATE *)((char *)&impl->__vftable + 2);
  v9 = HIWORD(impl->__vftable) - j->Freq;
  if ( impla->OrderFall || (Adder = 0, impla->MRMethod > model_restoration_freeze) )
    Adder = 1;
  v10 = (Adder + j->Freq) >> 1;
  j->Freq = v10;
  *(_WORD *)&v8->Symbol = (unsigned __int8)v10;
  do
  {
    Freq = j[1].Freq;
    ++j;
    v9 -= Freq;
    v12 = (Adder + Freq) >> 1;
    j->Freq = v12;
    *(_WORD *)&v8->Symbol += (unsigned __int8)v12;
    EscFreq = v9;
    if ( j->Freq > j[-1].Freq )
    {
      v13 = *(_WORD *)&j->Symbol;
      v14 = j->Successor;
      v15 = j;
      tmp = *(_WORD *)&j->Symbol;
      do
      {
        *(_WORD *)&v15->Symbol = *(_WORD *)&v15[-1].Symbol;
        v15->Successor = v15[-1].Successor;
        --v15;
      }
      while ( HIBYTE(tmp) > v15[-1].Freq );
      *(_WORD *)&v15->Symbol = v13;
      v9 = EscFreq;
      v15->Successor = v14;
      v4 = impla;
    }
    v16 = --i;
  }
  while ( i );
  p_Freq = &j->Freq;
  if ( *p_Freq )
    goto LABEL_21;
  do
  {
    p_Freq -= 6;
    ++v16;
  }
  while ( !*p_Freq );
  v18 = v16 + v9;
  v19 = (LOBYTE(impl->__vftable) + 2) >> 1;
  v20 = LOBYTE(impl->__vftable) - v16;
  EscFreqa = v18;
  LOBYTE(impl->__vftable) = v20;
  if ( v20 )
  {
    v24 = ppmd_allocator::ShrinkUnits(
            &v4->m_allocator,
            *(ppmd_allocator **)&impl->StartModelRare_first_time,
            v19,
            (v20 + 2) >> 1,
            impl);
    BYTE1(impl->__vftable) &= ~8u;
    v25 = BYTE1(impl->__vftable);
    v26 = LOBYTE(impl->__vftable);
    v27 = v24;
    *(_DWORD *)&impl->StartModelRare_first_time = v24;
    BYTE1(impl->__vftable) = v25 | (8 * (LOBYTE(v24->m_allocator) >= 0x40u));
    do
    {
      v27 = (ppmd_allocator *)((char *)v27 + 6);
      BYTE1(impl->__vftable) |= 8 * (LOBYTE(v27->m_allocator) >= 0x40u);
      --v26;
    }
    while ( v26 );
    v9 = EscFreqa;
    v4 = impla;
LABEL_21:
    v28 = *(PPM_CONTEXT::STATE **)&impl->StartModelRare_first_time;
    *(_WORD *)&v8->Symbol += v9 - (v9 >> 1);
    BYTE1(impl->__vftable) |= 4u;
    v4->FoundState = v28;
    return;
  }
  v21 = *(__int16 **)&impl->StartModelRare_first_time;
  tmpa = *v21;
  tmp_2 = *(_DWORD *)(v21 + 1);
  HIBYTE(tmpa) = (v18 + 2 * (unsigned __int8)HIBYTE(*v21) - 1) / v18;
  if ( HIBYTE(tmpa) > 0x29u )
    HIBYTE(tmpa) = 41;
  v22 = v4->m_allocator.Indx2Units[v19 + 37];
  v23 = v4->m_allocator.Indx2Units[v22];
  *((_DWORD *)v21 + 1) = v4->m_allocator.BList[v22].next;
  v4->m_allocator.BList[v22].next = (BLK_NODE *)v21;
  *((_DWORD *)v21 + 2) = v23;
  *(_DWORD *)v21 = -1;
  ++v4->m_allocator.BList[v22].Stamp;
  *(_WORD *)&v8->Symbol = tmpa;
  *(_DWORD *)&impl->StartModelRare_first_time = tmp_2;
  BYTE1(impl->__vftable) = (BYTE1(impl->__vftable) & 0x10) + 8 * ((unsigned __int8)tmpa >= 0x40u);
  v4->FoundState = v8;
}
