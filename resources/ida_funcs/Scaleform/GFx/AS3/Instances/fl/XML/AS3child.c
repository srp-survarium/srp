void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3child(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        const Scaleform::GFx::AS3::Value *propertyName)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *XMLListInstance; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+10h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( (propertyName->Flags & 0x1F) != 0 && ((propertyName->Flags & 0x1F) - 12 > 3 || propertyName->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, pVM, propertyName);
    if ( !pVM->HandleException )
    {
      XMLListInstance = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
                          this,
                          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&propertyName,
                          (Scaleform::GFx::AS3::SoundObject *)&prop_name);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        result,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)XMLListInstance->pV);
      this->GetProperty(this, (Scaleform::GFx::AS3::CheckResult *)&propertyName, &prop_name, result->pObject);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvalidArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
