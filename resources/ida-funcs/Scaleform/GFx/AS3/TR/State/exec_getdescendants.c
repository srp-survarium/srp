void __thiscall Scaleform::GFx::AS3::TR::State::exec_getdescendants(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebp
  unsigned int v6; // edi
  int *Data; // edx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // edx
  int v10; // eax
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *(__thiscall *GetITraitsXMLList)(Scaleform::GFx::AS3::XMLSupport *); // edx
  Scaleform::StringDataPtr v13; // [esp-8h] [ebp-5Ch]
  Scaleform::GFx::AS3::Value v14; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::TR::ReadMnObject args; // [esp+1Ch] [ebp-38h] BYREF

  if ( this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
    v6 = WCode->Size + 1;
    if ( v6 >= WCode->Size )
    {
      if ( v6 >= WCode->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          WCode,
          WCode,
          v6 + (v6 >> 2));
    }
    else if ( v6 < WCode->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        WCode->Size + 1);
    }
    Data = WCode->Data;
    WCode->Size = v6;
    Data[v6 - 1] = mn_index;
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
    v10 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
    args.Num += v10;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
      &this->OpStack,
      (Scaleform::GFx::AS3::Value *)&args.ArgObject);
    ++args.Num;
    pObject = this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject;
    GetITraitsXMLList = pObject->GetITraitsXMLList;
    v14.Bonus.pWeakProxy = 0;
    v14.value.VS._1.VInt = (int)GetITraitsXMLList(pObject);
    v14.Flags = 8;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v14);
    Scaleform::GFx::AS3::Value::~Value(&v14);
    Scaleform::GFx::AS3::TR::ReadMnObject::~ReadMnObject(&args);
  }
  else
  {
    v13.pStr = "getdescendants";
    v13.Size = 14;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v14,
      eNotImplementedError,
      (Scaleform::String)this->pTracer->CF->pFile->VMRef,
      v13);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v3,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v14.Bonus.pWeakProxy;
    --v14.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
}
