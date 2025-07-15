void __thiscall Scaleform::GFx::AS3::VM::exec_callsupermethod(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Traits *ot,
        unsigned int method_index,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::Traits *pObject; // eax
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // ecx
  Scaleform::StringDataPtr v9; // [esp-8h] [ebp-C8h]
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-B8h] BYREF
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+10h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    pObject = ot->pParent.pObject;
    if ( pObject )
    {
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(this, method_index, pObject, &args.ArgObject, arg_count, FixedArr);
    }
    else
    {
      v9.pStr = "Couldn't find parent property";
      v9.Size = 29;
      Scaleform::GFx::AS3::VM::Error::Error(&v10, eIllegalSuperCallError, (Scaleform::String)this, v9);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v6,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v10.Message.pNode;
      --v10.Message.pNode->RefCount;
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
