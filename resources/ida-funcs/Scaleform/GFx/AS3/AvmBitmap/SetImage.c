void __thiscall Scaleform::GFx::AS3::AvmBitmap::SetImage(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::ImageResource *img)
{
  Scaleform::GFx::ImageResource *pObject; // ecx

  if ( img )
    Scaleform::RefCountImpl::AddRef(img);
  pObject = this->pImage.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImage.pObject = img;
}
