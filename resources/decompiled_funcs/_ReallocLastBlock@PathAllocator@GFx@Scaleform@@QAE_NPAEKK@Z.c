bool __thiscall Scaleform::GFx::PathAllocator::ReallocLastBlock(
        Scaleform::GFx::PathAllocator *this,
        unsigned __int8 *ptr,
        unsigned int oldSize,
        unsigned int newSize)
{
  Scaleform::GFx::PathAllocator::Page *pLastPage; // edx
  int v5; // edx
  unsigned int v6; // edx
  bool result; // al

  if ( newSize >= oldSize )
    return 0;
  pLastPage = this->pLastPage;
  if ( !pLastPage )
    return 0;
  if ( ptr - (unsigned __int8 *)pLastPage - 8 >= (signed int)pLastPage->PageSize )
    return 0;
  v5 = pLastPage->PageSize - (ptr - (unsigned __int8 *)pLastPage - 8);
  if ( v5 - oldSize != this->FreeBytes )
    return 0;
  v6 = v5 - newSize;
  result = 0;
  if ( v6 < (unsigned int)&_sbh_sizeHeaderList )
    this->FreeBytes = v6;
  return result;
}
