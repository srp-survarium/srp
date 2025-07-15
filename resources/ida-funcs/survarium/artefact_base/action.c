void __thiscall survarium::artefact_base::action(survarium::artefact_base *this, bool key_down, int current_time_ms)
{
  survarium::game_effect_emitter *m_object; // eax
  survarium::loose_ptr_data *v5; // ecx
  survarium::game_effect_player *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<survarium::game_effect_time,boost::_mfi::mf3<survarium::game_effect_time,survarium::artefact_base,survarium::game_effect_node const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::artefact_base *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v8; // [esp-14h] [ebp-4Ch]
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> v9; // [esp+10h] [ebp-28h] BYREF
  const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v10; // [esp+14h] [ebp-24h]
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> f; // [esp+18h] [ebp-20h] BYREF

  if ( this->m_state == artefact_state_picked_passive && key_down && !this->m_time_left_to_cool )
  {
    this->enable_active_effects(this, current_time_ms);
    m_object = this->m_effect_emitter.m_object;
    if ( m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v5 = this->m_effect.m_object;
        if ( !v5 || !v5->m_pointer )
        {
          survarium::game_effect_emitter::emit((survarium::game_effect_emitter *)v5, (int)m_object, (int *)&v9);
          survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
            (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v9.m_object,
            (int *)&this->m_effect);
          v10 = (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
          f.functor.obj_ptr = this;
          f.vtable = (boost::detail::function::vtable_base *)survarium::artefact_base::effect_calculator;
          (&f.vtable)[1] = 0;
          HIDWORD(v8.f_.f_) = survarium::artefact_base::effect_calculator;
          *(_QWORD *)&v8.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
          LODWORD(v8.f_.f_) = &f;
          boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
            0,
            v8,
            (int)f.functor.vostok_pointer_size_alignment[1]);
          survarium::game_effect_player::add(v6, v10 + 196, &v9, current_time_ms, 0, &f);
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v7,
            (int *)&f);
          vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&v9);
        }
      }
    }
    this->m_state = artefact_state_picked_active;
  }
}
