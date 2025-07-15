bool __thiscall Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str,
        bool caseSensitive)
{
  if ( caseSensitive )
    return this->pNode == str->pNode;
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return this->pNode->pLower == str->pNode->pLower;
}
