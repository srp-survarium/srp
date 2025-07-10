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
