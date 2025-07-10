void __thiscall survarium::player_cook::on_subresources_loaded(
        survarium::player_cook *this,
        vostok::resources::queries_result *data,
        survarium::player_creation_params *params,
        survarium::inventory_cooker_data *inventory_cook_data,
        survarium::player_parameters_cooker_data *player_parameters_cook_data)
{
  void *v5; // esi
  void *v6; // esi
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v8; // esi
  vostok::configs::binary_config *v9; // eax
  vostok::render::skeleton_model_instance *v10; // ecx
  vostok::render::skeleton_model_instance *v11; // eax
  vostok::configs::binary_config *v12; // edi
  vostok::configs::binary_config *v13; // esi
  vostok::configs::binary_config *v14; // eax
  vostok::render::skeleton_model_instance *v15; // ecx
  vostok::render::skeleton_model_instance *v16; // eax
  vostok::configs::binary_config *v17; // esi
  vostok::configs::binary_config *v18; // esi
  vostok::configs::binary_config *v19; // edi
  vostok::configs::binary_config *v20; // esi
  vostok::configs::binary_config *v21; // eax
  survarium::inventory *v22; // ecx
  survarium::inventory *v23; // eax
  vostok::configs::binary_config *v24; // edi
  vostok::configs::binary_config *v25; // esi
  vostok::configs::binary_config *v26; // eax
  survarium::player_parameters_modifyer *v27; // ecx
  survarium::player_parameters_modifyer *v28; // eax
  vostok::configs::binary_config *v29; // edi
  vostok::configs::binary_config *v30; // esi
  vostok::configs::binary_config *v31; // eax
  survarium::interactive_object *v32; // edx
  vostok::configs::binary_config *v33; // eax
  vostok::resources::unmanaged_intrusive_base *v34; // ecx
  const char **v35; // eax
  BOOL v36; // ecx
  int v37; // esi
  void (__cdecl *v38)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v39; // eax
  vostok::resources::unmanaged_intrusive_base *v40; // ecx
  vostok::configs::binary_config *v41; // eax
  vostok::resources::unmanaged_intrusive_base *v42; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > v43; // [esp+6DCh] [ebp-1B0h]
  int v44; // [esp+6ECh] [ebp-1A0h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v45; // [esp+6F8h] [ebp-194h] BYREF
  int v46; // [esp+6FCh] [ebp-190h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v47; // [esp+700h] [ebp-18Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v48[2]; // [esp+704h] [ebp-188h] BYREF
  unsigned __int64 v49; // [esp+70Ch] [ebp-180h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v50; // [esp+718h] [ebp-174h] BYREF
  vostok::variant<32> *user_data; // [esp+71Ch] [ebp-170h] BYREF
  vostok::resources::query_result_for_cook *m_parent_query; // [esp+720h] [ebp-16Ch]
  _DWORD v53[2]; // [esp+724h] [ebp-168h] BYREF
  int v54[8]; // [esp+72Ch] [ebp-160h] BYREF
  _DWORD *v55; // [esp+74Ch] [ebp-140h]
  int v56; // [esp+750h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+754h] [ebp-138h] BYREF
  vostok::fs_new::path_string_impl v58; // [esp+774h] [ebp-118h] BYREF

  m_parent_query = data->m_parent_query;
  user_data = (vostok::variant<32> *)this;
  v46 = 0;
  if ( inventory_cook_data )
  {
    v5 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v5, inventory_cook_data);
  }
  if ( player_parameters_cook_data )
  {
    v6 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v6, player_parameters_cook_data);
  }
  v45.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v45,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v45.m_object;
  v8 = 0;
  if ( v45.m_object )
  {
    v8 = v45.m_object;
    _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
  }
  v9 = 0;
  if ( v8 )
  {
    v9 = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  v10 = (vostok::render::skeleton_model_instance *)v9;
  v11 = params->character_model.m_object;
  params->character_model.m_object = v10;
  if ( v11 )
  {
    if ( !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
    m_object = v45.m_object;
  }
  if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v45.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v45,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v12 = v45.m_object;
  v13 = 0;
  if ( v45.m_object )
  {
    v13 = v45.m_object;
    _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
  }
  v14 = 0;
  if ( v13 )
  {
    v14 = v13;
    _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  v15 = (vostok::render::skeleton_model_instance *)v14;
  v16 = params->server_character_model.m_object;
  params->server_character_model.m_object = v15;
  if ( v16 )
  {
    if ( !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
    v12 = v45.m_object;
  }
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v13->vostok::resources::unmanaged_intrusive_base, v13);
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
  v47.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v47,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
  v17 = v47.m_object;
  v50.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v50,
    v47.m_object);
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
  v48[0].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    v48,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[3].m_unmanaged_resource);
  v18 = v48[0].m_object;
  v47.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v47,
    v48[0].m_object);
  if ( v18 && !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v18->vostok::resources::unmanaged_intrusive_base, v18);
  v45.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v45,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[4].m_unmanaged_resource);
  v19 = v45.m_object;
  v20 = 0;
  if ( v45.m_object )
  {
    v20 = v45.m_object;
    _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
  }
  v21 = 0;
  if ( v20 )
  {
    v21 = v20;
    _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  v22 = (survarium::inventory *)v21;
  v23 = params->inventory.m_object;
  params->inventory.m_object = v22;
  if ( v23 )
  {
    if ( !_InterlockedExchangeAdd(&v23->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v23->vostok::resources::unmanaged_intrusive_base, v23);
    v19 = v45.m_object;
  }
  if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v20->vostok::resources::unmanaged_intrusive_base, v20);
  if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v19->vostok::resources::unmanaged_intrusive_base, v19);
  v45.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v45,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[5].m_unmanaged_resource);
  v24 = v45.m_object;
  v25 = 0;
  if ( v45.m_object )
  {
    v25 = v45.m_object;
    _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
  }
  v26 = 0;
  if ( v25 )
  {
    v26 = v25;
    _InterlockedExchangeAdd(&v25->m_reference_count, 1u);
  }
  v27 = (survarium::player_parameters_modifyer *)v26;
  v28 = params->player_parameters.m_object;
  params->player_parameters.m_object = v27;
  if ( v28 )
  {
    if ( !_InterlockedExchangeAdd(&v28->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v28->vostok::resources::unmanaged_intrusive_base, v28);
    v24 = v45.m_object;
  }
  if ( v25 && !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
  if ( v24 && !_InterlockedExchangeAdd(&v24->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v24->vostok::resources::unmanaged_intrusive_base, v24);
  if ( params->initial_info.is_demo_player )
  {
    v46 = 3;
    v45.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v45,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[6].m_unmanaged_resource);
    v29 = v45.m_object;
    v48[0].m_object = 0;
    if ( v45.m_object )
    {
      v48[0] = v45;
      _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
    }
    v30 = v48[0].m_object;
  }
  else
  {
    v29 = v45.m_object;
    v30 = 0;
    v46 = 4;
    v48[0].m_object = 0;
  }
  v31 = 0;
  if ( v48[0].m_object )
  {
    v31 = v48[0].m_object;
    _InterlockedExchangeAdd(&v48[0].m_object->m_reference_count, 1u);
  }
  v32 = params->empty_hands.m_object;
  params->empty_hands.m_object = (survarium::interactive_object *)v31;
  if ( v32 )
  {
    if ( !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v32->vostok::resources::unmanaged_intrusive_base, v32);
    v29 = v45.m_object;
  }
  if ( (v46 & 4) != 0 )
  {
    v46 &= ~4u;
    if ( v30 )
    {
      if ( !_InterlockedExchangeAdd(&v30->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v30->vostok::resources::unmanaged_intrusive_base, v30);
    }
  }
  if ( (v46 & 2) != 0 )
  {
    v33 = v48[0].m_object;
    v46 &= ~2u;
    if ( v48[0].m_object )
    {
      v34 = &v48[0].m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v48[0].m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v34, v33);
    }
  }
  if ( (v46 & 1) != 0 && v29 && !_InterlockedExchangeAdd(&v29->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v29->vostok::resources::unmanaged_intrusive_base, v29);
  params->damage_collision = vostok::physics::new_animated_bt_hit_model(
                               v50.m_object->m_root,
                               &params->character_model.m_object->m_skeleton,
                               (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_);
  v58.m_string.m_begin = v58.m_string.m_buffer;
  v58.m_string.m_end = v58.m_string.m_buffer;
  v58.m_string.m_max_end = &v58.m_separator;
  v58.m_string.m_buffer[0] = 0;
  v58.m_separator = 47;
  v35 = (const char **)vostok::configs::binary_config_value::operator[](v47.m_object->m_root, "hit_params");
  vostok::fs_new::path_string_impl::assignf(&v58, "resources/gameplay/hit_params/%s.options", *v35);
  v36 = !params->initial_info.profile->is_local;
  v55 = 0;
  v56 = 0;
  v37 = v36;
  v56 = vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::get();
  v48[0].m_object = (vostok::configs::binary_config *)survarium::player_cook::on_hit_params_loaded;
  v49 = __PAIR64__((unsigned int)params, (unsigned int)user_data);
  v48[1].m_object = 0;
  v43.f_.f_ = (void (__thiscall *__ptr64)(survarium::player_cook *, vostok::resources::queries_result *, survarium::player_creation_params *))(unsigned int)survarium::player_cook::on_hit_params_loaded;
  v54[0] = v37;
  v53[0] = &vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::`vftable';
  v55 = v53;
  v43.l_ = (boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> >)__PAIR64__((unsigned int)params, (unsigned int)user_data);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    v37,
    v43,
    v44);
  v48[0] = (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v58.m_string.m_begin;
  user_data = (vostok::variant<32> *)v53;
  v48[1].m_object = (vostok::configs::binary_config *)95;
  vostok::resources::query_resources(
    (const vostok::resources::request *)v48,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&user_data,
    m_parent_query,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v38 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v38 )
        v38(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v55 )
  {
    (*(void (__thiscall **)(_DWORD *, int *))(*v55 + 4))(v55, v54);
    v55 = 0;
  }
  v39 = v47.m_object;
  v40 = &v47.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&v47.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v40, v39);
  v41 = v50.m_object;
  v42 = &v50.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&v50.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v42, v41);
}
