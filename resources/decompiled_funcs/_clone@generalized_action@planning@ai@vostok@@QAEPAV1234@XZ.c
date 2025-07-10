vostok::ai::planning::generalized_action *__thiscall vostok::ai::planning::generalized_action::clone(
        vostok::ai::planning::generalized_action *this)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  const vostok::variant<32> **v3; // eax
  vostok::ai::planning::generalized_action *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *m_cost; // [esp-4h] [ebp-4Ch]
  vostok::ai::planning::generalized_action *v6; // [esp+0h] [ebp-48h]
  int *_Where; // [esp+38h] [ebp-10h]
  vostok::ai::planning::generalized_action *v9; // [esp+40h] [ebp-8h]
  vostok::ai::planning::generalized_action *copy; // [esp+44h] [ebp-4h] BYREF

  if ( this->m_parent )
    return vostok::ai::planning::generalized_action::clone(this->m_parent);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0xB8u);
  v9 = (vostok::ai::planning::generalized_action *)operator new(0xB8u, _Where);
  if ( v9 )
  {
    m_cost = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this->m_cost;
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           m_cost,
           (int)&this->m_caption);
    vostok::ai::planning::generalized_action::generalized_action(
      v9,
      this->m_domain,
      this->m_type,
      (const char *)v3,
      (unsigned int)m_cost);
    v6 = v4;
  }
  else
  {
    v6 = 0;
  }
  copy = v6;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::operator=(
    &v6->m_effects._M_impl,
    &this->m_effects._M_impl);
  v6->m_parent = this;
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    (vostok::buffer_vector<void const *> *)&this->m_clones,
    (const void **)&copy);
  return copy;
}
