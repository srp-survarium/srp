void __thiscall Scaleform::GFx::AS3::TR::State::exec_getdescendants(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // eax
  Scaleform::GFx::AS3::VM *v4; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v8; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // edx
  int v12; // eax
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *(__thiscall *GetITraitsXMLList)(Scaleform::GFx::AS3::XMLSupport *); // edx
  Scaleform::GFx::AS3::Value v15; // [esp+8h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::TR::ReadMnObject args; // [esp+18h] [ebp-38h] BYREF

  pTracer = this->pTracer;
  if ( this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)pTracer->WCode;
    v8 = WCode->Size + 1;
    if ( v8 >= WCode->Size )
    {
      if ( v8 >= WCode->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          WCode,
          WCode,
          v8 + (v8 >> 2));
    }
    else if ( v8 < WCode->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        WCode->Size + 1);
    }
    Data = WCode->Data;
    WCode->Size = v8;
    Data[v8 - 1] = mn_index;
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
    v12 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
    args.Num += v12;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
      &this->OpStack,
      (Scaleform::GFx::AS3::Value *)&args.ArgObject);
    ++args.Num;
    pObject = this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject;
    GetITraitsXMLList = pObject->GetITraitsXMLList;
    v15.Bonus.pWeakProxy = 0;
    v15.value.VS._1.VInt = (int)GetITraitsXMLList(pObject);
    v15.Flags = 8;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v15);
    Scaleform::GFx::AS3::Value::~Value(&v15);
    Scaleform::GFx::AS3::TR::ReadMnObject::~ReadMnObject(&args);
  }
  else
  {
    v4 = pTracer->CF->pFile->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v15, eNotImplementedError, v4);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v4,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v15.Bonus.pWeakProxy;
    --v15.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
}
