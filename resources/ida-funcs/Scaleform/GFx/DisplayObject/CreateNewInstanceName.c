Scaleform::GFx::ASString *__thiscall Scaleform::GFx::DisplayObject::CreateNewInstanceName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v3; // eax
  Scaleform::GFx::ASString resulta; // [esp+0h] [ebp-4h] BYREF

  resulta.pNode = (Scaleform::GFx::ASStringNode *)this;
  pNode = Scaleform::GFx::MovieImpl::CreateNewInstanceName(this->pASRoot->pMovieImpl, &resulta)->pNode;
  ++pNode->RefCount;
  result->pNode = pNode;
  v3 = resulta.pNode;
  --resulta.pNode->RefCount;
  if ( !v3->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  return result;
}
