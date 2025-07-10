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
