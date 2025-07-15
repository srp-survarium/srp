Scaleform::Render::MatrixPoolImpl::DataHeader *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        unsigned int size,
        Scaleform::Render::MatrixPoolImpl::EntryHandle *handle)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *pAllocPage; // eax
  unsigned int v5; // edi
  Scaleform::Render::MatrixPoolImpl::DataHeader *result; // eax
  Scaleform::Render::MatrixPoolImpl::DataPage *v7; // ecx

  pAllocPage = this->pAllocPage;
  v5 = size + 16;
  if ( (!pAllocPage || pAllocPage->FreeTail < v5)
    && !Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(this, size + 16) )
  {
    return 0;
  }
  v7 = this->pAllocPage;
  result = (Scaleform::Render::MatrixPoolImpl::DataHeader *)((char *)&v7[256] - v7->FreeTail);
  result->pHandle = handle;
  result->DataPageOffset = (_WORD)v7 - (_WORD)result;
  result->RefCount = 1;
  result->UnitSize = (size >> 4) + 1;
  result->Format = 0;
  v7->FreeTail -= v5;
  return result;
}
