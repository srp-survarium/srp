void __thiscall survarium::game_world::load(
        survarium::game_world *this,
        survarium::game_world *project_resource_name,
        vostok::resources::request *requests_begin,
        vostok::resources::request *requests_end,
        const vostok::variant<32> **user_datas_begin,
        const vostok::variant<32> **callback,
        const boost::function<void __cdecl(vostok::resources::queries_result &)> *callbacka)
{
  unsigned int v7; // esi
  void *v8; // esp
  vostok::ui::world **v9; // edi
  void *v10; // esp
  void *v11; // esp
  vostok::resources::request *v12; // eax
  const vostok::variant<32> **v14; // ecx
  survarium::damage_model_stats *v15; // eax
  survarium::damage_model_stats *v16; // eax
  survarium::npc_stats **v17; // esi
  survarium::npc_stats *v18; // eax
  survarium::npc_stats *v19; // eax
  vostok::variant<32> *v20; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  vostok::variant<32> *v22; // esi
  vostok::detail::abstract_type_helper *v23; // ecx
  vostok::variant<32> *v24; // esi
  vostok::detail::abstract_type_helper *v25; // ecx
  vostok::variant<32> *v26; // esi
  vostok::variant<32> *v27; // esi
  vostok::detail::abstract_type_helper *v28; // ecx
  vostok::variant<32> *v29; // esi
  const vostok::variant<32> **v30; // esi
  float **v31; // edi
  _DWORD *v32; // esi
  float **v33; // edi
  vostok::resources::request **v34; // esi
  float **v35; // edi
  _DWORD *v36; // esi
  unsigned int v37; // eax
  const vostok::variant<32> **m_end; // esi
  int v39; // eax
  void (__cdecl *v40)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void (__cdecl *v41)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::detail::abstract_type_helper *v42; // ecx
  vostok::variant<32> *v43; // ecx
  vostok::detail::abstract_type_helper *v44; // ecx
  int v45; // eax
  vostok::variant<32> *v46; // ecx
  vostok::variant<32> *v47; // eax
  vostok::ui::world **v48; // edi
  int v49; // esi
  const vostok::variant<32> **v50; // eax
  bool v51; // zf
  boost::detail::function::vtable_base *vtable; // eax
  boost::function1<void,vostok::resources::queries_result &> *v53; // ecx
  void (__cdecl *v54)(__int64 *, __int64 *, int); // eax
  void (__cdecl *v55)(char *, char *, int); // eax
  void (__cdecl *v56)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::variant<32> *v57; // edi
  vostok::detail::abstract_type_helper **p_m_helper; // esi
  _BYTE v59[52]; // [esp-34h] [ebp-F4h] BYREF
  vostok::ui::world *v60[3]; // [esp+0h] [ebp-C0h] BYREF
  int v61; // [esp+Ch] [ebp-B4h]
  const vostok::resources::request *v62; // [esp+10h] [ebp-B0h]
  survarium::game_world *a1; // [esp+14h] [ebp-ACh]
  int v64; // [esp+18h] [ebp-A8h]
  int v65; // [esp+1Ch] [ebp-A4h]
  int v66; // [esp+20h] [ebp-A0h]
  int v67; // [esp+24h] [ebp-9Ch]
  boost::function1<void,vostok::resources::queries_result &> *v68; // [esp+28h] [ebp-98h]
  __int64 v69; // [esp+30h] [ebp-90h] BYREF
  __int64 v70; // [esp+38h] [ebp-88h]
  __int64 v71; // [esp+40h] [ebp-80h]
  vostok::variant<32> other; // [esp+48h] [ebp-78h] BYREF
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+78h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+80h] [ebp-40h] BYREF
  char v75; // [esp+A0h] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::variant<32> const *> user_data_ptrs; // [esp+A4h] [ebp-1Ch]
  vostok::variant<32> *v77; // [esp+ACh] [ebp-14h]
  unsigned int requests_count; // [esp+B0h] [ebp-10h]
  vostok::buffer_vector<vostok::variant<32> > user_datas; // [esp+B4h] [ebp-Ch]
  unsigned __int8 victory_items_count; // [esp+BFh] [ebp-1h]
  vostok::resources::request *requests_begina; // [esp+D0h] [ebp+10h]
  void (__cdecl *scene_configuration)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+D4h] [ebp+14h]
  int scene_configurationa; // [esp+D4h] [ebp+14h]
  char v84; // [esp+D7h] [ebp+17h]
  char v85; // [esp+D7h] [ebp+17h]

  requests.m_end = 0;
  project_resource_name->m_is_loading = 1;
  victory_items_count = project_resource_name->m_game->m_network_client->match_options(project_resource_name->m_game->m_network_client)->victory_items_count;
  v61 = victory_items_count;
  a1 = (survarium::game_world *)(((char *)user_datas_begin - (char *)requests_end) >> 3);
  v7 = victory_items_count + s_max_tracers_count + 23;
  v8 = alloca(8 * ((_DWORD)a1 + v7));
  v9 = v60;
  v62 = (const vostok::resources::request *)v60;
  v10 = alloca(48 * v7);
  v77 = (vostok::variant<32> *)v60;
  user_datas.m_end = (vostok::variant<32> *)v60;
  v11 = alloca(4 * ((_DWORD)a1 + v7));
  requests_count = (unsigned int)v60;
  user_data_ptrs.m_end = (const vostok::variant<32> **)v60;
  v12 = requests_end;
  if ( requests_end != (vostok::resources::request *)user_datas_begin )
  {
    v14 = (const vostok::variant<32> **)v60;
    do
    {
      if ( v9 )
      {
        *v9 = (vostok::ui::world *)v12->path;
        v9[1] = (vostok::ui::world *)v12->id;
      }
      v9 += 2;
      if ( v14 )
        *v14 = *callback;
      ++v12;
      ++v14;
      ++callback;
    }
    while ( v12 != (vostok::resources::request *)user_datas_begin );
    user_data_ptrs.m_end = v14;
  }
  v84 = HIBYTE(user_datas_begin) & 0x80;
  if ( project_resource_name->m_render_scene.m_object )
  {
    m_end = user_data_ptrs.m_end;
  }
  else
  {
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
           0x1Cu) )
    {
      v15 = (survarium::damage_model_stats *)project_resource_name->m_game->ui_world(project_resource_name->m_game);
      survarium::damage_model_stats::damage_model_stats(v15, v60[0]);
    }
    else
    {
      v16 = 0;
    }
    project_resource_name->m_damage_model_stats = v16;
    v17 = (survarium::npc_stats **)vostok::memory::doug_lea_allocator::malloc_impl(
                                     (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                     0x1Cu);
    if ( v17 )
    {
      v18 = (survarium::npc_stats *)project_resource_name->m_game->ui_world(project_resource_name->m_game);
      survarium::npc_stats::npc_stats(v18, v17);
    }
    else
    {
      v19 = 0;
    }
    v20 = v77;
    project_resource_name->m_active_npc_stats = v19;
    m_helper = 0;
    v85 = v84 & 0x84 | 0x62;
    *(_QWORD *)(&log_callback.functor.data + 12) = 0xC400000080LL;
    other.m_helper = 0;
    other.m_type_id = 0;
    if ( v20 )
    {
      v20->m_helper = 0;
      v20->m_type_id = 0;
      vostok::variant<32>::operator=(v20, &other);
      m_helper = other.m_helper;
    }
    v22 = v20 + 1;
    requests_begina = (vostok::resources::request *)v22;
    user_datas.m_end = v22;
    if ( m_helper )
      m_helper->destroy(m_helper, other.m_storage);
    v23 = v22[-1].m_helper;
    v24 = v22 - 1;
    if ( v23 )
    {
      v23->destroy(v23, v24->m_storage);
      v24->m_helper = 0;
    }
    v24->m_type_id = vostok::detail::type_to_int<vostok::render::scene_configuration>::get();
    v25 = 0;
    if ( v24 != (vostok::variant<32> *)-8 )
      v24->m_storage[0] = v85;
    *(_DWORD *)v24->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
    v24->m_helper = (vostok::detail::abstract_type_helper *)v24;
    v26 = user_datas.m_end;
    other.m_helper = 0;
    other.m_type_id = 0;
    if ( user_datas.m_end )
    {
      user_datas.m_end->m_helper = 0;
      v26->m_type_id = 0;
      vostok::variant<32>::operator=(v26, &other);
      v25 = other.m_helper;
    }
    v27 = v26 + 1;
    user_datas.m_end = v27;
    if ( v25 )
      v25->destroy(v25, other.m_storage);
    v28 = v27[-1].m_helper;
    v29 = v27 - 1;
    if ( v28 )
    {
      v28->destroy(v28, v29->m_storage);
      v29->m_helper = 0;
    }
    v29->m_type_id = vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get();
    if ( v29 != (vostok::variant<32> *)-8 )
    {
      *(_QWORD *)v29->m_storage = *(_QWORD *)(&log_callback.functor.data + 12);
      *(_DWORD *)&v29->m_storage[8] = 1;
    }
    *(_DWORD *)v29->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::`vftable';
    v29->m_helper = (vostok::detail::abstract_type_helper *)v29;
    if ( v9 )
    {
      *v9 = (vostok::ui::world *)&stru_96A440.m_projection.lines[0].elements[3];
      v9[1] = (vostok::ui::world *)105;
    }
    v30 = user_data_ptrs.m_end;
    v31 = (float **)(v9 + 2);
    if ( user_data_ptrs.m_end )
      *user_data_ptrs.m_end = v77;
    v32 = v30 + 1;
    if ( v31 )
    {
      *v31 = &stru_96A440.m_projection.j.z;
      v31[1] = (float *)106;
    }
    v33 = v31 + 2;
    if ( v32 )
      *v32 = 0;
    v34 = (vostok::resources::request **)(v32 + 1);
    if ( v33 )
    {
      *v33 = &stru_96A440.m_projection.k.z;
      v33[1] = (float *)41;
    }
    v35 = v33 + 2;
    if ( v34 )
      *v34 = requests_begina;
    v36 = v34 + 1;
    if ( v35 )
    {
      *v35 = &stru_96A440.m_projection.c.w;
      v35[1] = (float *)515;
    }
    v9 = (vostok::ui::world **)(v35 + 2);
    if ( v36 )
      *v36 = 0;
    v37 = 0;
    for ( m_end = (const vostok::variant<32> **)(v36 + 1); v37 < s_max_tracers_count; ++m_end )
    {
      if ( v9 )
      {
        *v9 = (vostok::ui::world *)"weapons/trace";
        v9[1] = (vostok::ui::world *)14;
      }
      v9 += 2;
      if ( m_end )
        *m_end = 0;
      ++v37;
    }
    v39 = 16;
    do
    {
      if ( v9 )
      {
        *v9 = (vostok::ui::world *)"player_death";
        v9[1] = (vostok::ui::world *)72;
      }
      v9 += 2;
      if ( m_end )
        *m_end = 0;
      ++m_end;
      --v39;
    }
    while ( v39 );
  }
  if ( project_resource_name->m_game_project.m_object )
    survarium::game_world::unload(
      project_resource_name,
      (vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>)project_resource_name);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
  {
    v40 = vostok::core::g_log_callback;
    scene_configuration = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    {
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
      v40 = scene_configuration;
    }
    if ( v40 )
    {
      log_callback.functor.obj_ptr = v40;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    requests.m_end = (vostok::resources::request *)1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\game_world.cpp",
      0x22Du,
      "void __thiscall survarium::game_world::load(const char *,struct vostok::resources::request *,struct vostok::resour"
      "ces::request *,const class vostok::variant<32> **,const class boost::function<void __cdecl(class vostok::resources"
      "::queries_result &)> &)",
      "game:",
      info,
      "game_world::load : %s",
      (const char *)requests_begin);
  }
  if ( ((int)requests.m_end & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v41 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v41 )
          v41(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  if ( !project_resource_name->m_game_material_manager.m_object )
  {
    if ( v9 )
    {
      *v9 = (vostok::ui::world *)"game_material_manager";
      v9[1] = (vostok::ui::world *)94;
    }
    v9 += 2;
    if ( m_end )
      *m_end = 0;
    ++m_end;
  }
  v42 = 0;
  other.m_helper = 0;
  other.m_type_id = 0;
  if ( user_datas.m_end )
  {
    v43 = user_datas.m_end;
    user_datas.m_end->m_helper = 0;
    v43->m_type_id = 0;
    vostok::variant<32>::operator=(v43, &other);
    v42 = other.m_helper;
  }
  ++user_datas.m_end;
  if ( v42 )
    v42->destroy(v42, other.m_storage);
  v44 = user_datas.m_end[-1].m_helper;
  if ( v44 )
  {
    v44->destroy(v44, user_datas.m_end[-1].m_storage);
    user_datas.m_end[-1].m_helper = 0;
  }
  v45 = vostok::detail::type_to_int<survarium::base_game_scene *>::get();
  v46 = user_datas.m_end - 1;
  v46->m_type_id = v45;
  if ( v46 != (vostok::variant<32> *)-8 )
    *(_DWORD *)v46->m_storage = project_resource_name;
  v47 = user_datas.m_end - 1;
  *(_DWORD *)v47->m_helper_storage = &vostok::detail::concrete_type_helper<survarium::base_game_scene *>::`vftable';
  v47->m_helper = (vostok::detail::abstract_type_helper *)v47;
  if ( v9 )
  {
    *v9 = (vostok::ui::world *)requests_begin;
    v9[1] = (vostok::ui::world *)77;
  }
  v48 = v9 + 2;
  requests.m_end = (vostok::resources::request *)v48;
  if ( m_end )
    *m_end = v47;
  user_data_ptrs.m_end = m_end + 1;
  if ( victory_items_count )
  {
    v49 = 0;
    scene_configurationa = v61;
    do
    {
      log_callback.functor.vostok_pointer_size_alignment[1] = &log_callback.functor.data + 16;
      log_callback.functor.vostok_pointer_size_alignment[2] = &log_callback.functor.data + 16;
      log_callback.functor.vostok_pointer_size_alignment[3] = &v75;
      *(&log_callback.functor.data + 16) = 0;
      vostok::buffer_string::assignf(
        (vostok::buffer_string *)((char *)&log_callback.functor.bound_memfunc_ptr.memfunc_ptr + 4),
        "vp_%d",
        v49);
      if ( v48 )
      {
        *v48 = (vostok::ui::world *)log_callback.functor.vostok_pointer_size_alignment[1];
        v48[1] = (vostok::ui::world *)100;
      }
      v50 = user_data_ptrs.m_end;
      v48 += 2;
      if ( user_data_ptrs.m_end )
        *user_data_ptrs.m_end = 0;
      ++v49;
      v51 = scene_configurationa-- == 1;
      user_data_ptrs.m_end = v50 + 1;
    }
    while ( !v51 );
    requests.m_end = (vostok::resources::request *)v48;
  }
  *(_DWORD *)&v59[20] = 0;
  vtable = callbacka->vtable;
  if ( callbacka->vtable )
  {
    *(_DWORD *)&v59[20] = callbacka->vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
    {
      *(_QWORD *)&v59[28] = *(_QWORD *)&callbacka->functor.obj_ptr;
      *(_QWORD *)&v59[36] = *((_QWORD *)&callbacka->functor.data + 1);
      *(_QWORD *)&v59[44] = *((_QWORD *)&callbacka->functor.data + 2);
    }
    else
    {
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, _BYTE *, _DWORD))((unsigned int)vtable
                                                                                       & 0xFFFFFFFE))(
        &callbacka->functor,
        &v59[28],
        0);
    }
  }
  *(_DWORD *)&v59[4] = (unsigned __int8)1_79;
  *(_DWORD *)v59 = project_resource_name;
  boost::bind<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sky *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_sky *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)&other,
    *(void (__thiscall *__ptr64 *)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))v59,
    a1,
    (void (__thiscall *__ptr64)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))(unsigned int)survarium::game_world::on_project_loaded,
    *(boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v59[20]);
  v65 = *(_DWORD *)&other.m_helper_storage[4];
  v66 = *(_DWORD *)other.m_storage;
  v64 = *(_DWORD *)other.m_helper_storage;
  v67 = *(_DWORD *)&other.m_storage[4];
  v68 = 0;
  if ( *(_DWORD *)&other.m_storage[8] )
  {
    v68 = *(boost::function1<void,vostok::resources::queries_result &> **)&other.m_storage[8];
    if ( (other.m_storage[8] & 1) != 0 )
    {
      v69 = *(_QWORD *)&other.m_storage[16];
      v70 = *(_QWORD *)&other.m_storage[24];
      v71 = *(_QWORD *)&other.m_helper;
    }
    else
    {
      (*(void (__cdecl **)(char *, __int64 *, _DWORD))(*(_DWORD *)&other.m_storage[8] & 0xFFFFFFFE))(
        &other.m_storage[16],
        &v69,
        0);
    }
  }
  log_callback.vtable = 0;
  *(_DWORD *)&v59[4] = v64;
  *(_DWORD *)&v59[8] = v65;
  *(_DWORD *)&v59[12] = v66;
  *(_DWORD *)&v59[16] = v67;
  *(_DWORD *)&v59[20] = 0;
  v53 = v68;
  if ( v68 )
  {
    *(_DWORD *)&v59[20] = v68;
    if ( ((unsigned __int8)v68 & 1) != 0 )
    {
      *(_QWORD *)&v59[28] = v69;
      *(_QWORD *)&v59[36] = v70;
      *(_QWORD *)&v59[44] = v71;
    }
    else
    {
      (*(void (__cdecl **)(__int64 *, _BYTE *, _DWORD))((unsigned int)v68 & 0xFFFFFFFE))(&v69, &v59[28], 0);
    }
  }
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>>(
    v53,
    (int)&log_callback,
    *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *)&v59[4]);
  if ( v68 )
  {
    if ( ((unsigned __int8)v68 & 1) == 0 )
    {
      v54 = *(void (__cdecl **)(__int64 *, __int64 *, int))((unsigned int)v68 & 0xFFFFFFFE);
      if ( v54 )
        v54(&v69, &v69, 2);
    }
    v68 = 0;
  }
  if ( *(_DWORD *)&other.m_storage[8] )
  {
    if ( (other.m_storage[8] & 1) == 0 )
    {
      v55 = *(void (__cdecl **)(char *, char *, int))(*(_DWORD *)&other.m_storage[8] & 0xFFFFFFFE);
      if ( v55 )
        v55(&other.m_storage[16], &other.m_storage[16], 2);
    }
    *(_DWORD *)&other.m_storage[8] = 0;
  }
  vostok::resources::query_resources(
    v62,
    requests.m_end - v62,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&log_callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)requests_count,
    0,
    assert_on_fail_true);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v56 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v56 )
        v56(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  v57 = user_datas.m_end;
  if ( v77 != user_datas.m_end )
  {
    p_m_helper = &v77->m_helper;
    do
    {
      if ( *p_m_helper )
      {
        (*p_m_helper)->destroy(*p_m_helper, p_m_helper - 8);
        *p_m_helper = 0;
      }
      p_m_helper += 12;
    }
    while ( p_m_helper - 10 != (vostok::detail::abstract_type_helper **)v57 );
  }
}
