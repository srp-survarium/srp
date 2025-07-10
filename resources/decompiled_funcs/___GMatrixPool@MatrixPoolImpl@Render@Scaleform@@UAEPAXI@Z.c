Scaleform::Render::MatrixPoolImpl::MatrixPool *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::`scalar deleting destructor'(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        char a2)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
