void __thiscall Scaleform::HeapPT::HeapRoot::VisitSegments(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::LockSafe *p_RootLock; // edi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  this->AllocWrapper.VisitSegments((struct Scaleform::HeapPT::SysAllocWrapper *)this, visitor, 1u, 129u);
  Scaleform::HeapPT::Starter::VisitSegments(&this->AllocStarter, visitor);
  Scaleform::HeapPT::Bookkeeper::VisitSegments(&this->AllocBookkeeper, visitor);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
