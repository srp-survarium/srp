void __thiscall survarium::items_dictionary_cook::on_configs_loaded(
        survarium::items_dictionary_cook *this,
        vostok::configs::binary_config_value *data)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  const vostok::variant<32> **pointer; // eax
  vostok::memory::base_allocator *m_allocator; // esi
  char *v5; // eax
  vostok::memory::base_allocator *v6; // esi
  survarium::items_dictionary *v7; // ecx
  vostok::resources::request *M_data; // esi
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  vostok::resources::request *v12; // eax
  char *v13; // eax
  int v14; // esi
  int *v15; // eax
  _DWORD *v16; // edi
  vostok::render::stage_screen_space_reflections *v17; // ecx
  const vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // esi
  const vostok::configs::binary_config_value *v20; // eax
  vostok::resources::request *M_finish; // esi
  stlp_std::priv::_Impl_vector<survarium::items_compatibility,vostok::vectora_allocator<survarium::items_compatibility> > *v22; // ecx
  vostok::resources::request *v23; // esi
  const char *path; // ecx
  unsigned int v25; // eax
  const vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  vostok::strings::detail::tuples *v28; // eax
  int i; // ecx
  unsigned int v30; // eax
  void *v31; // esp
  vostok::strings::detail::tuples *v32; // ecx
  vostok::configs::binary_config_value *v33; // esi
  const vostok::configs::binary_config_value *v34; // eax
  int v35; // esi
  char *v36; // esi
  char *v37; // edx
  _BYTE *v38; // eax
  const void *v39; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v40; // ecx
  vostok::vectora<vostok::resources::request> *v41; // ecx
  vostok::configs::binary_config_value v42; // [esp-18h] [ebp-DCh] BYREF
  const stlp_std::__true_type *v43[2]; // [esp+0h] [ebp-C4h] BYREF
  BOOL v44; // [esp+8h] [ebp-BCh]
  vostok::strings::detail::tuples v45; // [esp+Ch] [ebp-B8h] BYREF
  int v46; // [esp+40h] [ebp-84h] BYREF
  const char *v47[9]; // [esp+48h] [ebp-7Ch] BYREF
  int v48; // [esp+6Ch] [ebp-58h]
  const vostok::variant<32> **v49; // [esp+74h] [ebp-50h]
  vostok::configs::binary_config_value v50; // [esp+78h] [ebp-4Ch] BYREF
  void (__thiscall *v51)(survarium::items_dictionary_cook *, vostok::resources::queries_result *, survarium::pure_game_effect_emitter_base *); // [esp+94h] [ebp-30h] BYREF
  const char *v52; // [esp+98h] [ebp-2Ch]
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v53; // [esp+9Ch] [ebp-28h] BYREF
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v54; // [esp+ACh] [ebp-18h] BYREF
  unsigned int v55; // [esp+BCh] [ebp-8h]

  v55 = 0;
  v2 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)data;
  pointer = (const vostok::variant<32> **)data[1].id.pointer;
  m_allocator = this->m_allocator;
  v53._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)this;
  v49 = pointer;
  v5 = type_info::raw_name(&survarium::items_dictionary `RTTI Type Descriptor');
  v53._M_impl._M_finish = (vostok::resources::request *)m_allocator->call_malloc(
                                                          m_allocator,
                                                          792u,
                                                          v5,
                                                          "survarium::items_dictionary_cook::on_configs_loaded",
                                                          ".\\items_dictionary_cook.cpp",
                                                          55u);
  if ( v53._M_impl._M_finish )
  {
    v55 = 15;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v53._M_impl._M_end_of_storage,
      v2 + 259);
    v6 = v53._M_impl._M_end_of_storage.m_allocator;
    v54._M_impl._M_finish = 0;
    if ( v53._M_impl._M_end_of_storage.m_allocator )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v54._M_impl._M_finish);
      v54._M_impl._M_finish = (vostok::resources::request *)v6;
      _InterlockedExchangeAdd((volatile signed __int32 *)&v6[10].m_arena_end, 1u);
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v54._M_impl._M_end_of_storage._M_data,
      v2 + 75);
    M_data = v54._M_impl._M_end_of_storage._M_data;
    data = 0;
    if ( v54._M_impl._M_end_of_storage._M_data )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      data = (vostok::configs::binary_config_value *)M_data;
      v7 = (survarium::items_dictionary *)_InterlockedExchangeAdd((volatile signed __int32 *)&M_data[26], 1u);
    }
    survarium::items_dictionary::items_dictionary(
      v7,
      (vostok::memory::base_allocator *)v53._M_impl._M_finish,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)v53._M_impl._M_end_of_storage._M_data[4].path,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v54._M_impl._M_finish);
    v10 = v9;
  }
  else
  {
    data = 0;
    v10 = 0;
  }
  if ( (v55 & 8) != 0 )
  {
    v55 &= ~8u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  }
  if ( (v55 & 4) != 0 )
  {
    v55 &= ~4u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v54._M_impl._M_end_of_storage._M_data);
  }
  if ( (v55 & 2) != 0 )
  {
    v55 &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v54._M_impl._M_finish);
  }
  if ( (v55 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v53._M_impl._M_end_of_storage);
  qmemcpy((void *)&v50, *(const void **)(*(_DWORD *)(v10 + 272) + 264), sizeof(v50));
  v11 = 24 * vostok::configs::binary_config_value::operator[](&v50, "quests")->count / 24;
  v12 = v53._M_impl._M_end_of_storage._M_data;
  *(_DWORD *)(v10 + 304) = v11;
  data = (vostok::configs::binary_config_value *)v12[4].path;
  v13 = type_info::raw_name(&survarium::quest_descriptor `RTTI Type Descriptor');
  v14 = 44 * v11;
  v15 = (int *)(*((int (__thiscall **)(vostok::configs::binary_config_value *, int, char *, const char *, const char *, int))data->data.pointer
                + 4))(
                 data,
                 176 * v11 + 8,
                 v13,
                 "survarium::items_dictionary_cook::on_configs_loaded",
                 ".\\items_dictionary_cook.cpp",
                 64);
  *v15++ = v11;
  v16 = v15 + 1;
  *v15 = 176;
  *(_DWORD *)&v42.type = &v15[v14 + 1];
  v42.id_crc = (unsigned int)(v15 + 1);
  vostok::memory::process_allocator::finalize_impl(v17);
  *(_DWORD *)(v10 + 308) = v16;
  v55 = 0;
  if ( *(_DWORD *)(v10 + 304) )
  {
    v54._M_impl._M_finish = 0;
    data = 0;
    do
    {
      v18 = vostok::configs::binary_config_value::operator[](&v50, "quests");
      qmemcpy((void *)&v42, (char *)data + (unsigned int)v18->data.pointer, sizeof(v42));
      survarium::load_quest_descriptor(
        (survarium::quest_descriptor *)((char *)v54._M_impl._M_finish + *(_DWORD *)(v10 + 308)),
        v42);
      ++data;
      v54._M_impl._M_finish += 22;
      ++v55;
    }
    while ( v55 < *(_DWORD *)(v10 + 304) );
  }
  v54._M_impl._M_end_of_storage._M_data = *(vostok::resources::request **)(*(_DWORD *)(v10 + 268) + 264);
  v19 = (vostok::configs::binary_config_value *)v54._M_impl._M_end_of_storage._M_data;
  data = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   (vostok::configs::binary_config_value *)v54._M_impl._M_end_of_storage._M_data,
                                                   "items_compatibility")->data.pointer;
  v20 = vostok::configs::binary_config_value::operator[](v19, "items_compatibility");
  M_finish = (vostok::resources::request *)((char *)v20->data.pointer + 24 * v20->count);
  v53._M_impl._M_finish = M_finish;
  while ( data != (vostok::configs::binary_config_value *)M_finish )
  {
    LOWORD(v54._M_impl._M_finish) = vostok::configs::binary_config_value::operator[](data, "first_item")->data.pointer;
    HIWORD(v54._M_impl._M_finish) = vostok::configs::binary_config_value::operator[](data, "second_item")->data.pointer;
    v22 = *(stlp_std::priv::_Impl_vector<survarium::items_compatibility,vostok::vectora_allocator<survarium::items_compatibility> > **)(v10 + 292);
    if ( v22 == *(stlp_std::priv::_Impl_vector<survarium::items_compatibility,vostok::vectora_allocator<survarium::items_compatibility> > **)(v10 + 300) )
    {
      stlp_std::priv::_Impl_vector<survarium::items_compatibility,vostok::vectora_allocator<survarium::items_compatibility>>::_M_insert_overflow(
        v22,
        (unsigned __int8 **)(v10 + 288),
        (survarium::items_compatibility *)v22,
        (const survarium::items_compatibility *)&v54._M_impl._M_finish,
        v43[0],
        (unsigned int)v43[1],
        v44);
      M_finish = v53._M_impl._M_finish;
    }
    else
    {
      v22->_M_start = (survarium::items_compatibility *)v54._M_impl._M_finish;
      *(_DWORD *)(v10 + 292) += 4;
    }
    ++data;
  }
  v23 = v53._M_impl._M_end_of_storage._M_data;
  path = v53._M_impl._M_end_of_storage._M_data[4].path;
  v50.id.max_storage = 0;
  v50.id_crc = (unsigned int)path;
  *(_DWORD *)&v50.type = 0;
  v53._M_impl._M_start = (vostok::resources::request *)"resources/gameplay/bodyparts/default";
  v53._M_impl._M_finish = (vostok::resources::request *)32;
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
    &v53,
    (const vostok::resources::request *)v43[0]);
  v25 = 24
      * vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v54._M_impl._M_end_of_storage._M_data,
          "items_dict")->count
      / 24;
  *(_DWORD *)(v10 + 284) = v25;
  *(_DWORD *)(v10 + 280) = vostok::memory::new_array_helper<survarium::dictionary_item>::call<vostok::memory::base_allocator>(
                             v25,
                             (vostok::memory::base_allocator *)v23[4].path);
  v55 = (unsigned int)vostok::configs::binary_config_value::operator[](
                        (vostok::configs::binary_config_value *)v54._M_impl._M_end_of_storage._M_data,
                        "items_dict")->data.pointer;
  v26 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v54._M_impl._M_end_of_storage._M_data,
          "items_dict");
  v53._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)((char *)v26->data.pointer
                                                                               + 24 * v26->count);
  if ( (vostok::memory::base_allocator *)v55 != v53._M_impl._M_end_of_storage.m_allocator )
  {
    v54._M_impl._M_end_of_storage._M_data = 0;
    v48 = 32;
    do
    {
      v27 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v55, "cfg_name");
      *(_DWORD *)&v42.type = 5;
      qmemcpy(v47, v27, 0x18u);
      v28 = &v45;
      for ( i = 5; i >= 0; --i )
      {
        v28->m_strings[0].first = 0;
        v28->m_strings[0].second = 0;
        v28 = (vostok::strings::detail::tuples *)((char *)v28 + 8);
      }
      v45.m_count = 2;
      vostok::strings::detail::tuples::helper<0>::add_string<char const *>(&v45, "resources/");
      if ( v47[0] )
        v30 = strlen(v47[0]);
      else
        v30 = 0;
      v45.m_strings[1].second = v30;
      v45.m_strings[1].first = v47[0];
      v31 = alloca(vostok::strings::detail::tuples::size((vostok::strings::detail::tuples *)v47[0], (unsigned int *)&v45));
      vostok::strings::detail::tuples::concat(v32, (int)&v45, (char *)v43);
      v54._M_impl._M_finish = (vostok::resources::request *)v48;
      v54._M_impl._M_start = (vostok::resources::request *)v43;
      stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
        &v54,
        (const vostok::resources::request *)v43[0]);
      v33 = (vostok::configs::binary_config_value *)v55;
      v53._M_impl._M_finish = (vostok::resources::request *)vostok::configs::binary_config_value::operator[](
                                                              (vostok::configs::binary_config_value *)v55,
                                                              "dict_id")->data.pointer;
      HIBYTE(data) = vostok::configs::binary_config_value::operator[](v33, "item_category")->data.pointer;
      HIBYTE(v54._M_impl._M_end_of_storage.m_allocator) = vostok::configs::binary_config_value::operator[](
                                                            v33,
                                                            "is_premium")->data.pointer != 0;
      v34 = vostok::configs::binary_config_value::operator[](v33, "is_stack");
      v35 = *(_DWORD *)(v10 + 280);
      BYTE2(v54._M_impl._M_end_of_storage.m_allocator) = v34->data.pointer != 0;
      v36 = (char *)v54._M_impl._M_end_of_storage._M_data + v35;
      *(_DWORD *)v36 = v53._M_impl._M_finish;
      v36[280] = HIBYTE(data);
      v37 = (char *)vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)v55,
                      "cfg_name")->data.pointer;
      v38 = (_BYTE *)*((_DWORD *)v36 + 2);
      *((_DWORD *)v36 + 3) = v38;
      *v38 = 0;
      vostok::buffer_string::operator+=((vostok::buffer_string *)(v36 + 8), v37);
      v36[282] = HIBYTE(v54._M_impl._M_end_of_storage.m_allocator);
      v36[283] = BYTE2(v54._M_impl._M_end_of_storage.m_allocator);
      v39 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v55, "item_level")->data.pointer;
      v55 += 24;
      v54._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)((char *)v54._M_impl._M_end_of_storage._M_data
                                                                           + 380);
      *((_DWORD *)v36 + 94) = v39;
    }
    while ( (vostok::memory::base_allocator *)v55 != v53._M_impl._M_end_of_storage.m_allocator );
    v23 = v53._M_impl._M_end_of_storage._M_data;
  }
  v47[8] = (const char *)v23;
  v47[6] = (const char *)survarium::items_dictionary_cook::on_subresources_loaded;
  v47[7] = 0;
  v48 = v10;
  v51 = survarium::items_dictionary_cook::on_subresources_loaded;
  v52 = 0;
  v53._M_impl._M_start = v23;
  *(_DWORD *)&v42.type = &v51;
  v53._M_impl._M_finish = (vostok::resources::request *)v10;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v46 = 0;
  }
  else
  {
    v47[0] = (const char *)v51;
    v47[1] = v52;
    v47[2] = (const char *)v53._M_impl._M_start;
    v47[3] = (const char *)v53._M_impl._M_finish;
    v46 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_dictionary_cook,vostok::resources::queries_result &,survarium::items_dictionary *>,boost::_bi::list3<boost::_bi::value<survarium::items_dictionary_cook *>,boost::arg<1>,boost::_bi::value<survarium::items_dictionary *>>>>'::`2'::stored_vtable
        + 1;
  }
  vostok::resources::query_resources(
    (const vostok::resources::request *)v50.id.pointer,
    (signed int)(HIDWORD(v50.id.max_storage) - (unsigned int)v50.id.pointer) >> 3,
    (vostok::memory::base_allocator *)v53._M_impl._M_end_of_storage._M_data[4].path,
    0,
    v49,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v40, &v46);
  vostok::vectora<vostok::resources::request>::~vectora<vostok::resources::request>(v41, (int)&v50.id);
}
