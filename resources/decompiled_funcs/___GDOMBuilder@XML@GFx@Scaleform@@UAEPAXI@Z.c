Scaleform::GFx::XML::DOMBuilder *__thiscall Scaleform::GFx::XML::DOMBuilder::`scalar deleting destructor'(
        Scaleform::GFx::XML::DOMBuilder *this,
        char a2)
{
  Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
