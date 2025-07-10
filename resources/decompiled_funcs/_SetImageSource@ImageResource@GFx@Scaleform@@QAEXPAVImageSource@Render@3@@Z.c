void __thiscall Scaleform::GFx::ImageResource::SetImageSource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageSrc)
{
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::ImageBase *v5; // ecx

  pImage = this->pImage;
  if ( pImage && pImage != &this->Delegate )
    pImage->Release(pImage);
  this->pImage = pimageSrc;
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->Delegate.pImage.pObject = 0;
  v5 = this->pImage;
  if ( v5 )
    v5->AddRef(v5);
}
