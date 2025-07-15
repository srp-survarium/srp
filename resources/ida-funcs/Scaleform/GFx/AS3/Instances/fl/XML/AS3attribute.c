void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3attribute(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        const Scaleform::GFx::AS3::Value *arg)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *XMLListInstance; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-30h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+10h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( (arg->Flags & 0x1F) != 0 && ((arg->Flags & 0x1F) - 12 > 3 || arg->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, pVM, arg);
    prop_name.Kind |= 8u;
    if ( !pVM->HandleException )
    {
      XMLListInstance = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
                          this,
                          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&arg,
                          (Scaleform::GFx::AS3::SoundObject *)&prop_name);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        result,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)XMLListInstance->pV);
      this->GetProperty(this, (Scaleform::GFx::AS3::CheckResult *)&arg, &prop_name, result->pObject);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  }
  else
  {
    v8.pStr = "arg";
    v8.Size = 3;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eInvalidArgumentError, pVM, v8);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
