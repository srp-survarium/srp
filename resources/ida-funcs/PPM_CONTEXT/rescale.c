void __userpurge PPM_CONTEXT::rescale(PPM_CONTEXT *this@<ecx>, unsigned __int8 *a2@<esi>, ppmd_compressor_impl *impl)
{
  PPM_CONTEXT::STATE *i; // eax
  __int16 v4; // di
  PPM_CONTEXT::STATE *v5; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  int Freq; // ecx
  unsigned int v9; // ecx
  PPM_CONTEXT::STATE *v10; // ecx
  unsigned __int8 *p_Freq; // eax
  unsigned int v12; // ecx
  bool v13; // zf
  unsigned __int8 v14; // al
  int v15; // eax
  char *v16; // eax
  int v17; // edx
  unsigned __int8 v18; // cl
  PPM_CONTEXT::STATE *v19; // eax
  unsigned int v20; // [esp+0h] [ebp-1Ch]
  __int16 v21; // [esp+8h] [ebp-14h]
  __int16 v22; // [esp+8h] [ebp-14h]
  PPM_CONTEXT *v23; // [esp+Ah] [ebp-12h]
  int v24; // [esp+Ah] [ebp-12h]
  PPM_CONTEXT::STATE *v25; // [esp+10h] [ebp-Ch]
  PPM_CONTEXT *Successor; // [esp+14h] [ebp-8h]
  BOOL v27; // [esp+14h] [ebp-8h]
  int v28; // [esp+18h] [ebp-4h]
  int v29; // [esp+18h] [ebp-4h]

  v28 = *a2;
  for ( i = impl->FoundState; i != *((PPM_CONTEXT::STATE **)a2 + 1); --i )
  {
    v4 = *(_WORD *)&i->Symbol;
    Successor = i->Successor;
    *(_WORD *)&i->Symbol = *(_WORD *)&i[-1].Symbol;
    i->Successor = i[-1].Successor;
    *(_WORD *)&i[-1].Symbol = v4;
    i[-1].Successor = Successor;
  }
  i->Freq += 4;
  v5 = (PPM_CONTEXT::STATE *)(a2 + 2);
  *((_WORD *)a2 + 1) += 4;
  v6 = *((unsigned __int16 *)a2 + 1) - i->Freq;
  v27 = impl->OrderFall || impl->MRMethod > model_restoration_freeze;
  v7 = (v27 + (unsigned int)i->Freq) >> 1;
  i->Freq = v7;
  *(_WORD *)&v5->Symbol = (unsigned __int8)v7;
  do
  {
    Freq = i[1].Freq;
    ++i;
    v6 -= Freq;
    v9 = (unsigned int)(v27 + Freq) >> 1;
    i->Freq = v9;
    *(_WORD *)&v5->Symbol += (unsigned __int8)v9;
    if ( i->Freq > i[-1].Freq )
    {
      v21 = *(_WORD *)&i->Symbol;
      v10 = i;
      v23 = i->Successor;
      do
      {
        v25 = v10 - 1;
        *(_WORD *)&v10->Symbol = *(_WORD *)&v10[-1].Symbol;
        v10->Successor = v10[-1].Successor;
        v10 = v25;
      }
      while ( HIBYTE(v21) > v25[-1].Freq );
      *(_WORD *)&v25->Symbol = v21;
      v25->Successor = v23;
    }
    --v28;
  }
  while ( v28 );
  p_Freq = &i->Freq;
  if ( *p_Freq )
    goto LABEL_22;
  do
  {
    ++v28;
    p_Freq -= 6;
  }
  while ( !*p_Freq );
  v6 += v28;
  v12 = (*a2 + 2) >> 1;
  v14 = *a2 - v28;
  v13 = *a2 == (unsigned __int8)v28;
  *a2 = v14;
  if ( !v13 )
  {
    v16 = ppmd_allocator::ShrinkUnits(&impl->m_allocator, v12, *((char **)a2 + 1), (v14 + 2) >> 1);
    a2[1] &= ~8u;
    v17 = *a2;
    v18 = a2[1];
    *((_DWORD *)a2 + 1) = v16;
    v29 = v17;
    a2[1] = v18 | (8 * ((unsigned __int8)*v16 >= 0x40u));
    do
    {
      v16 += 6;
      a2[1] |= 8 * ((unsigned __int8)*v16 >= 0x40u);
      --v29;
    }
    while ( v29 );
LABEL_22:
    *(_WORD *)&v5->Symbol += v6 - (v6 >> 1);
    v19 = (PPM_CONTEXT::STATE *)*((_DWORD *)a2 + 1);
    a2[1] |= 4u;
    impl->FoundState = v19;
    return;
  }
  v15 = *((_DWORD *)a2 + 1);
  v24 = *(_DWORD *)(v15 + 2);
  LOBYTE(v22) = *(_WORD *)v15;
  HIBYTE(v22) = (v6 + 2 * (unsigned __int8)HIBYTE(*(_WORD *)v15) - 1) / v6;
  if ( HIBYTE(v22) > 0x29u )
    HIBYTE(v22) = 41;
  ppmd_allocator::FreeUnits(*((ppmd_allocator **)a2 + 1), (int)&impl->m_allocator, (unsigned __int8 *)v12, v20);
  *(_WORD *)&v5->Symbol = v22;
  *((_DWORD *)a2 + 1) = v24;
  a2[1] = (a2[1] & 0x10) + 8 * ((unsigned __int8)v22 >= 0x40u);
  impl->FoundState = v5;
}
