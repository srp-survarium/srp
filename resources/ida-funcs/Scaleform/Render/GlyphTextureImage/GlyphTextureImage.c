void __thiscall Scaleform::Render::GlyphTextureImage::GlyphTextureImage(
        Scaleform::Render::GlyphTextureImage *this,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use)
{
  unsigned int Height; // ecx

  this->__vftable = (Scaleform::Render::GlyphTextureImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::GlyphTextureImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->__vftable = (Scaleform::Render::GlyphTextureImage_vtbl *)&Scaleform::Render::TextureImage::`vftable';
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->Format = Image_A8;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
  this->Use = use;
  this->__vftable = (Scaleform::Render::GlyphTextureImage_vtbl *)&Scaleform::Render::GlyphTextureImage::`vftable';
  this->pCache = cache;
  this->TextureId = textureId;
}
