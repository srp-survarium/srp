void __thiscall vostok::strings::shared::manager::~manager(
        vostok::strings::shared::manager *this,
        vostok::strings::shared::manager *thisa)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // ebx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::strings::shared::profile *m_value; // edi
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  remove_predicate v11; // [esp+10h] [ebp-60h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *p_m_storage; // [esp+14h] [ebp-5Ch]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator i; // [esp+18h] [ebp-58h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v14; // [esp+24h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+50h] [ebp-20h] BYREF

  v2 = (_RTL_CRITICAL_SECTION *)thisa;
  v3 = 0;
  vostok::threading::mutex::lock(&thisa->m_mutex);
  v11.m_mutex = &thisa->m_mutex;
  p_m_storage = &thisa->m_storage;
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::clear<remove_predicate>(
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&v11,
    &thisa->m_storage,
    &v11);
  LeaveCriticalSection((LPCRITICAL_SECTION)thisa);
  if ( *(_DWORD *)((char *)thisa->m_mutex.m_mutex.m_mutex + (_DWORD)&loc_2001B + 1) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "strings:shared:", error) )
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
      v3 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\strings_shared_manager.cpp",
        0x3Eu,
        "__thiscall vostok::strings::shared::manager::~manager(void)",
        "strings:shared:",
        error,
        "leaked %d strings",
        *(_DWORD *)((char *)thisa->m_mutex.m_mutex.m_mutex + (_DWORD)&loc_2001B + 1));
    }
    if ( (v3 & 1) != 0 )
    {
      v3 &= ~1u;
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v6 )
            v6(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::begin(
      v4,
      &i,
      p_m_storage);
    while ( 1 )
    {
      m_value = i.m_value;
      if ( !i.m_value )
        break;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "strings:shared:", error) )
      {
        v9 = vostok::core::g_log_callback;
        v16.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v16.functor,
            &v16.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          v16.functor.obj_ptr = v9;
          v16.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v16.vtable = 0;
        }
        v3 |= 2u;
        vostok::logging::append(
          &v16,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\strings_shared_manager.cpp",
          0x43u,
          "__thiscall vostok::strings::shared::manager::~manager(void)",
          "strings:shared:",
          error,
          "[%d count] %s",
          m_value->m_reference_count,
          (const char *)&m_value[1]);
      }
      if ( (v3 & 2) != 0 )
      {
        v3 &= ~2u;
        if ( v16.vtable )
        {
          if ( ((int)v16.vtable & 1) == 0 )
          {
            v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v16.vtable & 0xFFFFFFFE);
            if ( v10 )
              v10(&v16.functor, &v16.functor, 2);
          }
        }
      }
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
        v8,
        &v14,
        (__int64 *)&i);
    }
    v2 = (_RTL_CRITICAL_SECTION *)thisa;
  }
  memset((int)&v2[1].LockCount, 0, (unsigned int)&loc_20000);
  *(_RTL_CRITICAL_SECTION_DEBUG **)((char *)&v2->DebugInfo + (_DWORD)&loc_2001B + 1) = 0;
  DeleteCriticalSection(v2);
}
