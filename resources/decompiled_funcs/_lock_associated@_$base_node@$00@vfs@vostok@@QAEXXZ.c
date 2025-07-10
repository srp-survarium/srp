void __thiscall vostok::vfs::base_node<1>::lock_associated(vostok::vfs::base_node<1> *this)
{
  volatile int *v1; // eax
  btNullPairCache *v3; // [esp+8h] [ebp-10h]
  int locked_value; // [esp+10h] [ebp-8h]
  int unlocked_value; // [esp+14h] [ebp-4h]

  do
  {
    v3 = (btNullPairCache *)(16
                           - (survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) == 0));
    unlocked_value = ~(1 << (char)v3) & *vostok::vfs::base_node<1>::ref_lock(this);
    locked_value = unlocked_value | (1 << (16 - (survarium::player_logic_base_state::is_ready_for_transition(v3) == 0)));
    v1 = vostok::vfs::base_node<1>::ref_lock(this);
  }
  while ( vostok::threading::interlocked_compare_exchange(locked_value, v1, unlocked_value) != unlocked_value );
}
