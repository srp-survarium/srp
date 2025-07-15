void __thiscall Scaleform::HeapMH::AllocEngineMH::freePage(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        bool globalLocked)
{
  Scaleform::LockSafe *p_RootLock; // ebx

  if ( globalLocked )
  {
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&this->Allocator, page->Start);
    page->pPrev->pNext = page->pNext;
    page->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$17E717CE4C6DC4C18BA375293F14B2A4::pPrev = page->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, page);
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&this->Allocator, page->Start);
    page->pPrev->pNext = page->pNext;
    page->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$17E717CE4C6DC4C18BA375293F14B2A4::pPrev = page->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, page);
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
  this->Footprint -= 4096;
}
