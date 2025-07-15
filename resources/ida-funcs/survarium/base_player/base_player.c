void __thiscall survarium::base_player::base_player(
        survarium::base_player *this,
        survarium::base_player_creation_params *params,
        vostok::buffer_vector<float> *other)
{
  vostok::animation::animation_player *v3; // ebx
  vostok::buffer_vector<float> *v4; // esi
  char m_end; // dl
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::buffer_vector<float> *v7; // eax
  vostok::animation::animation_player *v8; // ecx
  vostok::buffer_vector<float> *v9; // esi
  float *p_m_max_end; // eax
  float *v11; // ecx
  _DWORD *v12; // eax
  char *v13; // eax
  int i; // ecx
  _DWORD *v15; // eax
  char *v16; // eax
  survarium::base_player_creation_params *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // edi
  char *v19; // eax
  vostok::physics::bt_character_controller *v20; // eax
  _DWORD *v21; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  int *v23; // eax
  int v24; // ecx
  int v25; // eax
  float v26; // xmm0_4
  bool v27; // zf
  survarium::base_player_creation_params *v28; // eax
  vostok::collision::animated_object *v29; // ecx
  survarium::damage_model *v30; // ecx
  survarium::body_part_parameters *body_part; // eax
  void *v32; // ecx
  int v33; // ecx
  vostok::particle::particle_action *v34; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  survarium::damage_model *v36; // ecx
  survarium::body_part_parameters *v37; // eax
  survarium::body_part_events_subscriber *v38; // ecx
  vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *p_m_events_subscribers; // eax
  boost::function<enum vostok::collision::recompute_bones_result __cdecl(void *)> v40; // [esp-8h] [ebp-8Ch] BYREF
  unsigned int harmless_fall_heigth; // [esp+18h] [ebp-6Ch]
  const vostok::math::float2 *v42; // [esp+1Ch] [ebp-68h]
  const vostok::math::float2 *v43; // [esp+20h] [ebp-64h]
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> v44; // [esp+2Ch] [ebp-58h] BYREF
  float *v45; // [esp+4Ch] [ebp-38h] BYREF
  _BYTE v46[12]; // [esp+50h] [ebp-34h]
  boost::function<void __cdecl(float)> callback; // [esp+5Ch] [ebp-28h] BYREF
  int v48; // [esp+80h] [ebp-4h]

  v3 = (vostok::animation::animation_player *)params;
  vostok::resources::unmanaged_resource::unmanaged_resource(this, params, fs_iterator_class);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&params,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other[32].m_max_end);
  *(_DWORD *)&v3->m_tree_buffers[0][264] = &survarium::inventory_holder::`vftable';
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3->m_tree_buffers[0][268],
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&params);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&params);
  v4 = other;
  *(_DWORD *)&v3->m_tree_buffers[0][272] = &survarium::collision_user::`vftable';
  *(_DWORD *)&v3->m_tree_buffers[0][292] = -1;
  *(_DWORD *)&v3->m_tree_buffers[0][276] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][280] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][284] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][288] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][296] = 0;
  m_end = (char)v4[10].m_end;
  v3->m_tree_buffers[0][305] = *((_BYTE *)v4[10].m_begin + 444);
  v3->m_tree_buffers[0][304] = m_end;
  *(_DWORD *)&v3->m_tree_buffers[0][300] = &survarium::hit_initiator::`vftable';
  *(_DWORD *)&v3->m_tree_buffers[0][308] = &survarium::hit_receiver::`vftable';
  *(_DWORD *)&v3->m_tree_buffers[0][300] = &survarium::base_player::`vftable'{for `survarium::hit_initiator'};
  *(_DWORD *)&v3->m_tree_buffers[0][272] = &survarium::base_player::`vftable'{for `survarium::collision_user'};
  harmless_fall_heigth = 13;
  *(_DWORD *)&v3->m_tree_buffers[0][308] = &survarium::base_player::`vftable'{for `survarium::hit_receiver'};
  v40.functor.vostok_pointer_size_alignment[5] = &v3->m_tree_buffers[0][328];
  *(_DWORD *)&v3->m_tree_buffers[0][0] = &survarium::base_player::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)&v3->m_tree_buffers[0][264] = &survarium::base_player::`vftable'{for `survarium::inventory_holder'};
  *(_DWORD *)&v3->m_tree_buffers[0][312] = &survarium::base_player::`vftable'{for `survarium::spottable_object'};
  *(_DWORD *)&v3->m_tree_buffers[0][316] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][320] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][324] = 0;
  vostok::buffer_vector<float>::buffer_vector<float>(
    (float *)&v3->m_tree_buffers[0][340],
    v4,
    (vostok::buffer_vector<float> *)v40.functor.vostok_pointer_size_alignment[5],
    harmless_fall_heigth);
  vostok::buffer_vector<float>::buffer_vector<float>(
    (float *)&v3->m_tree_buffers[0][404],
    (vostok::buffer_vector<float> *)((char *)v4 + 64),
    (vostok::buffer_vector<float> *)&v3->m_tree_buffers[0][392],
    9u);
  v6 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)other;
  *(float *)&v3->m_tree_buffers[0][440] = *(float *)&v4[9].m_end;
  *(float *)&v3->m_tree_buffers[0][444] = *(float *)&v4[9].m_max_end;
  *(_DWORD *)&v3->m_tree_buffers[0][452] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][456] = 0;
  v4 = (vostok::buffer_vector<float> *)((char *)v4 + 140);
  *(_DWORD *)&v3->m_tree_buffers[0][460] = v4->m_begin;
  v4 = (vostok::buffer_vector<float> *)((char *)v4 + 4);
  *(_DWORD *)&v3->m_tree_buffers[0][464] = v4->m_begin;
  v4 = (vostok::buffer_vector<float> *)((char *)v4 + 4);
  *(_DWORD *)&v3->m_tree_buffers[0][468] = v4->m_begin;
  *(_DWORD *)&v3->m_tree_buffers[0][472] = v4->m_end;
  qmemcpy(&v3->m_tree_buffers[0][476], &v6[39], 0x3Cu);
  qmemcpy(&v3->m_tree_buffers[0][536], &v6[54], 0x34u);
  qmemcpy(&v3->m_tree_buffers[0][588], &v6[67], 0x24u);
  *(_DWORD *)&v3->m_tree_buffers[0][624] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][656] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][664] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][696] = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3->m_tree_buffers[0][704],
    v6 + 97);
  v7 = other;
  v3->m_tree_buffers[0][708] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][712] = v7[33].m_end;
  *(_DWORD *)&v3->m_tree_buffers[0][716] = v7[33].m_max_end;
  *(vostok::buffer_vector<float> *)&v3->m_tree_buffers[0][720] = v7[34];
  *(_DWORD *)&v3->m_tree_buffers[0][732] = v7[35].m_begin;
  *(_DWORD *)&v3->m_tree_buffers[0][736] = -1;
  *(_DWORD *)&v3->m_tree_buffers[0][740] = -1;
  *(_DWORD *)&v3->m_tree_buffers[0][744] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][748] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][752] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][756] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][760] = 0;
  *(float *)&v3->m_tree_buffers[0][764] = 0.0;
  *(_DWORD *)&v3->m_tree_buffers[0][772] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][776] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][780] = v7[11].m_begin;
  survarium::game_effect_player::game_effect_player(
    (survarium::game_effect_player *)&v3->m_tree_buffers[0][744],
    (int)&v3->m_tree_buffers[0][784]);
  *(_DWORD *)&v3->m_tree_buffers[0][840] = 0;
  vostok::animation::animation_player::animation_player(v8, (int)&v3->m_tree_buffers[0][848]);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_10E28 + (_DWORD)v3),
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other[35].m_end);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_10E78 + (_DWORD)v3),
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other[33]);
  v9 = other;
  p_m_max_end = (float *)&other[28].m_max_end;
  v11 = (float *)((char *)&unk_10E7C + (_DWORD)v3);
  if ( (float **)((char *)&unk_10E7C + (_DWORD)v3) != &other[28].m_max_end )
  {
    *v11 = *p_m_max_end;
    v11[1] = p_m_max_end[1];
    v11[2] = p_m_max_end[2];
    v11[3] = p_m_max_end[3];
    v11[4] = p_m_max_end[4];
    v11[5] = p_m_max_end[5];
    v11[6] = p_m_max_end[6];
    v11[7] = p_m_max_end[7];
    v11[8] = p_m_max_end[8];
    v11[9] = p_m_max_end[9];
    v11[10] = p_m_max_end[10];
  }
  v12 = (int *)((char *)&dword_10EA8 + (_DWORD)v3);
  *v12 = 0;
  v12[1] = 0;
  v12[2] = 0;
  v13 = &byte_10EB8[(_DWORD)v3];
  for ( i = 8; i >= 0; --i )
  {
    *(_DWORD *)v13 = 0;
    *((_DWORD *)v13 + 8) = 0;
    v13 += 40;
  }
  v15 = (_DWORD *)((char *)&loc_11020 + (_DWORD)v3);
  *v15 = 0;
  v15[8] = 0;
  v15[16] = 0;
  *(_DWORD *)&v3->m_tree_buffers[0][(_DWORD)&loc_11066 + 2] = v9[10].m_begin;
  survarium::player_stamina::player_stamina(
    (survarium::player_stamina *)i,
    (const survarium::stamina_base_parameters *)((char *)v3 + (_DWORD)&loc_1106F + 1),
    (survarium::player_params_modifiers_container *)&v9[25].m_end,
    COERCE_FLOAT((int)(v9[10].m_begin + 112)));
  v16 = (char *)v3 + (_DWORD)&loc_1110F + 1;
  *(_DWORD *)v16 = 0;
  *((_DWORD *)v16 + 1) = 0;
  *((_DWORD *)v16 + 2) = 0;
  v17 = *(survarium::base_player_creation_params **)&v3->m_tree_buffers[0][780];
  *(_DWORD *)((char *)&loc_1111C + (_DWORD)v3) = 0;
  v18 = survarium::g_allocator;
  params = v17;
  v19 = type_info::raw_name(&vostok::physics::bt_character_controller `RTTI Type Descriptor');
  v20 = (vostok::physics::bt_character_controller *)v18->call_malloc(
                                                      v18,
                                                      12u,
                                                      v19,
                                                      "vostok::physics::create_character_controller",
                                                      ".\\character_controller.cpp",
                                                      32u);
  if ( v20 )
    vostok::physics::bt_character_controller::bt_character_controller(
      (vostok::physics::bullet_physics_world *)params,
      v20,
      (vostok::math::float2 *)&v9[35].m_max_end,
      (const vostok::math::float2 *)&v9[36].m_end,
      v42,
      v43);
  else
    v21 = 0;
  *(int *)((char *)&dword_10E74 + (_DWORD)v3) = (int)v21;
  *(_DWORD *)(*v21 + 16) = &v3->m_tree_buffers[0][308];
  *(_DWORD *)(v21[1] + 16) = &v3->m_tree_buffers[0][308];
  callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::on_physical_controller_landing;
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)v3, 0);
  v45 = (float *)survarium::base_player::on_physical_controller_landing;
  *(_QWORD *)v46 = __PAIR64__((unsigned int)v3, 0);
  *(float *)&harmless_fall_heigth = COERCE_FLOAT(&v45);
  *(_DWORD *)&v46[8] = callback.functor.vostok_pointer_size_alignment[5];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__(*(unsigned int *)v46, (unsigned int)v45);
    *((_QWORD *)&callback.functor.data + 1) = *(_QWORD *)&v46[4];
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,float>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::base_player,float>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::physics::bt_character_controller::set_landing_callback(
    (vostok::physics::bt_character_controller *)&v45,
    *(_DWORD **)((char *)&dword_10E74 + (_DWORD)v3),
    &callback,
    *(float *)&v3->m_tree_buffers[0][724]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v22,
    (int *)&callback);
  v23 = *(int **)((char *)&dword_10E74 + (_DWORD)v3);
  v24 = *v23;
  v25 = v23[1];
  v26 = *(float *)&v3->m_tree_buffers[0][732];
  *(float *)(v24 + 1160) = v26;
  *(float *)(v25 + 568) = v26;
  *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10E78 + (_DWORD)v3) + 300) + 12) = &v3->m_tree_buffers[0][308];
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)v3, 0);
  callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::recompute_damage_collision_bones;
  v45 = (float *)survarium::base_player::recompute_damage_collision_bones;
  *(_QWORD *)v46 = __PAIR64__((unsigned int)v3, 0);
  params = (survarium::base_player_creation_params *)&(&v40.vtable)[1];
  (&v40.vtable)[1] = 0;
  v40.vtable = (boost::detail::function::vtable_base *)&v45;
  *(_DWORD *)&v46[8] = callback.functor.vostok_pointer_size_alignment[5];
  v27 = !Scaleform::Render::RenderEvent::GetListenerStatus(0);
  v28 = params;
  v29 = (vostok::collision::animated_object *)&v45;
  if ( v27 )
  {
    if ( params != (survarium::base_player_creation_params *)-8 )
    {
      params->speed_parameters.m_multipliers.m_max_end = v45;
      v28->speed_parameters.m_multipliers.m_buffer[0] = *(vostok::fixed_vector<float,13>::allign_helper *)v46;
      v28->speed_parameters.m_multipliers.m_buffer[1] = *(vostok::fixed_vector<float,13>::allign_helper *)&v46[4];
      v28->speed_parameters.m_multipliers.m_buffer[2] = *(vostok::fixed_vector<float,13>::allign_helper *)&v46[8];
    }
    v29 = (vostok::collision::animated_object *)((char *)&`boost::function1<enum vostok::collision::recompute_bones_result,void *>::assign_to<boost::_bi::bind_t<enum vostok::collision::recompute_bones_result,boost::_mfi::mf1<enum vostok::collision::recompute_bones_result,survarium::base_player,void *>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                               + 1);
    v28->speed_parameters.m_multipliers.m_begin = (float *)((char *)&`boost::function1<enum vostok::collision::recompute_bones_result,void *>::assign_to<boost::_bi::bind_t<enum vostok::collision::recompute_bones_result,boost::_mfi::mf1<enum vostok::collision::recompute_bones_result,survarium::base_player,void *>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                          + 1);
  }
  else
  {
    params->speed_parameters.m_multipliers.m_begin = 0;
  }
  v40.vtable = *(boost::detail::function::vtable_base **)((char *)&dword_10E78 + (_DWORD)v3);
  vostok::collision::animated_object::set_recompute_bones_callback(v29, v40, harmless_fall_heigth);
  survarium::setup_damage_model_from_profile(
    *(survarium::damage_model **)&v3->m_tree_buffers[0][704],
    *(const survarium::player_profile **)&v3->m_tree_buffers[0][(_DWORD)&loc_11066 + 2],
    *(const survarium::items_dictionary **)(*(_DWORD *)&v3->m_tree_buffers[0][268] + 268));
  body_part = survarium::damage_model::get_body_part(v30, *(_DWORD *)&v3->m_tree_buffers[0][704], "pain");
  harmless_fall_heigth = (unsigned int)v32;
  v40.functor.vostok_pointer_size_alignment[5] = v32;
  v33 = *(_DWORD *)&v3->m_tree_buffers[0][(_DWORD)&loc_11066 + 2];
  *(float *)&harmless_fall_heigth = 1.0;
  body_part->m_max_health = survarium::player_params_modifiers_container::apply_modifier(
                              (survarium::player_params_modifiers_container *)(v33 + 448),
                              pain_health_modifier,
                              v26,
                              body_part->m_max_health,
                              1.0);
  *(_DWORD *)(*(_DWORD *)&v3->m_tree_buffers[0][704] + 1784) = v3;
  callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::on_broken_limb_affect;
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[3] = survarium::base_player::on_broken_limb_affect;
  *((_QWORD *)&v40.functor.data + 2) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[2] = &v3->m_tree_buffers[0][624];
  boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::base_player,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::base_player *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::base_player,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::base_player *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)(&v40.functor.data + 8),
    (unsigned int)callback.functor.vostok_pointer_size_alignment[5]);
  callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::on_broken_limb_affect;
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[3] = survarium::base_player::on_broken_limb_affect;
  *((_QWORD *)&v40.functor.data + 2) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[2] = &v3->m_tree_buffers[0][664];
  boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::base_player,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::base_player *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::base_player,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::base_player *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)(&v40.functor.data + 8),
    (unsigned int)callback.functor.vostok_pointer_size_alignment[5]);
  survarium::damage_model::subscribe_on_affect(
    *(survarium::damage_model **)&v3->m_tree_buffers[0][704],
    affects_type_leg_damage,
    (survarium::affect_subscriber *const)&v3->m_tree_buffers[0][624]);
  survarium::damage_model::subscribe_on_affect(
    *(survarium::damage_model **)&v3->m_tree_buffers[0][704],
    affects_type_hand_damage,
    (survarium::affect_subscriber *const)&v3->m_tree_buffers[0][664]);
  params = (survarium::base_player_creation_params *)&byte_10EB8[(_DWORD)v3];
  v48 = 9;
  do
  {
    callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::on_affect;
    callback.functor.vostok_pointer_size_alignment[3] = 0;
    callback.functor.bound_memfunc_ptr.obj_ptr = (void *)v3;
    v45 = (float *)survarium::base_player::on_affect;
    *(_DWORD *)v46 = 0;
    *(_QWORD *)&v46[4] = __PAIR64__((unsigned int)callback.functor.vostok_pointer_size_alignment[5], (unsigned int)v3);
    *(float *)&harmless_fall_heigth = COERCE_FLOAT(&v45);
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(v34) )
    {
      v44.vtable = 0;
    }
    else
    {
      *(_QWORD *)&v44.functor.obj_ptr = __PAIR64__(*(unsigned int *)v46, (unsigned int)v45);
      *((_QWORD *)&v44.functor.data + 1) = *(_QWORD *)&v46[4];
      v44.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::base_player,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::base_player *>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>'::`2'::stored_vtable
                                                          + 1);
    }
    boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
      (boost::function1<void,vostok::physics::contact_point const &> *)params,
      &v44);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v35,
      (int *)&v44);
    params = (survarium::base_player_creation_params *)((char *)params + 40);
    --v48;
  }
  while ( v48 );
  callback.functor.vostok_pointer_size_alignment[2] = survarium::base_player::on_pain_regenerated;
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[3] = survarium::base_player::on_pain_regenerated;
  *((_QWORD *)&v40.functor.data + 2) = __PAIR64__((unsigned int)v3, 0);
  v40.functor.vostok_pointer_size_alignment[2] = (char *)&loc_11040 + (_DWORD)v3;
  boost::function<void __cdecl (unsigned int,char const *)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::base_player>,boost::_bi::list1<boost::_bi::value<survarium::base_player *>>>>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::base_player>,boost::_bi::list1<boost::_bi::value<survarium::base_player *> > > *)(&v40.functor.data + 8),
    (unsigned int)callback.functor.vostok_pointer_size_alignment[5]);
  v37 = survarium::damage_model::get_body_part(v36, *(_DWORD *)&v3->m_tree_buffers[0][704], "pain");
  v38 = (survarium::body_part_events_subscriber *)((char *)&loc_11020 + (_DWORD)v3);
  *(_DWORD *)((char *)&loc_11020 + (_DWORD)v3 + 64) = 0;
  p_m_events_subscribers = &v37->m_events_subscribers;
  if ( p_m_events_subscribers->m_first )
    p_m_events_subscribers->m_last->next = v38;
  else
    p_m_events_subscribers->m_first = v38;
  p_m_events_subscribers->m_last = v38;
  *(_DWORD *)(*(_DWORD *)&v3->m_tree_buffers[0][268] + 376) = &v3->m_tree_buffers[0][264];
  *(_DWORD *)&v3->m_tree_buffers[0][276] = &v3->m_tree_buffers[0][272];
  if ( !LOBYTE(other[11].m_end) )
    survarium::base_player::set_resolvers(
      (survarium::base_player *)&v3->m_tree_buffers[0][264],
      v3,
      (survarium::animations_registry *)&v3->m_tree_buffers[0][848]);
}
