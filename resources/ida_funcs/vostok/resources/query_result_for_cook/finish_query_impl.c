void __userpurge vostok::resources::query_result_for_cook::finish_query_impl(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<edi>,
        vostok::resources::cook_base::result_enum result,
        assert_on_fail_bool assert_on_cook_failure,
        vostok::resources::query_result_for_cook *error_code)
{
  vostok::resources::cook_base::result_enum v5; // esi
  char v6; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  const char **v9; // eax
  vostok::resources::cook_base *v10; // eax
  int v11; // ecx
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v15; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-250h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+28h] [ebp-230h] BYREF
  int v18; // [esp+48h] [ebp-210h]
  _BYTE v19[524]; // [esp+4Ch] [ebp-20Ch] BYREF

  v5 = result;
  v6 = 0;
  v18 = 0;
  if ( result == result_error )
  {
    if ( !*(_DWORD *)(*(_DWORD *)(a2 + 328) + 76) )
    {
LABEL_14:
      if ( assert_on_cook_failure && vostok::command_line::key::is_set(&s_assert_on_cook_failure) )
        __debugbreak();
      goto LABEL_30;
    }
    if ( assert_on_cook_failure )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", warning) )
      {
        v8 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v8 )
        {
          log_callback.functor.obj_ptr = v8;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v6 = 1;
        v9 = (const char **)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)a2 + 4))(a2, v19);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_query_result_finalization.cpp",
          0x10Au,
          "void __thiscall vostok::resources::query_result_for_cook::finish_query_impl(enum vostok::resources::cook_base:"
          ":result_enum,const enum assert_on_fail_bool,enum vostok::resources::query_result_for_user::error_type_enum)",
          "resources:",
          warning,
          "cook of %s failed",
          *v9);
      }
      if ( (v6 & 1) != 0 )
      {
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v7,
          (int *)&log_callback);
        v5 = result_error;
      }
      goto LABEL_14;
    }
LABEL_30:
    this = error_code;
    *(_DWORD *)(a2 + 256) = error_code;
    *(_DWORD *)(a2 + 260) = v5;
LABEL_31:
    cook = vostok::resources::resources_manager::find_cook((int)this, *(vostok::resources::class_id_enum *)(a2 + 132));
    if ( cook && (cook->m_flags.m_flags & 8) != 0 )
      vostok::resources::query_result::finish_translated_query((vostok::resources::query_result *)a2, v5);
    else
      vostok::resources::query_result::finish_normal_query(v15, (vostok::resources::query_result *)a2, v5);
    return;
  }
  if ( result != result_out_of_memory )
  {
    if ( result == result_postponed )
    {
      if ( (((unsigned int)&loc_1FFFFE + 2) & *(_DWORD *)(a2 + 688)) == 0 )
        *(_DWORD *)(a2 + 260) = 2;
      goto LABEL_31;
    }
    goto LABEL_30;
  }
  v10 = vostok::resources::resources_manager::find_cook((int)this, *(vostok::resources::class_id_enum *)(a2 + 132));
  if ( v10 )
    v10 = (v10->m_flags.m_flags & 8) != 8 ? 0 : v10;
  *(_DWORD *)(a2 + 304) = 2 - (v10 != 0);
  *(_DWORD *)(a2 + 256) = 7;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
    (int)&callback);
  v11 = -(callback.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v11) == 0 )
  {
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&callback.functor, &callback.functor, 2);
      }
    }
    v5 = result_error;
    goto LABEL_30;
  }
  *(_DWORD *)(a2 + 256) = error_code;
  *(_DWORD *)(a2 + 260) = 5;
  boost::function1<void,vostok::collision::object const &>::operator()(
    (boost::function1<void,vostok::collision::object const &> *)v11,
    &callback,
    (const vostok::collision::object *)a2);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v12 )
        v12(&callback.functor, &callback.functor, 2);
    }
  }
}
