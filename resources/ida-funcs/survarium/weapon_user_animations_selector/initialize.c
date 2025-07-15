void __thiscall survarium::weapon_user_animations_selector::initialize(
        survarium::weapon_user_animations_selector *this,
        vostok::ai::fsm *a2)
{
  vostok::ai::fsm_state *m_first; // edi
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::animation::animation_player *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::animation::animation_states_dumper dumper; // [esp+Ch] [ebp-2Ch] BYREF
  char v7; // [esp+14h] [ebp-24h]
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> animation_resolver; // [esp+18h] [ebp-20h] BYREF

  if ( vostok::physics::bt_character_controller::can_stand(
         (vostok::physics::bt_character_controller *)this,
         *(int *)((char *)&dword_10E74 + *(_DWORD *)&a2[1].m_states.gap4)) )
  {
    m_first = a2[1].m_states.m_first;
  }
  else
  {
    m_first = a2[1].m_states.m_last;
  }
  vostok::ai::fsm::set_initial_state(a2, m_first, ignore_current_state);
  animation_resolver.vtable = 0;
  v3 = (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)&a2[1].m_states.gap4 + 848);
  dumper.__vftable = (vostok::animation::animation_states_dumper_vtbl *)&survarium::supporting_leg_selector::`vftable';
  v7 = 1;
  vostok::animation::animation_player::dump_animation_states(v4, v3, &dumper, &animation_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&animation_resolver);
  LOBYTE(a2[1].m_current_state) = v7;
}
