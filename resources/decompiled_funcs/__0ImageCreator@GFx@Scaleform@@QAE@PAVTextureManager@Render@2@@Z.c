void __thiscall Scaleform::GFx::ImageCreator::ImageCreator(
        Scaleform::GFx::ImageCreator *this,
        Scaleform::GFx::Resource *textureManager)
{
  this->__vftable = (Scaleform::GFx::ImageCreator_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_ImageCreator;
  this->__vftable = (Scaleform::GFx::ImageCreator_vtbl *)&Scaleform::GFx::ImageCreator::`vftable';
  if ( textureManager )
    Scaleform::RefCountImpl::AddRef(textureManager);
  this->pTextureManager.pObject = (Scaleform::Render::TextureManager *)textureManager;
}
