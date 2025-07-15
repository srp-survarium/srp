void __thiscall Scaleform::Render::MatrixPoolImpl::DataHeader::Release(
        Scaleform::Render::MatrixPoolImpl::DataHeader *this)
{
  char *v3; // eax

  if ( this->RefCount-- == 1 )
  {
    v3 = (char *)this + this->DataPageOffset;
    *((_WORD *)v3 + 7) += 16 * this->UnitSize;
    *(_DWORD *)(*((_DWORD *)v3 + 2) + 20) += 16 * this->UnitSize;
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(this->pHandle);
    this->pHandle = 0;
  }
}
