void __thiscall Scaleform::GFx::FontGlyphPacker::generateGlyphInfo(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *glyphs,
        Scaleform::GFx::FontResource *font)
{
  Scaleform::GFx::TextureGlyphData *v4; // esi
  unsigned int v5; // eax
  Scaleform::GFx::TextureGlyphData *v6; // eax
  Scaleform::GFx::TextureGlyphData *v7; // esi
  int PadPixels; // ecx
  Scaleform::GFx::FontPackParams::TextureConfig *p_PackTextureConfig; // ebx
  Scaleform::Render::Font *pObject; // ecx
  unsigned int (__thiscall *GetGlyphShapeCount)(Scaleform::Render::Font *); // eax
  unsigned int *v12; // ebx
  const Scaleform::Render::ShapeDataInterface *v13; // eax
  float *v14; // esi
  unsigned int v15; // eax
  unsigned int *v16; // eax
  Scaleform::GFx::TextureGlyphData *v17; // [esp+1C8h] [ebp-60h]
  unsigned int value; // [esp+1D0h] [ebp-58h] BYREF
  float v20; // [esp+1D4h] [ebp-54h]
  int v21; // [esp+1D8h] [ebp-50h]
  Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey v22; // [esp+1DCh] [ebp-4Ch] BYREF
  Scaleform::Render::Rect<float> bounds; // [esp+1E8h] [ebp-40h] BYREF
  Scaleform::GFx::FontGlyphPacker::GlyphInfo trans; // [esp+1F8h] [ebp-30h] BYREF

  if ( font->pFont.pObject->GetGlyphShapeCount(font->pFont.pObject) )
  {
    v4 = (Scaleform::GFx::TextureGlyphData *)this->pFontHeap->Alloc(this->pFontHeap, 44, 0);
    if ( v4 )
    {
      v5 = font->pFont.pObject->GetGlyphShapeCount(font->pFont.pObject);
      Scaleform::GFx::TextureGlyphData::TextureGlyphData(v4, v5, 0);
      v7 = v6;
      v17 = v6;
    }
    else
    {
      v17 = 0;
      v7 = 0;
    }
    v7->PackTextureConfig.NominalSize = this->PackTextureConfig.NominalSize;
    PadPixels = this->PackTextureConfig.PadPixels;
    p_PackTextureConfig = &this->PackTextureConfig;
    v7->PackTextureConfig.PadPixels = PadPixels;
    v7->PackTextureConfig.TextureWidth = p_PackTextureConfig->TextureWidth;
    v7->PackTextureConfig.TextureHeight = p_PackTextureConfig->TextureHeight;
    font->pFont.pObject->SetTextureGlyphData(font->pFont.pObject, v7);
    pObject = font->pFont.pObject;
    GetGlyphShapeCount = pObject->GetGlyphShapeCount;
    v20 = (double)p_PackTextureConfig->NominalSize / 1536.0;
    v12 = 0;
    v21 = GetGlyphShapeCount(pObject);
    if ( v21 )
    {
      do
      {
        if ( !Scaleform::GFx::TextureGlyphData::GetTextureGlyph(v7, (unsigned int)v12)->pImage.pObject )
        {
          v13 = font->pFont.pObject->GetPermanentGlyphShape(font->pFont.pObject, v12);
          v14 = (float *)v13;
          if ( v13 )
          {
            *(float *)&trans.pFont = 1.0;
            *(float *)&trans.GlyphIndex = 0.0;
            *(float *)&trans.GlyphReuse = 0.0;
            *(float *)&trans.TextureIdx = 0.0;
            trans.Bounds.x1 = 0.0;
            trans.Bounds.x2 = 0.0;
            trans.Bounds.y2 = 0.0;
            trans.Bounds.y1 = 1.0;
            bounds.x1 = 1.0e30;
            bounds.y1 = 1.0e30;
            bounds.x2 = -1.0e30;
            bounds.y2 = -1.0e30;
            Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(
              v13,
              (const Scaleform::Render::Matrix2x4<float> *)&trans,
              &bounds,
              Bound_FillEdges);
            *(float *)&value = bounds.x2 - bounds.x1;
            if ( *(float *)&value > 0.0 )
            {
              *(float *)&value = bounds.y2 - bounds.y1;
              if ( *(float *)&value > 0.0 )
              {
                *(float *)&value = (float)this->PackTextureConfig.PadPixels;
                trans.Bounds.x1 = bounds.x1 * v20 - *(float *)&value;
                trans.Bounds.y1 = bounds.y1 * v20 - *(float *)&value;
                trans.Bounds.x2 = bounds.x2 * v20 + *(float *)&value;
                trans.Bounds.y2 = *(float *)&value + v20 * bounds.y2;
                trans.Origin.x = 0.0;
                trans.Origin.y = 0.0;
                *(float *)&value = trans.Bounds.x2 - trans.Bounds.x1;
                if ( *(float *)&value > 0.0 )
                {
                  *(float *)&value = trans.Bounds.y2 - trans.Bounds.y1;
                  if ( *(float *)&value > 0.0 )
                  {
                    trans.pFont = font;
                    trans.GlyphIndex = (unsigned int)v12;
                    *(_QWORD *)&trans.GlyphReuse = -1;
                    v15 = Scaleform::GFx::ComputeGeometryHash(
                            v12,
                            v14,
                            (const Scaleform::Render::ShapeDataInterface *)v14);
                    v22.pShape = (const Scaleform::Render::ShapeDataInterface *)v14;
                    v22.pFont = font;
                    v22.Hash = v15;
                    v16 = Scaleform::Hash<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Get(
                            &this->GlyphGeometryHash,
                            &v22);
                    if ( v16 )
                    {
                      trans.GlyphReuse = *v16;
                    }
                    else
                    {
                      value = glyphs->Data.Size;
                      Scaleform::Hash<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Add(
                        &this->GlyphGeometryHash,
                        &v22,
                        &value);
                    }
                    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::FontGlyphPacker::GlyphInfo,Scaleform::AllocatorGH<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                      glyphs,
                      &trans);
                  }
                }
              }
            }
          }
          v7 = v17;
        }
        v12 = (unsigned int *)((char *)v12 + 1);
      }
      while ( (unsigned int)v12 < v21 );
    }
    Scaleform::RefCountNTSImpl::Release(v7);
  }
}
