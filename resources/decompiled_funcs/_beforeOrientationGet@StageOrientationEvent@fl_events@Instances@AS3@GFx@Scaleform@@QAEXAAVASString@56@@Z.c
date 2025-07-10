void __thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::beforeOrientationGet(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // edi
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  if ( (this->BeforeOrientation.Flags & 0x1F) - 12 > 3 || this->BeforeOrientation.value.VS._1.VInt )
  {
    VStr = this->BeforeOrientation.value.VS._1.VStr;
    v2 = result;
  }
  else
  {
    v2 = result;
    VStr = &result->pNode->pManager->NullStringNode;
  }
  ++VStr->RefCount;
  pNode = v2->pNode;
  if ( v2->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v2->pNode = VStr;
}
