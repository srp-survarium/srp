unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::reallocGeneral(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        unsigned __int8 *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        char alignShift)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax

  result = Scaleform::HeapPT::AllocEngine::Alloc(this, newSize, (Scaleform::Heap::HeapSegment *)(1 << alignShift));
  v8 = result;
  if ( result )
  {
    v9 = oldSize;
    if ( oldSize >= newSize )
      v9 = newSize;
    memcpy(v8, oldPtr, v9);
    Scaleform::HeapPT::AllocEngine::Free(this, seg, (Scaleform::HeapPT::AllocEngine::TinyBlock *)oldPtr);
    return v8;
  }
  return result;
}
