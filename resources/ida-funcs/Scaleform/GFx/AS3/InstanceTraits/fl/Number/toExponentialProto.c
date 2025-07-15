void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Number::toExponentialProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Value *v6; // ebp
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *pObject; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebp
  const char *pData; // eax
  const char *v11; // eax
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-10h] [ebp-40h]
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-38h]
  Scaleform::GFx::AS3::CheckResult v18; // [esp+Fh] [ebp-21h] BYREF
  Scaleform::GFx::ASStringNode *v19[2]; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value coerced_this; // [esp+20h] [ebp-10h] BYREF

  v6 = _this;
  coerced_this.Flags = 0;
  coerced_this.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, &v18, (long double *)v19)->Result )
  {
    Flags = coerced_this.Flags;
    v20 = *(Scaleform::GFx::AS3::VM::Error *)v19;
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
      Flags = coerced_this.Flags;
    }
    coerced_this.value.VNumber = *(double *)&v20;
    coerced_this.Flags = Flags & 0xFFFFFFE0 | 4;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toExponential(ti, vm, &coerced_this, result, argc, argv);
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
      {
LABEL_9:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
        return;
      }
      goto LABEL_23;
    }
  }
  else
  {
    pObject = vm->TraitsNumber.pObject;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v6);
    pData = pObject->GetName(pObject, (Scaleform::GFx::ASString *)v19)->pNode->pData;
    v17.Size = (unsigned int)pData;
    if ( pData )
      strlen(pData);
    v17.pStr = (const char *)&_this;
    v11 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
    v16.pStr = v11;
    if ( v11 )
      v12 = strlen(v11);
    else
      v12 = 0;
    v16.Size = v12;
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eCheckTypeFailedError, vm, v16, v17);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v13);
    pNode = v20.Message.pNode;
    --v20.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !--vm->StringManagerRef )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)vm);
    v15 = v19[0];
    --v19[0]->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        goto LABEL_9;
LABEL_23:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
    }
  }
}
