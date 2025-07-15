const Scaleform::Render::Cxform *__thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 1) != 0 )
    return (const Scaleform::Render::Cxform *)(&pHeader[1].RefCount
                                             + 4
                                             * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]);
  else
    return &Scaleform::Render::Cxform::Identity;
}
