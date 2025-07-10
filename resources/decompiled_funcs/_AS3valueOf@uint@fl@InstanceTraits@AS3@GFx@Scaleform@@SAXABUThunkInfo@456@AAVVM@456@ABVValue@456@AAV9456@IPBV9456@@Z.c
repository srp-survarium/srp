void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3valueOf(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v4; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+0h] [ebp-8h] BYREF

  v4 = _this->Flags & 0x1F;
  if ( v4 == 2 || v4 == 3 )
  {
    Scaleform::GFx::AS3::Value::SetUInt32(result, _this->value.VS._1.VUInt);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v5);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
