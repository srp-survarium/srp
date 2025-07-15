void __thiscall vostok::render::skeleton_combined_model_cook::translate_query(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::query_result_for_user *parent)
{
  int m_helper_storage; // esi
  vostok::render::skeleton_combined_model_cook *v4; // ecx
  const char *requested_path; // eax
  vostok::buffer_string *v6; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v9; // [esp-10h] [ebp-168h]
  vostok::render::skeleton_combined_cook_data *out_value[4]; // [esp+10h] [ebp-148h] BYREF
  int f[8]; // [esp+20h] [ebp-138h] BYREF
  const char *v12[3]; // [esp+40h] [ebp-118h] BYREF
  _BYTE v13[260]; // [esp+4Ch] [ebp-10Ch] BYREF
  char v14; // [esp+150h] [ebp-8h] BYREF

  m_helper_storage = (int)parent->m_user_data->m_helper_storage;
  if ( m_helper_storage
    && (out_value[0] = 0,
        vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>(
          (vostok::variant<32> *)this,
          m_helper_storage,
          out_value),
        out_value[0]) )
  {
    vostok::render::skeleton_combined_model_cook::query_resources_by_data(
      v4,
      __SPAIR64__((unsigned int)parent, (unsigned int)this),
      (int)out_value[0]);
  }
  else
  {
    v12[0] = v13;
    v12[1] = v13;
    v12[2] = &v14;
    v13[0] = 0;
    v14 = 47;
    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
    vostok::fs_new::path_string_impl::assignf(
      v12,
      v6,
      (vostok::buffer_string *)"resources/models/%s.combined_skin",
      requested_path);
    out_value[2] = (vostok::render::skeleton_combined_cook_data *)this;
    out_value[1] = (vostok::render::skeleton_combined_cook_data *)vostok::render::skeleton_combined_model_cook::on_config_loaded;
    out_value[3] = (vostok::render::skeleton_combined_cook_data *)parent;
    v9.l_.a1_.t_ = (vostok::render::skeleton_combined_model_cook *)vostok::render::skeleton_combined_model_cook::on_config_loaded;
    v9.l_.a3_.t_ = (vostok::resources::query_result_for_cook *)this;
    v9.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_combined_model_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *))f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v7,
      v9,
      (int)parent);
    vostok::resources::query_resource(
      v12[0],
      (vostok::variant<32> *)0x20,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
  }
}
