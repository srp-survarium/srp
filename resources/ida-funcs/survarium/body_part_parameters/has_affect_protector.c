bool __thiscall survarium::body_part_parameters::has_affect_protector(
        survarium::body_part_parameters *this,
        survarium::hit_affects_type_enum affect)
{
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_affect_predicate> pred; // [esp+10h] [ebp-18h] BYREF
  const vostok::variant<32> **v5; // [esp+14h] [ebp-14h]
  bool m_result; // [esp+1Bh] [ebp-Dh]
  survarium::protect_affect_predicate p; // [esp+1Ch] [ebp-Ch] BYREF

  v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_name);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&p);
  p.m_body_type_name = (const char *)v5;
  p.m_affect_type = affect;
  p.m_result = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &p;
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_affect_predicate>>(
    &this->m_damage_protectors,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  m_result = p.m_result;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&p);
  return m_result;
}
