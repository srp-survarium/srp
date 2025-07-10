Scaleform::Render::MatrixPoolImpl::EntryHandle *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        unsigned __int8 formatBits)
{
  int v3; // ebp
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // esi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // eax

  v3 = (unsigned __int8)byte_9B2B74[5 * (formatBits & 0xF)];
  v4 = Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(&this->HandleTable, 0);
  if ( !v4 )
    return 0;
  v5 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
         this,
         16 * (v3 + ((formatBits & 0x10 | 0x20u) >> 4)),
         v4);
  v4->pHeader = v5;
  if ( !v5 )
  {
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v4);
    return 0;
  }
  v5->Format = formatBits;
  return v4;
}
