void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const Scaleform::String *name,
        unsigned int off)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> > *p_Scenes; // ebx
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v5; // eax
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::SceneInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieDataDef::SceneInfo,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // esi
  void *v8; // esi
  Scaleform::GFx::MovieDataDef::SceneInfo v9; // [esp+Ch] [ebp-20h] BYREF

  p_Scenes = &this->Scenes;
  if ( !this->Scenes.pObject )
  {
    v5 = (Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *)this->pHeap->Alloc(this->pHeap, 12, 0);
    if ( v5 )
    {
      v5->Data.Data = 0;
      v5->Data.Size = 0;
      v5->Data.Policy.Capacity = 0;
    }
    else
    {
      v5 = 0;
    }
    Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy>>::operator=(
      p_Scenes,
      v5);
  }
  pHeap = this->pHeap;
  Scaleform::StringDH::CopyConstructHelper(&v9.Name, name, pHeap);
  v9.Labels.Data.pHeap = pHeap;
  p_Data = &p_Scenes->pObject->Data;
  v9.Offset = off;
  memset(&v9.NumFrames, 0, 16);
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::SceneInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieDataDef::SceneInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_Data,
    p_Data,
    p_Data->Size + 1);
  if ( &p_Data->Data[p_Data->Size] != (Scaleform::GFx::MovieDataDef::SceneInfo *)32 )
    Scaleform::GFx::MovieDataDef::SceneInfo::SceneInfo(&p_Data->Data[p_Data->Size - 1], &v9);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
    v9.Labels.Data.Data,
    v9.Labels.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9.Labels.Data.Data);
  v8 = (void *)(v9.Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v9.Name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
}
