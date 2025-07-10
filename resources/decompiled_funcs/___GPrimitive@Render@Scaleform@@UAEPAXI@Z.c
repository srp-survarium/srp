Scaleform::Render::Primitive *__thiscall Scaleform::Render::Primitive::`scalar deleting destructor'(
        Scaleform::Render::Primitive *this,
        char a2)
{
  Scaleform::Render::Primitive::~Primitive(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
