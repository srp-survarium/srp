Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *__thiscall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *v5; // ecx

  pNode = this->Text.pNode;
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v5 = this->Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::Scaleform::GFx::AS3::Instances::fl_events::TextEvent::Text.pNode;
  v4 = v5->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
