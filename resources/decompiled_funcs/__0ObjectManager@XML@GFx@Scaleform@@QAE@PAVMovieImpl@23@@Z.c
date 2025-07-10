void __thiscall Scaleform::GFx::XML::ObjectManager::ObjectManager(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::MovieImpl *powner)
{
  this->RefCount = 1;
  this->Scaleform::GFx::ExternalLibPtr::__vftable = (Scaleform::GFx::ExternalLibPtr_vtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable';
  this->pOwner = powner;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::XML::ObjectManager_vtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>'};
  this->Scaleform::GFx::ExternalLibPtr::__vftable = (Scaleform::GFx::ExternalLibPtr_vtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable'{for `Scaleform::GFx::ExternalLibPtr'};
  Scaleform::GFx::XML::DOMStringManager::DOMStringManager(&this->StringPool);
  this->pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
}
