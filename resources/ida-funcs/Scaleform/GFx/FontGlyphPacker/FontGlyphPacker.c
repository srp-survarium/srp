void __thiscall Scaleform::GFx::FontGlyphPacker::FontGlyphPacker(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::GFx::FontPackParams *params,
        Scaleform::GFx::Resource *pimageCreator,
        Scaleform::GFx::Resource *plog,
        Scaleform::GFx::ResourceId *ptextureIdGen,
        Scaleform::MemoryHeap *fontHeap,
        bool threadedLoading)
{
  Scaleform::GFx::FontPackParams *pFontPackParams; // eax
  unsigned int TextureHeight; // edx

  this->pFontPackParams = params;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::FontGlyphPacker_vtbl *)&Scaleform::GFx::FontGlyphPacker::`vftable';
  this->PackTextureConfig.NominalSize = 48;
  this->PackTextureConfig.PadPixels = 3;
  this->PackTextureConfig.TextureWidth = 1024;
  this->PackTextureConfig.TextureHeight = 1024;
  this->pTextureIdGen = ptextureIdGen;
  if ( pimageCreator )
    Scaleform::RefCountImpl::AddRef(pimageCreator);
  this->pImageCreator.pObject = (Scaleform::GFx::ImageCreator *)pimageCreator;
  if ( plog )
    Scaleform::RefCountImpl::AddRef(plog);
  this->pLog.pObject = (Scaleform::Log *)plog;
  this->pFontHeap = fontHeap;
  Scaleform::Render::RectPacker::RectPacker(&this->Packer);
  Scaleform::Render::Rasterizer::Rasterizer(&this->Ras, Scaleform::Memory::pGlobalHeap);
  this->GlyphGeometryHash.mHash.pTable = 0;
  pFontPackParams = this->pFontPackParams;
  this->ThreadedLoading = threadedLoading;
  if ( pFontPackParams )
  {
    this->PackTextureConfig.NominalSize = pFontPackParams->PackTextureConfig.NominalSize;
    this->PackTextureConfig.PadPixels = pFontPackParams->PackTextureConfig.PadPixels;
    this->PackTextureConfig.TextureWidth = pFontPackParams->PackTextureConfig.TextureWidth;
    this->PackTextureConfig.TextureHeight = pFontPackParams->PackTextureConfig.TextureHeight;
  }
  TextureHeight = this->PackTextureConfig.TextureHeight;
  this->Packer.Width = this->PackTextureConfig.TextureWidth;
  this->Packer.Height = TextureHeight;
}
