Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument *__thiscall Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument::~XMLDocument(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
