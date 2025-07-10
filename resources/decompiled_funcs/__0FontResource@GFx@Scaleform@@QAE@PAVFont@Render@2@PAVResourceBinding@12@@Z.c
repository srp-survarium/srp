void __thiscall Scaleform::GFx::FontResource::FontResource(
        Scaleform::GFx::FontResource *this,
        Scaleform::GFx::Resource *pfont,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::FontResource_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->__vftable = (Scaleform::GFx::FontResource_vtbl *)&Scaleform::GFx::FontResource::`vftable';
  this->pFont.pObject = 0;
  this->pBinding = pbinding;
  Scaleform::GFx::ResourceKey::ResourceKey((Scaleform::GFx::AS3::Value *)&this->FontKey);
  if ( pfont )
    Scaleform::RefCountImpl::AddRef(pfont);
  pObject = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  this->LowerCaseTop = 0;
  this->UpperCaseTop = 0;
}
