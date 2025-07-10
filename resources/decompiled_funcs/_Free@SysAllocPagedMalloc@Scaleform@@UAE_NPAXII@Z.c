char __thiscall Scaleform::SysAllocPagedMalloc::Free(
        Scaleform::SysAllocPagedMalloc *this,
        void *ptr,
        unsigned int size,
        unsigned int __formal)
{
  free(ptr);
  this->Footprint -= size;
  return 1;
}
