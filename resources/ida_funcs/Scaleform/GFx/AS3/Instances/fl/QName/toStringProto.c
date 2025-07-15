void __cdecl Scaleform::GFx::AS3::Instances::fl::QName::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *v4; // edi
  Scaleform::GFx::AS3::Object *VObj; // ebx
  Scaleform::GFx::AS3::Classes::fl::QName *ClassQName; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const Scaleform::GFx::AS3::Value *pStringManager; // eax
  Scaleform::GFx::AS3::Instances::fl::QName *VInt; // ecx
  Scaleform::GFx::ASStringNode *v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  v4 = _this;
  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassQName = Scaleform::GFx::AS3::VM::GetClassQName(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassQName)) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v4);
    if ( ValueTraits->TraitsType != Traits_QName || (ValueTraits->Flags & 0x20) != 0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v13, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v11);
      pNode = v13.Message.pNode;
      --v13.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      pStringManager = (const Scaleform::GFx::AS3::Value *)vm->StringManagerRef->pStringManager;
      VInt = (Scaleform::GFx::AS3::Instances::fl::QName *)v4->value.VS._1.VInt;
      _this = (Scaleform::GFx::AS3::Value *)&pStringManager[2];
      ++pStringManager[2].value.VS._2.VObj;
      Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(VInt, (Scaleform::GFx::ASString *)&_this);
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&_this);
      v10 = (Scaleform::GFx::ASStringNode *)_this;
      --_this->value.VS._2.VObj;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
  }
}
