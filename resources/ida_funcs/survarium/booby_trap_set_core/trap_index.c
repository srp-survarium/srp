int __thiscall survarium::booby_trap_set_core::trap_index(
        survarium::booby_trap_set_core *this,
        survarium::booby_trap_core *trap)
{
  survarium::game_camera *v2; // ecx
  survarium::booby_trap_core *__val; // [esp+20h] [ebp-8h] BYREF
  const vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *trap_iter; // [esp+24h] [ebp-4h]

  __val = trap;
  trap_iter = stlp_std::find<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> const *,survarium::booby_trap_core const *>(
                this->m_traps.m_begin,
                this->m_traps.m_end,
                (const survarium::booby_trap_core *const *)&__val);
  survarium::weapon_user_dead_state::finalize(v2);
  return trap_iter - this->m_traps.m_begin;
}
