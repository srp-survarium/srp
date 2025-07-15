void __thiscall Scaleform::GFx::ImageResource::SetImage(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage)
{
  Scaleform::Render::ImageBase *v3; // ecx
  Scaleform::Render::Image *pObject; // ecx

  v3 = this->pImage;
  if ( v3 && v3 != &this->Delegate )
    v3->Release(v3);
  if ( pimage )
    pimage->AddRef(pimage);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->Delegate.pImage.pObject = pimage;
  this->pImage = &this->Delegate;
}
