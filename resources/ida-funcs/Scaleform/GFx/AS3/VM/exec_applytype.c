void __thiscall Scaleform::GFx::AS3::VM::exec_applytype(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // eax
  Scaleform::GFx::AS3::Class *v6; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-B0h] BYREF
  Scaleform::GFx::AS3::ReadArgsObjectRef args; // [esp+Ch] [ebp-A8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException )
  {
    if ( (args.ArgObject->Flags & 0x1F) == 0xD )
    {
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      v6 = (Scaleform::GFx::AS3::Class *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, const unsigned int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)args.ArgObject->value.VS._1.VInt + 76))(
                                           args.ArgObject->value.VS._1,
                                           args.ArgNum,
                                           FixedArr);
      Scaleform::GFx::AS3::Value::Assign(args.ArgObject, v6);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v7, eTypeAppOfNonParamType, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v3,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v7.Message.pNode;
      --v7.Message.pNode->RefCount;
      if ( !pNode->RefCount )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
        return;
      }
    }
  }
  Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
}
