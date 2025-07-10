Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx *__thiscall Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->message.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
