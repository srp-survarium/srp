void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        wchar_t ch)
{
  Scaleform::GFx::ASStringNode *v3; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v5; // zf

  v3 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
         &ch,
         1);
  v3->RefCount += 2;
  pNode = this->Text.pNode;
  v5 = pNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Text.pNode = v3;
  v5 = v3->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
}
