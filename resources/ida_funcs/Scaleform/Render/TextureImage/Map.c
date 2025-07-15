int __thiscall Scaleform::Render::TextureImage::Map(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::ImageData *pdata,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  return ((int (__thiscall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::ImageData *, unsigned int, unsigned int))this->pTexture.Value->Map)(
           this->pTexture.Value,
           pdata,
           mipLevel,
           levelCount);
}
