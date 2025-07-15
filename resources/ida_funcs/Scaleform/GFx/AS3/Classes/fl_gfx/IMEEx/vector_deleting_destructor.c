Scaleform::GFx::AS3::Classes::fl_xml::XMLNodeType *__thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::`vector deleting destructor'(
        Scaleform::GFx::AS3::Classes::fl_xml::XMLNodeType *this,
        char a2)
{
  Scaleform::GFx::AS3::Class::~Class(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
