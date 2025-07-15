int __thiscall Scaleform::SysAllocWinAPI::Free(
        Scaleform::SysAllocWinAPI *this,
        void *ptr,
        unsigned int size,
        unsigned int align)
{
  return ((int (__thiscall *)(Scaleform::SysAllocMapper *, void *, unsigned int, unsigned int))this->pAllocator->Free)(
           this->pAllocator,
           ptr,
           size,
           align);
}
