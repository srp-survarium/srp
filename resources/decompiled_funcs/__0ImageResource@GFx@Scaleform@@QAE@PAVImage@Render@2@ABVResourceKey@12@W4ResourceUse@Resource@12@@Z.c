void __thiscall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage,
        const Scaleform::GFx::ResourceKey *key,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // edi
  Scaleform::Render::ImageBase *v6; // ecx
  Scaleform::Render::Image *v7; // ecx
  Scaleform::Render::Image *pObject; // eax

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
  v6 = this->pImage;
  if ( v6 && v6 != p_Delegate )
    v6->Release(v6);
  v7 = pimage;
  if ( pimage )
  {
    pimage->AddRef(pimage);
    v7 = pimage;
  }
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
  {
    pObject->Release(this->Delegate.pImage.pObject);
    v7 = pimage;
  }
  this->Delegate.pImage.pObject = v7;
  this->pImage = p_Delegate;
  Scaleform::GFx::ResourceKey::operator=(&this->Key, key);
  this->UseType = use;
}
