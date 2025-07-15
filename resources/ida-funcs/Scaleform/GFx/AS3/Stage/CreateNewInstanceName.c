Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Stage::CreateNewInstanceName(
        Scaleform::GFx::AS3::Stage *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  bool v4; // zf

  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  p_EmptyStringNode = &pObject->GetStringManager(pObject)->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v4 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  result->pNode = p_EmptyStringNode;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  return result;
}
