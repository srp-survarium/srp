void __userpurge survarium::scheduler::record::record(
        survarium::scheduler::record *__that@<eax>,
        survarium::scheduler::record *this)
{
  unsigned int *v2; // esi

  v2 = (unsigned int *)__that;
  this->m_id = __that->m_id;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&__that->m_callback,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_callback);
  v2 += 10;
  *(_DWORD *)&this->survarium::scheduler::scheduler_record = *v2++;
  this->m_max_update_count = *v2;
  this->m_last_update_time = v2[1];
}
