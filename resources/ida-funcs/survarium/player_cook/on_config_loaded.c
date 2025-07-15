void __userpurge survarium::player_cook::on_config_loaded(
        survarium::player_cook *this@<ecx>,
        survarium::pure_game_effect_emitter_base *a2@<ebp>,
        const vostok::variant<32> *const *a3@<edi>,
        const char *a4@<esi>,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::configs::binary_config_value *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  survarium::player_creation_params *v12; // ecx
  int v13; // eax
  int v14; // esi
  survarium::player_creation_params *v15; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v16; // esi
  void *v17; // esp
  void *v18; // esp
  vostok::resources::class_id_enum *v19; // edi
  vostok::variant<32> *v20; // ecx
  const char **v21; // eax
  vostok::buffer_string *v22; // ecx
  const char **v23; // eax
  vostok::buffer_string *v24; // ecx
  vostok::memory::doug_lea_allocator *v25; // esi
  char *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  char *v28; // eax
  char *v29; // edi
  int v30; // eax
  vostok::resources::class_id_enum v31; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  vostok::variant<32> *v33; // ecx
  vostok::variant<32> *v34; // ecx
  vostok::configs::binary_config_value *v35; // [esp-314h] [ebp-320h]
  const vostok::variant<32> *const *v36; // [esp-310h] [ebp-31Ch] BYREF
  const char *v37; // [esp-30Ch] [ebp-318h]
  unsigned int v38[3]; // [esp-308h] [ebp-314h] BYREF
  _BYTE v39[260]; // [esp-2FCh] [ebp-308h] BYREF
  char v40; // [esp-1F8h] [ebp-204h] BYREF
  _DWORD v41[3]; // [esp-1F0h] [ebp-1FCh] BYREF
  _BYTE v42[260]; // [esp-1E4h] [ebp-1F0h] BYREF
  char v43; // [esp-E0h] [ebp-ECh] BYREF
  _DWORD v44[10]; // [esp-D8h] [ebp-E4h] BYREF
  _DWORD *v45; // [esp-B0h] [ebp-BCh]
  int v46; // [esp-ACh] [ebp-B8h]
  _DWORD v47[10]; // [esp-A8h] [ebp-B4h] BYREF
  _DWORD *v48; // [esp-80h] [ebp-8Ch]
  int v49; // [esp-7Ch] [ebp-88h]
  int v50; // [esp-78h] [ebp-84h] BYREF
  _DWORD v51[6]; // [esp-70h] [ebp-7Ch] BYREF
  survarium::player_cook *v52; // [esp-54h] [ebp-60h]
  const vostok::variant<32> **v53; // [esp-50h] [ebp-5Ch]
  vostok::resources::request v54[3]; // [esp-4Ch] [ebp-58h] BYREF
  const vostok::variant<32> *const *v55[3]; // [esp-34h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::resources::request> v56; // [esp-28h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v57; // [esp-1Ch] [ebp-28h] BYREF
  int v58; // [esp-18h] [ebp-24h]
  vostok::resources::class_id_enum **i; // [esp-14h] [ebp-20h]
  vostok::resources::request v60; // [esp-10h] [ebp-1Ch] BYREF
  vostok::configs::binary_config_value *v61; // [esp-8h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v62[4]; // [esp-4h] [ebp-10h] BYREF
  survarium::pure_game_effect_emitter_base *retaddr; // [esp+Ch] [ebp+0h]

  v62[1].m_object = a2;
  v62[2].m_object = retaddr;
  v37 = a4;
  v36 = a3;
  v52 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v62,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v62[0].m_object;
  v57.m_object = 0;
  if ( v62[0].m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v57);
    v57.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v62);
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)v57.m_object->m_lods[0].m_template.m_object,
         "player");
  v7 = survarium::g_allocator;
  v61 = v6;
  m_parent_query = data->m_parent_query;
  v53 = (const vostok::variant<32> **)m_parent_query;
  v9 = type_info::raw_name(&survarium::player_creation_params `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v7, 0x260u, v9, (const char *const)v36, v37, v38[0]);
  if ( v11 )
  {
    survarium::player_creation_params::player_creation_params(v12, v11);
    v14 = v13;
    v58 = v13;
  }
  else
  {
    v58 = 0;
    v14 = 0;
  }
  i = (vostok::resources::class_id_enum **)(v14 + 120);
  vostok::variant<32>::try_get<survarium::player_initial_info>(
    (vostok::variant<32> *)v12,
    (int)m_parent_query->m_user_data->m_helper_storage,
    (survarium::player_initial_info *)(v14 + 120));
  v35 = v61;
  *(_DWORD *)(v14 + 452) = *(_DWORD *)(v14 + 128);
  survarium::player_creation_params::load(v15, (const vostok::configs::binary_config_value *)v14, v35);
  *(_DWORD *)(v14 + 456) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v14 + 452) + 160) + 13908);
  *(_WORD *)(v14 + 604) = vostok::configs::binary_config_value::operator[](v61, "min_toxic_damage_sounds_interval")->data.pointer;
  *(_WORD *)(v14 + 606) = vostok::configs::binary_config_value::operator[](v61, "max_toxic_damage_sounds_interval")->data.pointer;
  v16 = (vostok::buffer_vector<vostok::variant<32> const *> *)(24
                                                             * vostok::configs::binary_config_value::operator[](
                                                                 v61,
                                                                 "damage_sounds")->count
                                                             / 24
                                                             + (*(_BYTE *)(v14 + 136) != 0)
                                                             + 5);
  v17 = alloca(8 * (_DWORD)v16);
  v56.m_max_end = (vostok::resources::request *)&(&v36)[2 * (_DWORD)v16];
  v56.m_begin = (vostok::resources::request *)&v36;
  v56.m_end = (vostok::resources::request *)&v36;
  v18 = alloca(4 * (_DWORD)v16);
  v62[0].m_object = 0;
  v55[0] = (const vostok::variant<32> *const *)&v36;
  v55[1] = (const vostok::variant<32> *const *)&v36;
  v55[2] = (const vostok::variant<32> *const *)&(&v36)[(_DWORD)v16];
  vostok::buffer_vector<vostok::variant<32> const *>::resize(v16, (int *)v55, v62, v36);
  v45 = 0;
  v46 = 0;
  v19 = *i;
  vostok::variant<32>::destroy_previous_variable_if_needed(v20, (int)v44);
  v46 = vostok::detail::type_to_int<survarium::player_profile const *>::get();
  v45 = v44;
  v44[2] = v19;
  v44[0] = &vostok::detail::concrete_type_helper<survarium::player_profile const *>::`vftable';
  *v55[0] = (const vostok::variant<32> *const)v44;
  v60.path = "combined_skin";
  v60.id = player_skin_visual_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v60);
  v60.path = "character/human/base/base_character_full";
  v60.id = skeleton_model_instance_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v60);
  v41[0] = v42;
  v41[1] = v42;
  v41[2] = &v43;
  v42[0] = 0;
  v43 = 47;
  v21 = (const char **)vostok::configs::binary_config_value::operator[](v61, "skeleton_model_instance");
  vostok::fs_new::path_string_impl::assignf(
    v41,
    v22,
    (vostok::buffer_string *)"resources/models/%s.skinned_model/hit_targets",
    *v21);
  v60.path = (const char *)v41[0];
  v60.id = binary_config_class_impl;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v60);
  v38[0] = (unsigned int)v39;
  v38[1] = (unsigned int)v39;
  v38[2] = (unsigned int)&v40;
  v39[0] = 0;
  v40 = 47;
  v23 = (const char **)vostok::configs::binary_config_value::operator[](v61, "skeleton_model_instance");
  vostok::fs_new::path_string_impl::assignf(
    v38,
    v24,
    (vostok::buffer_string *)"resources/models/%s.skinned_model/settings",
    *v23);
  v60.path = (const char *)v38[0];
  v60.id = binary_config_class_impl;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v60);
  v25 = survarium::g_allocator;
  v26 = type_info::raw_name(&survarium::inventory_cooker_data `RTTI Type Descriptor');
  v28 = vostok::memory::doug_lea_allocator::malloc_impl(v27, (int)v25, 0x14u, v26, (const char *const)v36, v37, v38[0]);
  if ( v28 )
  {
    v29 = v28;
    *(_DWORD *)v28 = 0;
    *((_DWORD *)v28 + 1) = 0;
    *((_DWORD *)v28 + 2) = 0;
    *((_DWORD *)v28 + 3) = 0;
    v28[16] = 0;
    v62[0].m_object = (survarium::pure_game_effect_emitter_base *)v28;
  }
  else
  {
    v62[0].m_object = 0;
    v29 = 0;
  }
  *(_DWORD *)v29 = *i;
  v30 = v58;
  *((_DWORD *)v29 + 1) = *(_DWORD *)(v58 + 456);
  *((_DWORD *)v29 + 2) = *(_DWORD *)(v30 + 132);
  *((_DWORD *)v29 + 3) = *(_DWORD *)(v30 + 128);
  v29[16] = *(_BYTE *)(v30 + 136);
  v48 = 0;
  v49 = 0;
  vostok::variant<32>::destroy_previous_variable_if_needed(0, (int)v47);
  v49 = vostok::detail::type_to_int<survarium::inventory_cooker_data *>::get();
  v48 = v47;
  v47[2] = v29;
  v47[0] = &vostok::detail::concrete_type_helper<survarium::inventory_cooker_data *>::`vftable';
  v55[0][v56.m_end - v56.m_begin] = (const vostok::variant<32> *const)v47;
  v60.path = "inventory";
  v60.id = inventory_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v60);
  qmemcpy(v51, vostok::configs::binary_config_value::operator[](v61, "damage_sounds"), sizeof(v51));
  v60.id = v51[0] + 24 * HIWORD(v51[5]);
  for ( i = (vostok::resources::class_id_enum **)v51[0]; i != (vostok::resources::class_id_enum **)v60.id; i += 6 )
  {
    v31 = **i;
    v54[2].path = (const char *)(*i)[6];
    v54[2].id = v31;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v54[2]);
  }
  if ( *(_BYTE *)(v58 + 136) )
  {
    v54[2].path = (const char *)vostok::configs::binary_config_value::operator[](v61, "empty_hands")->data.pointer;
    v54[2].id = empty_hands_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v54[2]);
  }
  v51[1] = 0;
  v51[0] = survarium::player_cook::on_subresources_loaded;
  v51[2] = v52;
  v51[3] = v58;
  v51[4] = v62[0];
  qmemcpy(v54, v51, sizeof(v54));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v50 = 0;
  }
  else
  {
    qmemcpy(v51, v54, sizeof(v51));
    v50 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *>,boost::_bi::list4<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>>>>'::`2'::stored_vtable
        + 1;
  }
  vostok::resources::query_resources(
    v56.m_begin,
    v56.m_end - v56.m_begin,
    survarium::g_allocator,
    v55[0],
    v53,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v32, &v50);
  vostok::variant<32>::destroy_previous_variable_if_needed(v33, (int)v47);
  vostok::variant<32>::destroy_previous_variable_if_needed(v34, (int)v44);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v57);
}
