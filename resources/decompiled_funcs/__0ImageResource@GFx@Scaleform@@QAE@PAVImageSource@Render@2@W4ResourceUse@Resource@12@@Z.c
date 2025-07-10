void __thiscall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageSrc,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // edi
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::ImageBase *v7; // ecx

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
  pImage = this->pImage;
  if ( pImage && pImage != p_Delegate )
    pImage->Release(pImage);
  this->pImage = pimageSrc;
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->Delegate.pImage.pObject = 0;
  v7 = this->pImage;
  if ( v7 )
    v7->AddRef(v7);
  this->UseType = use;
}
