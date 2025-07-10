void __thiscall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageBase,
        Scaleform::GFx::Resource::ResourceUse use)
{
  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::ImageResource::`vftable';
  this->pImage = 0;
  this->Delegate.__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Delegate.RefCount = 1;
  this->Delegate.__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->Delegate.pTexture, 0);
  this->Delegate.pUpdateSync = 0;
  this->Delegate.pInverseMatrix = 0;
  this->Delegate.pImage.pObject = 0;
  this->Delegate.__vftable = (Scaleform::GFx::ImageResource::ImageDelegate_vtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable';
  Scaleform::GFx::ResourceKey::ResourceKey((Scaleform::GFx::AS3::Value *)&this->Key);
  this->UseType = use;
  if ( pimageBase )
  {
    if ( pimageBase->GetImageType(pimageBase) )
      Scaleform::GFx::ImageResource::SetImageSource(this, pimageBase);
    else
      Scaleform::GFx::ImageResource::SetImage(this, (Scaleform::Render::Image *)pimageBase);
  }
}
