char *__thiscall Scaleform::SysAllocMapper::Alloc(
        Scaleform::SysAllocMapper *this,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int PageSize; // edi
  unsigned int v5; // esi
  char *result; // eax

  PageSize = alignment;
  if ( alignment < this->PageSize )
    PageSize = this->PageSize;
  v5 = ~(PageSize - 1) & (size + PageSize - 1);
  result = Scaleform::SysAllocMapper::allocMem(this, v5, PageSize);
  if ( !result )
  {
    if ( Scaleform::SysAllocMapper::reserveSegment(this, v5) )
      return Scaleform::SysAllocMapper::allocMem(this, v5, PageSize);
    else
      return 0;
  }
  return result;
}
