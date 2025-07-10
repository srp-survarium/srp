Scaleform::HeapPT::SysAllocWrapper *__thiscall Scaleform::HeapPT::SysAllocWrapper::`scalar deleting destructor'(
        Scaleform::HeapPT::SysAllocWrapper *this,
        char a2)
{
  this->Allocator.__vftable = (Scaleform::HeapPT::SysAllocGranulator_vtbl *)&Scaleform::SysAllocBase::`vftable';
  this->__vftable = (Scaleform::HeapPT::SysAllocWrapper_vtbl *)&Scaleform::SysAllocBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
