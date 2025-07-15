void __thiscall Scaleform::GFx::AS3::TR::State::exec_newarray(Scaleform::GFx::AS3::TR::State *this, int arr_size)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-B0h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgs args; // [esp+1Ch] [ebp-A0h] BYREF

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
  Data[v4 - 1] = arr_size;
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&args, this->pTracer->CF->pFile->VMRef, this, arr_size);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)pObject;
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
  Scaleform::GFx::AS3::TR::ReadArgs::~ReadArgs(&args);
}
