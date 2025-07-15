void __thiscall Scaleform::GFx::FontGlyphPacker::generateTextures(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *glyphs,
        unsigned int numTextures)
{
  Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // edi
  int v7; // ebx
  Scaleform::GFx::FontGlyphPacker::GlyphInfo *v8; // esi
  unsigned int TextureWidth; // edi
  unsigned int TextureHeight; // esi
  Scaleform::Render::RawImage *v11; // ebx
  Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *v12; // edi
  unsigned int v13; // esi
  double v14; // st7
  Scaleform::GFx::ResourceId *pTextureIdGen; // eax
  int v16; // esi
  Scaleform::GFx::ImageResource *v17; // eax
  Scaleform::GFx::ImageResource *v18; // eax
  Scaleform::GFx::FontGlyphPacker::GlyphInfo *Data; // eax
  unsigned int GlyphReuse; // ecx
  unsigned int TextureIdx; // edx
  int v22; // ecx
  double v23; // st7
  Scaleform::GFx::FontGlyphPacker::GlyphInfo *v24; // ecx
  void (__thiscall *AddRef)(struct Scaleform::Render::Image *); // edx
  Scaleform::GFx::TextureGlyphData *v26; // edi
  Scaleform::Render::Palette *pObject; // esi
  __int64 X; // [esp+588h] [ebp-F8h]
  Scaleform::GFx::ImageResource *pimageRes; // [esp+5A8h] [ebp-D8h]
  float pimageResc; // [esp+5A8h] [ebp-D8h]
  Scaleform::GFx::ImageResource *pimageResa; // [esp+5A8h] [ebp-D8h]
  Scaleform::GFx::ImageResource *pimageResb; // [esp+5A8h] [ebp-D8h]
  float v33; // [esp+5ACh] [ebp-D4h]
  float v34; // [esp+5ACh] [ebp-D4h]
  int v35; // [esp+5B0h] [ebp-D0h]
  float v36; // [esp+5B0h] [ebp-D0h]
  unsigned int v37; // [esp+5B0h] [ebp-D0h]
  float v38; // [esp+5B4h] [ebp-CCh]
  unsigned int i; // [esp+5BCh] [ebp-C4h]
  Scaleform::GFx::ResourceId v41; // [esp+5C8h] [ebp-B8h]
  Scaleform::GFx::FontResource *pFont; // [esp+5D0h] [ebp-B0h]
  unsigned int glyphIndex; // [esp+5D4h] [ebp-ACh]
  float x1; // [esp+5E0h] [ebp-A0h]
  float y1; // [esp+5E4h] [ebp-9Ch]
  float x2; // [esp+5E8h] [ebp-98h]
  float y2; // [esp+5ECh] [ebp-94h]
  float v48; // [esp+5F0h] [ebp-90h]
  float y; // [esp+5F4h] [ebp-8Ch]
  float v50; // [esp+608h] [ebp-78h]
  float v51; // [esp+60Ch] [ebp-74h]
  Scaleform::Render::TextureGlyph glyph; // [esp+610h] [ebp-70h] BYREF
  Scaleform::Render::ImageData pdata; // [esp+648h] [ebp-38h] BYREF
  _DWORD v54[2]; // [esp+670h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [esp+678h] [ebp-8h] BYREF

  for ( i = 0; i < numTextures; ++i )
  {
    v3 = glyphs;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v35 = 0;
    pimageRes = 0;
    if ( glyphs->Data.Size )
    {
      v7 = 0;
      do
      {
        v8 = &v3->Data.Data[v7];
        if ( v8->TextureIdx == i )
        {
          v33 = ceil(v8->Bounds.x2);
          if ( (int)v33 > v35 )
          {
            v36 = ceil(v8->Bounds.x2);
            v35 = (__int64)v36;
          }
          v34 = ceil(v8->Bounds.y2);
          if ( (int)v34 > (int)pimageRes )
          {
            pimageResc = ceil(v8->Bounds.y2);
            pimageRes = (Scaleform::GFx::ImageResource *)(__int64)pimageResc;
          }
        }
        v3 = glyphs;
        ++v6;
        ++v7;
      }
      while ( v6 < glyphs->Data.Size );
      v4 = v35;
      v5 = (unsigned int)pimageRes;
    }
    TextureWidth = this->PackTextureConfig.TextureWidth;
    TextureHeight = this->PackTextureConfig.TextureHeight;
    if ( v4 <= TextureWidth >> 1 )
    {
      for ( TextureWidth = 1; TextureWidth < v4; TextureWidth *= 2 )
        ;
    }
    if ( v5 <= TextureHeight >> 1 )
    {
      for ( TextureHeight = 1; TextureHeight < v5; TextureHeight *= 2 )
        ;
    }
    X = (unsigned int)this->pFontHeap;
    size.Width = TextureWidth;
    size.Height = TextureHeight;
    v11 = Scaleform::Render::RawImage::Create(
            Image_A8,
            1u,
            &size,
            2u,
            (Scaleform::MemoryHeap *)X,
            (Scaleform::Render::ImageUpdateSync *)HIDWORD(X));
    memset(&pdata, 0, 10);
    memset(&pdata.pPalette, 0, 24);
    pdata.RawPlaneCount = 1;
    pdata.pPlanes = &pdata.Plane0;
    Scaleform::Render::RawImage::GetImageData(v11, &pdata);
    memset((int)pdata.pPlanes->pData, 0, TextureWidth * TextureHeight);
    v12 = glyphs;
    v13 = 0;
    if ( glyphs->Data.Size )
    {
      pimageResa = 0;
      do
      {
        if ( *(Scaleform::Render::ImageBase **)((char *)&pimageResa->pImage + (unsigned int)glyphs->Data.Data) == (Scaleform::Render::ImageBase *)i )
          Scaleform::GFx::FontGlyphPacker::rasterizeGlyph(
            this,
            (unsigned int *)glyphs,
            v11,
            (Scaleform::GFx::FontGlyphPacker::GlyphInfo *)((char *)pimageResa + (unsigned int)glyphs->Data.Data));
        pimageResa = (Scaleform::GFx::ImageResource *)((char *)pimageResa + 48);
        ++v13;
      }
      while ( v13 < glyphs->Data.Size );
    }
    v11->GetSize(v11, (Scaleform::Render::Size<unsigned long> *)v54);
    v51 = 1.0 / (double)v54[0];
    v14 = 1.0 / (double)v54[1];
    pTextureIdGen = this->pTextureIdGen;
    v41.Id = pTextureIdGen->Id++;
    v16 = 0;
    v50 = v14;
    v17 = (Scaleform::GFx::ImageResource *)this->pFontHeap->Alloc(this->pFontHeap, 52, 0);
    if ( v17 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v17, v11, Use_FontTexture);
      pimageResb = v18;
    }
    else
    {
      pimageResb = 0;
    }
    v37 = 0;
    if ( glyphs->Data.Size )
    {
      do
      {
        Data = v12->Data.Data;
        pFont = v12->Data.Data[v16].pFont;
        GlyphReuse = v12->Data.Data[v16].GlyphReuse;
        glyphIndex = v12->Data.Data[v16].GlyphIndex;
        TextureIdx = v12->Data.Data[v16].TextureIdx;
        x1 = v12->Data.Data[v16].Bounds.x1;
        y1 = v12->Data.Data[v16].Bounds.y1;
        x2 = v12->Data.Data[v16].Bounds.x2;
        y2 = v12->Data.Data[v16].Bounds.y2;
        v48 = v12->Data.Data[v16].Origin.x;
        y = v12->Data.Data[v16].Origin.y;
        if ( GlyphReuse != -1 )
        {
          v22 = GlyphReuse;
          v23 = Data[v22].Bounds.x1;
          v24 = &Data[v22];
          v38 = v23;
          TextureIdx = v24->TextureIdx;
          x1 = v38;
          y1 = v24->Bounds.y1;
          x2 = v24->Bounds.x2;
          y2 = v24->Bounds.y2;
          v48 = v24->Origin.x;
          y = v24->Origin.y;
        }
        if ( TextureIdx == i )
        {
          AddRef = v11->AddRef;
          glyph.UvBounds.x1 = 0.0;
          glyph.UvBounds.y1 = 0.0;
          glyph.UvBounds.x2 = 0.0;
          glyph.UvBounds.y2 = 0.0;
          glyph.RefCount = 1;
          glyph.__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::Render::TextureGlyph::`vftable';
          glyph.pImage.pObject = 0;
          glyph.BindIndex = -1;
          AddRef(v11);
          if ( glyph.pImage.pObject )
            glyph.pImage.pObject->Release(glyph.pImage.pObject);
          glyph.pImage.pObject = v11;
          glyph.BindIndex = -1;
          glyph.UvBounds.x1 = x1 * v51;
          glyph.UvBounds.y1 = y1 * v50;
          glyph.UvBounds.x2 = x2 * v51;
          glyph.UvBounds.y2 = y2 * v50;
          glyph.UvOrigin.x = v51 * v48;
          glyph.UvOrigin.y = v50 * y;
          v26 = (Scaleform::GFx::TextureGlyphData *)pFont->pFont.pObject->GetTextureGlyphData(pFont->pFont.pObject);
          Scaleform::GFx::TextureGlyphData::AddTextureGlyph(v26, glyphIndex, &glyph);
          Scaleform::GFx::TextureGlyphData::AddTexture(v26, v41, pimageResb);
          if ( glyph.pImage.pObject )
            glyph.pImage.pObject->Release(glyph.pImage.pObject);
          Scaleform::RefCountImplCore::~RefCountImplCore(&glyph.Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>);
          v12 = glyphs;
        }
        ++v16;
        ++v37;
      }
      while ( v37 < v12->Data.Size );
    }
    if ( pimageResb )
      Scaleform::GFx::Resource::Release(pimageResb);
    Scaleform::Render::ImageData::freePlanes(&pdata);
    if ( pdata.pPalette.pObject )
    {
      pObject = pdata.pPalette.pObject;
      if ( InterlockedExchangeAdd(&pdata.pPalette.pObject->RefCount.Value, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    v11->Release(v11);
  }
}
