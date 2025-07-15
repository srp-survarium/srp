Scaleform::Render::TreeCacheMeshBase *__thiscall Scaleform::Render::TreeCacheMeshBase::`scalar deleting destructor'(
        Scaleform::Render::TreeCacheMeshBase *this,
        char a2)
{
  Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
