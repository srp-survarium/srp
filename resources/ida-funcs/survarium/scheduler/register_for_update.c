void __userpurge survarium::scheduler::register_for_update(
        survarium::scheduler *this@<edi>,
        const unsigned int update_delta@<eax>,
        survarium::scheduler *a3@<ecx>,
        survarium::scheduler::identifier *identifier,
        boost::function<void __cdecl(unsigned int,unsigned int)> *callback,
        const bool active,
        const unsigned int max_update_count,
        const unsigned int time_start_from)
{
  survarium::scheduler::record *v9; // eax
  bool v10; // [esp+0h] [ebp-4h]

  v9 = survarium::scheduler::register_object(a3, (int)this, identifier, callback, v10);
  *(_DWORD *)&v9->survarium::scheduler::scheduler_record = update_delta | 0x80000000;
  v9->m_max_update_count = 1;
  v9->m_last_update_time = this->m_last_tick_time_ms;
}
