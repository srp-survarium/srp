void __thiscall Scaleform::GFx::FontCompactor::EndGlyph(Scaleform::GFx::FontCompactor *this, bool mergeContours)
{
  Scaleform::GFx::FontCompactor *v2; // esi
  unsigned __int16 FontNumGlyphs; // ax
  unsigned int Size; // ebx
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Encoder; // edi
  unsigned int v6; // eax
  const Scaleform::GFx::FontCompactor::ContourType *v7; // ecx
  unsigned int v8; // edx
  Scaleform::GFx::FontCompactor::VertexType **Pages; // edi
  unsigned int v10; // eax
  Scaleform::GFx::FontCompactor::VertexType *v11; // edx
  int v12; // eax
  unsigned int y; // ebp
  int v14; // edi
  unsigned int j; // ebx
  Scaleform::GFx::FontCompactor::VertexType **v16; // edx
  Scaleform::GFx::FontCompactor::VertexType *v17; // ecx
  __int16 x; // ax
  unsigned int v19; // ebx
  Scaleform::GFx::FontCompactor::VertexType *v20; // edx
  int v21; // eax
  int v22; // esi
  Scaleform::GFx::FontCompactor::VertexType *v23; // edx
  int v24; // ecx
  unsigned int v25; // ebx
  unsigned int v26; // ecx
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
  bool newShapesAdded; // [esp+Fh] [ebp-2Dh]
  unsigned int numEdges; // [esp+10h] [ebp-2Ch] BYREF
  const Scaleform::GFx::FontCompactor::ContourType *c; // [esp+14h] [ebp-28h] BYREF
  unsigned int i; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::FontCompactor *v53; // [esp+1Ch] [ebp-20h]
  int y2; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int startPath; // [esp+24h] [ebp-18h]
  Scaleform::GFx::FontCompactor::GlyphInfoType glyphInfo; // [esp+28h] [ebp-14h]
  Scaleform::GFx::FontCompactor::GlyphKeyType key; // [esp+30h] [ebp-Ch] BYREF

  v2 = this;
  FontNumGlyphs = this->FontNumGlyphs;
  Size = this->Encoder.Data->Size;
  p_Encoder = &this->Encoder;
  v53 = this;
  glyphInfo.GlyphCode = FontNumGlyphs;
  glyphInfo.AdvanceX = 0;
  glyphInfo.GlobalOffset = Size;
  if ( this->TmpContours.Size )
    Scaleform::GFx::FontCompactor::normalizeLastContour(this);
  Scaleform::GFx::FontCompactor::computeBounds(v2, (int *)&i, (int *)&c, (int *)&numEdges, &y2);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, i);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, (int)c);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(
    p_Encoder,
    numEdges);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteSInt15(p_Encoder, y2);
  Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(
    p_Encoder,
    v2->TmpContours.Size);
  newShapesAdded = 0;
  if ( v2->TmpContours.Size )
  {
    v6 = 0;
    for ( i = 0; ; v6 = i )
    {
      v7 = &v2->TmpContours.Pages[v6 >> 6][v6 & 0x3F];
      v8 = 1;
      c = v7;
      numEdges = 0;
      if ( v7->DataSize > 1 )
      {
        Pages = v2->TmpVertices.Pages;
        v10 = v7->DataStart + 1;
        do
        {
          ++numEdges;
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
      startPath = v2->Encoder.Data->Size;
      Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
        &v2->Encoder,
        2 * numEdges);
      for ( j = 1; j < c->DataSize; ++j )
      {
        v16 = v2->TmpVertices.Pages;
        y2 = c->DataStart;
        v17 = &v16[(j + y2) >> 6][(j + y2) & 0x3F];
        x = v17->x;
        if ( (v17->x & 1) != 0 )
        {
          v19 = j + 1;
          v20 = v16[(v19 + y2) >> 6];
          v21 = (v19 + y2) & 0x3F;
          v22 = v20[v21].x;
          v23 = &v20[v21];
          LOWORD(v21) = v17->x;
          v24 = v17->y;
          numEdges = v19;
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
          j = numEdges;
        }
        else
        {
          v26 = v17->y;
          v27 = x >> 1;
          y2 = v27;
          numEdges = v26;
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
          y = numEdges;
        }
      }
      if ( mergeContours )
      {
        v29 = startPath;
        key.pFont = v2;
        HashValue = Scaleform::GFx::FontCompactor::ComputePathHash(v2, startPath);
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
          newShapesAdded = 1;
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
      if ( ++i >= v2->TmpContours.Size )
      {
        Size = glyphInfo.GlobalOffset;
        break;
      }
    }
  }
  ++v2->FontNumGlyphs;
  startPath = Size;
  if ( mergeContours && !newShapesAdded )
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
      glyphInfo.GlobalOffset = *(_DWORD *)(v39 + 8);
      Size = glyphInfo.GlobalOffset;
    }
  }
  v41 = v2->FontNumGlyphs;
  FontStartGlyphs = v2->FontStartGlyphs;
  v2->FontTotalGlyphBytes += v2->Encoder.Data->Size - startPath;
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
  v47 = *(_DWORD *)&glyphInfo.GlyphCode;
  v48 = p_GlyphInfoTable->Size & 0x3F;
  v46[v48].Adjustment = Size;
  *(_DWORD *)&v46[v48].Char1 = v47;
  ++p_GlyphInfoTable->Size;
}
