char *__thiscall Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        void *oldPtr,
        unsigned int newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo,
        BOOL globalLocked)
{
  char *result; // eax
  unsigned __int8 *v8; // ebx
  unsigned int UsableSize; // eax

  result = Scaleform::HeapMH::AllocEngineMH::Alloc(this, newSize, newInfo, (Scaleform::LockSafe::Locker)globalLocked);
  v8 = (unsigned __int8 *)result;
  if ( result )
  {
    UsableSize = Scaleform::HeapMH::AllocBitSet2MH::GetUsableSize(&this->Allocator, page, oldPtr);
    if ( UsableSize >= newInfo->UsableSize )
      UsableSize = newInfo->UsableSize;
    memcpy(v8, (unsigned __int8 *)oldPtr, UsableSize);
    Scaleform::HeapMH::AllocEngineMH::Free(this, page, (unsigned int)oldPtr, globalLocked);
    return (char *)v8;
  }
  return result;
}
