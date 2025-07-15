unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::reallocGeneral(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        __m128i *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        char alignShift)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax

  result = Scaleform::HeapPT::AllocEngine::Alloc(this, newSize, 1 << alignShift);
  v8 = result;
  if ( result )
  {
    v9 = oldSize;
    if ( oldSize >= newSize )
      v9 = newSize;
    memcpy((int)v8, oldPtr, v9);
    Scaleform::HeapPT::AllocEngine::Free(this, seg, (Scaleform::HeapPT::AllocEngine::TinyBlock *)oldPtr);
    return v8;
  }
  return result;
}
