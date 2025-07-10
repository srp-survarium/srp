void __thiscall Scaleform::GFx::AS3::VM::exec_callsupermethod(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Traits *ot,
        unsigned int method_index,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // ecx
  Scaleform::GFx::AS3::VM::Error v9; // [esp+8h] [ebp-B8h] BYREF
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+10h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = *(Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    pObject = (Scaleform::GFx::AS3::Traits *)ot->pParent.pObject;
    if ( pObject )
    {
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(this, method_index, pObject, &args.ArgObject, arg_count, FixedArr);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v9, eIllegalSuperCallError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v6,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v9.Message.pNode;
      --v9.Message.pNode->RefCount;
      if ( !pNode->RefCount )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
        return;
      }
    }
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
