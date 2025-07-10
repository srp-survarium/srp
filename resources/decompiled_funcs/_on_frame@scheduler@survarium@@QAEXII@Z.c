void __thiscall survarium::scheduler::on_frame(
        survarium::scheduler *this,
        unsigned int frame_delta,
        unsigned int current_time)
{
  survarium::scheduler::record *v3; // eax
  survarium::scheduler *thisa; // [esp+0h] [ebp-274h]

  thisa = this;
  this->m_current_index = 0;
  while ( thisa->m_current_index < vostok::vectora<survarium::scheduler::record>::size(
                                     &this->m_inactive_objects,
                                     &thisa->m_active_objects._M_impl._M_start) )
  {
    v3 = stlp_std::vector<survarium::scheduler::record,vostok::vectora_allocator<void *>>::operator[](
           &thisa->m_active_objects,
           thisa->m_current_index);
    survarium::scheduler::on_frame(thisa, v3, frame_delta, current_time);
    this = thisa;
    ++thisa->m_current_index;
  }
  thisa->m_current_index = -1;
}
