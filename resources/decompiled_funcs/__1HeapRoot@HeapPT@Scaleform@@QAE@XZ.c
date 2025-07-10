void __thiscall Scaleform::HeapPT::HeapRoot::~HeapRoot(Scaleform::HeapPT::HeapRoot *this)
{
  Scaleform::Lock::~Lock(&this->RootLock.mLock);
  this->AllocWrapper.Allocator.__vftable = (Scaleform::HeapPT::SysAllocGranulator_vtbl *)&Scaleform::SysAllocBase::`vftable';
  this->AllocWrapper.__vftable = (Scaleform::HeapPT::SysAllocWrapper_vtbl *)&Scaleform::SysAllocBase::`vftable';
}
