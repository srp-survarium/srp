void __thiscall Scaleform::GFx::FontCompactor::EndFont(Scaleform::GFx::FontCompactor *this)
{
  Scaleform::GFx::FontCompactor *v1; // esi
  unsigned int j; // edi
  int v3; // ebx
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Encoder; // ebp
  unsigned int v5; // eax
  Scaleform::GFx::FontCompactor::KerningPairType **Pages; // edx
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *Data; // esi
  Scaleform::GFx::FontCompactor::KerningPairType *v8; // ecx
  int v9; // eax
  unsigned int Char1; // ebx
  unsigned int v11; // edi
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // ebx
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *v15; // esi
  unsigned int Char2; // ebx
  unsigned int v17; // edi
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *v18; // esi
  unsigned int v19; // edi
  unsigned int v20; // ebx
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *v21; // esi
  int Adjustment; // ebx
  unsigned int v23; // edi
  Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *v24; // esi
  unsigned int v25; // edi
  int v26; // ebx
  unsigned int i; // [esp+10h] [ebp-Ch]
  const Scaleform::GFx::FontCompactor::KerningPairType *kerningPair; // [esp+14h] [ebp-8h]

  v1 = this;
  for ( j = 0; j < v1->GlyphInfoTable.Size; ++j )
  {
    v3 = (int)&v1->GlyphInfoTable.Pages[j >> 6][j & 0x3F];
    Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
      &v1->Encoder,
      *(_WORD *)v3);
    Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt16fixlen(
      &v1->Encoder,
      *(_WORD *)(v3 + 2));
    Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
      &v1->Encoder,
      *(_DWORD *)(v3 + 4));
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::ArrayPagedPOD<Scaleform::GFx::FontCompactor::KerningPairType,6,64,261>,bool (__cdecl *)(Scaleform::GFx::FontCompactor::KerningPairType const &,Scaleform::GFx::FontCompactor::KerningPairType const &)>(
    &v1->KerningTable,
    0,
    v1->KerningTable.Size,
    (bool (__cdecl *)(const Scaleform::GFx::FontCompactor::KerningPairType *, const Scaleform::GFx::FontCompactor::KerningPairType *))Scaleform::GFx::FontCompactor::cmpKerningPairs);
  p_Encoder = &v1->Encoder;
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
    &v1->Encoder,
    v1->KerningTable.Size);
  v5 = 0;
  i = 0;
  if ( v1->KerningTable.Size )
  {
    while ( 1 )
    {
      Pages = v1->KerningTable.Pages;
      Data = p_Encoder->Data;
      v8 = Pages[v5 >> 6];
      v9 = v5 & 0x3F;
      Char1 = v8[v9].Char1;
      v11 = p_Encoder->Data->Size >> 12;
      kerningPair = &v8[v9];
      if ( v11 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          Data,
          v11);
      Data->Pages[v11][Data->Size++ & 0xFFF] = Char1;
      v12 = p_Encoder->Data;
      v13 = p_Encoder->Data->Size >> 12;
      v14 = Char1 >> 8;
      if ( v13 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v12,
          p_Encoder->Data->Size >> 12);
      v12->Pages[v13][v12->Size++ & 0xFFF] = v14;
      v15 = p_Encoder->Data;
      Char2 = kerningPair->Char2;
      v17 = p_Encoder->Data->Size >> 12;
      if ( v17 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v15,
          p_Encoder->Data->Size >> 12);
      v15->Pages[v17][v15->Size++ & 0xFFF] = Char2;
      v18 = p_Encoder->Data;
      v19 = p_Encoder->Data->Size >> 12;
      v20 = Char2 >> 8;
      if ( v19 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v18,
          p_Encoder->Data->Size >> 12);
      v18->Pages[v19][v18->Size++ & 0xFFF] = v20;
      v21 = p_Encoder->Data;
      Adjustment = kerningPair->Adjustment;
      v23 = p_Encoder->Data->Size >> 12;
      if ( v23 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v21,
          p_Encoder->Data->Size >> 12);
      v21->Pages[v23][v21->Size++ & 0xFFF] = Adjustment;
      v24 = p_Encoder->Data;
      v25 = p_Encoder->Data->Size >> 12;
      v26 = Adjustment >> 8;
      if ( v25 >= p_Encoder->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v24,
          p_Encoder->Data->Size >> 12);
      v24->Pages[v25][v24->Size++ & 0xFFF] = v26;
      if ( ++i >= this->KerningTable.Size )
        break;
      v5 = i;
      v1 = this;
    }
  }
}
