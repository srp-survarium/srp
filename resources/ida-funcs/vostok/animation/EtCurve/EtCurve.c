void __usercall vostok::animation::EtCurve::EtCurve(
        vostok::animation::EtCurve *this@<eax>,
        vostok::memory::base_allocator *a@<edx>)
{
  this->keyList._M_impl._M_start = 0;
  this->keyList._M_impl._M_finish = 0;
  this->keyList._M_impl._M_end_of_storage.m_allocator = a;
  this->keyList._M_impl._M_end_of_storage._M_data = 0;
  this->lastIndex = -1;
  this->lastInterval = -1;
  this->isWeighted = 0;
  this->isStatic = 0;
  this->preInfinity = kInfinityConstant;
  this->postInfinity = kInfinityConstant;
  this->lastKey = 0;
  this->isStep = 0;
  this->isStepNext = 0;
}
