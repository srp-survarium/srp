unsigned __int8 *__thiscall survarium::scaleform_engine::xrSysAllocMalloc::Realloc(
        survarium::scaleform_engine::xrSysAllocMalloc *this,
        unsigned __int8 *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int align)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax

  result = (unsigned __int8 *)this->Alloc(this, newSize, align);
  v7 = result;
  if ( result )
  {
    v8 = newSize;
    if ( newSize >= oldSize )
      v8 = oldSize;
    memcpy(v7, oldPtr, v8);
    this->Free(this, oldPtr, oldSize, align);
    return v7;
  }
  return result;
}
