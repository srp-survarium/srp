void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::XML::PropertyIsEnumerableProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // eax
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Object *VObj; // ebx
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v11; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v12; // [esp+Ch] [ebp-8h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (v6 = vm->XMLSupport_.pObject->GetITraitsXML(vm->XMLSupport_.pObject),
        Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v6),
        VObj = _this->value.VS._1.VObj,
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(Constructor)) )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);
  }
  else if ( (_this->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(_this->value.VS._1.VObj) )
  {
    Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable(
      (Scaleform::GFx::AS3::Instances::fl::XML *)_this->value.VS._1.VInt,
      result,
      (unsigned int)argc.pNode,
      argv);
  }
  else
  {
    v11.pStr = "XML::PropertyIsEnumerableProto";
    v11.Size = 30;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvokeOnIncompatibleObjectError, vm, v11);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v9);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
