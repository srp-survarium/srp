void __thiscall Scaleform::GFx::FontCompactor::EndGlyph(Scaleform::GFx::FontCompactor *this, bool mergeContours)
{
  Scaleform::GFx::FontCompactor *v2; // esi
  unsigned __int16 FontNumGlyphs; // ax
  unsigned int Size; // ebx
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Encoder; // edi
  unsigned int v6; // eax
  Scaleform::GFx::FontCompactor::ContourType *v7; // ecx
  unsigned int v8; // edx
  Scaleform::GFx::FontCompactor::VertexType **Pages; // edi
  unsigned int v10; // eax
  Scaleform::GFx::FontCompactor::VertexType *v11; // edx
  int v12; // eax
  int y; // ebp
  int v14; // edi
  unsigned int i; // ebx
  Scaleform::GFx::FontCompactor::VertexType **v16; // edx
  Scaleform::GFx::FontCompactor::VertexType *v17; // ecx
  __int16 x; // ax
  int v19; // ebx
  Scaleform::GFx::FontCompactor::VertexType *v20; // edx
  int v21; // eax
  int v22; // esi
  Scaleform::GFx::FontCompactor::VertexType *v23; // edx
  int v24; // ecx
  int v25; // ebx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  unsigned int v29; // ebp
  unsigned int HashValue; // eax
  Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType> >::TableType *pTable; // ebx
  signed int v32; // eax
  int v33; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // eax
  unsigned int v35; // ebp
  Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> >::TableType *v36; // eax
  Scaleform::HashSet<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> > *p_GlyphHash; // edi
  signed int v38; // eax
  int v39; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v40; // eax
  unsigned int v41; // edx
  unsigned int FontStartGlyphs; // eax
  unsigned int v43; // edi
  Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *p_GlyphInfoTable; // esi
  unsigned int v45; // edi
  Scaleform::GFx::FontCompactor::KerningPairType *v46; // edi
  int v47; // edx
  int v48; // eax
  char v49; // [esp+Fh] [ebp-2Dh]
  int x2; // [esp+10h] [ebp-2Ch] BYREF
  int y1; // [esp+14h] [ebp-28h] BYREF
  int x1; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::FontCompactor *v53; // [esp+1Ch] [ebp-20h]
  int y2; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int v55; // [esp+24h] [ebp-18h]
  int v56; // [esp+28h] [ebp-14h]
  unsigned int v57; // [esp+2Ch] [ebp-10h]
  Scaleform::GFx::FontCompactor::GlyphKeyType key; // [esp+30h] [ebp-Ch] BYREF

  v2 = this;
  FontNumGlyphs = this->FontNumGlyphs;
  Size = this->Encoder.Data->Size;
  p_Encoder = &this->Encoder;
  v53 = this;
  v56 = FontNumGlyphs;
  v57 = Size;
  if ( this->TmpContours.Size )
    Scaleform::GFx::FontCompactor::normalizeLastContour(this);
  Scaleform::GFx::FontCompactor::computeBounds(v2, &x1, &y1, &x2, &y2);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, x1);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, y1);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, x2);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, y2);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(
    p_Encoder,
    v2->TmpContours.Size);
  v49 = 0;
  if ( v2->TmpContours.Size )
  {
    v6 = 0;
    for ( x1 = 0; ; v6 = x1 )
    {
      v7 = &v2->TmpContours.Pages[v6 >> 6][v6 & 0x3F];
      v8 = 1;
      y1 = (int)v7;
      x2 = 0;
      if ( v7->DataSize > 1 )
      {
        Pages = v2->TmpVertices.Pages;
        v10 = v7->DataStart + 1;
        do
        {
          ++x2;
          if ( (Pages[v10 >> 6][v10 & 0x3F].x & 1) != 0 )
          {
            ++v8;
            ++v10;
          }
          ++v8;
          ++v10;
        }
        while ( v8 < v7->DataSize );
      }
      v11 = v2->TmpVertices.Pages[v7->DataStart >> 6];
      v12 = v7->DataStart & 0x3F;
      y = v11[v12].y;
      v14 = v11[v12].x >> 1;
      Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
        &v2->Encoder,
        v14);
      Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
        &v2->Encoder,
        y);
      v55 = v2->Encoder.Data->Size;
      Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
        &v2->Encoder,
        2 * x2);
      for ( i = 1; i < *(_DWORD *)(y1 + 4); ++i )
      {
        v16 = v2->TmpVertices.Pages;
        y2 = *(_DWORD *)y1;
        v17 = &v16[(i + y2) >> 6][(i + y2) & 0x3F];
        x = v17->x;
        if ( (v17->x & 1) != 0 )
        {
          v19 = i + 1;
          v20 = v16[(unsigned int)(v19 + y2) >> 6];
          v21 = (v19 + y2) & 0x3F;
          v22 = v20[v21].x;
          v23 = &v20[v21];
          LOWORD(v21) = v17->x;
          v24 = v17->y;
          x2 = v19;
          v25 = v23->y;
          v22 >>= 1;
          Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteQuad(
            &v53->Encoder,
            ((__int16)v21 >> 1) - v14,
            v24 - y,
            v22 - ((__int16)v21 >> 1),
            v25 - v24);
          v14 = v22;
          v2 = v53;
          y = v25;
          i = x2;
        }
        else
        {
          v26 = v17->y;
          v27 = x >> 1;
          y2 = v27;
          x2 = v26;
          if ( v27 == v14 )
          {
            Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteVLine(
              &v2->Encoder,
              v26 - y);
          }
          else
          {
            v28 = v27 - v14;
            if ( v26 == y )
              Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteHLine(
                &v2->Encoder,
                v28);
            else
              Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteLine(
                &v2->Encoder,
                v28,
                v26 - y);
          }
          v14 = y2;
          y = x2;
        }
      }
      if ( mergeContours )
      {
        v29 = v55;
        key.pFont = v2;
        HashValue = Scaleform::GFx::FontCompactor::ComputePathHash(v2, v55);
        pTable = v2->ContourHash.pTable;
        key.HashValue = HashValue;
        key.DataStart = v29;
        if ( !pTable )
          goto LABEL_29;
        v32 = Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::ContourKeyType,Scaleform::GFx::FontCompactor::ContourKeyType>>::findIndexCore<Scaleform::GFx::FontCompactor::ContourKeyType>(
                &v2->ContourHash,
                (const Scaleform::GFx::FontCompactor::ContourKeyType *)&key,
                HashValue & pTable->SizeMask);
        if ( v32 < 0 || (v33 = (int)&pTable[2] + 20 * v32) == 0 )
        {
          HashValue = key.HashValue;
LABEL_29:
          Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType>>::add<Scaleform::GFx::FontCompactor::GlyphKeyType>(
            (Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> > *)&v2->ContourHash,
            &v2->ContourHash,
            &key,
            HashValue);
          v49 = 1;
          goto LABEL_30;
        }
        Data = v2->Encoder.Data;
        if ( v29 < Data->Size )
          Data->Size = v29;
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
          &v2->Encoder,
          (2 * *(_DWORD *)(v33 + 8)) | 1);
      }
LABEL_30:
      if ( ++x1 >= v2->TmpContours.Size )
      {
        Size = v57;
        break;
      }
    }
  }
  ++v2->FontNumGlyphs;
  v55 = Size;
  if ( mergeContours && !v49 )
  {
    key.pFont = v2;
    v35 = Scaleform::GFx::FontCompactor::ComputeGlyphHash(v2, Size);
    v36 = v2->GlyphHash.pTable;
    p_GlyphHash = &v2->GlyphHash;
    key.HashValue = v35;
    key.DataStart = Size;
    if ( !v36
      || (v38 = Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType>>::findIndexCore<Scaleform::GFx::FontCompactor::GlyphKeyType>(
                  &v2->GlyphHash,
                  &key,
                  v35 & v36->SizeMask),
          v38 < 0)
      || (v39 = (int)&p_GlyphHash->pTable[2] + 20 * v38,
          (Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> >::TableType *)((char *)p_GlyphHash->pTable + 20 * v38) == (Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType> >::TableType *)-16) )
    {
      Scaleform::HashSetBase<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::AllocatorGH<Scaleform::GFx::FontCompactor::ContourKeyType,261>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontCompactor::GlyphKeyType,Scaleform::GFx::FontCompactor::GlyphKeyType>>::add<Scaleform::GFx::FontCompactor::GlyphKeyType>(
        &v2->GlyphHash,
        &v2->GlyphHash,
        &key,
        v35);
    }
    else
    {
      v40 = v2->Encoder.Data;
      if ( Size < v40->Size )
        v40->Size = Size;
      v57 = *(_DWORD *)(v39 + 8);
      Size = v57;
    }
  }
  v41 = v2->FontNumGlyphs;
  FontStartGlyphs = v2->FontStartGlyphs;
  v2->FontTotalGlyphBytes += v2->Encoder.Data->Size - v55;
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::UpdateUInt32fixlen(
    &v2->Encoder,
    FontStartGlyphs,
    v41);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::UpdateUInt32fixlen(
    &v2->Encoder,
    v2->FontStartGlyphs + 4,
    v2->FontTotalGlyphBytes);
  v43 = v2->GlyphInfoTable.Size;
  p_GlyphInfoTable = (Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *)&v2->GlyphInfoTable;
  v45 = v43 >> 6;
  if ( v45 >= p_GlyphInfoTable->NumPages )
    Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::ContourType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::ContourType,261>>::allocatePage(
      p_GlyphInfoTable,
      v45);
  v46 = p_GlyphInfoTable->Pages[v45];
  v47 = v56;
  v48 = p_GlyphInfoTable->Size & 0x3F;
  v46[v48].Adjustment = Size;
  *(_DWORD *)&v46[v48].Char1 = v47;
  ++p_GlyphInfoTable->Size;
}
