void __thiscall survarium::weapon_cook::on_weapon_config_loaded(
        survarium::weapon_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  const void *pointer; // eax
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  const void *v11; // eax
  int v12; // esi
  const vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  survarium::items_dictionary_vtbl *v16; // edx
  survarium::items_dictionary *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // ebx
  int v20; // esi
  void *v21; // esp
  vostok::configs::binary_config_value *v22; // eax
  vostok::resources::class_id_enum v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // eax
  vostok::variant<32> *m_user_data; // eax
  survarium::weapon *v27; // ecx
  boost::function1<void,vostok::resources::queries_result &> *v28; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v29; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > v30; // [esp-18h] [ebp-44h] BYREF
  _BYTE v31[12]; // [esp+0h] [ebp-2Ch] BYREF
  int v32[8]; // [esp+Ch] [ebp-20h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > result; // [esp+2Ch] [ebp+0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > v34; // [esp+44h] [ebp+18h] BYREF
  const vostok::variant<32> **m_parent_query; // [esp+5Ch] [ebp+30h]
  vostok::resources::class_id_enum v36; // [esp+60h] [ebp+34h]
  vostok::resources::class_id_enum v37; // [esp+68h] [ebp+3Ch]
  survarium::weapon_cook *a1; // [esp+6Ch] [ebp+40h]
  vostok::buffer_vector<vostok::resources::request> v39; // [esp+70h] [ebp+44h] BYREF
  int v40; // [esp+7Ch] [ebp+50h]
  int v41; // [esp+80h] [ebp+54h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v42; // [esp+84h] [ebp+58h] BYREF
  survarium::weapon_cook_data out_value; // [esp+88h] [ebp+5Ch] BYREF
  vostok::resources::request v44; // [esp+90h] [ebp+64h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v45; // [esp+98h] [ebp+6Ch] BYREF
  vostok::resources::unmanaged_resource *v46; // [esp+9Ch] [ebp+70h]

  a1 = this;
  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v45,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v45.m_object;
  v42.m_object = 0;
  if ( v45.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v42);
    v42.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v45);
  v46 = v42.m_object->m_lods[0].m_template.m_object;
  v3 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)v3, (unsigned int)"bullet_shells_count") )
  {
    v5 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
    pointer = vostok::configs::binary_config_value::operator[](v5, "bullet_shells_count")->data.pointer;
    *(_DWORD *)&out_value.preview_mode = 0;
    LOBYTE(v40) = (_BYTE)pointer;
  }
  else
  {
    LOBYTE(v40) = 10;
  }
  v7 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)v7, (unsigned int)"shoot_pfx_count") )
  {
    v10 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
    v11 = vostok::configs::binary_config_value::operator[](v10, "shoot_pfx_count")->data.pointer;
    *(_DWORD *)&out_value.preview_mode = 0;
    LOBYTE(v41) = (_BYTE)v11;
  }
  else
  {
    LOBYTE(v41) = 3;
  }
  v45.m_object = 0;
  v36 = (unsigned __int8)v41;
  v37 = (unsigned __int8)v40;
  v12 = (unsigned __int8)v40 + (unsigned __int8)v41 + 1;
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)v46, (unsigned int)"addons") )
  {
    v13 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "addons");
    if ( vostok::configs::binary_config_value::value_exists(v14, (int)v13, (unsigned int)"rifle_scope_dict_id") )
    {
      v15 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "addons");
      v16 = (survarium::items_dictionary_vtbl *)vostok::configs::binary_config_value::operator[](
                                                  v15,
                                                  "rifle_scope_dict_id")->data.pointer;
      v17 = a1->m_game->m_items_dictionary.m_object;
      *(_DWORD *)&out_value.preview_mode = 0;
      v45.m_object = (survarium::pure_game_effect_emitter_base *)survarium::items_dictionary::item_by_id(v17, v16)->item_cfg_name.m_begin;
      v12 = (unsigned __int8)v40 + (unsigned __int8)v41 + 2;
    }
  }
  v18 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v46,
          "user_animations_in_place");
  v19 = vostok::configs::binary_config_value::operator[](v18, "preview");
  v20 = 8 * (24 * v19->count / 24 + v12);
  v21 = alloca(v20);
  v39.m_begin = (vostok::resources::request *)v31;
  v39.m_end = (vostok::resources::request *)v31;
  v39.m_max_end = (vostok::resources::request *)&v31[v20];
  if ( v45.m_object )
  {
    v44.path = (const char *)v45.m_object;
    v44.id = rifle_scope_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v39, &v44);
  }
  v22 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "object");
  v44.path = (const char *)vostok::configs::binary_config_value::operator[](v22, "model")->data.pointer;
  v44.id = skeleton_model_instance_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v39, &v44);
  v23 = 24 * v19->count / 24;
  if ( v23 )
  {
    v45.m_object = 0;
    v44.id = v23;
    do
    {
      out_value.game_scene = *(survarium::pure_game_effect_emitter_base_vtbl **)((char *)&v45.m_object->__vftable
                                                                               + (unsigned int)v19->data.pointer);
      *(_DWORD *)&out_value.preview_mode = 50;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v39, (const vostok::resources::request *)&out_value);
      v45.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v45.m_object + 24);
      --v44.id;
    }
    while ( v44.id );
  }
  if ( (_BYTE)v40 )
  {
    v44.id = v37;
    do
    {
      v24 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
      out_value.game_scene = (void *)vostok::configs::binary_config_value::operator[](v24, "bullet_shells")->data.pointer;
      *(_DWORD *)&out_value.preview_mode = 62;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v39, (const vostok::resources::request *)&out_value);
      --v44.id;
    }
    while ( v44.id );
  }
  if ( (_BYTE)v41 )
  {
    v37 = particle_system_instance_class;
    v44.id = v36;
    do
    {
      v25 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v46, "particles");
      out_value.game_scene = (void *)vostok::configs::binary_config_value::operator[](v25, "shoot")->data.pointer;
      *(_DWORD *)&out_value.preview_mode = v37;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v39, (const vostok::resources::request *)&out_value);
      --v44.id;
    }
    while ( v44.id );
  }
  m_user_data = data->m_parent_query->m_user_data;
  out_value.game_scene = 0;
  vostok::variant<32>::try_get<survarium::weapon_cook_data>(m_user_data, &out_value);
  *((_DWORD *)&v30.l_ + 3) = survarium::weapon_cook::allocate_weapon(
                               (survarium::weapon_cook *)0x18,
                               (survarium::base_game_scene *)out_value.game_scene,
                               (vostok::math::float4x4 *)(24 * v19->count / 24),
                               v40,
                               v41);
  v30.l_.a4_.t_ = v27;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30.l_.a4_,
    &v42);
  boost::bind<void,survarium::victory_item_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *,survarium::victory_item_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *>(
    &result,
    (void (__thiscall *__ptr64)(survarium::weapon_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *))(unsigned int)survarium::weapon_cook::on_weapon_subresources_ready,
    a1,
    1_92,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v30.l_.a4_.t_,
    *((survarium::weapon **)&v30.l_ + 3));
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>(
    &v34,
    &result);
  v32[0] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>(
    &v30,
    &v34);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>>(
    v28,
    (int)v32,
    v30);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
  vostok::resources::query_resources(
    v39.m_begin,
    v39.m_end - v39.m_begin,
    survarium::g_allocator,
    0,
    m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v29, v32);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v42);
}
