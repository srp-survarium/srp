void __thiscall vostok::render::skeleton_model_instance_cook::translate_query(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  int v7; // ebx
  const char *requested_path; // eax
  vostok::buffer_string *v9; // ecx
  const char *v10; // eax
  vostok::buffer_string *v11; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *> > > v16; // [esp-10h] [ebp-280h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *> > > v17; // [esp-10h] [ebp-280h]
  const char *v18; // [esp+0h] [ebp-270h]
  const char *v19; // [esp+4h] [ebp-26Ch]
  unsigned int v20; // [esp+8h] [ebp-268h]
  int f[8]; // [esp+20h] [ebp-250h] BYREF
  const char *v23[3]; // [esp+40h] [ebp-230h] BYREF
  _BYTE v24[260]; // [esp+4Ch] [ebp-224h] BYREF
  char v25; // [esp+150h] [ebp-120h] BYREF
  const char *v26[3]; // [esp+158h] [ebp-118h] BYREF
  _BYTE v27[260]; // [esp+164h] [ebp-10Ch] BYREF
  char v28; // [esp+268h] [ebp-8h] BYREF

  v2 = vostok::render::g_allocator;
  v4 = type_info::raw_name(&vostok::render::skeleton_model_instance_cook_data `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v2, 0x10u, v4, v18, v19, v20);
  v7 = 0;
  if ( v6 )
  {
    *v6 = 0;
    v6[1] = 0;
    *((_DWORD *)v6 + 1) = parent;
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 3) = 0;
    v7 = (int)v6;
  }
  v23[0] = v24;
  v23[1] = v24;
  v23[2] = &v25;
  v26[0] = v27;
  v26[1] = v27;
  v24[0] = 0;
  v25 = 47;
  v26[2] = &v28;
  v27[0] = 0;
  v28 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v23, v9, (vostok::buffer_string *)&stru_8010B4, requested_path);
  v10 = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v26, v11, (vostok::buffer_string *)"%s.skinned_model/render", v10);
  v16.l_.a1_.t_ = (vostok::render::skeleton_model_instance_cook *)vostok::render::skeleton_model_instance_cook::on_skeleton_config_loaded;
  v16.l_.a3_.t_ = (vostok::render::skeleton_model_instance_cook_data *)this;
  v16.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_model_instance_cook *, vostok::resources::queries_result *, vostok::render::skeleton_model_instance_cook_data *))f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v12,
    v16,
    v7);
  vostok::resources::query_resource(
    v23[0],
    (vostok::variant<32> *)0x20,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v13, f);
  v17.l_.a1_.t_ = (vostok::render::skeleton_model_instance_cook *)vostok::render::skeleton_model_instance_cook::on_render_model_loaded;
  v17.l_.a3_.t_ = (vostok::render::skeleton_model_instance_cook_data *)this;
  v17.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_model_instance_cook *, vostok::resources::queries_result *, vostok::render::skeleton_model_instance_cook_data *))f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v14,
    v17,
    v7);
  vostok::resources::query_resource(
    v26[0],
    (vostok::variant<32> *)0x16,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v15, f);
}
