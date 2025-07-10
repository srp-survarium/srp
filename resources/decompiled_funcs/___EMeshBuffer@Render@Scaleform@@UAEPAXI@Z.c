Scaleform::Render::MeshBuffer *__thiscall Scaleform::Render::MeshBuffer::`vector deleting destructor'(
        Scaleform::Render::MeshBuffer *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::MeshBuffer_vtbl *)&Scaleform::Render::MeshBuffer::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
