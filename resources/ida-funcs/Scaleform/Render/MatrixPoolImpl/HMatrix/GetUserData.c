unsigned int *__thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::GetUserData(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 8) != 0 )
    return &pHeader[1].RefCount + 4 * (unsigned __int8)byte_874213[5 * (pHeader->Format & 0xF)];
  else
    return 0;
}
