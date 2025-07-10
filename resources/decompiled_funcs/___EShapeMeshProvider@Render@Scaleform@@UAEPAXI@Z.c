Scaleform::Render::ShapeMeshProvider *__thiscall Scaleform::Render::ShapeMeshProvider::`vector deleting destructor'(
        Scaleform::Render::ShapeMeshProvider *this,
        char a2)
{
  Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
