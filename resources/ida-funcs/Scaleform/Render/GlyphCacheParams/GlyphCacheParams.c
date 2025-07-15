void __thiscall Scaleform::Render::GlyphCacheParams::GlyphCacheParams(
        Scaleform::Render::GlyphCacheParams *this,
        unsigned int numTextures,
        unsigned int textureWidth,
        unsigned int textureHeight,
        unsigned int maxSlotHeight)
{
  this->MaxRasterScale = 1.0;
  this->FauxItalicAngle = 0.25;
  this->TextureWidth = textureWidth;
  this->FauxBoldRatio = 0.045000002;
  this->TextureHeight = textureHeight;
  this->OutlineRatio = 0.0099999998;
  this->NumTextures = numTextures;
  this->MaxSlotHeight = maxSlotHeight;
  this->ShadowQuality = 1.0;
  this->SlotPadding = 2;
  this->TexUpdWidth = 256;
  this->TexUpdHeight = 512;
  this->MaxVectorCacheSize = 500;
  this->UseAutoFit = 1;
  this->UseVectorOnFullCache = 0;
  this->FenceWaitOnFullCache = 1;
}
