bool __thiscall Scaleform::Render::TextureImage::Decode(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  return this->pTexture.Value && this->pTexture.Value->Copy(this->pTexture.Value, pdest);
}
