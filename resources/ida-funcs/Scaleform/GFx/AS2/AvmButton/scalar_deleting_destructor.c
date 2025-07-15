Scaleform::GFx::AS2::AvmButton *__thiscall Scaleform::GFx::AS2::AvmButton::`scalar deleting destructor'(
        Scaleform::GFx::AS2::AvmButton *this,
        unsigned int a2)
{
  Scaleform::GFx::AS2::ButtonObject *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->ASButtonObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmButtonBase_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmButton_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>(&this->EventHandlers.mHash);
  Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(&this->Scaleform::GFx::AS2::ObjectInterface);
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmButton_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  return this;
}
