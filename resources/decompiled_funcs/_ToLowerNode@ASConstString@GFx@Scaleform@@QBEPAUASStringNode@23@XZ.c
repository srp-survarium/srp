Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::ToLowerNode(
        Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *result; // eax

  pNode = this->pNode;
  if ( !pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
  result = this->pNode->pLower;
  if ( !result )
    return &this->pNode->pManager->EmptyStringNode;
  return result;
}
