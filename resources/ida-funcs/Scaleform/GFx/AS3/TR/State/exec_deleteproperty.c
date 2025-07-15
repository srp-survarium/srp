void __thiscall Scaleform::GFx::AS3::TR::State::exec_deleteproperty(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebx
  unsigned int v4; // edi
  int *Data; // ecx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // edx
  int v8; // eax
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::TR::ReadMnObject args; // [esp+1Ch] [ebp-38h] BYREF

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
  Data[v4 - 1] = mn_index;
  pFile = this->pTracer->CF->pFile;
  VMRef = pFile->VMRef;
  args.File = pFile;
  args.VMRef = VMRef;
  args.StateRef = this;
  args.Num = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &args.ArgMN,
    pFile,
    &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
  v8 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
  args.Num += v8;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    (Scaleform::GFx::AS3::Value *)&args.ArgObject);
  ++args.Num;
  val.value.VS._1.VInt = (int)this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  val.Bonus.pWeakProxy = 0;
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
  Scaleform::GFx::AS3::TR::ReadMnObject::~ReadMnObject(&args);
}
