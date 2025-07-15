void __thiscall survarium::body_part_parameters::check_effects(
        survarium::body_part_parameters *this,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> current_time_in_ms,
        unsigned int a3)
{
  survarium::body_part_parameters *m_object; // ebx
  int m_intervals_count; // eax
  int *p_m_reference_count; // esi
  survarium::game_effect_emitter *m_reference_count; // ecx
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *v7; // ecx
  survarium::game_effect_player *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  int m_first; // ecx
  survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v11; // esi
  _DWORD *v12; // eax
  survarium::loose_ptr_base *(__thiscall *v13)(survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *); // eax
  float v14; // xmm0_4
  float m_health; // xmm1_4
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *v16; // ecx
  survarium::game_effect_player *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  boost::_bi::bind_t<survarium::game_effect_time,boost::_mfi::mf4<survarium::game_effect_time,survarium::body_part_parameters,survarium::affects_threshold *,survarium::game_effect_node const &,unsigned int,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::body_part_parameters *>,boost::_bi::value<survarium::affects_threshold *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v19; // [esp-10h] [ebp-58h]
  boost::_bi::bind_t<survarium::game_effect_time,boost::_mfi::mf3<survarium::game_effect_time,survarium::body_part_parameters,survarium::game_effect_node const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::body_part_parameters *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v20; // [esp-8h] [ebp-50h]
  int v21; // [esp+0h] [ebp-48h]
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> f; // [esp+10h] [ebp-38h] BYREF
  survarium::game_effect_time *(__thiscall *v23)(survarium::body_part_parameters *, survarium::game_effect_time *, survarium::affects_threshold *, const survarium::game_effect_node *, unsigned int, unsigned int); // [esp+34h] [ebp-14h]
  survarium::body_part_parameters *v24; // [esp+38h] [ebp-10h]
  int v25; // [esp+3Ch] [ebp-Ch]
  survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> object; // [esp+40h] [ebp-8h] BYREF
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> v27; // [esp+44h] [ebp-4h] BYREF

  m_object = (survarium::body_part_parameters *)current_time_in_ms.m_object;
  m_intervals_count = current_time_in_ms.m_object[7].m_intervals_count;
  if ( m_intervals_count )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_reference_count = (int *)&current_time_in_ms.m_object[7].m_reference_count;
      m_reference_count = (survarium::game_effect_emitter *)current_time_in_ms.m_object[7].m_reference_count;
      if ( (!m_reference_count || !m_reference_count->__vftable)
        && *(float *)&current_time_in_ms.m_object[5].m_pointer > *(float *)&current_time_in_ms.m_object[5].m_emitter.m_object )
      {
        survarium::game_effect_emitter::emit(m_reference_count, m_intervals_count, (int *)&current_time_in_ms);
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
          (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)current_time_in_ms.m_object,
          p_m_reference_count);
        v20.l_.a1_.t_ = m_object;
        v20.f_.f_ = survarium::body_part_parameters::effect_calculator;
        boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
          v7,
          (boost::_bi::bind_t<survarium::game_effect_time,boost::_mfi::mf3<survarium::game_effect_time,survarium::body_part_parameters,survarium::game_effect_node const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::body_part_parameters *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)&f,
          v20,
          v21);
        survarium::game_effect_player::add(
          v8,
          (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&m_object->m_damage_model->m_owner->m_effect_player,
          &current_time_in_ms,
          a3,
          0,
          &f);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v9,
          (int *)&f);
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&current_time_in_ms);
      }
    }
  }
  m_first = (int)m_object->m_thresholds.m_first;
  current_time_in_ms.m_object = (survarium::game_effect *)m_first;
  if ( m_first )
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(m_first + 12) )
      {
        v11 = (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)(m_first + 16);
        v12 = *(_DWORD **)(m_first + 16);
        if ( v12 && *v12 )
          v13 = survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::c_ptr;
        else
          v13 = 0;
        if ( !v13 )
        {
          v14 = *(float *)(m_first + 4);
          m_health = m_object->m_health;
          if ( (float)(m_object->m_max_health * v14) > m_health || v14 == 0.0 && m_health == 0.0 )
          {
            survarium::game_effect_emitter::emit(
              (survarium::game_effect_emitter *)m_first,
              *(_DWORD *)(m_first + 12),
              (int *)&v27);
            survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
              (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v27.m_object,
              &object.m_object);
            survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
              v11,
              &object);
            survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>((survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&object);
            v25 = (int)current_time_in_ms.m_object;
            v23 = survarium::body_part_parameters::threshold_effect_calculator;
            v24 = m_object;
            v19.l_.a1_.t_ = (survarium::body_part_parameters *)survarium::body_part_parameters::threshold_effect_calculator;
            v19.l_.a2_.t_ = (survarium::affects_threshold *)m_object;
            v19.f_.f_ = (survarium::game_effect_time *(__thiscall *)(survarium::body_part_parameters *, survarium::game_effect_time *, survarium::affects_threshold *, const survarium::game_effect_node *, unsigned int, unsigned int))&f;
            boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
              v16,
              v19,
              (int)current_time_in_ms.m_object);
            survarium::game_effect_player::add(
              v17,
              (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&m_object->m_damage_model->m_owner->m_effect_player,
              &v27,
              a3,
              0,
              &f);
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v18,
              (int *)&f);
            vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&v27);
            m_first = (int)current_time_in_ms.m_object;
          }
        }
      }
      current_time_in_ms.m_object = *(survarium::game_effect **)m_first;
      if ( !current_time_in_ms.m_object )
        break;
      m_first = (int)current_time_in_ms.m_object;
    }
  }
}
