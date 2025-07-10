void __userpurge survarium::shotgun_weapon_reload_state_cook::create_resource(
        survarium::shotgun_weapon_reload_state_cook *this@<ecx>,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer,
        int a5,
        int a6,
        int a7,
        char a8)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::resources::creation_request *v10; // edi
  char *v11; // esi
  const vostok::configs::binary_config_value *v12; // ebx
  char *v13; // eax
  bool v14; // zf
  vostok::resources::query_result_for_cook *v15; // ecx
  void (__cdecl *v16)(char *, char *, int); // eax
  int v17; // edi
  char *v18; // esi
  int v19; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,survarium::game_object_ &,survarium::simple_game_project *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<survarium::simple_game_project *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v20; // [esp+464h] [ebp-14Ch]
  vostok::sound::encoded_sound_interface *v21; // [esp+484h] [ebp-12Ch]
  int v22; // [esp+488h] [ebp-128h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48Ch] [ebp-124h] BYREF
  vostok::configs::binary_config_value out_value; // [esp+4B0h] [ebp-100h] BYREF
  vostok::variant<32> *v25[3]; // [esp+4CCh] [ebp-E4h] BYREF
  vostok::resources::creation_request v26; // [esp+4D8h] [ebp-D8h] BYREF
  const char *v27; // [esp+4E8h] [ebp-C8h]
  vostok::const_buffer v28; // [esp+4ECh] [ebp-C4h]
  int v29; // [esp+4F4h] [ebp-BCh]
  const char *v30; // [esp+4F8h] [ebp-B8h]
  vostok::const_buffer v31; // [esp+4FCh] [ebp-B4h]
  int v32; // [esp+504h] [ebp-ACh]
  void (__thiscall *v33)(survarium::shotgun_weapon_reload_state_cook *, vostok::resources::queries_result *, vostok::mutable_buffer, const survarium::weapon_state_creation_params *); // [esp+508h] [ebp-A8h]
  int v34; // [esp+50Ch] [ebp-A4h]
  char __t[40]; // [esp+520h] [ebp-90h] BYREF
  char v36; // [esp+548h] [ebp-68h] BYREF
  char v37; // [esp+550h] [ebp-60h] BYREF
  char v38; // [esp+580h] [ebp-30h] BYREF

  callback.vtable = (boost::detail::function::vtable_base *)this;
  v21 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  out_value.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&out_value.id, 0);
  out_value.id_crc = 0;
  m_user_data = parent->m_user_data;
  out_value.type = 0;
  out_value.count = 0;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(m_user_data, &out_value, 0) )
  {
    v26.m_name = "start_substate";
    v26.m_data = raw_file_data;
    v26.m_id = weapon_shotgun_reload_start_substate_class;
    v27 = "reload_one_substate";
    v28 = raw_file_data;
    v29 = 312;
    v30 = "finish_substate";
    v31 = raw_file_data;
    v32 = 313;
    `vector constructor iterator'(__t, 0x30u, 3, (void *(__thiscall *)(void *))vostok::variant<32>::variant<32>);
    v10 = &v26;
    v11 = &v36;
    v22 = 3;
    do
    {
      v12 = vostok::configs::binary_config_value::operator[](&out_value, v10->m_name);
      if ( *(_DWORD *)v11 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)v11 + 4))(*(_DWORD *)v11, (_DWORD *)v11 - 8);
        *(_DWORD *)v11 = 0;
      }
      *((_DWORD *)v11 + 1) = vostok::detail::type_to_int<vostok::configs::binary_config_value>::get();
      if ( v11 != (char *)32 )
      {
        *((_QWORD *)v11 - 4) = v12->data.max_storage;
        *((_QWORD *)v11 - 3) = v12->id.max_storage;
        *((_QWORD *)v11 - 2) = *(_QWORD *)&v12->id_crc;
      }
      v13 = v11 - 40;
      *(_DWORD *)v11 = v11 - 40;
      ++v10;
      v11 += 48;
      v14 = v22-- == 1;
      *(_DWORD *)v13 = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
    }
    while ( !v14 );
    v25[0] = (vostok::variant<32> *)__t;
    (&callback.vtable)[1] = callback.vtable;
    *(vostok::mutable_buffer *)&callback.functor.obj_ptr = in_out_unmanaged_resource_buffer;
    v25[1] = (vostok::variant<32> *)&v37;
    v25[2] = (vostok::variant<32> *)&v38;
    v33 = survarium::shotgun_weapon_reload_state_cook::on_substates_ready;
    v34 = 0;
    LODWORD(v20.f_.f_) = 0;
    callback.functor.vostok_pointer_size_alignment[2] = v21;
    *(void (__thiscall *__ptr64 *)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))((char *)&v20.f_.f_ + 4) = *(void (__thiscall *__ptr64 *)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))&(&callback.vtable)[1];
    (&callback.vtable)[1] = 0;
    *(_QWORD *)&v20.l_.a3_.t_ = *(_QWORD *)((char *)&callback.functor.bound_memfunc_ptr.memfunc_ptr + 4);
    if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>(
           (boost::detail::function::function_buffer *)((char *)&callback.functor.bound_memfunc_ptr.memfunc_ptr + 4),
           (boost::detail::function::basic_vtable1<void,survarium::game_object_ &> *)survarium::shotgun_weapon_reload_state_cook::on_substates_ready,
           v20) )
    {
      (&callback.vtable)[1] = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::shotgun_weapon_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::shotgun_weapon_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>'::`2'::stored_vtable
                                                                     + 1);
    }
    else
    {
      (&callback.vtable)[1] = 0;
    }
    vostok::resources::query_create_resources(
      &v26,
      3u,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&(&callback.vtable)[1],
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      (const vostok::variant<32> **)v25,
      parent,
      assert_on_fail_true);
    if ( (&callback.vtable)[1] )
    {
      if ( ((int)(&callback.vtable)[1] & 1) == 0 )
      {
        v16 = *(void (__cdecl **)(char *, char *, int))((int)(&callback.vtable)[1] & 0xFFFFFFFE);
        if ( v16 )
          v16((char *)&callback.functor.type.const_qualified, (char *)&callback.functor.type.const_qualified, 2);
      }
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v15,
      result_postponed,
      assert_on_fail_true,
      error_type_unset);
    v17 = 2;
    v18 = &a8;
    do
    {
      v19 = *((_DWORD *)v18 - 12);
      v18 -= 48;
      if ( v19 )
      {
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v19 + 4))(v19, (_DWORD *)v18 - 8);
        *(_DWORD *)v18 = 0;
      }
      --v17;
    }
    while ( v17 >= 0 );
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
