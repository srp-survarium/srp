unsigned __int8 *__thiscall survarium::scaleform_engine::xrSysAllocMalloc::Realloc(
        survarium::scaleform_engine::xrSysAllocMalloc *this,
        unsigned __int8 *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int align)
{
  unsigned __int8 *v6; // edi
  unsigned int v7; // eax

  v6 = (unsigned __int8 *)this->Alloc(this, newSize, align);
  if ( v6 )
  {
    v7 = newSize;
    if ( newSize >= oldSize )
      v7 = oldSize;
    memcpy(v6, oldPtr, v7);
    this->Free(this, oldPtr, oldSize, align);
  }
  return v6;
}
