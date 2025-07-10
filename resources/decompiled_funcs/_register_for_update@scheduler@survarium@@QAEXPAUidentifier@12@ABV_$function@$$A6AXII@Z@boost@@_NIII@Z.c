void __userpurge survarium::scheduler::register_for_update(
        survarium::scheduler *callback@<ecx>,
        bool active@<al>,
        survarium::scheduler *this,
        survarium::scheduler::identifier *identifier,
        unsigned int update_delta,
        unsigned int max_update_count,
        unsigned int time_start_from)
{
  survarium::scheduler::record *v7; // eax

  v7 = survarium::scheduler::register_object(
         callback,
         this,
         identifier,
         (boost::function<void __cdecl(unsigned int,unsigned int)> *)callback,
         active);
  *(_DWORD *)&v7->survarium::scheduler::scheduler_record = update_delta | 0x80000000;
  v7->m_max_update_count = max_update_count;
  v7->m_last_update_time = time_start_from;
}
