void __thiscall survarium::ladder_cook::translate_query(
        survarium::ladder_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  survarium::game_camera *v2; // ecx
  vostok::configs::binary_config_value *v3; // ecx
  int v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::vectora<vostok::resources::request> *v6; // ecx
  BOOL v7; // ecx
  bool v8; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  const vostok::configs::binary_config_value *v10; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  survarium::game_camera *v12; // ecx
  vostok::resources::request *v13; // eax
  vostok::resources::request *v14; // edx
  survarium::game_camera *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v17; // ecx
  vostok::memory::base_allocator *v18; // eax
  vostok::resources::request *v19; // edx
  const vostok::configs::binary_config_value *v20; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v21; // ecx
  survarium::game_camera *v22; // ecx
  vostok::resources::request *v23; // eax
  vostok::resources::request *v24; // edx
  BOOL v25; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v27; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  const vostok::variant<32> **v29; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::ladder_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::ladder_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value> > > v30; // [esp-28h] [ebp-1B8h] BYREF
  const vostok::resources::request *v31; // [esp+0h] [ebp-190h]
  survarium::ladder_cook *thisa; // [esp+8h] [ebp-188h]
  _BYTE v33[40]; // [esp+1Ch] [ebp-174h] BYREF
  int v34; // [esp+94h] [ebp-FCh]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::ladder_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::ladder_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value> > > f; // [esp+98h] [ebp-F8h] BYREF
  boost::function1<void,vostok::resources::queries_result &> v36; // [esp+C0h] [ebp-D0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+E0h] [ebp-B0h] BYREF
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v38; // [esp+104h] [ebp-8Ch] BYREF
  char v39; // [esp+116h] [ebp-7Ah]
  char v40; // [esp+117h] [ebp-79h]
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v41[2]; // [esp+118h] [ebp-78h] BYREF
  char v42; // [esp+146h] [ebp-4Ah]
  char v43; // [esp+147h] [ebp-49h]
  const char *end_animation; // [esp+148h] [ebp-48h]
  const char *start_animation; // [esp+14Ch] [ebp-44h]
  const vostok::configs::binary_config_value *point; // [esp+150h] [ebp-40h]
  const vostok::configs::binary_config_value *it_point_end; // [esp+154h] [ebp-3Ch]
  bool result; // [esp+15Bh] [ebp-35h]
  const vostok::configs::binary_config_value *points; // [esp+15Ch] [ebp-34h]
  vostok::variant<32> *user_data; // [esp+160h] [ebp-30h]
  const vostok::configs::binary_config_value *it_point; // [esp+164h] [ebp-2Ch]
  vostok::configs::binary_config_value config; // [esp+168h] [ebp-28h] BYREF
  vostok::vectora<vostok::resources::request> requests; // [esp+180h] [ebp-10h] BYREF

  thisa = this;
  v34 = 0;
  user_data = vostok::resources::query_result_for_cook::user_data(
                (vostok::resources::query_result_for_cook *)this,
                (int)parent);
  v43 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::configs::binary_config_value::binary_config_value(v3);
  result = vostok::variant<32>::try_get<vostok::configs::binary_config_value>(user_data, &config, v4);
  v42 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  vostok::vectora<vostok::resources::request>::vectora<vostok::resources::request>(v6, &requests);
  if ( vostok::configs::binary_config_value::value_exists(&config, "main_animation") )
  {
    v10 = vostok::configs::binary_config_value::operator[](&config, "main_animation");
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v11, (int)v10);
    survarium::weapon_user_dead_state::finalize(v12);
    v41[0]._M_impl._M_start = v13;
    v41[0]._M_impl._M_finish = v14;
    stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(v41, v31);
    v40 = 0;
    survarium::weapon_user_dead_state::finalize(v15);
    points = vostok::configs::binary_config_value::operator[](&config, "landing_points");
    it_point = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)points);
    it_point_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)points);
    while ( it_point != it_point_end )
    {
      point = it_point;
      v39 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)it_point);
      v16 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)point,
              "start_animation");
      start_animation = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                        v17,
                                        (int)v16);
      if ( !vostok::strings::equal(start_animation, (const char *)&buf) )
      {
        survarium::weapon_user_dead_state::finalize(0);
        v38._M_impl._M_end_of_storage.m_allocator = v18;
        v38._M_impl._M_end_of_storage._M_data = v19;
        stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
          (stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > *)&v38._M_impl._M_end_of_storage,
          v31);
      }
      v20 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)point,
              "end_animation");
      end_animation = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                      v21,
                                      (int)v20);
      if ( !vostok::strings::equal(end_animation, (const char *)&buf) )
      {
        survarium::weapon_user_dead_state::finalize(v22);
        v38._M_impl._M_start = v23;
        v38._M_impl._M_finish = v24;
        stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(&v38, v31);
      }
      ++it_point;
    }
    if ( vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests) == 1 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   vostok::core::g_log_filter_tree,
                                   "game_core:",
                                   error),
            v25 = has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v25);
        v34 |= 2u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\ladder_cook.cpp",
          0x42u,
          "void __thiscall survarium::ladder_cook::translate_query(class vostok::resources::query_result_for_cook &)",
          "game_core:",
          error,
          "there are no animations for landing points of this ladder, object will be useless, hence won't be created");
      }
      v27 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v34 & 2);
      if ( (v34 & 2) != 0 )
      {
        v34 &= ~2u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v27,
          (int *)&log_callback);
      }
      vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
      stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(&requests);
    }
    else
    {
      qmemcpy(
        v33,
        boost::bind<void,survarium::ladder_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &,survarium::ladder_cook *,boost::arg<1>,vostok::configs::binary_config_value>(
          &f,
          (void (__thiscall *)(survarium::ladder_cook *, vostok::resources::queries_result *, const vostok::configs::binary_config_value *))survarium::ladder_cook::on_animations_loaded,
          thisa,
          1_165,
          config),
        sizeof(v33));
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, &v36);
      qmemcpy(&v30, v33, sizeof(v30));
      boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::ladder_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::ladder_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>>>>(
        &v36,
        v30);
      *(_DWORD *)&v30.l_.a3_.t_.type = 1;
      v30.l_.a3_.t_.id_crc = (unsigned int)parent;
      v30.l_.a3_.t_.id.max_storage = LODWORD(survarium::g_allocator.f_.f_);
      HIDWORD(v30.l_.a3_.t_.data.max_storage) = &v36;
      v30.l_.a3_.t_.data.pointer = (const void *)vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests);
      v29 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v28, (int)&requests);
      vostok::resources::query_resources(
        (const vostok::resources::request *)v29,
        (unsigned int)v30.l_.a3_.t_.data.pointer,
        (boost::function4<void,unsigned int,float,float,char const *> *)HIDWORD(v30.l_.a3_.t_.data.max_storage),
        (vostok::memory::base_allocator *)v30.l_.a3_.t_.id.pointer,
        (const vostok::variant<32> **)HIDWORD(v30.l_.a3_.t_.id.max_storage),
        (vostok::resources::query_result_for_cook *)v30.l_.a3_.t_.id_crc,
        *(assert_on_fail_bool *)&v30.l_.a3_.t_.type);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v36);
      stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(&requests);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v8 = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", error), v7 = v8) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7);
      v34 |= 1u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v41[0]._M_impl._M_end_of_storage,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\ladder_cook.cpp",
        0x24u,
        "void __thiscall survarium::ladder_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "game_core:",
        error,
        "there's no animation for this ladder, object can't be created");
    }
    v9 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v34 & 1);
    if ( (v34 & 1) != 0 )
    {
      v34 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v9,
        (int *)&v41[0]._M_impl._M_end_of_storage);
    }
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
    stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(&requests);
  }
}
