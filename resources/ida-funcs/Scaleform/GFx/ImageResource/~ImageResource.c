void __thiscall Scaleform::GFx::ImageResource::~ImageResource(Scaleform::GFx::ImageResource *this)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  Scaleform::Render::Image *pObject; // ecx

  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::ImageResource::`vftable';
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveImage(Instance, this);
  pImage = this->pImage;
  if ( pImage && pImage != &this->Delegate )
    pImage->Release(pImage);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->Release(pKeyInterface, this->Key.hKeyData);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::Render::Image::~Image(&this->Delegate);
  this->__vftable = (Scaleform::GFx::ImageResource_vtbl *)&Scaleform::GFx::Resource::`vftable';
}
