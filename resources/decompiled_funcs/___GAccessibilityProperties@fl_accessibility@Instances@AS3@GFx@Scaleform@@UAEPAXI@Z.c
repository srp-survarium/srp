Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties *__thiscall Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::ASStringNode *v6; // ecx

  pNode = this->shortcut.pNode;
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v5 = this->name.pNode;
  v4 = v5->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v6 = this->description.pNode;
  v4 = v6->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
