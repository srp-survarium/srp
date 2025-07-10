void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::prefixGet(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( (_this->Flags & 0x1F) == 0xB )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::AS3::Value *)(_this->value.VS._1.VInt + 40));
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
