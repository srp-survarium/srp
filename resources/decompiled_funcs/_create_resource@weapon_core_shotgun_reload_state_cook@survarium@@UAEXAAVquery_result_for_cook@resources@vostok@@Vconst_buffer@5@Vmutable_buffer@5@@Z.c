void __thiscall survarium::weapon_core_shotgun_reload_state_cook::create_resource(
        survarium::weapon_core_shotgun_reload_state_cook *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::variant<32> *v5; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  survarium::game_camera *v14; // ecx
  survarium::game_camera *v15; // ecx
  survarium::game_camera *v16; // ecx
  survarium::game_camera *v17; // ecx
  survarium::game_camera *v18; // ecx
  survarium::game_camera *v19; // ecx
  survarium::game_camera *v20; // ecx
  survarium::game_camera *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v24; // ecx
  survarium::game_camera *v25; // ecx
  const char *v26; // eax
  vostok::resources::class_id_enum v27; // edx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v30; // ecx
  survarium::game_camera *v31; // ecx
  const char *v32; // eax
  vostok::resources::class_id_enum v33; // edx
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v36; // ecx
  survarium::game_camera *v37; // ecx
  const char *v38; // eax
  vostok::resources::class_id_enum v39; // edx
  vostok::configs::binary_config_value *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v42; // ecx
  survarium::game_camera *v43; // ecx
  const char *v44; // eax
  vostok::resources::class_id_enum v45; // edx
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v48; // ecx
  survarium::game_camera *v49; // ecx
  const char *v50; // eax
  vostok::resources::class_id_enum v51; // edx
  vostok::configs::binary_config_value *v52; // eax
  const vostok::configs::binary_config_value *v53; // eax
  survarium::game_camera *id_crc; // ecx
  const vostok::configs::binary_config_value *v55; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v56; // ecx
  survarium::game_camera *v57; // ecx
  const char *v58; // eax
  vostok::resources::class_id_enum v59; // edx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v60; // ecx
  const vostok::variant<32> **v61; // eax
  vostok::buffer_vector<vostok::resources::request> *v62; // ecx
  unsigned int v63; // [esp-18h] [ebp-328h]
  vostok::memory::base_allocator *f; // [esp-10h] [ebp-320h]
  unsigned int v65; // [esp+0h] [ebp-310h]
  unsigned int v66; // [esp+4h] [ebp-30Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_shotgun_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_shotgun_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > v68; // [esp+10h] [ebp-300h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_shotgun_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_shotgun_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > result; // [esp+104h] [ebp-20Ch] BYREF
  boost::function1<void,vostok::resources::queries_result &> v70; // [esp+118h] [ebp-1F8h] BYREF
  char v71; // [esp+13Fh] [ebp-1D1h]
  vostok::resources::request v72; // [esp+140h] [ebp-1D0h] BYREF
  vostok::resources::request v73; // [esp+148h] [ebp-1C8h] BYREF
  vostok::resources::request v74; // [esp+150h] [ebp-1C0h] BYREF
  vostok::resources::request v75; // [esp+158h] [ebp-1B8h] BYREF
  vostok::resources::request v76; // [esp+160h] [ebp-1B0h] BYREF
  vostok::resources::request value; // [esp+168h] [ebp-1A8h] BYREF
  char v78; // [esp+171h] [ebp-19Fh]
  char v79; // [esp+172h] [ebp-19Eh]
  char v80; // [esp+173h] [ebp-19Dh]
  char v81; // [esp+174h] [ebp-19Ch]
  char v82; // [esp+175h] [ebp-19Bh]
  char v83; // [esp+176h] [ebp-19Ah]
  char v84; // [esp+177h] [ebp-199h]
  char v85; // [esp+178h] [ebp-198h]
  char v86; // [esp+179h] [ebp-197h]
  char v87; // [esp+17Ah] [ebp-196h]
  char v88; // [esp+17Bh] [ebp-195h]
  char v89; // [esp+17Ch] [ebp-194h]
  char v90; // [esp+17Dh] [ebp-193h]
  char v91; // [esp+17Eh] [ebp-192h]
  char v92; // [esp+17Fh] [ebp-191h]
  int n; // [esp+180h] [ebp-190h]
  int m; // [esp+184h] [ebp-18Ch]
  int k; // [esp+188h] [ebp-188h]
  int j; // [esp+18Ch] [ebp-184h]
  int index; // [esp+190h] [ebp-180h]
  unsigned int i; // [esp+194h] [ebp-17Ch]
  vostok::configs::binary_config_value cfg; // [esp+198h] [ebp-178h] BYREF
  vostok::configs::binary_config_value start_user_anim_cfg; // [esp+1B0h] [ebp-160h] BYREF
  vostok::configs::binary_config_value finish_weapon_anim_cfg; // [esp+1C8h] [ebp-148h] BYREF
  vostok::configs::binary_config_value start_weapon_anim_cfg; // [esp+1E0h] [ebp-130h] BYREF
  vostok::configs::binary_config_value reload_one_weapon_anim_cfg; // [esp+1F8h] [ebp-118h] BYREF
  vostok::configs::binary_config_value reload_one_user_anim_cfg; // [esp+210h] [ebp-100h] BYREF
  vostok::configs::binary_config_value finish_user_anim_cfg; // [esp+228h] [ebp-E8h] BYREF
  const survarium::weapon_state_creation_params *params; // [esp+244h] [ebp-CCh]
  vostok::fixed_vector<vostok::resources::request,24> requests; // [esp+248h] [ebp-C8h] BYREF

  params = (const survarium::weapon_state_creation_params *)raw_file_data.m_data;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this);
  v5 = vostok::resources::query_result_for_cook::user_data(v4, (int)parent);
  v7 = vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v5, &cfg, v6);
  if ( v7 )
  {
    v92 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
    v91 = 0;
    survarium::weapon_user_dead_state::finalize(v8);
    v90 = 0;
    survarium::weapon_user_dead_state::finalize(v9);
    v89 = 0;
    survarium::weapon_user_dead_state::finalize(v10);
    v88 = 0;
    survarium::weapon_user_dead_state::finalize(v11);
    v87 = 0;
    survarium::weapon_user_dead_state::finalize(v12);
    v86 = 0;
    survarium::weapon_user_dead_state::finalize(v13);
    v85 = 0;
    survarium::weapon_user_dead_state::finalize(v14);
    v84 = 0;
    survarium::weapon_user_dead_state::finalize(v15);
    v83 = 0;
    survarium::weapon_user_dead_state::finalize(v16);
    v82 = 0;
    survarium::weapon_user_dead_state::finalize(v17);
    v81 = 0;
    survarium::weapon_user_dead_state::finalize(v18);
    v80 = 0;
    survarium::weapon_user_dead_state::finalize(v19);
    v79 = 0;
    survarium::weapon_user_dead_state::finalize(v20);
    v78 = 0;
    survarium::weapon_user_dead_state::finalize(v21);
    vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
      (vostok::buffer_vector<vostok::resources::request> *)requests.m_buffer,
      (vostok::buffer_vector<vostok::resources::request> **)&requests,
      0,
      v65,
      v66);
    v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "start_substate");
    start_weapon_anim_cfg = *vostok::configs::binary_config_value::operator[](v22, "animations");
    for ( i = 0; i != 4; ++i )
    {
      v23 = vostok::configs::binary_config_value::operator[](&start_weapon_anim_cfg, i);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v24, (int)v23);
      survarium::weapon_user_dead_state::finalize(v25);
      value.path = v26;
      value.id = v27;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &value);
    }
    v28 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "start_substate");
    start_user_anim_cfg = *vostok::configs::binary_config_value::operator[](v28, "user_animations");
    for ( index = 0; index != 4; ++index )
    {
      v29 = vostok::configs::binary_config_value::operator[](&start_user_anim_cfg, index);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v30, (int)v29);
      survarium::weapon_user_dead_state::finalize(v31);
      v76.path = v32;
      v76.id = v33;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &v76);
    }
    v34 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "reload_one_substate");
    reload_one_weapon_anim_cfg = *vostok::configs::binary_config_value::operator[](v34, "animations");
    for ( j = 0; j != 4; ++j )
    {
      v35 = vostok::configs::binary_config_value::operator[](&reload_one_weapon_anim_cfg, j);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v36, (int)v35);
      survarium::weapon_user_dead_state::finalize(v37);
      v75.path = v38;
      v75.id = v39;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &v75);
    }
    v40 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "reload_one_substate");
    reload_one_user_anim_cfg = *vostok::configs::binary_config_value::operator[](v40, "user_animations");
    for ( k = 0; k != 4; ++k )
    {
      v41 = vostok::configs::binary_config_value::operator[](&reload_one_user_anim_cfg, k);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v42, (int)v41);
      survarium::weapon_user_dead_state::finalize(v43);
      v74.path = v44;
      v74.id = v45;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &v74);
    }
    v46 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "finish_substate");
    finish_weapon_anim_cfg = *vostok::configs::binary_config_value::operator[](v46, "animations");
    for ( m = 0; m != 4; ++m )
    {
      v47 = vostok::configs::binary_config_value::operator[](&finish_weapon_anim_cfg, m);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v48, (int)v47);
      survarium::weapon_user_dead_state::finalize(v49);
      v73.path = v50;
      v73.id = v51;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &v73);
    }
    v52 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &cfg,
                                                    "finish_substate");
    v53 = vostok::configs::binary_config_value::operator[](v52, "user_animations");
    finish_user_anim_cfg.data.max_storage = v53->data.max_storage;
    finish_user_anim_cfg.id.max_storage = v53->id.max_storage;
    id_crc = (survarium::game_camera *)v53->id_crc;
    finish_user_anim_cfg.id_crc = (unsigned int)id_crc;
    *(_DWORD *)&finish_user_anim_cfg.type = *(_DWORD *)&v53->type;
    for ( n = 0; n != 4; ++n )
    {
      v55 = vostok::configs::binary_config_value::operator[](&finish_user_anim_cfg, n);
      stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v56, (int)v55);
      survarium::weapon_user_dead_state::finalize(v57);
      v72.path = v58;
      v72.id = v59;
      vostok::buffer_vector<vostok::resources::request>::push_back(&requests, &v72);
    }
    v71 = 0;
    survarium::weapon_user_dead_state::finalize(id_crc);
    v68 = *boost::bind<void,survarium::weapon_core_shotgun_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *,survarium::weapon_core_shotgun_reload_state_cook *,boost::arg<1>,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>(
             &result,
             (void (__thiscall *)(survarium::weapon_core_shotgun_reload_state_cook *, vostok::resources::queries_result *, vostok::mutable_buffer, const survarium::weapon_state_creation_params *))survarium::weapon_core_shotgun_reload_state_cook::on_subresources_ready,
             this,
             1_220,
             in_out_unmanaged_resource_buffer,
             params);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v68.l_.a3_.t_.m_size,
      &v70);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_shotgun_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_shotgun_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
      &v70,
      v68);
    f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
    v63 = vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests);
    v61 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v60, (int)&requests);
    vostok::resources::query_resources(
      (const vostok::resources::request *)v61,
      v63,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v70,
      f,
      0,
      parent,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v70);
    vostok::resources::query_result_for_cook::finish_query(parent, result_postponed, assert_on_fail_true);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v62, &requests);
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
