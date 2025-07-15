Scaleform::GFx::XML::Prefix *__thiscall Scaleform::GFx::XML::Prefix::`vector deleting destructor'(
        Scaleform::GFx::XML::Prefix *this,
        char a2)
{
  Scaleform::GFx::XML::Prefix::~Prefix(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
