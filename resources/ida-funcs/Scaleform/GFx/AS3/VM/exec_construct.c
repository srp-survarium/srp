void __thiscall Scaleform::GFx::AS3::VM::exec_construct(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int v3; // ecx
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // edx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const Scaleform::GFx::ASString *v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-C8h] BYREF
  Scaleform::GFx::AS3::VM::Error v12; // [esp+10h] [ebp-C0h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+18h] [ebp-B8h] BYREF
  Scaleform::GFx::AS3::ReadArgsObjectRef args; // [esp+28h] [ebp-A8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( this->HandleException )
    goto LABEL_19;
  v3 = args.ArgObject->Flags & 0x1F;
  if ( !v3 || v3 - 12 <= 3 && !args.ArgObject->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eConvertNullToObjectError, this);
LABEL_6:
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v4,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v11.Message.pNode;
LABEL_17:
    if ( !--pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_19:
    Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
    return;
  }
  if ( v3 == 7 || v3 == 17 )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, args.ArgObject);
    v8 = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&v11);
    Scaleform::GFx::AS3::Value::Value(&arg1, v8);
    Scaleform::GFx::AS3::VM::Error::Error(
      &v12,
      (Scaleform::GFx::AS3::VM_vtbl *)0x428,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    Scaleform::GFx::AS3::Value::~Value(&arg1);
    pNode = (Scaleform::GFx::ASStringNode *)v11.ID;
    goto LABEL_17;
  }
  if ( v3 - 12 > 3 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(
      &v11,
      (Scaleform::GFx::AS3::VM_vtbl *)0x45B,
      (Scaleform::GFx::ASStringNode *)this,
      args.ArgObject);
    goto LABEL_6;
  }
  FixedArr = args.FixedArr;
  if ( args.ArgNum > 8 )
    FixedArr = args.CallArgs.Data.Data;
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)args.ArgObject->value.VS._1.VInt + 48))(
    args.ArgObject->value.VS._1,
    args.ArgObject,
    arg_count,
    FixedArr,
    0);
  Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
}
