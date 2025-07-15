void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::int_::toFixedProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Value *v6; // ebp
  unsigned int Flags; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *pObject; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebp
  const char *pData; // eax
  const char *v12; // eax
  unsigned int v13; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::StringDataPtr v17; // [esp-10h] [ebp-3Ch]
  Scaleform::StringDataPtr v18; // [esp-8h] [ebp-34h]
  Scaleform::GFx::AS3::CheckResult v19; // [esp+Fh] [ebp-1Dh] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v21; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value coerced_this; // [esp+1Ch] [ebp-10h] BYREF

  v6 = _this;
  coerced_this.Flags = 0;
  coerced_this.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(_this, &v19, (int *)&v20)->Result )
  {
    Flags = coerced_this.Flags;
    v8 = v20;
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
      Flags = coerced_this.Flags;
    }
    coerced_this.Flags = Flags & 0xFFFFFFE0 | 2;
    *(_QWORD *)&coerced_this.value.VNumber = __PAIR64__((unsigned int)v21.Message.pNode, (unsigned int)v8);
    Scaleform::GFx::AS3::InstanceTraits::fl::int_::AS3toFixed(ti, vm, &coerced_this, result, argc, argv);
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
    pObject = vm->TraitsInt.pObject;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v6);
    pData = pObject->GetName(pObject, (Scaleform::GFx::ASString *)&v20)->pNode->pData;
    v18.Size = (unsigned int)pData;
    if ( pData )
      strlen(pData);
    v18.pStr = (const char *)&_this;
    v12 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
    v17.pStr = v12;
    if ( v12 )
      v13 = strlen(v12);
    else
      v13 = 0;
    v17.Size = v13;
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eCheckTypeFailedError, vm, v17, v18);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v14);
    pNode = v21.Message.pNode;
    --v21.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !--vm->StringManagerRef )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)vm);
    v16 = v20;
    --v20->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( (coerced_this.Flags & 0x1F) > 9 )
    {
      if ( (coerced_this.Flags & 0x200) != 0 )
        goto LABEL_9;
LABEL_23:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced_this);
    }
  }
}
