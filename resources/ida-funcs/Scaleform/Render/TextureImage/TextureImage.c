void __thiscall Scaleform::Render::TextureImage::TextureImage(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::GFx::Resource *ptexture,
        Scaleform::Render::ImageUpdateSync *psync)
{
  unsigned int Width; // eax

  this->__vftable = (Scaleform::Render::TextureImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::TextureImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, (LONG)ptexture);
  this->pUpdateSync = psync;
  this->pInverseMatrix = 0;
  if ( ptexture )
    Scaleform::RefCountImpl::AddRef(ptexture);
  this->__vftable = (Scaleform::Render::TextureImage_vtbl *)&Scaleform::Render::TextureImage::`vftable';
  this->Format = format;
  Width = size->Width;
  this->Size.Height = size->Height;
  this->Size.Width = Width;
  this->Use = use;
  this->ImageId = Scaleform::Render::ImageBase::GetNextImageId();
}
