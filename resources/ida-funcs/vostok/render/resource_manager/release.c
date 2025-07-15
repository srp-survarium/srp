void __userpurge vostok::render::resource_manager::release(
        vostok::render::render_target *rt@<eax>,
        vostok::render::resource_manager *this)
{
  bool v3; // zf
  vostok::strings::shared::profile *m_object; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v5; // ecx
  vostok::strings::shared::profile *v6; // eax
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  stlp_std::priv::_Rb_tree_node_base *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  vostok::memory::doug_lea_allocator *v11; // esi
  vostok::render::render_target *v12; // ecx
  vostok::memory::doug_lea_allocator *v13; // ecx
  bool has_passed_filters; // al
  vostok::strings::shared::profile *v15; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp-4h] [ebp-44h]
  const char *v17; // [esp+0h] [ebp-40h]
  const char *v18; // [esp+0h] [ebp-40h]
  const char *v19; // [esp+4h] [ebp-3Ch]
  const char *v20; // [esp+4h] [ebp-3Ch]
  unsigned int v21; // [esp+8h] [ebp-38h]
  unsigned int v22; // [esp+8h] [ebp-38h]
  vostok::shared_string v23; // [esp+10h] [ebp-30h] BYREF
  int v24; // [esp+14h] [ebp-2Ch]
  vostok::strings::shared::profile *v25; // [esp+18h] [ebp-28h] BYREF
  vostok::shared_string *p_m_name; // [esp+1Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+20h] [ebp-20h] BYREF

  v3 = !rt->m_is_registered;
  v24 = 0;
  if ( !v3 )
  {
    p_m_name = &rt->m_name;
    m_object = rt->m_name.m_pointer.m_object;
    v23.m_pointer.m_object = 0;
    if ( m_object )
    {
      v23.m_pointer.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v25 = vostok::shared_string::c_str(&v23);
    if ( v23.m_pointer.m_object )
    {
      v6 = v23.m_pointer.m_object;
      v5 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)_InterlockedExchangeAdd(&v23.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v5 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v6);
    }
    v7 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
           v5,
           (const char *const *)&this->m_rt_registry,
           (const char **)&v25);
    if ( v7 == (stlp_std::priv::_Rb_tree_node_base *)&this->m_rt_registry )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v8 = v16,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v8,
          &v27);
        v24 = 1;
        v15 = vostok::shared_string::c_str(p_m_name);
        vostok::logging::append(
          &v27,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xF68u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::render_target *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "! ERROR: Failed to find render-target '%s'",
          (const char *)v15);
      }
      if ( (v24 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
          (int *)&v27);
    }
    else
    {
      v9 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
             v7,
             &this->m_rt_registry._M_t._M_header._M_data._M_parent,
             &this->m_rt_registry._M_t._M_header._M_data._M_left,
             &this->m_rt_registry._M_t._M_header._M_data._M_right);
      vostok::memory::doug_lea_allocator::free_impl(
        v10,
        (int)vostok::render::g_allocator,
        (char *)&v9->_M_color,
        v17,
        v19,
        v21);
      --this->m_rt_registry._M_t._M_node_count;
      v11 = vostok::render::g_allocator;
      vostok::render::render_target::~render_target(v12, (int)rt);
      vostok::memory::doug_lea_allocator::free_impl(v13, (int)v11, (char *)rt, v18, v20, v22);
    }
  }
}


void __userpurge vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_pass *dcl)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  vostok::render::res_state *m_object; // ecx
  vostok::memory::doug_lea_allocator *v7; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-34h]
  const char *v11; // [esp+0h] [ebp-30h]
  const char *v12; // [esp+4h] [ebp-2Ch]
  unsigned int v13; // [esp+8h] [ebp-28h]
  char v14; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+10h] [ebp-20h] BYREF

  v14 = 0;
  if ( LOBYTE(dcl[165].m_ps.m_object) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)&loc_938E8 + a2),
           dcl);
    v4 = v9;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      m_object = dcl[37].m_state.m_object;
      dcl[37].m_vs.m_object = (vostok::render::res_xs<vostok::render::vs_data> *)m_object;
      vostok::buffer_vector<vostok::render::signature_layout_pair>::~buffer_vector<vostok::render::signature_layout_pair>(
        (vostok::buffer_vector<vostok::render::signature_layout_pair> *)m_object,
        (int *)&dcl->m_state);
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)v5, (char *)dcl, v11, v12, v13);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v10,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v15);
        v14 = 1;
        vostok::logging::append(
          &v15,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xEBBu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_declaration *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "! ERROR: Failed to find compiled vertex-declarator");
      }
      if ( (v14 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v15);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *geom@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_geometry *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( LOBYTE(geom->m_input_layout.m_object) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)this + (_DWORD)&loc_94631 + 3),
           geom);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_geometry::~res_geometry(v8, (int)geom);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)geom, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x10C7u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_geometry *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find the geometry.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *layout@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_input_layout *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( LOBYTE(layout->m_ps.m_object) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)this + (_DWORD)&loc_93914 + 4),
           layout);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_input_layout::~res_input_layout(
        v8,
        (vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)layout);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)layout, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xF12u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_input_layout *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "! ERROR: Failed to find created layout");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_render_output *render_output@<eax>)
{
  char v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_render_output *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( render_output->m_is_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_render_output,64>(render_output);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_render_output::~res_render_output(
        v8,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)render_output);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)render_output, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x10E3u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_render_output *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to render output in registry.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *smp_list@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::render::res_state *m_object; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-34h]
  const char *v9; // [esp+0h] [ebp-30h]
  const char *v10; // [esp+4h] [ebp-2Ch]
  unsigned int v11; // [esp+8h] [ebp-28h]
  char v12; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+10h] [ebp-20h] BYREF

  v12 = 0;
  if ( smp_list[55].m_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)this + (_DWORD)&loc_9395C + 4),
           smp_list);
    v4 = v7;
    if ( v3 )
    {
      m_object = smp_list[5].m_state.m_object;
      smp_list[5].m_vs.m_object = (vostok::render::res_xs<vostok::render::vs_data> *)m_object;
      smp_list->m_vs.m_object = (vostok::render::res_xs<vostok::render::vs_data> *)smp_list->m_state.m_object;
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)m_object,
        (int)vostok::render::g_allocator,
        (char *)smp_list,
        v9,
        v10,
        v11);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v8,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v13);
        v12 = 1;
        vostok::logging::append(
          &v13,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x1007u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_sampler_list *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find compiled list of samplers");
      }
      if ( (v12 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v13);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *signature@<eax>)
{
  bool v3; // al
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::render::res_state *m_object; // eax
  vostok::memory::doug_lea_allocator *v6; // edi
  bool has_passed_filters; // al
  vostok::memory::doug_lea_allocator *v8; // [esp-4h] [ebp-34h]
  vostok::memory::doug_lea_allocator *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( LOBYTE(signature->m_vs.m_object) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)&loc_93900 + (_DWORD)this),
           signature);
    v4 = v8;
    if ( v3 )
    {
      m_object = signature->m_state.m_object;
      v6 = vostok::render::g_allocator;
      if ( m_object )
      {
        (*(void (__stdcall **)(vostok::render::res_state *))(m_object->m_reference_count + 8))(signature->m_state.m_object);
        signature->m_state.m_object = 0;
      }
      vostok::memory::doug_lea_allocator::free_impl(v4, (int)v6, (char *)signature, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xEE6u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_signature *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "! ERROR: Failed to find created signature.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        vostok::render::res_texture *texture,
        vostok::render::res_texture *a3)
{
  vostok::render::res_texture *v3; // ebx
  float w; // esi
  vostok::fixed_string<260> *v5; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v6; // ecx
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  const char *v9; // esi
  vostok::memory::doug_lea_allocator *v10; // ecx
  unsigned int v11; // ecx
  vostok::buffer_vector<vostok::fixed_string<260> > *v12; // [esp-4h] [ebp-14h]
  const char *v13; // [esp+0h] [ebp-10h]
  const char *v14; // [esp+4h] [ebp-Ch]
  unsigned int v15; // [esp+8h] [ebp-8h]
  vostok::fixed_string<260> *where; // [esp+Ch] [ebp-4h] BYREF

  v3 = texture;
  if ( a3->m_is_registered )
  {
    w = texture->m_rescale_min.w;
    texture = (vostok::render::res_texture *)a3->m_name.m_string.m_begin;
    v5 = stlp_std::priv::__find<vostok::fixed_string<260> *,char const *>(
           (vostok::fixed_string<260> *)LODWORD(v3->m_rescale_min.z),
           (vostok::fixed_string<260> *)LODWORD(w),
           (const char **)&texture);
    v6 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v12;
    where = v5;
    if ( v5 != (vostok::fixed_string<260> *)LODWORD(w) )
      vostok::buffer_vector<vostok::fixed_string<260>>::erase(v12, &v3->m_rescale_min.z, &where);
    v7 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
           v6,
           (const char *const *)&v3[1211].m_desc_3d.MiscFlags,
           (const char **)&texture);
    if ( v7 != (stlp_std::priv::_Rb_tree_node_base *)&v3[1211].m_desc_3d.MiscFlags )
    {
      v8 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
             v7,
             (stlp_std::priv::_Rb_tree_node_base **)&v3[1211].m_name,
             (stlp_std::priv::_Rb_tree_node_base **)&v3[1211].m_name.m_string.m_end,
             (stlp_std::priv::_Rb_tree_node_base **)&v3[1211].m_name.m_string.m_max_end);
      v9 = (const char *)vostok::render::g_allocator;
      vostok::memory::doug_lea_allocator::free_impl(
        v10,
        (int)vostok::render::g_allocator,
        (char *)&v8->_M_color,
        v13,
        v14,
        v15);
      --*(_DWORD *)v3[1211].m_name.m_string.m_buffer;
      vostok::render::resource_manager::release_impl(
        (vostok::render::resource_manager *)v3,
        a3,
        v11,
        (const char *)v3,
        v9);
    }
  }
}


void __userpurge vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_pass *tex_list)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( LOBYTE(tex_list[9].m_input_layout.m_object) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)&loc_9392C + a2 + 4),
           tex_list);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
        v8,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&tex_list->m_state);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)tex_list, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xFD1u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_texture_list *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find compiled list of textures");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __userpurge vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_pass *cbuffer)
{
  bool v4; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  vostok::memory::doug_lea_allocator *v7; // ecx
  bool has_passed_filters; // al
  vostok::render::shader_constant_buffer *v9; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-38h]
  const char *v11; // [esp+0h] [ebp-34h]
  const char *v12; // [esp+4h] [ebp-30h]
  unsigned int v13; // [esp+8h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-24h] BYREF
  char ptr; // [esp+3Ch] [ebp+8h]

  ptr = 0;
  if ( BYTE1(cbuffer[3].m_ps.m_object) )
  {
    v4 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)(a2 + 557268),
           cbuffer);
    v5 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v9;
    if ( v4 )
    {
      v6 = vostok::render::g_allocator;
      vostok::render::shader_constant_buffer::~shader_constant_buffer(v9);
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)v6, (char *)cbuffer, v11, v12, v13);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v5 = v10,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v5,
          &v14);
        ptr = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xF87u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::shader_constant_buffer *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find shader_constant buffer");
      }
      if ( (ptr & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
          (int *)&v14);
    }
  }
}


void __userpurge vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_pass *const_table)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::shader_constant_table *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( LOBYTE(const_table[33].m_reference_count) )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)(a2 + 557244),
           const_table);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::shader_constant_table::~shader_constant_table(v8, (int)const_table);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)const_table, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x8B8u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::shader_constant_table *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find compiled shader_constant-table");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *gs@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_xs<vostok::render::gs_data> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+8h] [ebp-28h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  v13 = 0;
  if ( gs->m_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)&this->m_g_shaders,
           gs);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_xs<vostok::render::gs_data>::`scalar deleting destructor'(v8, (int)gs);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)gs, v10, v11, (const unsigned int)v12.vtable);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v12);
        v13 = 1;
        vostok::logging::append(
          &v12,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x1068u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::gs_data> *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find GS.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v12);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *ps@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_xs<vostok::render::ps_data> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( ps->m_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)&this->m_p_shaders,
           ps);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_xs<vostok::render::ps_data>::`scalar deleting destructor'(v8, (int)ps);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)ps, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x1095u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::ps_data> *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find PS.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_pass *vs@<eax>)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_xs<vostok::render::vs_data> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+8h] [ebp-28h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  v13 = 0;
  if ( vs->m_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)((char *)&loc_88150 + (_DWORD)this),
           vs);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_xs<vostok::render::vs_data>::`scalar deleting destructor'(v8, (int)vs);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)vs, v10, v11, (const unsigned int)v12.vtable);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v12);
        v13 = 1;
        vostok::logging::append(
          &v12,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x103Cu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::vs_data> *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find VS.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v12);
    }
  }
}
