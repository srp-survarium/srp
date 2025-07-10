Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(this, result);
  return result;
}
