void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        const Scaleform::GFx::ASString *t)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = t->pNode;
  ++t->pNode->RefCount;
  v4 = this->Text.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Text.pNode = pNode;
}
