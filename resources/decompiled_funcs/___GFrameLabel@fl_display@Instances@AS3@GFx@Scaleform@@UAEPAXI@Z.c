Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *__thiscall Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->FrameName.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
