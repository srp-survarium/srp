char __usercall Scaleform::GFx::GetGlyphShape_Scaleform::GFx::FontDataCompactedGfx_@<al>(
        const Scaleform::GFx::FontDataCompactedGfx *font@<ecx>,
        unsigned int glyphIndex@<eax>,
        Scaleform::Render::GlyphShape *shape)
{
  unsigned int GlyphInfoTablePos; // edx
  unsigned int v5; // eax
  unsigned __int8 *Data; // edx
  Scaleform::Render::GlyphShape *v7; // ebx
  bool v8; // zf
  signed int NominalSize; // esi
  int v10; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v11; // esi
  unsigned int Size; // eax
  unsigned int v13; // edi
  bool *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edi
  bool *v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edi
  bool *v20; // ecx
  double v21; // st7
  int v22; // esi
  int v23; // edi
  int v24; // ebx
  int v25; // eax
  int v26; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // edx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v28; // edi
  unsigned int v29; // esi
  bool *v30; // edx
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
  signed int v53; // [esp+38h] [ebp-78h]
  int edge; // [esp+3Ch] [ebp-74h] BYREF
  int v55; // [esp+40h] [ebp-70h]
  int v56; // [esp+44h] [ebp-6Ch]
  int v57; // [esp+48h] [ebp-68h]
  int v58; // [esp+4Ch] [ebp-64h]
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > v59; // [esp+50h] [ebp-60h] BYREF
  int v60; // [esp+7Ch] [ebp-34h]
  int v61; // [esp+80h] [ebp-30h]

  if ( glyphIndex >= font->CompactedFontValue.NumGlyphs )
    return 0;
  GlyphInfoTablePos = font->CompactedFontValue.GlyphInfoTablePos;
  v59.Data.Data = &font->Container;
  v5 = GlyphInfoTablePos + 8 * glyphIndex + 4;
  Data = font->CompactedFontValue.Decoder.Data->Data;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::StartGlyph(
    &v59,
    Data[v5] | ((Data[v5 + 1] | ((Data[v5 + 2] | (Data[v5 + 3] << 8)) << 8)) << 8));
  v7 = shape;
  v8 = shape->Data.Data.Size == 0;
  NominalSize = font->CompactedFontValue.NominalSize;
  v53 = NominalSize;
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
  v8 = v59.NumContours == 0;
  shape->Data.Data.Size = 0;
  if ( !v8 )
  {
    v44 = (float)(unsigned int)NominalSize;
    while ( 1 )
    {
      v10 = (v59.MoveY << 10) / NominalSize;
      v45.Data = v7->pContainer;
      v11 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v45.Data;
      v34 = (double)v59.MoveX * 1024.0 / v44;
      v42 = (float)v10;
      Multiplier = v7->Multiplier;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        &v45,
        1u);
      Size = v11->Size;
      v13 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v13 >= v11->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v11,
            v11,
            v13 + (v13 >> 2));
      }
      else if ( v13 < v11->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          Size + 1);
      }
      v14 = v11->Data;
      v11->Size = v13;
      v14[v13 - 1] = 4;
      v15 = v11->Size;
      v16 = v15 + 1;
      if ( v15 + 1 >= v15 )
      {
        if ( v16 >= v11->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v11,
            v11,
            v16 + (v16 >> 2));
      }
      else if ( v16 < v11->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v15 + 1);
      }
      v17 = v11->Data;
      v11->Size = v16;
      v17[v16 - 1] = 0;
      v18 = v11->Size;
      v19 = v18 + 1;
      if ( v18 + 1 >= v18 )
      {
        if ( v19 >= v11->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v11,
            v11,
            v19 + (v19 >> 2));
      }
      else if ( v19 < v11->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v18 + 1);
      }
      v20 = v11->Data;
      v21 = v34 * Multiplier;
      v11->Size = v19;
      v20[v19 - 1] = 0;
      v22 = (int)v21;
      v60 = (int)v21;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v45,
        (int)v21);
      v23 = (int)(v42 * Multiplier);
      v61 = v23;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v45,
        v23);
      if ( v59.NumEdges )
      {
        do
        {
          Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(&v59, &edge);
          if ( edge == 2 )
          {
            v48 = v7->Multiplier;
            v47.Data = v7->pContainer;
            v35 = (double)v55 * 1024.0 / v44;
            v24 = (int)(v35 * v48) - v22;
            v36 = 1024.0 * (double)v56 / v44;
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
            v38 = (double)v57 * 1024.0 / v44;
            v26 = (int)(v38 * v52) - v22;
            v39 = (double)v58 * 1024.0 / v44;
            v43 = (int)(v39 * v52) - v23;
            v40 = (double)v56 * 1024.0 / v44;
            v32 = (int)(v40 * v52) - v23;
            v41 = 1024.0 * (double)v55 / v44;
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
        while ( v59.NumEdges );
        pContainer = shape->pContainer;
        v50 = shape->Multiplier;
        v49.Data = pContainer;
        if ( v22 != v60 || v23 != v61 )
        {
          if ( v61 == v23 )
          {
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
              &v49,
              v60 - v22);
          }
          else
          {
            v33 = v61 - v23;
            if ( v60 == v22 )
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                &v49,
                v33);
            else
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                &v49,
                v60 - v22,
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
      --v59.NumContours;
      Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(&v59);
      if ( !v59.NumContours )
        break;
      NominalSize = v53;
    }
  }
  if ( !v7->IsEmpty(v7) )
  {
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v7);
    return 1;
  }
  return 0;
}
