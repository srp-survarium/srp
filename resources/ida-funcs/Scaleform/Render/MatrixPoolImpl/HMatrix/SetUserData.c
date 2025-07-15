void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        const __m128i *data,
        unsigned int size)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  unsigned int *v6; // eax

  pHandle = this->pHandle;
  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 8) == 0 )
  {
    if ( !data )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_DWORD *)(((unsigned int)pHandle & 0xFFFFF800) + 0x10) + 4),
      pHandle,
      pHeader->Format | 8);
  }
  v6 = &this->pHandle->pHeader[1].RefCount
     + 4 * (unsigned __int8)byte_874213[5 * (this->pHandle->pHeader->Format & 0xF)];
  if ( data )
    memcpy((int)v6, data, size);
  else
    memset((int)v6, 0, size);
}
