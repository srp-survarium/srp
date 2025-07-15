unsigned int *__thiscall Scaleform::Render::MatrixPoolImpl::DataHeader::GetData(
        Scaleform::Render::MatrixPoolImpl::DataHeader *this,
        Scaleform::Render::MatrixPoolImpl::HMatrixConstants::ElementIndex index)
{
  return &this[1].RefCount
       + 4
       * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[this->Format & 0xF].Offsets[index];
}
