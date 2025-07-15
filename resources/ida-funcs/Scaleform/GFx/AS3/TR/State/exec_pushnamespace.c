void __thiscall Scaleform::GFx::AS3::TR::State::exec_pushnamespace(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value v9; // [esp+Ch] [ebp-10h] BYREF

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = (int)v;
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this->pTracer->CF->pFile, v);
  Scaleform::GFx::AS3::Value::Value(&v9, InternedNamespace);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    v7);
  if ( (v9.Flags & 0x1F) > 9 )
  {
    if ( (v9.Flags & 0x200) != 0 )
    {
      pWeakProxy = v9.Bonus.pWeakProxy;
      --v9.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
    }
  }
}
