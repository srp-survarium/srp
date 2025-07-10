bool __thiscall Scaleform::GFx::ASString::Compare_CaseInsensitive_Resolved(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str)
{
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return this->pNode->pLower == str->pNode->pLower;
}
