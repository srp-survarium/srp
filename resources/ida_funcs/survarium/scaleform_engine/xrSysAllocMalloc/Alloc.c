char *__thiscall survarium::scaleform_engine::xrSysAllocMalloc::Alloc(
        survarium::scaleform_engine::xrSysAllocMalloc *this,
        unsigned int size,
        unsigned int align)
{
  char *v3; // ecx
  char *result; // eax

  v3 = (char *)this->m_mem_alloc_ptr(align + size);
  result = 0;
  if ( v3 )
  {
    result = (char *)(~(align - 1) & (unsigned int)&v3[align - 1]);
    if ( result == v3 )
      result += align;
    *((_DWORD *)result - 1) = result - v3;
  }
  return result;
}
