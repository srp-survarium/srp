Scaleform::Render::GlyphTextureImage *__cdecl Scaleform::Render::GlyphTextureImage::Create(
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::TextureManager *texMan,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use)
{
  Scaleform::Render::GlyphTextureImage *v6; // eax
  Scaleform::Render::Image *v7; // eax
  Scaleform::Render::Image *v8; // esi
  Scaleform::Render::Texture *v9; // eax

  v6 = (Scaleform::Render::GlyphTextureImage *)heap->Alloc(heap, 48, 0);
  if ( v6 )
  {
    Scaleform::Render::GlyphTextureImage::GlyphTextureImage(v6, cache, textureId, size, use);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = texMan->CreateTexture(texMan, 9, 1, size, use, v8, 0);
  if ( v9 )
  {
    Scaleform::Render::Image::initTexture_NoAddRef(v8, v9);
    return (Scaleform::Render::GlyphTextureImage *)v8;
  }
  else
  {
    v8->Release(v8);
    return 0;
  }
}
