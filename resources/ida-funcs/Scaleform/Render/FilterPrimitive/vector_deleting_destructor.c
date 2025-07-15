Scaleform::Render::FilterPrimitive *__thiscall Scaleform::Render::FilterPrimitive::`vector deleting destructor'(
        Scaleform::Render::FilterPrimitive *this,
        char a2)
{
  Scaleform::Render::FilterPrimitive::~FilterPrimitive(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::Render::FilterPrimitive *__thiscall Scaleform::Render::FilterPrimitive::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::Render::FilterPrimitive::`vector deleting destructor'(
           (Scaleform::Render::FilterPrimitive *)(this - 8),
           a2);
}
