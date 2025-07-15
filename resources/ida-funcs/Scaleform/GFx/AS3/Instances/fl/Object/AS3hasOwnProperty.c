void __cdecl Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Value *v6; // edi
  unsigned int v7; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // eax
  Scaleform::GFx::AS3::Object *VObj; // edi
  const Scaleform::GFx::AS3::Multiname *v13; // eax
  bool v14; // al
  Scaleform::GFx::AS3::Value *v15; // ecx
  const Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  Scaleform::StringDataPtr v18; // [esp-14h] [ebp-5Ch]
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // [esp-Ch] [ebp-54h]
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-3Ch] BYREF
  unsigned int index; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::ASStringNode *v22; // [esp+14h] [ebp-34h]
  Scaleform::GFx::AS3::PropRef r; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname v24; // [esp+30h] [ebp-18h] BYREF

  v6 = _this;
  v7 = _this->Flags & 0x1F;
  if ( !v7 || v7 - 12 <= 3 && !_this->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&index, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v8);
    pNode = v22;
    goto LABEL_15;
  }
  if ( !argc )
  {
    v18.pStr = "Object::AS3hasOwnProperty";
    v18.Size = 25;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&index,
      eWrongArgumentCountError,
      vm,
      v18,
      1,
      1,
      0);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(vm, v10);
    pNode = v22;
LABEL_15:
    if ( !--pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( v7 - 12 > 3 )
  {
    v15 = argv;
    name.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
    ++name.pNode->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(v15, (Scaleform::GFx::AS3::CheckResult *)&_this, &name)->Result )
    {
      pObject = vm->PublicNamespace.pObject;
      index = 0;
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v6);
      FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(ValueTraits, &name, pObject, &index, 0);
      Scaleform::GFx::AS3::Value::SetBool(result, FixedSlot != 0);
    }
    pNode = name.pNode;
    goto LABEL_15;
  }
  v11 = vm->PublicNamespace.pObject;
  VObj = _this->value.VS._1.VObj;
  memset(&r, 0, 16);
  Scaleform::GFx::AS3::Multiname::Multiname(&v24, v11, argv);
  Scaleform::GFx::AS3::Object::FindProperty(VObj, &r, v13, FindSet);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v24);
  v14 = Scaleform::GFx::AS3::PropRef::operator bool(&r);
  Scaleform::GFx::AS3::Value::SetBool(result, v14);
  if ( (r.This.Flags & 0x1F) > 9 )
  {
    if ( (r.This.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r.This);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r.This);
  }
}
