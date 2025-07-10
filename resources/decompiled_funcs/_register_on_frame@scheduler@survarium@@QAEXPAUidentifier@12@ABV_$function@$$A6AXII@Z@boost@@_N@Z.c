void __userpurge survarium::scheduler::register_on_frame(
        survarium::scheduler *callback@<ecx>,
        bool active@<al>,
        survarium::scheduler *this,
        survarium::scheduler::identifier *identifier)
{
  survarium::scheduler::record *v4; // eax

  v4 = survarium::scheduler::register_object(
         callback,
         this,
         identifier,
         (boost::function<void __cdecl(unsigned int,unsigned int)> *)callback,
         active);
  *(_DWORD *)&v4->survarium::scheduler::scheduler_record = 0x7FFFFFFF;
  v4->m_max_update_count = 0;
  v4->m_last_update_time = 0;
}
