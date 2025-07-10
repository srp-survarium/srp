Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int ind; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(this, result, (Scaleform::GFx::ASStringNode *)ind, value);
    return result;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eXMLAssignmentToIndexedXMLNotAllowed, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v7);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v5 = result;
    result->Result = 0;
  }
  return v5;
}
