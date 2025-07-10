void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextSnapshotObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextSnapshotObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  volatile LONG *v3; // esi

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  v3 = (volatile LONG *)(this->SnapshotData.SnapshotString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(&this->SnapshotData.StaticTextCharRefs.Data);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
