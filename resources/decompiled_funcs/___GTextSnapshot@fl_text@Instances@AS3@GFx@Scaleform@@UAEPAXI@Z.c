Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *__thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        char a2)
{
  Scaleform::GFx::StaticTextSnapshotData *p_SnapshotData; // ebx
  volatile LONG *v4; // esi

  p_SnapshotData = &this->SnapshotData;
  v4 = (volatile LONG *)(this->SnapshotData.SnapshotString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(&p_SnapshotData->StaticTextCharRefs.Data);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
