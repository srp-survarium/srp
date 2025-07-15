char *__thiscall Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        __m128i *oldPtr,
        unsigned int newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo,
        Scaleform::LockSafe *globalLocked)
{
  char *result; // eax
  char *v8; // ebx
  unsigned int UsableSize; // eax

  result = Scaleform::HeapMH::AllocEngineMH::Alloc(this, newSize, newInfo, globalLocked);
  v8 = result;
  if ( result )
  {
    UsableSize = Scaleform::HeapMH::AllocBitSet2MH::GetUsableSize(&this->Allocator, page, (int)oldPtr);
    if ( UsableSize >= newInfo->UsableSize )
      UsableSize = newInfo->UsableSize;
    memcpy((int)v8, oldPtr, UsableSize);
    Scaleform::HeapMH::AllocEngineMH::Free(this, page, (unsigned __int8 *)oldPtr, (bool)globalLocked);
    return v8;
  }
  return result;
}
