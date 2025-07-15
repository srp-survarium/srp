void __thiscall survarium::profile_skin_visual_cook::on_configs_loaded(
        survarium::profile_skin_visual_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent,
        const survarium::player_profile *profile)
{
  void *v4; // eax
  vostok::render::skeleton_combined_cook_data *v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  vostok::configs::binary_config *m_object; // esi
  unsigned __int64 *v9; // eax
  unsigned __int64 v10; // xmm0_8
  unsigned __int8 v11; // al
  vostok::buffer_string *v12; // esi
  const char *pointer; // ecx
  char *m_begin; // eax
  const char *v15; // ecx
  char *v16; // eax
  const char *v17; // ecx
  _BYTE *v18; // eax
  const char *v19; // ecx
  _BYTE *v20; // eax
  vostok::configs::binary_config *v21; // eax
  vostok::configs::binary_config_vtbl *v22; // esi
  const char *type; // eax
  int v24; // edx
  survarium::profile_slot *v25; // esi
  vostok::buffer_string *v26; // edi
  bool v27; // zf
  vostok::resources::unmanaged_resource *v28; // ecx
  vostok::resources::unmanaged_resource *v29; // eax
  char *v30; // eax
  vostok::resources::unmanaged_intrusive_base *v31; // ecx
  const char *dict_id; // eax
  const char *v33; // ecx
  char *v34; // eax
  const char *v35; // ecx
  char *v36; // eax
  char *v37; // eax
  char *v38; // ecx
  char *m_end; // esi
  char *v40; // eax
  char *v41; // ecx
  char *v42; // esi
  char *v43; // eax
  char *v44; // ecx
  char *v45; // esi
  void (__cdecl *v46)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v47; // eax
  vostok::resources::unmanaged_intrusive_base *v48; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,survarium::game_object_ &,survarium::simple_game_project *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<survarium::simple_game_project *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > path_252; // [esp+F28h] [ebp-1ECh]
  char v50; // [esp+F4Ch] [ebp-1C8h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v51; // [esp+F50h] [ebp-1C4h] BYREF
  vostok::configs::binary_config_value v52; // [esp+F54h] [ebp-1C0h] BYREF
  vostok::resources::unmanaged_resource *resource; // [esp+F70h] [ebp-1A4h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v54; // [esp+F74h] [ebp-1A0h] BYREF
  vostok::variant<32> *user_data; // [esp+F78h] [ebp-19Ch] BYREF
  vostok::resources::request requests; // [esp+F7Ch] [ebp-198h] BYREF
  const char *v57; // [esp+F88h] [ebp-18Ch]
  vostok::resources::query_result *v58; // [esp+F8Ch] [ebp-188h]
  char *key; // [esp+F90h] [ebp-184h]
  vostok::resources::unmanaged_intrusive_base *v60; // [esp+F94h] [ebp-180h]
  int v61; // [esp+F98h] [ebp-17Ch]
  vostok::configs::binary_config_value v62; // [esp+F9Ch] [ebp-178h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+FB4h] [ebp-160h] BYREF
  _DWORD v64[2]; // [esp+FD4h] [ebp-140h] BYREF
  unsigned int v65[8]; // [esp+FDCh] [ebp-138h] BYREF
  _DWORD *v66; // [esp+FFCh] [ebp-118h]
  int v67; // [esp+1000h] [ebp-114h]
  const char *v68; // [esp+1004h] [ebp-110h]
  _BYTE *v69; // [esp+1008h] [ebp-10Ch]
  char *v70; // [esp+100Ch] [ebp-108h]
  _BYTE v71[260]; // [esp+1010h] [ebp-104h] BYREF
  char vars0; // [esp+1114h] [ebp+0h] BYREF

  user_data = (vostok::variant<32> *)this;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x1C98u);
  if ( v4 )
  {
    vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(v5, (int)v4, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v68 = v71;
  v67 = vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get();
  v66 = v64;
  v65[0] = v7;
  v64[0] = &vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *>::`vftable';
  v69 = v71;
  v70 = &vars0;
  v71[0] = 0;
  v51.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v51,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v51.m_object;
  v54.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v54,
    v51.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v9 = (unsigned __int64 *)vostok::configs::binary_config_value::operator[](v54.m_object->m_root, "body_parts");
  v62.data.max_storage = *v9;
  v62.id.max_storage = v9[1];
  v10 = v9[2];
  *(_BYTE *)(v7 + 7316) = 0;
  *(_QWORD *)&v62.id_crc = v10;
  v57 = "data";
  key = "data";
  v52.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&v52.id, 0);
  v52.count = 0;
  v52.id_crc = 0;
  v52.type = 0;
  v11 = *(_BYTE *)(v7 + 7316);
  v12 = (vostok::buffer_string *)(844 * v11 + v7 + 564);
  *(_BYTE *)(v7 + 7316) = v11 + 1;
  v52 = *vostok::configs::binary_config_value::operator[](&v62, "head");
  pointer = (const char *)vostok::configs::binary_config_value::operator[](&v52, "base_model")->data.pointer;
  m_begin = v12->m_begin;
  v12->m_end = v12->m_begin;
  *m_begin = 0;
  vostok::buffer_string::operator+=(v12, pointer);
  v15 = (const char *)vostok::configs::binary_config_value::operator[](&v52, "part_name")->data.pointer;
  v16 = v12[23].m_begin;
  v12 += 23;
  v12->m_end = v16;
  *v16 = 0;
  vostok::buffer_string::operator+=(v12, v15);
  v17 = (const char *)vostok::configs::binary_config_value::operator[](&v62, "skeleton")->data.pointer;
  v18 = *(_BYTE **)v7;
  *(_DWORD *)(v7 + 4) = *(_DWORD *)v7;
  *v18 = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)v7, v17);
  v19 = (const char *)vostok::configs::binary_config_value::operator[](&v62, "bind_pose")->data.pointer;
  v20 = *(_BYTE **)(v7 + 280);
  *(_DWORD *)(v7 + 284) = v20;
  *v20 = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)(v7 + 280), v19);
  v21 = (vostok::configs::binary_config *)body_parts;
  v51.m_object = (vostok::configs::binary_config *)body_parts;
  v58 = &data->m_queries[1];
  v61 = 7;
  while ( 1 )
  {
    v22 = v21->__vftable;
    type = (const char *)v21->type;
    v24 = 844 * *(unsigned __int8 *)(v7 + 7316);
    requests.path = (const char *)v22;
    v25 = (survarium::profile_slot *)((char *)profile + 16 * (_DWORD)&v22->link_child_resource);
    v26 = (vostok::buffer_string *)(v24 + v7 + 564);
    v27 = v25->item.id == 0;
    requests.id = (vostok::resources::class_id_enum)type;
    v50 = 0;
    if ( v27 )
    {
      if ( vostok::configs::binary_config_value::value_exists(&v62, type) )
      {
        v52 = *vostok::configs::binary_config_value::operator[](&v62, (const char *)requests.id);
        v50 = 1;
      }
      dict_id = 0;
    }
    else
    {
      v28 = v58->m_unmanaged_resource.m_object;
      ++v58;
      v29 = 0;
      if ( v28 )
      {
        v29 = v28;
        _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
      }
      resource = 0;
      if ( v29 )
      {
        resource = v29;
        v60 = &v29->vostok::resources::unmanaged_intrusive_base;
        _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
        if ( !_InterlockedExchangeAdd(&v29->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v29->vostok::resources::unmanaged_intrusive_base, v29);
      }
      if ( requests.path == (const char *)2 )
      {
        v30 = key;
      }
      else
      {
        v30 = (char *)v57;
        if ( requests.path != (const char *)4 )
          v30 = "data";
      }
      v52 = *vostok::configs::binary_config_value::operator[](
               (vostok::configs::binary_config_value *)resource[1].__vftable,
               v30);
      v31 = &resource->vostok::resources::unmanaged_intrusive_base;
      v50 = 1;
      if ( !_InterlockedExchangeAdd(&resource->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v31, resource);
      dict_id = (const char *)v25->item.dict_id;
    }
    vostok::buffer_string::appendf((vostok::buffer_string *)&stru_96B880, dict_id);
    if ( v50 )
    {
      if ( vostok::configs::binary_config_value::value_exists(&v52, (const char *)&stru_96B880.m_end)
        && vostok::configs::binary_config_value::value_exists(&v52, "part_name_hud") )
      {
        v33 = (const char *)vostok::configs::binary_config_value::operator[](&v52, (const char *)&stru_96B880.m_end)->data.pointer;
        v34 = v26->m_begin;
        v26->m_end = v26->m_begin;
        *v34 = 0;
        vostok::buffer_string::operator+=(v26, v33);
        v35 = (const char *)vostok::configs::binary_config_value::operator[](&v52, "part_name_hud")->data.pointer;
        v36 = v26[23].m_begin;
        v26[23].m_end = v36;
        *v36 = 0;
        vostok::buffer_string::operator+=(v26 + 23, v35);
      }
      else
      {
        v37 = (char *)vostok::configs::binary_config_value::operator[](&v52, "base_model")->data.pointer;
        v38 = v26->m_begin;
        v26->m_end = v26->m_begin;
        *v38 = 0;
        if ( v37 )
        {
          for ( ; *v37; ++v37 )
          {
            m_end = v26->m_end;
            if ( m_end >= v26->m_max_end )
              break;
            *m_end = *v37;
            ++v26->m_end;
          }
          *v26->m_end = 0;
        }
        v40 = (char *)vostok::configs::binary_config_value::operator[](&v52, "part_name")->data.pointer;
        v41 = v26[23].m_begin;
        v26[23].m_end = v41;
        *v41 = 0;
        if ( v40 )
        {
          for ( ; *v40; ++v40 )
          {
            v42 = v26[23].m_end;
            if ( v42 >= v26[23].m_max_end )
              break;
            *v42 = *v40;
            ++v26[23].m_end;
          }
          *v26[23].m_end = 0;
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(&v52, "material") )
      {
        v43 = (char *)vostok::configs::binary_config_value::operator[](&v52, "material")->data.pointer;
        v44 = v26[46].m_begin;
        v26[46].m_end = v44;
        *v44 = 0;
        if ( v43 )
        {
          for ( ; *v43; ++v43 )
          {
            v45 = v26[46].m_end;
            if ( v45 >= v26[46].m_max_end )
              break;
            *v45 = *v43;
            ++v26[46].m_end;
          }
          *v26[46].m_end = 0;
        }
      }
      if ( requests.path == (const char *)5 )
      {
        key = (char *)vostok::configs::binary_config_value::operator[](&v52, "model_type")->data.pointer;
      }
      else if ( requests.path == (const char *)6 )
      {
        v57 = (const char *)vostok::configs::binary_config_value::operator[](&v52, "model_type")->data.pointer;
      }
      ++*(_BYTE *)(v7 + 7316);
    }
    v51.m_object = (vostok::configs::binary_config *)((char *)v51.m_object + 8);
    if ( !--v61 )
      break;
    v21 = v51.m_object;
  }
  v62.data.pointer = survarium::profile_skin_visual_cook::on_visual_loaded;
  HIDWORD(v62.data.max_storage) = 0;
  requests = (vostok::resources::request)__PAIR64__((unsigned int)parent, (unsigned int)user_data);
  LODWORD(path_252.f_.f_) = 0;
  *(void (__thiscall *__ptr64 *)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))((char *)&path_252.f_.f_ + 4) = (void (__thiscall *__ptr64)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))__PAIR64__((unsigned int)parent, (unsigned int)user_data);
  v62.id_crc = v7;
  callback.vtable = 0;
  *(_QWORD *)&path_252.l_.a3_.t_ = *(_QWORD *)&v62.id_crc;
  if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,survarium::game_object_ &> *)survarium::profile_skin_visual_cook::on_visual_loaded,
         path_252) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  requests.path = v68;
  user_data = (vostok::variant<32> *)v64;
  requests.id = skeleton_combined_model_instance_class;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v46 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v46 )
        v46(&callback.functor, &callback.functor, 2);
    }
  }
  v47 = v54.m_object;
  v48 = &v54.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&v54.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v48, v47);
  if ( v66 )
    (*(void (__thiscall **)(_DWORD *, unsigned int *))(*v66 + 4))(v66, v65);
}
