void __thiscall Scaleform::MemoryHeapPT::checkIntegrity(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // ebx
  Scaleform::MemoryHeap *pNext; // edi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // esi
  int v5; // eax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(
    (Scaleform::GFx::AS3::Object *)&this->pEngine->Allocator.Bin,
    this->pEngine->Allocator.MinAlignShift);
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v5 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v5 )
      break;
    pNext->checkIntegrity(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}
