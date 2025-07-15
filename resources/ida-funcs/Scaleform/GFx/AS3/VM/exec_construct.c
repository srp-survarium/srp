void __thiscall Scaleform::GFx::AS3::VM::exec_construct(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int v3; // eax
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+8h] [ebp-B0h] BYREF
  Scaleform::GFx::AS3::ReadArgsObjectRef args; // [esp+10h] [ebp-A8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( this->HandleException )
    goto LABEL_16;
  v3 = args.ArgObject->Flags & 0x1F;
  if ( !v3 || v3 - 12 <= 3 && !args.ArgObject->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eConvertNullToObjectError, this);
    goto LABEL_14;
  }
  if ( v3 == 7 || v3 == 17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eCannotCallMethodAsConstructor, this);
LABEL_14:
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v4,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_16:
    Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
    return;
  }
  if ( v3 - 12 > 3 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eNotConstructorError, this);
    goto LABEL_14;
  }
  FixedArr = args.FixedArr;
  if ( args.ArgNum > 8 )
    FixedArr = args.CallArgs.Data.Data;
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)args.ArgObject->value.VS._1.VInt + 36))(
    args.ArgObject->value.VS._1,
    args.ArgObject,
    arg_count,
    FixedArr,
    0);
  Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
}
