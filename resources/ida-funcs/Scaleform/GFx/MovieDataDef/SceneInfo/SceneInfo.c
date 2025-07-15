void __thiscall Scaleform::GFx::MovieDataDef::SceneInfo::SceneInfo(
        Scaleform::GFx::MovieDataDef::SceneInfo *this,
        const Scaleform::GFx::MovieDataDef::SceneInfo *__that)
{
  Scaleform::MemoryHeap *pHeap; // eax
  unsigned int Size; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *src; // [esp+14h] [ebp+4h]

  Scaleform::StringDH::CopyConstructHelper(&this->Name, &__that->Name, __that->Name.pHeap);
  this->Offset = __that->Offset;
  this->NumFrames = __that->NumFrames;
  this->Labels.Data.Data = 0;
  this->Labels.Data.Size = 0;
  this->Labels.Data.Policy.Capacity = 0;
  pHeap = (Scaleform::MemoryHeap *)__that->Labels.Data.pHeap;
  this->Labels.Data.pHeap = pHeap;
  Size = __that->Labels.Data.Size;
  src = __that->Labels.Data.Data;
  if ( Size )
  {
    v5 = this->Labels.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Labels.Data,
      pHeap,
      v5 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::ConstructArray(
      &this->Labels.Data.Data[v5].Name,
      Size,
      src);
  }
}
