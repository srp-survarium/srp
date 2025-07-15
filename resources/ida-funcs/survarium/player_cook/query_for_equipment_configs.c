void __thiscall survarium::player_cook::query_for_equipment_configs(
        survarium::player_cook *this,
        survarium::player_cook *params,
        survarium::player_creation_params *parent,
        const vostok::variant<32> **a4)
{
  vostok::buffer_vector<vostok::fs_new::virtual_path_string> *v4; // ecx
  survarium::inventory_item_descr *slots; // ebx
  survarium::dictionary_item *v6; // eax
  vostok::buffer_string *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > v9; // [esp-14h] [ebp-70Ch]
  vostok::resources::request v10; // [esp+Ch] [ebp-6ECh] BYREF
  survarium::items_dictionary *m_object; // [esp+14h] [ebp-6E4h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > f; // [esp+18h] [ebp-6E0h] BYREF
  vostok::buffer_vector<vostok::resources::request> v13; // [esp+38h] [ebp-6C0h] BYREF
  _BYTE v14[48]; // [esp+44h] [ebp-6B4h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+74h] [ebp-684h] BYREF
  _BYTE *v16; // [esp+188h] [ebp-570h] BYREF
  _BYTE *v17; // [esp+18Ch] [ebp-56Ch]
  char *v18; // [esp+190h] [ebp-568h]
  _BYTE v19[1380]; // [esp+194h] [ebp-564h] BYREF
  char vars0; // [esp+6F8h] [ebp+0h] BYREF

  m_object = params->m_game->m_items_dictionary.m_object;
  v13.m_begin = (vostok::resources::request *)v14;
  v13.m_end = (vostok::resources::request *)v14;
  v13.m_max_end = (vostok::resources::request *)&v15;
  v16 = v19;
  v17 = v19;
  v18 = &vars0;
  v10.path = "resources/gameplay/bodyparts/default";
  v10.id = binary_config_class_impl;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v13, &v10);
  slots = parent->initial_info.profile->slots;
  v10.path = (const char *)slots_with_sound_options;
  do
  {
    if ( slots[*(_DWORD *)v10.path].id )
    {
      v15.m_string.m_begin = v15.m_string.m_buffer;
      v15.m_string.m_end = v15.m_string.m_buffer;
      v15.m_string.m_max_end = &v15.m_separator;
      v15.m_string.m_buffer[0] = 0;
      v15.m_separator = 47;
      vostok::buffer_vector<vostok::fs_new::virtual_path_string>::push_back(v4, (int)&v16, &v15);
      v6 = survarium::items_dictionary::item_by_id(
             m_object,
             (survarium::items_dictionary_vtbl *)slots[*(_DWORD *)v10.path].dict_id);
      vostok::fs_new::path_string_impl::assignf(
        (_DWORD *)v17 - 69,
        v7,
        (vostok::buffer_string *)"resources/%s",
        v6->item_cfg_name.m_begin);
      LODWORD(f.f_.f_) = *((_DWORD *)v17 - 69);
      HIDWORD(f.f_.f_) = 32;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v13, (const vostok::resources::request *)&f);
    }
    v10.path += 8;
  }
  while ( (const float *)v10.path != &epsilon_5_286 );
  LODWORD(f.f_.f_) = survarium::player_cook::on_equipment_configs_loaded;
  f.l_.a1_.t_ = params;
  f.l_.a3_.t_ = parent;
  HIDWORD(f.f_.f_) = 0;
  HIDWORD(v9.f_.f_) = survarium::player_cook::on_equipment_configs_loaded;
  v9.l_.a1_.t_ = 0;
  v9.l_.a3_.t_ = (survarium::player_creation_params *)params;
  LODWORD(v9.f_.f_) = &f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v9,
    (int)parent);
  vostok::resources::query_resources(
    v13.m_begin,
    v13.m_end - v13.m_begin,
    survarium::g_allocator,
    0,
    a4,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, (int *)&f);
}
