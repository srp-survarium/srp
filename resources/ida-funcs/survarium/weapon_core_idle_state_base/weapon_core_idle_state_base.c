void __userpurge survarium::weapon_core_idle_state_base::weapon_core_idle_state_base(
        survarium::weapon_core_idle_state_base *this@<ecx>,
        _DWORD *a2@<eax>,
        survarium::weapon_core *weapon)
{
  survarium::weapon_core_base_state::weapon_core_base_state(this, (int)a2, weapon, weapon_state_idle);
  *a2 = &survarium::weapon_core_idle_state_base::`vftable'{for `vostok::ai::fsm_state'};
  a2[6] = &survarium::weapon_core_idle_state_base::`vftable'{for `vostok::resources::unmanaged_resource'};
}
