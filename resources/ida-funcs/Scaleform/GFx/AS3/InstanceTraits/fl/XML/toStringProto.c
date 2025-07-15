void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::XML::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // eax
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Object *VObj; // ebx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *VInt; // ecx
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::StringDataPtr v12; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v13; // [esp+Ch] [ebp-8h] BYREF

  v4 = (const Scaleform::GFx::AS3::Value *)_this;
  if ( ((int)_this->pData & 0x1Fu) - 12 <= 3
    && (v5 = vm->XMLSupport_.pObject->GetITraitsXML(vm->XMLSupport_.pObject),
        Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v5),
        VObj = v4->value.VS._1.VObj,
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(Constructor)) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else if ( (v4->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(v4->value.VS._1.VObj) )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::XML *)v4->value.VS._1.VInt;
    _this = vm->StringManagerRef->Builtins[0].pNode;
    ++_this->RefCount;
    Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(VInt, (Scaleform::GFx::ASString *)&_this);
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&_this);
    v11 = _this;
    --_this->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    v12.pStr = "XML::toStringProto";
    v12.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eInvokeOnIncompatibleObjectError, vm, v12);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v8);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
