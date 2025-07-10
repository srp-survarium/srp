void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *other)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // esi
  char *v6; // eax

  if ( other->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++other->pHandle->pHeader->RefCount;
  pHandle = this->pHandle;
  if ( this->pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    this->pHandle = other->pHandle;
  }
  else
  {
    pHeader = pHandle->pHeader;
    if ( pHandle->pHeader->RefCount-- == 1 )
    {
      v6 = (char *)pHeader + pHeader->DataPageOffset;
      *((_WORD *)v6 + 7) += 16 * pHeader->UnitSize;
      *(_DWORD *)(*((_DWORD *)v6 + 2) + 20) += 16 * pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0;
    }
    this->pHandle = other->pHandle;
  }
}
