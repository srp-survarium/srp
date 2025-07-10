Scaleform::Render::MorphShapeData *__thiscall Scaleform::Render::MorphShapeData::`vector deleting destructor'(
        Scaleform::Render::MorphShapeData *this,
        char a2)
{
  Scaleform::Render::MorphShapeData::~MorphShapeData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
