void __thiscall survarium::body_part_parameters::hit_by_type(
        survarium::body_part_parameters *this,
        survarium::affects_threshold *hit_type,
        survarium::hit_type_parameters *time_in_ms,
        float *damage,
        float *armor_piercing,
        float *const out_damage,
        const survarium::body_part_parameters *const last_hitted_body_part,
        survarium::hit_type_parameters *orientation,
        const char *a9)
{
  survarium::affects_threshold *v9; // ebx
  survarium::loose_ptr_data *m_object; // edi
  float m_value; // esi
  int v12; // ecx
  float *v13; // esi
  float v14; // xmm4_4
  survarium::game_effect_emitter *i; // eax
  survarium::game_effect_emitter *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float j; // edi
  const std::exception *v23; // eax
  survarium::hit_type_parameters *type; // ecx
  char v25; // al
  survarium::game_effect_emitter *k; // eax
  float v27; // xmm0_4
  float *v28; // eax
  unsigned int m_affects_count; // edi
  float v30; // xmm0_4
  float v31; // xmm2_4
  survarium::loose_ptr_data *v32; // ecx
  survarium::game_effect_emitter *v33; // eax
  survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *p_m_effect; // esi
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *v35; // ecx
  survarium::game_effect_player *v36; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v37; // ecx
  float v38; // xmm0_4
  int v39; // [esp+8h] [ebp-148h]
  stlp_std::out_of_range v40; // [esp+18h] [ebp-138h] BYREF
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> v41; // [esp+128h] [ebp-28h] BYREF
  _DWORD v42[2]; // [esp+148h] [ebp-8h] BYREF

  v9 = hit_type;
  if ( a9 == (const char *)1 && BYTE1(hit_type[8].m_effect_emitter.m_object) != 0xFF )
  {
    *armor_piercing = 0.0;
    return;
  }
  m_object = hit_type[5].m_effect.m_object;
  m_value = hit_type[9].m_value;
  a9 = (const char *)m_object;
  while ( m_value != 0.0 )
  {
    v12 = -(*(_DWORD *)(LODWORD(m_value) + 8) != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v12) != 0 )
      boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::operator()(
        (boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &> *)v12,
        (_DWORD *)(LODWORD(m_value) + 8),
        (const char *)m_object,
        (survarium::hit_type_enum)time_in_ms,
        armor_piercing,
        out_damage);
    m_value = *(float *)(LODWORD(m_value) + 104);
  }
  v13 = armor_piercing;
  v14 = *armor_piercing;
  for ( i = v9->m_effect_emitter.m_object; ; i = (survarium::game_effect_emitter *)i->__vftable )
  {
    if ( !i )
    {
      v16 = 0;
      goto LABEL_14;
    }
    if ( (survarium::hit_type_parameters *)i->type == time_in_ms )
      break;
  }
  v16 = i;
LABEL_14:
  v17 = *(float *)&v16->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v18 = s_bm_current_air_resistance;
  if ( v17 == 0.0 )
    goto LABEL_20;
  v19 = (float)(*out_damage - v17) / v17;
  if ( v19 <= 0.0 )
  {
    v20 = 0.0;
    goto LABEL_21;
  }
  if ( s_bm_current_air_resistance < v19 )
LABEL_20:
    v20 = s_bm_current_air_resistance;
  else
    v20 = (float)(*out_damage - v17) / v17;
LABEL_21:
  v21 = (float)(s_bm_current_air_resistance - v20) * (float)(s_bm_current_air_resistance - v20);
  if ( last_hitted_body_part )
    *(float *)&last_hitted_body_part->next = (float)(s_bm_current_air_resistance - v21) * v14;
  *v13 = (float)(v18 - (float)(*((float *)&v16->vostok::resources::resource_flags + 3) * v21)) * v14;
  for ( j = v9[9].m_value; j != 0.0; j = *(float *)(LODWORD(j) + 104) )
  {
    if ( (*(_DWORD *)(LODWORD(j) + 40) != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      if ( !*(_DWORD *)(LODWORD(j) + 40) )
      {
        boost::bad_function_call::bad_function_call((boost::bad_function_call *)v16, (stlp_std::runtime_error *)&v40);
        boost::throw_exception(v23);
        stlp_std::__Named_exception::~__Named_exception(&v40);
        v13 = armor_piercing;
      }
      (*(void (__cdecl **)(int, const char *, survarium::hit_type_parameters *, float *))((*(_DWORD *)(LODWORD(j) + 40)
                                                                                         & 0xFFFFFFFE)
                                                                                        + 4))(
        LODWORD(j) + 48,
        a9,
        time_in_ms,
        v13);
    }
  }
  type = orientation;
  if ( orientation == (survarium::hit_type_parameters *)v9
    || orientation && (v25 = BYTE1(v9[8].m_effect_emitter.m_object), v25 != -1) && BYTE1(orientation[5].m_reduce) == v25 )
  {
    *v13 = 0.0;
  }
  else
  {
    for ( k = v9->m_effect_emitter.m_object; ; k = (survarium::game_effect_emitter *)k->__vftable )
    {
      if ( !k )
      {
        time_in_ms = 0;
        goto LABEL_39;
      }
      type = (survarium::hit_type_parameters *)k->type;
      if ( type == time_in_ms )
        break;
    }
    time_in_ms = (survarium::hit_type_parameters *)k;
LABEL_39:
    if ( !time_in_ms->m_invulnerable )
    {
      v27 = *(float *)&v9[7].m_affects_count - *v13;
      if ( v27 > 0.0 )
      {
        if ( v9[7].m_value < v27 )
          v27 = v9[7].m_value;
      }
      else
      {
        v27 = 0.0;
      }
      v28 = damage;
      m_affects_count = v9[1].m_affects_count;
      *(float *)&v9[7].m_affects_count = v27;
      *(float *)&v9[8].m_affects_count = v27;
      LODWORD(v9[8].m_value) = v28;
      while ( m_affects_count )
      {
        v30 = *(float *)(m_affects_count + 4);
        v31 = *(float *)&v9[7].m_affects_count;
        if ( (float)((float)v9[7].m_value * v30) > v31 || v30 == 0.0 && v31 == 0.0 )
          survarium::body_part_parameters::apply_affects(
            (survarium::body_part_parameters *)m_affects_count,
            v9,
            (unsigned int)damage);
        m_affects_count = *(_DWORD *)m_affects_count;
      }
      survarium::body_part_parameters::check_effects(
        (survarium::body_part_parameters *)type,
        (int)v9,
        (unsigned int)damage);
      v32 = (survarium::loose_ptr_data *)time_in_ms;
      v33 = time_in_ms->m_effect_emitter.m_object;
      if ( v33
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        p_m_effect = &time_in_ms->m_effect;
        v32 = time_in_ms->m_effect.m_object;
        if ( !v32 || !v32->m_pointer )
        {
          survarium::game_effect_emitter::emit((survarium::game_effect_emitter *)v32, (int)v33, (int *)&out_damage);
          survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(
            (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)out_damage,
            (survarium::loose_ptr_data **)&hit_type);
          survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::operator=(
            p_m_effect,
            (const survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&hit_type);
          survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>((survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&hit_type);
          LOBYTE(hit_type) = 0;
          boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
            v35,
            &v41,
            0,
            v39);
          survarium::game_effect_player::add(
            v36,
            (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&v9[5].m_effect_emitter.m_object[6].m_next_in_increase_quality_queue[3].m_fat_it,
            (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&out_damage,
            (unsigned int)damage,
            0,
            &v41);
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v37,
            (int *)&v41);
          vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&out_damage);
        }
        v13 = armor_piercing;
      }
      v38 = *v13;
      v42[0] = a9;
      armor_piercing = (float *)v42;
      *(float *)&v42[1] = v38;
      vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::notify_damage_received_functor>>(
        (vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *)v32,
        (int)&v9[10].m_value,
        (const vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::notify_damage_received_functor> *)&armor_piercing);
    }
    survarium::hit_type_parameters::apply_damage(time_in_ms, *v13, damage);
  }
}
