char __thiscall Scaleform::SysAllocMapper::Free(
        Scaleform::SysAllocMapper *this,
        unsigned __int8 *ptr,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int v4; // eax
  unsigned int PageSize; // ecx
  unsigned int v7; // eax

  v4 = alignment;
  PageSize = this->PageSize;
  if ( alignment < PageSize )
    v4 = PageSize;
  v7 = Scaleform::SysAllocMapper::freeMem(this, ptr, ~(v4 - 1) & (size + v4 - 1));
  if ( !this->Segments[v7].PageCount )
    Scaleform::SysAllocMapper::releaseSegment(this, v7);
  return 1;
}
