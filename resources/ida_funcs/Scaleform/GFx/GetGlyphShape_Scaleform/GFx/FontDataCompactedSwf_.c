char __usercall Scaleform::GFx::GetGlyphShape_Scaleform::GFx::FontDataCompactedSwf_@<al>(
        const Scaleform::GFx::FontDataCompactedSwf *font@<ecx>,
        unsigned int glyphIndex@<eax>,
        Scaleform::Render::GlyphShape *shape)
{
  unsigned int v4; // eax
  int UInt32fixlen; // eax
  unsigned int UInt15; // eax
  Scaleform::Render::GlyphShape *v7; // ebx
  bool v8; // zf
  signed int NominalSize; // esi
  int v10; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v13; // edi
  bool *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edi
  bool *v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edi
  bool *v20; // eax
  double v21; // st7
  int v22; // esi
  int v23; // edi
  int v24; // ebx
  int v25; // eax
  int v26; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v28; // edi
  unsigned int v29; // esi
  bool *v30; // ecx
  int v32; // [esp-Ch] [ebp-BCh]
  int v33; // [esp-4h] [ebp-B4h]
  float v34; // [esp+Ch] [ebp-A4h]
  float v35; // [esp+Ch] [ebp-A4h]
  float v36; // [esp+Ch] [ebp-A4h]
  int v37; // [esp+Ch] [ebp-A4h]
  float v38; // [esp+Ch] [ebp-A4h]
  float v39; // [esp+Ch] [ebp-A4h]
  float v40; // [esp+Ch] [ebp-A4h]
  float v41; // [esp+Ch] [ebp-A4h]
  float v42; // [esp+10h] [ebp-A0h]
  int v43; // [esp+10h] [ebp-A0h]
  float v44; // [esp+14h] [ebp-9Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v45; // [esp+18h] [ebp-98h] BYREF
  float Multiplier; // [esp+1Ch] [ebp-94h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v47; // [esp+20h] [ebp-90h] BYREF
  float v48; // [esp+24h] [ebp-8Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v49; // [esp+28h] [ebp-88h] BYREF
  float v50; // [esp+2Ch] [ebp-84h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v51; // [esp+30h] [ebp-80h] BYREF
  float v52; // [esp+34h] [ebp-7Ch]
  Scaleform::GFx::Normalizer n; // [esp+38h] [ebp-78h]
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > glyph; // [esp+3Ch] [ebp-74h] BYREF
  int edge[5]; // [esp+64h] [ebp-4Ch] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+78h] [ebp-38h]

  if ( glyphIndex >= font->CompactedFontValue.NumGlyphs )
    return 0;
  v4 = font->CompactedFontValue.GlyphInfoTablePos + 8 * glyphIndex + 4;
  glyph.Data.Data = &font->Container;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&font->CompactedFontValue.Decoder,
                   v4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &glyph,
    UInt32fixlen);
  UInt15 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt15(
             &glyph.Data,
             glyph.Pos,
             &glyph.NumContours);
  glyph.Pos += UInt15;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader(&glyph);
  v7 = shape;
  v8 = shape->Data.Data.Size == 0;
  NominalSize = font->CompactedFontValue.NominalSize;
  n.NominalSize = NominalSize;
  if ( v8 )
  {
    if ( shape->Data.Data.Policy.Capacity )
      goto LABEL_7;
  }
  else if ( (shape->Data.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
    goto LABEL_7;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&shape->Data,
    &shape->Data,
    0);
LABEL_7:
  v8 = glyph.NumContours == 0;
  shape->Data.Data.Size = 0;
  if ( !v8 )
  {
    v44 = (float)(unsigned int)NominalSize;
    while ( 1 )
    {
      v10 = (glyph.MoveY << 10) / NominalSize;
      v45.Data = v7->pContainer;
      Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v45.Data;
      v34 = (double)glyph.MoveX * 1024.0 / v44;
      v42 = (float)v10;
      Multiplier = v7->Multiplier;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        &v45,
        1u);
      Size = Data->Size;
      v13 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v13 >= Data->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            Data,
            Data,
            v13 + (v13 >> 2));
      }
      else if ( v13 < Data->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          Data,
          Data,
          Size + 1);
      }
      v14 = Data->Data;
      Data->Size = v13;
      v14[v13 - 1] = 4;
      v15 = Data->Size;
      v16 = v15 + 1;
      if ( v15 + 1 >= v15 )
      {
        if ( v16 >= Data->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            Data,
            Data,
            v16 + (v16 >> 2));
      }
      else if ( v16 < Data->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          Data,
          Data,
          v15 + 1);
      }
      v17 = Data->Data;
      Data->Size = v16;
      v17[v16 - 1] = 0;
      v18 = Data->Size;
      v19 = v18 + 1;
      if ( v18 + 1 >= v18 )
      {
        if ( v19 >= Data->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            Data,
            Data,
            v19 + (v19 >> 2));
      }
      else if ( v19 < Data->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          Data,
          Data,
          v18 + 1);
      }
      v20 = Data->Data;
      v21 = Multiplier * v34;
      Data->Size = v19;
      v20[v19 - 1] = 0;
      v22 = (int)v21;
      pos.StartX = (int)v21;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v45,
        (int)v21);
      v23 = (int)(Multiplier * v42);
      pos.StartY = v23;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v45,
        v23);
      if ( glyph.NumEdges )
      {
        do
        {
          Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(
            &glyph,
            edge);
          if ( edge[0] == 2 )
          {
            v48 = v7->Multiplier;
            v47.Data = v7->pContainer;
            v35 = (double)edge[1] * 1024.0 / v44;
            v24 = (int)(v35 * v48) - v22;
            v36 = 1024.0 * (double)edge[2] / v44;
            v25 = (int)(v48 * v36) - v23;
            v37 = v25;
            if ( v25 )
            {
              if ( v24 )
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                  &v47,
                  v24,
                  v25);
                v22 += v24;
              }
              else
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                  &v47,
                  v25);
              }
              v23 += v37;
            }
            else
            {
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                &v47,
                v24);
              v22 += v24;
            }
          }
          else
          {
            v52 = v7->Multiplier;
            v51.Data = v7->pContainer;
            v38 = (double)edge[3] * 1024.0 / v44;
            v26 = (int)(v38 * v52) - v22;
            v39 = (double)edge[4] * 1024.0 / v44;
            v43 = (int)(v39 * v52) - v23;
            v40 = (double)edge[2] * 1024.0 / v44;
            v32 = (int)(v40 * v52) - v23;
            v41 = 1024.0 * (double)edge[1] / v44;
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
              &v51,
              (int)(v52 * v41) - v22,
              v32,
              v26,
              v43);
            v22 += v26;
            v23 += v43;
          }
          v7 = shape;
        }
        while ( glyph.NumEdges );
        pContainer = shape->pContainer;
        v50 = shape->Multiplier;
        v49.Data = pContainer;
        if ( v22 != pos.StartX || v23 != pos.StartY )
        {
          if ( pos.StartY == v23 )
          {
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
              &v49,
              pos.StartX - v22);
          }
          else
          {
            v33 = pos.StartY - v23;
            if ( pos.StartX == v22 )
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                &v49,
                v33);
            else
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                &v49,
                pos.StartX - v22,
                v33);
          }
        }
        v28 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)shape->pContainer;
        v29 = v28->Size + 1;
        if ( v29 >= v28->Size )
        {
          if ( v29 >= v28->Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v28,
              v28,
              v29 + (v29 >> 2));
        }
        else if ( v29 < v28->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v28,
            v28,
            v28->Size + 1);
        }
        v30 = v28->Data;
        v28->Size = v29;
        v30[v29 - 1] = 15;
      }
      --glyph.NumContours;
      Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader(&glyph);
      if ( !glyph.NumContours )
        break;
      NominalSize = n.NominalSize;
    }
  }
  if ( !v7->IsEmpty(v7) )
  {
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v7);
    return 1;
  }
  return 0;
}
