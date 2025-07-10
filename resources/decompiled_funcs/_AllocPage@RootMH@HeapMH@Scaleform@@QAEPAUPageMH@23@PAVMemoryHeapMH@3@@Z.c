Scaleform::HeapMH::PageMH *__thiscall Scaleform::HeapMH::RootMH::AllocPage(
        Scaleform::HeapMH::RootMH *this,
        Scaleform::MemoryHeapMH *heap)
{
  Scaleform::HeapMH::PageMH *result; // eax
  Scaleform::HeapMH::PageMH *pNext; // esi
  unsigned int Start; // [esp-8h] [ebp-2Ch]
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+8h] [ebp-1Ch] BYREF

  if ( (Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *)this->FreePages.Root.pNext == &this->FreePages
    && !Scaleform::HeapMH::RootMH::allocPagePool(this) )
  {
    return 0;
  }
  pNext = this->FreePages.Root.pNext;
  result = (Scaleform::HeapMH::PageMH *)this->pSysAlloc->Alloc(this->pSysAlloc, 4096, 4);
  pNext->Start = (unsigned __int8 *)result;
  if ( result )
  {
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$175536D4FE6D43D2B2160FD1C4F2F895::pPrev = pNext->pPrev;
    Start = (unsigned int)pNext->Start;
    pNext->pHeap = heap;
    Scaleform::HeapMH::GetMagicHeaders(Start, &headers);
    if ( headers.Header1 )
      headers.Header1->Magic = 24512;
    if ( headers.Header2 )
      headers.Header2->Magic = 24512;
    return pNext;
  }
  else
  {
    pNext->pHeap = 0;
  }
  return result;
}
