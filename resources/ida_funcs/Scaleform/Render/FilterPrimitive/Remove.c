void __thiscall Scaleform::Render::FilterPrimitive::Remove(
        Scaleform::Render::FilterPrimitive *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax

  pHandle = this->FilterArea.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
    this->FilterArea.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  }
}
