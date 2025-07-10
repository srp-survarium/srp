void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  Scaleform::GFx::ImageResource *pObject; // ecx
  Scaleform::GFx::MovieDef *v4; // ecx

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  pObject = this->pImageRes.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImageRes.pObject = 0;
  v4 = this->pMovieDef.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  this->pMovieDef.pObject = 0;
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
