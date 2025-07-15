void __thiscall survarium::victory_items_container_cook::create_resource(
        survarium::victory_items_container_cook *this,
        const vostok::variant<32> **parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer buffer)
{
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v4; // edi
  vostok::configs::binary_config_value *v5; // eax
  vostok::variant<32> *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  char *m_data; // ecx
  int v13; // eax
  survarium::pure_game_effect_emitter_base *v14; // edi
  survarium::pure_game_effect_emitter_base *v15; // ecx
  _BYTE v16[52]; // [esp-34h] [ebp-1C4h] BYREF
  int pointer; // [esp+10h] [ebp-180h]
  vostok::resources::memory_usage_type v18; // [esp+14h] [ebp-17Ch] BYREF
  survarium::victory_items_container_cook *v19; // [esp+1Ch] [ebp-174h]
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,survarium::victory_items_container_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::victory_items_container_core_creation_params const *,vostok::math::float3 const &,vostok::math::float3 const &>,boost::_bi::list6<boost::_bi::value<survarium::victory_items_container_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::victory_items_container_core_creation_params const *>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<vostok::math::float3> > > f; // [esp+20h] [ebp-170h] BYREF
  _BYTE v21[40]; // [esp+50h] [ebp-140h] BYREF
  survarium::victory_items_container::victory_item_transform *victory_item_transforms; // [esp+78h] [ebp-118h] BYREF
  _BYTE *v23; // [esp+7Ch] [ebp-114h]
  char *v24; // [esp+80h] [ebp-110h]
  _BYTE v25[240]; // [esp+84h] [ebp-10Ch] BYREF
  char v26; // [esp+174h] [ebp-1Ch] BYREF
  _BYTE v27[8]; // [esp+188h] [ebp-8h] BYREF

  pointer = 0;
  v19 = this;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&f);
  v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v6, (int)parent[66], v5) )
  {
    if ( vostok::configs::binary_config_value::value_exists(v7, (int)&f, (unsigned int)"visual_geometry") )
    {
      v8 = vostok::configs::binary_config_value::operator[](
             (vostok::configs::binary_config_value *)&f,
             "visual_geometry");
      pointer = (int)vostok::configs::binary_config_value::operator[](v8, "position")->data.pointer;
      v18.type = (const vostok::resources::memory_type *)vostok::configs::binary_config_value::operator[](
                                                           v8,
                                                           "rotation")->data.pointer;
      *(_DWORD *)&v16[48] = vostok::configs::binary_config_value::operator[](v8, "model_name")->data.pointer;
      victory_item_transforms = (survarium::victory_items_container::victory_item_transform *)v25;
      v23 = v25;
      v24 = v27;
      v25[0] = 0;
      v27[0] = 47;
      vostok::fs_new::path_string_impl::assignf(
        &victory_item_transforms,
        (vostok::buffer_string *)v27,
        (vostok::buffer_string *)"resources/models/%s.model/render/export_properties",
        *(const char **)&v16[48]);
      *(_DWORD *)v21 = v19;
      *(vostok::mutable_buffer *)&v21[4] = buffer;
      *(_DWORD *)&v21[12] = raw_file_data.m_data;
      *(_DWORD *)&v21[16] = *(_DWORD *)pointer;
      *(_DWORD *)&v21[20] = *(_DWORD *)(pointer + 4);
      *(_DWORD *)&v21[24] = *(_DWORD *)(pointer + 8);
      *(_DWORD *)&v21[28] = v18.type->m_next;
      *(_DWORD *)&v21[32] = v18.type->m_name;
      HIDWORD(f.f_.f_) = 0;
      *(_DWORD *)&v21[36] = *(_DWORD *)&v18.type->in_list;
      LODWORD(f.f_.f_) = survarium::victory_items_container_cook::on_locators_config_ready;
      qmemcpy(&f.l_, v21, sizeof(f.l_));
      *(_DWORD *)v16 = &f;
      qmemcpy(&v16[4], &f, 0x30u);
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        0,
        *(boost::_bi::bind_t<void,boost::_mfi::mf5<void,survarium::victory_items_container_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::victory_items_container_core_creation_params const *,vostok::math::float3 const &,vostok::math::float3 const &>,boost::_bi::list6<boost::_bi::value<survarium::victory_items_container_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::victory_items_container_core_creation_params const *>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<vostok::math::float3> > > *)v16,
        *(int *)&v16[48]);
      v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
      vostok::resources::query_resource(
        (const char *)victory_item_transforms,
        (vostok::variant<32> *)0x20,
        survarium::g_allocator,
        0,
        parent,
        assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v9,
        (int *)&f);
      *(_DWORD *)&v16[48] = 0;
      *(_DWORD *)&v16[44] = 1;
      *(_DWORD *)&v16[40] = 2;
    }
    else
    {
      v18.type = (const vostok::resources::memory_type *)vostok::configs::binary_config_value::operator[](
                                                           (vostok::configs::binary_config_value *)&f,
                                                           "name")->data.pointer;
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            v10 = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> **)&v16[48],
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          v21);
        pointer = 1;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v21,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\victory_items_container_cook.cpp",
          0x3Cu,
          "void __thiscall survarium::victory_items_container_cook::create_resource(class vostok::resources::query_result"
          "_for_cook &,class vostok::const_buffer,class vostok::mutable_buffer)",
          "game",
          error,
          "Victory items container \"%s\" has no visual geometry",
          (const char *)v18.type);
      }
      if ( (pointer & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)v21);
      victory_item_transforms = (survarium::victory_items_container::victory_item_transform *)v25;
      v23 = v25;
      v24 = &v26;
      vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize(
        (vostok::buffer_vector<survarium::victory_items_container::victory_item_transform> *)v10,
        (int *)&victory_item_transforms);
      m_data = buffer.m_data;
      if ( buffer.m_data )
        survarium::victory_items_container::victory_items_container(
          (survarium::victory_items_container *)buffer.m_data,
          (v23 - (_BYTE *)victory_item_transforms) / 24,
          *(vostok::physics::world **)raw_file_data.m_data,
          *((survarium::gather_victory_items_rule **)raw_file_data.m_data + 1),
          (const vostok::configs::binary_config_value *)&f,
          victory_item_transforms);
      else
        v13 = 0;
      if ( v13 )
        v14 = (survarium::pure_game_effect_emitter_base *)(v13 + 72);
      else
        v14 = 0;
      *(_DWORD *)&v16[48] = m_data;
      v18.type = &vostok::resources::nocache_memory;
      v18.size = 624;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v16[48],
        v14);
      v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        &v18,
        v15,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
        *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v16[48]);
      *(_DWORD *)&v16[48] = 0;
      *(_DWORD *)&v16[44] = 1;
      *(_DWORD *)&v16[40] = 3;
    }
  }
  else
  {
    __debugbreak();
    *(_DWORD *)&v16[48] = 11;
    *(_DWORD *)&v16[44] = 1;
    *(_DWORD *)&v16[40] = 1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)v7,
    v4,
    *(vostok::resources::cook_base::result_enum *)&v16[40],
    *(const assert_on_fail_bool *)&v16[44],
    *(vostok::resources::cook_base::result_enum *)&v16[48]);
}
