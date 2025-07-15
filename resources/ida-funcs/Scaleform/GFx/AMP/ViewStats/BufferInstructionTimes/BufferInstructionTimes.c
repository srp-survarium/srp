void __thiscall Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes::BufferInstructionTimes(
        Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes *this,
        unsigned int size)
{
  int *p_Times; // edi

  this->__vftable = (Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  p_Times = (int *)&this->Times;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes_vtbl *)&Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes::`vftable';
  Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::ArrayDefaultPolicy>(
    &this->Times.Data,
    size);
  memset(*p_Times, 0, 8 * size);
}
