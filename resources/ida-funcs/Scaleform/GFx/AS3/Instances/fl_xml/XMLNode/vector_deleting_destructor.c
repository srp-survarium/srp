Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *__thiscall Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::~XMLNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
