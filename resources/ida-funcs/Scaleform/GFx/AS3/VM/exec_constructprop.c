void __thiscall Scaleform::GFx::AS3::VM::exec_constructprop(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::AS3::Value *FixedArr; // eax
  int v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::Value *Data; // eax
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-F1h] BYREF
  Scaleform::GFx::AS3::VM::Error v17; // [esp+14h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+1Ch] [ebp-E8h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+2Ch] [ebp-D8h] BYREF
  Scaleform::GFx::AS3::ReadArgsMnObjectRef args; // [esp+44h] [ebp-C0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( this->HandleException )
    goto LABEL_33;
  if ( (args.ArgMN.Kind & 3) == 0 || (args.ArgMN.Kind & 3) == 1 )
  {
    v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
           this,
           &args.ArgMN,
           (Scaleform::GFx::ASStringNode *)file->AppDomain);
    if ( v5 )
    {
      pNode = v5[25].pNode;
      if ( !pNode[2].Size )
        (*((void (__thiscall **)(Scaleform::GFx::ASStringNode *))pNode->pData + 11))(pNode);
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)pNode[2].Size + 36))(
        pNode[2].Size,
        args.ArgObject,
        arg_count,
        FixedArr,
        0);
      goto LABEL_33;
    }
  }
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::FindObjProperty(
    &prop,
    this,
    args.ArgObject,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
    FindGet);
  if ( (prop.This.Flags & 0x1F) == 0
    || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0
    || ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eReadSealedError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v14,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v15 = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    goto LABEL_32;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &result, this, &value, valGet)->Result )
  {
LABEL_21:
    Scaleform::GFx::AS3::Value::~Value(&value);
LABEL_32:
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
LABEL_33:
    Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
    Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
    return;
  }
  v8 = value.Flags & 0x1F;
  if ( (value.Flags & 0x1F) == 0 || (unsigned int)(v8 - 12) <= 3 && !value.value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eConvertNullToObjectError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    goto LABEL_21;
  }
  if ( v8 == 7 || v8 == 17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eCannotCallMethodAsConstructor, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v12,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v13 = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    Data = args.FixedArr;
    if ( args.ArgNum > 8 )
      Data = args.CallArgs.Data.Data;
    (*(void (__stdcall **)(Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)value.value.VS._1.VInt + 36))(
      args.ArgObject,
      arg_count,
      Data,
      0);
  }
  Scaleform::GFx::AS3::Value::~Value(&value);
  Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  Scaleform::GFx::AS3::ReadArgsMnObjectRef::~ReadArgsMnObjectRef(&args);
}
