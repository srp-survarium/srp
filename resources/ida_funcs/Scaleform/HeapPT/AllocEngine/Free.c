void __thiscall Scaleform::HeapPT::AllocEngine::Free(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        Scaleform::HeapPT::AllocEngine::TinyBlock *ptr)
{
  unsigned __int16 SegType; // ax
  Scaleform::LockSafe *p_RootLock; // ebx

  SegType = seg->SegType;
  if ( SegType > 7u )
  {
    if ( SegType == 10 )
    {
      Scaleform::HeapPT::AllocBitSet2::Free(&this->Allocator, seg, ptr);
      if ( seg->UseCount-- == 1 )
        Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(this, seg);
    }
    else
    {
      this->SysDirectSpace -= seg->DataSize;
      p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      Scaleform::HeapPT::AllocEngine::freeSegment(this, seg);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
    }
  }
  else
  {
    Scaleform::HeapPT::AllocEngine::freeTiny(this, seg, ptr);
  }
}
