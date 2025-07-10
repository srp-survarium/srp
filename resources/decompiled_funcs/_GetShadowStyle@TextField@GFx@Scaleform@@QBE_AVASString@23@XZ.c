Scaleform::GFx::ASString *__thiscall Scaleform::GFx::TextField::GetShadowStyle(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *result)
{
  char v2; // bl
  Scaleform::GFx::TextField::ShadowParams *pShadow; // eax
  Scaleform::GFx::ASStringNode **p_pNode; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::ASStringNode *v9; // [esp+8h] [ebp-4h] BYREF

  v2 = 0;
  v9 = 0;
  pShadow = this->pShadow;
  if ( pShadow )
  {
    p_pNode = &pShadow->ShadowStyleStr.pNode;
    p_EmptyStringNode = v9;
  }
  else
  {
    v2 = 1;
    p_EmptyStringNode = &Scaleform::GFx::InteractiveObject::GetStringManager(this)->EmptyStringNode;
    ++p_EmptyStringNode->RefCount;
    v9 = p_EmptyStringNode;
    p_pNode = &v9;
  }
  v6 = *p_pNode;
  ++v6->RefCount;
  result->pNode = v6;
  if ( (v2 & 1) != 0 && p_EmptyStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  return result;
}
