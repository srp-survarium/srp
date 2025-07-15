int __thiscall Scaleform::SysAllocWinAPI::ReallocInPlace(
        Scaleform::SysAllocWinAPI *this,
        void *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int align)
{
  return ((int (__thiscall *)(Scaleform::SysAllocMapper *, void *, unsigned int, unsigned int, unsigned int))this->pAllocator->ReallocInPlace)(
           this->pAllocator,
           oldPtr,
           oldSize,
           newSize,
           align);
}
