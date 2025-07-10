void __thiscall survarium::scaleform_engine::xrSysAllocMalloc::Free(
        survarium::scaleform_engine::xrSysAllocMalloc *this,
        _DWORD *ptr,
        unsigned int size,
        unsigned int align)
{
  this->m_mem_free_ptr((char *)ptr - *(ptr - 1));
}
