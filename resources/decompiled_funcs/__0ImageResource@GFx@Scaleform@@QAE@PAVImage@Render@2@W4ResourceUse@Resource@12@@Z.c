void __thiscall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // edi
  Scaleform::Render::ImageBase *v5; // ecx
  Scaleform::Render::Image *pObject; // ecx

  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  p_Delegate = &this->Delegate;
  this->pLib = 0;
  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::ImageResource::`vftable';
  this->pImage = 0;
  this->Delegate.__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Delegate.RefCount = 1;
  this->Delegate.__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->Delegate.pTexture, 0);
  p_Delegate->pUpdateSync = 0;
  p_Delegate->pInverseMatrix = 0;
  p_Delegate->pImage.pObject = 0;
  p_Delegate->__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable';
  Scaleform::GFx::ResourceKey::ResourceKey((Scaleform::GFx::AS3::Value *)&this->Key);
  v5 = this->pImage;
  if ( v5 && v5 != p_Delegate )
    v5->Release(v5);
  if ( pimage )
    pimage->AddRef(pimage);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->Delegate.pImage.pObject = pimage;
  this->pImage = p_Delegate;
  this->UseType = use;
}
