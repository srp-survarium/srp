void __thiscall Scaleform::GFx::MovieDataDef::SceneInfo::AddFrameLabel(
        Scaleform::GFx::MovieDataDef::SceneInfo *this,
        const Scaleform::String *n,
        unsigned int num)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *v3; // esi
  unsigned int Capacity; // eax
  const void *Size; // ecx
  Scaleform::StringDH *p_Name; // esi
  void *v7; // esi
  Scaleform::StringDH v8; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v9; // [esp+Ch] [ebp-4h]

  v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *)this;
  Scaleform::StringDH::CopyConstructHelper(&v8, n, this->Name.pHeap);
  Capacity = v3[1].Policy.Capacity;
  Size = (const void *)v3[2].Size;
  v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v3 + 16);
  v9 = num;
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v3,
    Size,
    Capacity + 1);
  p_Name = &v3->Data[v3->Size - 1].Name;
  if ( p_Name )
  {
    Scaleform::StringDH::CopyConstructHelper(p_Name, &v8, v8.pHeap);
    p_Name[1].HeapTypeBits = v9;
  }
  v7 = (void *)(v8.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v8.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
