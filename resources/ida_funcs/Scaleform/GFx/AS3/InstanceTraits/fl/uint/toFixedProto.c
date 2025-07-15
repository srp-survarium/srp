void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::uint::toFixedProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM::ErrorID ID; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult v10; // [esp+7h] [ebp-19h] BYREF
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value coerced_this; // [esp+10h] [ebp-10h] BYREF

  coerced_this.Flags = 0;
  coerced_this.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(_this, &v10, (unsigned int *)&v11)->Result )
  {
    Flags = coerced_this.Flags;
    ID = v11.ID;
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
      Flags = coerced_this.Flags;
    }
    coerced_this.Flags = Flags & 0xFFFFFFE0 | 3;
    *(_QWORD *)&coerced_this.value.VNumber = __PAIR64__((unsigned int)v11.Message.pNode, ID);
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toFixed(ti, vm, &coerced_this, result, argc, argv);
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
      {
LABEL_9:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
        return;
      }
      goto LABEL_14;
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v8);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        goto LABEL_9;
LABEL_14:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
    }
  }
}
