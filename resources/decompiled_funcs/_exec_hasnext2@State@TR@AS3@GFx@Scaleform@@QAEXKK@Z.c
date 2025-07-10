void __thiscall Scaleform::GFx::AS3::TR::State::exec_hasnext2(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int object_reg,
        unsigned int index_reg)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v5; // esi
  int *Data; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v7; // edi
  unsigned int v8; // esi
  int *v9; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-10h] BYREF

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v5 = WCode->Size + 1;
  if ( v5 >= WCode->Size )
  {
    if ( v5 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v5 + (v5 >> 2));
  }
  else if ( v5 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v5;
  Data[v5 - 1] = object_reg;
  v7 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v8 = v7->Size + 1;
  if ( v8 >= v7->Size )
  {
    if ( v8 >= v7->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v7,
        v7,
        v8 + (v8 >> 2));
  }
  else if ( v8 < v7->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v7,
      v7,
      v7->Size + 1);
  }
  v9 = v7->Data;
  v7->Size = v8;
  v9[v8 - 1] = index_reg;
  pObject = this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)pObject;
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
}
