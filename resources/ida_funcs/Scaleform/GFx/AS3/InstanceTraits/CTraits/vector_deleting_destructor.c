Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *__thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::`vector deleting destructor'(
        Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *this,
        char a2)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
