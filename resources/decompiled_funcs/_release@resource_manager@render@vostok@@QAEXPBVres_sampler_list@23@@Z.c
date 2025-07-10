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
