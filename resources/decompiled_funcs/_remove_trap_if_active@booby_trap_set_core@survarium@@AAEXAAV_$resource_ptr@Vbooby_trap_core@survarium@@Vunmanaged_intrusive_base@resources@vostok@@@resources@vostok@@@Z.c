void __thiscall survarium::booby_trap_set_core::remove_trap_if_active(
        survarium::booby_trap_set_core *this,
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *trap)
{
  survarium::game_camera *v2; // ecx
  const vostok::variant<32> **v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( trap->m_object->m_trap_state )
  {
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)trap->m_object,
           (int)trap);
    survarium::booby_trap_set_core::remove_trap_impl(this, (survarium::booby_trap_core *)v3);
  }
}
