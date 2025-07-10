Scaleform::GFx::AS2::TextSnapshotObject *__thiscall Scaleform::GFx::AS2::TextSnapshotObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::TextSnapshotObject *this,
        char a2)
{
  Scaleform::GFx::StaticTextSnapshotData *p_SnapshotData; // ebx
  volatile LONG *v4; // edi

  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextSnapshotObject_vtbl *)&Scaleform::GFx::AS2::TextSnapshotObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  p_SnapshotData = &this->SnapshotData;
  v4 = (volatile LONG *)(this->SnapshotData.SnapshotString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(&p_SnapshotData->StaticTextCharRefs.Data);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
