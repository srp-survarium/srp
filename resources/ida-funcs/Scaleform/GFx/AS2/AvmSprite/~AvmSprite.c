void __thiscall Scaleform::GFx::AS2::AvmSprite::~AvmSprite(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // edi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // ecx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmSprite_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable';
  v2 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->InitActionsExecuted.Data.Data);
  pObject = this->ASMovieClipObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS2::Environment::~Environment(&this->ASEnvironment);
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmSprite_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v2->__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>(&this->EventHandlers.mHash);
  Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(&this->Scaleform::GFx::AS2::ObjectInterface);
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmSprite_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
}
