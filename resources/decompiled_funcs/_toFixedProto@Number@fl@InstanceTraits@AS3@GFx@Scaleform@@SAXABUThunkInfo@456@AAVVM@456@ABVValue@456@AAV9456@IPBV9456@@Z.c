void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Number::toFixedProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult v9; // [esp+3h] [ebp-21h] BYREF
  double v10; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value coerced_this; // [esp+14h] [ebp-10h] BYREF

  coerced_this.Flags = 0;
  coerced_this.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, &v9, &v10)->Result )
  {
    Flags = coerced_this.Flags;
    *(double *)&v11 = v10;
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
      Flags = coerced_this.Flags;
    }
    coerced_this.value.VNumber = *(double *)&v11;
    coerced_this.Flags = Flags & 0xFFFFFFE0 | 4;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toFixed(ti, vm, &coerced_this, result, argc, argv);
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
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v7);
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
