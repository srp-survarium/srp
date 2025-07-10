void __thiscall survarium::booby_trap_core::unregister_tick(
        survarium::booby_trap_core *this,
        survarium::scheduler *scheduler)
{
  survarium::scheduler::unregister(scheduler, &this->m_scheduler_identifier);
}
