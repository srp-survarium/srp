void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *rt,
        const char *name)
{
  char *v3; // ebp
  volatile signed __int32 *v4; // ecx
  int v5; // eax
  const vostok::render::render_target *v6; // eax
  vostok::render::grass_render_model *m_object; // esi
  vostok::render::render_target *v8; // ecx
  int v9; // [esp-4h] [ebp-10h] BYREF

  v3 = (char *)name;
  if ( name[56] )
  {
    v4 = (volatile signed __int32 *)*((_DWORD *)name + 1);
    v5 = 0;
    if ( v4
      && (v5 = *((_DWORD *)name + 1),
          _InterlockedExchangeAdd(v4, 1u),
          vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
    {
      name = (const char *)(v5 + 16);
    }
    else
    {
      name = 0;
    }
    if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)v5, 0xFFFFFFFF) )
    {
      v9 = v5;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v5,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
    v6 = (const vostok::render::render_target *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                                                  (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&name,
                                                  (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&rt->m_rt_registry,
                                                  &name);
    if ( v6 != (const vostok::render::render_target *)&rt->m_rt_registry )
    {
      stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
        (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v9,
        (int)&rt->m_rt_registry,
        (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v6);
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::render_target::~render_target(v8, v3);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v3);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_declaration *dcl@<eax>)
{
  char v2; // bl
  vostok::render::res_declaration *v4; // ecx
  vostok::render::grass_render_model *m_object; // ebx
  vostok::render::res_declaration *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( dcl->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_declaration,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>>(
           &this->m_declarations,
           dcl) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_declaration::~res_declaration(v4);
      v6 = dcl;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xB53u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_declaration *)",
          "render:",
          error,
          "! ERROR: Failed to find compiled vertex-declarator");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_geometry *geom@<eax>)
{
  char v2; // bl
  vostok::render::res_geometry *v4; // ecx
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::res_geometry *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( geom->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           &this->m_geometries,
           geom) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_geometry::~res_geometry(v4);
      v6 = geom;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xD3Eu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_geometry *)",
          "render:",
          error,
          "!ERROR: Failed to find the geometry.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        const vostok::render::res_input_layout *layout)
{
  char v2; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( layout->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_input_layout,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>>(
           (vostok::render::res_input_layout *const *)&this->m_input_layouts,
           layout) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::res_input_layout,vostok::render::resource_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::render::res_input_layout **)&layout);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v4 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v4 )
        {
          log_callback.functor.obj_ptr = v4;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xBAAu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_input_layout *)",
          "render:",
          error,
          "! ERROR: Failed to find created layout");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v3,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<eax>,
        vostok::render::res_state *render_output@<edi>)
{
  char v2; // bl
  vostok::render::res_render_output *v3; // ecx
  vostok::render::grass_render_model *m_object; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( BYTE2(render_output[9].m_blend_state) )
  {
    if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
           (vostok::render::vector<vostok::render::res_state *> *)&this->m_render_outputs,
           render_output) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_render_output::~res_render_output(v3, (int)render_output);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), render_output);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v6 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v6 )
        {
          log_callback.functor.obj_ptr = v6;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xD5Au,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_render_output *)",
          "render:",
          error,
          "!ERROR: Failed to render output in registry.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v5,
          (int *)&log_callback);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        const vostok::render::res_sampler_list *smp_list)
{
  char v2; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( smp_list->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_sampler_list,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>>(
           (const vostok::render::res_sampler_list *const *)&this->m_sampler_lists,
           (stlp_std::priv::_Rb_tree<vostok::render::res_sampler_list *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_sampler_list>,vostok::render::res_sampler_list *,stlp_std::priv::_Identity<vostok::render::res_sampler_list *>,stlp_std::priv::_SetTraitsT<vostok::render::res_sampler_list *>,vostok::render::std_allocator<vostok::render::res_sampler_list *> > *)this) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::res_sampler_list,vostok::render::resource_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::render::res_sampler_list **)&smp_list);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v4 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v4 )
        {
          log_callback.functor.obj_ptr = v4;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xC7Eu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_sampler_list *)",
          "render:",
          error,
          "!ERROR: Failed to find compiled list of samplers");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v3,
          (int *)&log_callback);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        const vostok::render::res_signature *signature)
{
  char v2; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( signature->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_signature,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>>(
           &this->m_signatures,
           signature) )
    {
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_signature const,vostok::render::resource_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (const vostok::render::untyped_buffer **)&signature);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v4 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v4 )
        {
          log_callback.functor.obj_ptr = v4;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xB7Eu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_signature *)",
          "render:",
          error,
          "! ERROR: Failed to find created signature.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v3,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<eax>,
        vostok::render::res_state *state@<edi>)
{
  char v2; // bl
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( state->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::untyped_buffer>(&this->m_states, state) )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, state);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v5 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v5 )
        {
          log_callback.functor.obj_ptr = v5;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xB25u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_state *)",
          "render:",
          error,
          "!ERROR: Failed to find compiled stateblock");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v4,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        const vostok::render::res_texture *texture@<esi>)
{
  vostok::render::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred> *p_m_texture_registry; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v3; // eax
  vostok::render::resource_manager *v4[2]; // [esp-4h] [ebp-Ch] BYREF
  const char *name; // [esp+4h] [ebp-4h] BYREF

  if ( texture->m_is_registered )
  {
    p_m_texture_registry = &this->m_texture_registry;
    name = texture->m_name.m_string.m_begin;
    v3 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
           (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&name,
           &this->m_texture_registry._M_t,
           &name);
    if ( v3 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)p_m_texture_registry )
    {
      stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
        (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)v4,
        (int)p_m_texture_registry,
        (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v3);
      vostok::render::resource_manager::release_impl(texture, v4[1]);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        const vostok::render::res_texture_list *tex_list)
{
  char v2; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( tex_list->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_texture_list,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_texture_list>>(
           &this->m_texture_lists,
           tex_list) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::res_texture_list,vostok::render::resource_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::render::res_texture_list **)&tex_list);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v4 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v4 )
        {
          log_callback.functor.obj_ptr = v4;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xC48u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_texture_list *)",
          "render:",
          error,
          "!ERROR: Failed to find compiled list of textures");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v3,
          (int *)&log_callback);
    }
  }
}


void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        const vostok::render::shader_constant_buffer *cbuffer)
{
  char v2; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( cbuffer->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::shader_constant_buffer,vostok::render::resource_manager::constant_buffer_predicate>(
           (const vostok::render::shader_constant_buffer *const *)&this->m_const_buffers,
           (stlp_std::priv::_Rb_tree<vostok::render::shader_constant_buffer *,vostok::render::resource_manager::constant_buffer_predicate,vostok::render::shader_constant_buffer *,stlp_std::priv::_Identity<vostok::render::shader_constant_buffer *>,stlp_std::priv::_SetTraitsT<vostok::render::shader_constant_buffer *>,vostok::render::std_allocator<vostok::render::shader_constant_buffer *> > *)this) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::shader_constant_buffer,vostok::render::resource_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::render::shader_constant_buffer **)&cbuffer);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v4 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v4 )
        {
          log_callback.functor.obj_ptr = v4;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xC18u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::shader_constant_buffer *)",
          "render:",
          error,
          "!ERROR: Failed to find shader_constant buffer");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v3,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::shader_constant_table *const_table@<eax>)
{
  char v2; // bl
  vostok::render::shader_constant_table *v4; // ecx
  vostok::render::grass_render_model *m_object; // ebx
  vostok::render::shader_constant_table *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( const_table->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::shader_constant_table,vostok::render::resource_manager::constant_table_predicate>(
           &this->m_const_tables,
           const_table) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::shader_constant_table::~shader_constant_table(v4);
      v6 = const_table;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0x620u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::shader_constant_table *)",
          "render:",
          error,
          "!ERROR: Failed to find compiled shader_constant-table");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __userpurge vostok::render::resource_manager::release(
        vostok::render::res_state *buffer@<edi>,
        vostok::render::resource_manager *this)
{
  ID3D11Buffer *m_rasterizer_state; // eax
  vostok::render::grass_render_model *m_object; // esi

  if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
         (vostok::render::vector<vostok::render::res_state *> *)&this->m_buffers,
         buffer) )
  {
    this->m_num_bytes_of_buffers_video_memory -= (unsigned int)buffer->m_depth_stencil_state;
    m_rasterizer_state = (ID3D11Buffer *)buffer->m_rasterizer_state;
    m_object = vostok::render::g_allocator.m_object;
    if ( m_rasterizer_state )
    {
      m_rasterizer_state->Release(buffer->m_rasterizer_state);
      buffer->m_rasterizer_state = 0;
    }
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), buffer);
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs<vostok::render::gs_data> *gs@<eax>)
{
  char v2; // bl
  vostok::render::res_xs<vostok::render::gs_data> *v4; // ecx
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::res_xs<vostok::render::gs_data> *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v2 = 0;
  if ( gs->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>>(
           (const vostok::render::res_xs<vostok::render::vs_data> *const *)&this->m_g_shaders,
           (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)this) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_xs<vostok::render::gs_data>::~res_xs<vostok::render::gs_data>(v4, (int)gs);
      v6 = gs;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xCDFu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::gs_data> *)",
          "render:",
          error,
          "!ERROR: Failed to find GS.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs<vostok::render::ps_data> *ps@<eax>)
{
  char v2; // bl
  vostok::render::res_xs<vostok::render::ps_data> *v4; // ecx
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::res_xs<vostok::render::ps_data> *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v2 = 0;
  if ( ps->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>>(
           (const vostok::render::res_xs<vostok::render::vs_data> *const *)&this->m_p_shaders,
           (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)this) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_xs<vostok::render::ps_data>::~res_xs<vostok::render::ps_data>(v4, (int)ps);
      v6 = ps;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xD0Cu,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::ps_data> *)",
          "render:",
          error,
          "!ERROR: Failed to find PS.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs<vostok::render::vs_data> *vs@<eax>)
{
  char v2; // bl
  vostok::render::res_xs<vostok::render::vs_data> *v4; // ecx
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::res_xs<vostok::render::vs_data> *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v2 = 0;
  if ( vs->m_is_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>>(
           (const vostok::render::res_xs<vostok::render::vs_data> *const *)&this->m_v_shaders,
           (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)this) )
    {
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::res_xs<vostok::render::vs_data>::~res_xs<vostok::render::vs_data>(v4, (int)vs);
      v6 = vs;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resource_manager.cpp",
          0xCB3u,
          "void __thiscall vostok::render::resource_manager::release(const class vostok::render::res_xs<struct vostok::re"
          "nder::vs_data> *)",
          "render:",
          error,
          "!ERROR: Failed to find VS.");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&log_callback);
    }
  }
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *gs@<eax>)
{
  vostok::render::resource_manager::release_impl<vostok::render::gs_data>(this, gs);
}


void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::ps_data> *ps@<eax>)
{
  vostok::render::resource_manager::release_impl<vostok::render::ps_data>(this, ps);
}


void __userpurge vostok::render::resource_manager::release(
        const vostok::render::res_xs_hw<vostok::render::vs_data> *vs@<eax>,
        vostok::render::resource_manager *a2@<ecx>,
        vostok::render::resource_manager *this)
{
  vostok::render::resource_manager::release_impl<vostok::render::vs_data>(a2, (int)this, vs);
}
