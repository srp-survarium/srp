void __thiscall survarium::booby_trap_set_core::deserialize_game_world_object(
        survarium::booby_trap_set_core *this,
        vostok::network_core::packet_reader *reader)
{
  survarium::game_camera *v2; // ecx
  survarium::booby_trap_set_core *v3; // ecx
  vostok::buffer_vector<unsigned int> *v4; // eax
  unsigned int *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  survarium::game_camera *v7; // ecx
  const vostok::variant<32> **trap; // [esp+14h] [ebp-8h]
  unsigned __int8 trap_index; // [esp+1Bh] [ebp-1h]

  trap_index = vostok::network_core::packet_reader::r<unsigned char>(
                 (vostok::network_core::packet_reader *)this,
                 (int)reader);
  survarium::weapon_user_dead_state::finalize(v2);
  v4 = (vostok::buffer_vector<unsigned int> *)survarium::booby_trap_set_core::traps(v3, (int)this);
  v5 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](v4, trap_index);
  trap = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)v5);
  survarium::weapon_user_dead_state::finalize(v7);
  ((void (__thiscall *)(const vostok::variant<32> **, vostok::network_core::packet_reader *))(*trap)->m_helper)(
    trap,
    reader);
}
