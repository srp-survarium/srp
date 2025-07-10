void __thiscall survarium::body_part_parameters::hit_by_type(
        survarium::body_part_parameters *this,
        char *hit_type,
        unsigned int time_in_ms,
        float amount,
        float armor_piercing,
        bool __formal,
        survarium::damage_protector *prot)
{
  survarium::game_camera *v7; // ecx
  float v8; // xmm0_4
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  float a2; // [esp+0h] [ebp-194h]
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_damage_predicate> pred; // [esp+150h] [ebp-44h] BYREF
  const vostok::variant<32> **v14; // [esp+154h] [ebp-40h]
  float m_absorption_amount; // [esp+15Ch] [ebp-38h]
  float m_reduce; // [esp+160h] [ebp-34h]
  float v17; // [esp+168h] [ebp-2Ch]
  float m_armor; // [esp+16Ch] [ebp-28h]
  char v19; // [esp+173h] [ebp-21h]
  float delta; // [esp+174h] [ebp-20h]
  float e_wnd; // [esp+178h] [ebp-1Ch]
  float arp_arm_coeff; // [esp+17Ch] [ebp-18h]
  survarium::hit_type_parameters *params; // [esp+180h] [ebp-14h]
  survarium::protect_damage_predicate p; // [esp+184h] [ebp-10h] BYREF

  params = (survarium::hit_type_parameters *)survarium::body_part_parameters::get_hit_parameters(this, hit_type);
  v19 = 0;
  survarium::weapon_user_dead_state::finalize(v7);
  delta = amount;
  m_armor = params->m_armor;
  if ( m_armor == 0.0 )
  {
    arp_arm_coeff = *(float *)&clear_value;
  }
  else
  {
    v17 = params->m_armor;
    v8 = (float)(armor_piercing / v17) - *(float *)&clear_value;
    vostok::math::min();
    arp_arm_coeff = v8;
  }
  vostok::math::max();
  e_wnd = *(float *)&FLOAT_0_0;
  m_reduce = params->m_reduce;
  m_absorption_amount = params->m_absorption_amount;
  vostok::math::max();
  delta = (float)(delta * 0.0) + 0.0;
  v14 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&this->m_name);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&p);
  p.m_body_type_name = (const char *)v14;
  p.m_damage_type = hit_type;
  p.m_armor_piercing = armor_piercing;
  p.m_amount = delta;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &p;
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_damage_predicate>>(
    &this->m_damage_protectors,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  vostok::math::max();
  delta = *(float *)&FLOAT_0_0;
  if ( prot )
  {
    a2 = delta;
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)hit_type,
            (int)&this->m_name);
    boost::function4<float,char const *,char const *,float,float>::operator()(
      &prot->reduce_damage_functor,
      (const char *)v10,
      hit_type,
      a2,
      armor_piercing);
    vostok::math::max();
    delta = *(float *)&FLOAT_0_0;
  }
  survarium::body_part_parameters::decrease_health(this, delta);
  this->m_last_hit_health = this->m_health;
  this->m_last_hit_time = time_in_ms;
  if ( this->m_damage_model->m_affects_applying_type == type_apply_directly )
    survarium::body_part_parameters::check_affects(this, time_in_ms);
  survarium::hit_type_parameters::apply_damage(params, delta, time_in_ms);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&p);
}
