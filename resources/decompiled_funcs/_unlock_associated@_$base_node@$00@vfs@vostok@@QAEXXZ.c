void __thiscall vostok::vfs::base_node<1>::unlock_associated(vostok::vfs::base_node<1> *this)
{
  survarium::game_camera *v1; // ecx
  btNullPairCache *v2; // ecx
  volatile int *v3; // eax
  int locked_value; // [esp+Ch] [ebp-8h]
  int unlocked_value; // [esp+10h] [ebp-4h]

  do
  {
    locked_value = *vostok::vfs::base_node<1>::ref_lock(this);
    survarium::weapon_user_dead_state::finalize(v1);
    unlocked_value = locked_value
                   & ~(1 << (16 - (survarium::player_logic_base_state::is_ready_for_transition(v2) == 0)));
    v3 = vostok::vfs::base_node<1>::ref_lock(this);
  }
  while ( vostok::threading::interlocked_compare_exchange(unlocked_value, v3, locked_value) != locked_value );
}
