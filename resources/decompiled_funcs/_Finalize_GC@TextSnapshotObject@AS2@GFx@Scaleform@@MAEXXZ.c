void __thiscall Scaleform::GFx::AS2::TextSnapshotObject::Finalize_GC(Scaleform::GFx::AS2::TextSnapshotObject *this)
{
  Scaleform::GFx::StaticTextSnapshotData *p_SnapshotData; // ebx
  volatile LONG *v3; // esi

  p_SnapshotData = &this->SnapshotData;
  v3 = (volatile LONG *)(this->SnapshotData.SnapshotString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(&p_SnapshotData->StaticTextCharRefs.Data);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
