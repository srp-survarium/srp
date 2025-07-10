Scaleform::GFx::AS3::Instances::fl::XMLElement *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement::~XMLElement(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
