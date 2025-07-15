Scaleform::Render::ComplexMesh *__thiscall Scaleform::Render::ComplexMesh::`scalar deleting destructor'(
        Scaleform::Render::ComplexMesh *this,
        char a2)
{
  Scaleform::Render::ComplexMesh::~ComplexMesh(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
