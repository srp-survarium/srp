void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::orientationGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pScrollRect; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pScrollRect = (Scaleform::GFx::ASStringNode *)this->pDispObj.pObject[1].pScrollRect;
  ++pScrollRect->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = pScrollRect;
}
