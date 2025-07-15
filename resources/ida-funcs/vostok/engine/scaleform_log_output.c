void __cdecl vostok::engine::scaleform_log_output(unsigned __int8 message_type, char *fmt)
{
  char v2; // bl
  unsigned int v3; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  _BYTE v10[2060]; // [esp-80Ch] [ebp-1094h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+10h] [ebp-878h] BYREF
  int v12; // [esp+34h] [ebp-854h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+38h] [ebp-850h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+58h] [ebp-830h] BYREF
  vostok::fixed_string<2048> buff; // [esp+78h] [ebp-810h] BYREF
  char v16; // [esp+884h] [ebp-4h] BYREF

  buff.m_max_end = &v16;
  v2 = 0;
  buff.m_begin = buff.m_buffer;
  v12 = 0;
  buff.m_buffer[0] = 0;
  v3 = strlen(fmt);
  memcpy((unsigned __int8 *)buff.m_buffer, (unsigned __int8 *)fmt, v3);
  buff.m_end = &buff.m_buffer[v3];
  buff.m_buffer[v3] = 0;
  switch ( message_type )
  {
    case 1u:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "scaleform:", info) )
      {
        v9 = vostok::core::g_log_callback;
        v13.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v13.functor,
            &v13.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          v13.functor.obj_ptr = v9;
          v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v13.vtable = 0;
        }
        qmemcpy(v10, &buff, sizeof(v10));
        v2 = 1;
        vostok::logging::append(
          &v13,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\engine_scaleform_initialize.cpp",
          0x23u,
          "void __cdecl vostok::engine::scaleform_log_output(unsigned char,const char *)",
          "scaleform:",
          info,
          "%s");
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v8,
          (int *)&v13);
      break;
    case 2u:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "scaleform:", warning) )
      {
        v7 = vostok::core::g_log_callback;
        v11.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v11.functor,
            &v11.functor,
            destroy_functor_tag);
        if ( v7 )
        {
          v11.functor.obj_ptr = v7;
          v11.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v11.vtable = 0;
        }
        qmemcpy(v10, &buff, sizeof(v10));
        v2 = 2;
        vostok::logging::append(
          &v11,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\engine_scaleform_initialize.cpp",
          0x27u,
          "void __cdecl vostok::engine::scaleform_log_output(unsigned char,const char *)",
          "scaleform:",
          warning,
          "%s");
      }
      if ( (v2 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v6,
          (int *)&v11);
      break;
    case 3u:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "scaleform:", error) )
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
        qmemcpy(v10, &buff, sizeof(v10));
        v2 = 4;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\engine_scaleform_initialize.cpp",
          0x2Bu,
          "void __cdecl vostok::engine::scaleform_log_output(unsigned char,const char *)",
          "scaleform:",
          error,
          "%s");
      }
      if ( (v2 & 4) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v4,
          (int *)&log_callback);
      break;
  }
}
