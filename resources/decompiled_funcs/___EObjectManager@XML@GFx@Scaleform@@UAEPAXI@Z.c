Scaleform::GFx::XML::ObjectManager *__thiscall Scaleform::GFx::XML::ObjectManager::`vector deleting destructor'(
        Scaleform::GFx::XML::ObjectManager *this,
        char a2)
{
  Scaleform::GFx::MovieImpl *pOwner; // eax

  pOwner = this->pOwner;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::XML::ObjectManager_vtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>'};
  this->Scaleform::GFx::ExternalLibPtr::__vftable = (Scaleform::GFx::ExternalLibPtr_vtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable'{for `Scaleform::GFx::ExternalLibPtr'};
  if ( pOwner )
    pOwner->pXMLObjectManager = 0;
  Scaleform::GFx::XML::DOMStringManager::~DOMStringManager(&this->StringPool);
  this->Scaleform::GFx::ExternalLibPtr::__vftable = (Scaleform::GFx::ExternalLibPtr_vtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable';
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
