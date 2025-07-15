void __thiscall Scaleform::GFx::AS2::BitmapData::Finalize_GC(Scaleform::GFx::AS2::BitmapData *this)
{
  Scaleform::GFx::ImageResource *pObject; // ecx
  Scaleform::GFx::MovieDef *v3; // ecx

  pObject = this->pImageRes.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImageRes.pObject = 0;
  v3 = this->pMovieDef.pObject;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  this->pMovieDef.pObject = 0;
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
