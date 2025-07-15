void __thiscall survarium::ladder_cook::translate_query(
        survarium::ladder_cook *this,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  void *obj_ptr; // esi
  vostok::configs::binary_config_value *v3; // eax
  vostok::variant<32> *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  bool v8; // zf
  vostok::vectora<vostok::resources::request> *v9; // ecx
  const vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // ebx
  int v12; // esi
  const char *v13; // edi
  const char *v14; // edi
  unsigned int v15; // ebx
  bool v16; // al
  void *v17; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // [esp-4h] [ebp-ACh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v20; // [esp-4h] [ebp-ACh]
  const vostok::resources::request *v21; // [esp+0h] [ebp-A8h]
  const vostok::resources::request *v22; // [esp+0h] [ebp-A8h]
  char v23; // [esp+Ch] [ebp-9Ch]
  const vostok::resources::request *v24; // [esp+10h] [ebp-98h] BYREF
  int v25; // [esp+14h] [ebp-94h]
  vostok::memory::doug_lea_allocator *v26; // [esp+18h] [ebp-90h]
  int v27; // [esp+1Ch] [ebp-8Ch]
  void *pointer; // [esp+20h] [ebp-88h] BYREF
  int v29; // [esp+24h] [ebp-84h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v30; // [esp+28h] [ebp-80h] BYREF
  survarium::ladder_cook *v31; // [esp+4Ch] [ebp-5Ch]
  _DWORD v32[2]; // [esp+50h] [ebp-58h] BYREF
  _DWORD v33[10]; // [esp+58h] [ebp-50h] BYREF
  _DWORD v34[10]; // [esp+80h] [ebp-28h] BYREF

  obj_ptr = parent[5].m_on_out_of_memory.functor.bound_memfunc_ptr.obj_ptr;
  v31 = this;
  v23 = 0;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&v30);
  vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v4, (int)obj_ptr, v3);
  v26 = survarium::g_allocator;
  v24 = 0;
  v25 = 0;
  v27 = 0;
  if ( !vostok::configs::binary_config_value::value_exists(v5, (int)&v30, (unsigned int)"main_animation") )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game_core",
                                 (const char *)2),
          v6 = v19,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v30);
      v23 = 1;
      vostok::logging::append(
        &v30,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\ladder_cook.cpp",
        0x24u,
        "void __thiscall survarium::ladder_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "game_core",
        error,
        "there's no animation for this ladder, object can't be created");
    }
    v8 = (v23 & 1) == 0;
LABEL_6:
    if ( !v8 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v30);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v6,
      parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
    goto LABEL_28;
  }
  pointer = (void *)vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)&v30,
                      "main_animation")->data.pointer;
  v29 = 50;
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
    (stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > *)&pointer,
    v21);
  v10 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)&v30, "landing_points");
  v11 = (vostok::configs::binary_config_value *)v10->data.pointer;
  v12 = (int)v10->data.pointer + 24 * v10->count;
  while ( v11 != (vostok::configs::binary_config_value *)v12 )
  {
    v13 = (const char *)vostok::configs::binary_config_value::operator[](v11, "start_animation")->data.pointer;
    if ( vostok::strings::compare(v13, uri) )
    {
      v29 = 50;
      pointer = (void *)v13;
      stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
        (stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > *)&pointer,
        v22);
    }
    v14 = (const char *)vostok::configs::binary_config_value::operator[](v11, "end_animation")->data.pointer;
    if ( vostok::strings::compare(v14, uri) )
    {
      v32[1] = 50;
      v32[0] = v14;
      stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
        (stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > *)v32,
        v22);
    }
    ++v11;
  }
  v15 = (v25 - (int)v24) >> 3;
  if ( v15 == 1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_core", (const char *)2),
          v6 = v20,
          v16) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v30);
      v23 = 2;
      vostok::logging::append(
        &v30,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\ladder_cook.cpp",
        0x42u,
        "void __thiscall survarium::ladder_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "game_core",
        error,
        "there are no animations for landing points of this ladder, object will be useless, hence won't be created");
    }
    v8 = (v23 & 2) == 0;
    goto LABEL_6;
  }
  v33[0] = v31;
  qmemcpy(&v33[2], &v30, 0x18u);
  v30.vtable = 0;
  v34[0] = survarium::ladder_cook::on_animations_loaded;
  qmemcpy(&v34[2], v33, 0x20u);
  qmemcpy(v33, v34, sizeof(v33));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v30.vtable = 0;
  }
  else
  {
    qmemcpy(v34, v33, sizeof(v34));
    v17 = operator new(0x28u);
    if ( v17 )
    {
      qmemcpy(v17, v34, 0x28u);
      v30.functor.obj_ptr = v17;
    }
    else
    {
      v30.functor.obj_ptr = 0;
    }
    v30.vtable = (boost::detail::function::vtable_base *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::ladder_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::ladder_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>>>>'::`2'::stored_vtable;
  }
  vostok::resources::query_resources(
    v24,
    v15,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&v30);
LABEL_28:
  vostok::vectora<vostok::resources::request>::~vectora<vostok::resources::request>(v9, (int)&v24);
}
