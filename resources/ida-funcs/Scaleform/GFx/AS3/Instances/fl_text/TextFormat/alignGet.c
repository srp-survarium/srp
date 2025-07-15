void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::alignGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // edi
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  if ( (this->mAlign.Flags & 0x1F) - 12 > 3 || this->mAlign.value.VS._1.VInt )
  {
    VStr = this->mAlign.value.VS._1.VStr;
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
