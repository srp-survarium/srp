void __thiscall Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::MovieDefImpl *md)
{
  Scaleform::GFx::MovieDefImpl *pObject; // ecx

  if ( md )
    Scaleform::RefCountImpl::AddRef(md);
  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pDefImpl.pObject = md;
}
