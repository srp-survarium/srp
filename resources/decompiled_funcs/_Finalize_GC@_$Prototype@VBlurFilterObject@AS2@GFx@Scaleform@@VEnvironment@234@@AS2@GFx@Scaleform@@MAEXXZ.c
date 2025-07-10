void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BlurFilterObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFilter.pObject = 0;
}
