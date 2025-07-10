Scaleform::Render::Mesh *__thiscall Scaleform::Render::Mesh::`vector deleting destructor'(
        Scaleform::Render::Mesh *this,
        char a2)
{
  Scaleform::Render::Mesh::~Mesh(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
