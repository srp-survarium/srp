void __thiscall Scaleform::GFx::AS3::Stage::SetOrientation(
        Scaleform::GFx::AS3::Stage *this,
        const Scaleform::GFx::ASString *newOrient)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = newOrient->pNode;
  ++newOrient->pNode->RefCount;
  v4 = this->CurrentStageOrientation.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->CurrentStageOrientation.pNode = pNode;
}
