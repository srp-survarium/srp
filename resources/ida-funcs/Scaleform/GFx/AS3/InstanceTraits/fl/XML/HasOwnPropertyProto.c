void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::XML::HasOwnPropertyProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v7; // eax
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Object *VObj; // ebx
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::AS3::Value::V1U v11; // ecx
  char v12; // al
  Scaleform::GFx::ASStringNode *v13; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-1Ch]
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v18; // [esp+Ch] [ebp-8h] BYREF

  v6 = _this;
  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    v7 = vm->XMLSupport_.pObject->GetITraitsXML(vm->XMLSupport_.pObject);
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v7);
    VObj = v6->value.VS._1.VObj;
    if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(Constructor) )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(ti, vm, v6, result, argc, argv);
      return;
    }
  }
  if ( (v6->Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::IsXMLObject(v6->value.VS._1.VObj) )
  {
    v16.pStr = "XML::HasOwnPropertyProto";
    v16.Size = 24;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvokeOnIncompatibleObjectError, vm, v16);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v10);
    goto LABEL_12;
  }
  v11 = v6->value.VS._1;
  if ( !argc || (argv->Flags & 0x1F) != 0xA )
  {
    v17.pStr = "XML::HasOwnPropertyProto";
    v17.Size = 24;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvalidArgumentError, vm, v17);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(vm, v14);
LABEL_12:
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  _this = (Scaleform::GFx::AS3::Value *)argv->value.VS._1.VInt;
  ++_this->value.VS._2.VObj;
  v12 = (*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value **))(*(_DWORD *)v11.VInt + 116))(
          v11,
          &_this);
  Scaleform::GFx::AS3::Value::SetBool(result, v12);
  v13 = (Scaleform::GFx::ASStringNode *)_this;
  --_this->value.VS._2.VObj;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}
