void __userpurge vostok::resources::query_result_for_cook::finish_query_impl(
        vostok::resources::query_result_for_cook *this@<ecx>,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *a2@<edi>,
        vostok::resources::cook_base::result_enum result,
        const assert_on_fail_bool assert_on_cook_failure,
        vostok::resources::cook_base::result_enum error_code)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *obj_ptr; // ecx
  bool has_passed_filters; // al
  const char **v7; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  int v10; // eax
  vostok::resources::query_result *v11; // ecx
  vostok::resources::query_result *v12; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-244h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // [esp-4h] [ebp-244h]
  vostok::resources::query_result_for_user::error_type_enum v15; // [esp+0h] [ebp-240h]
  char v16; // [esp+Ch] [ebp-234h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-230h] BYREF
  _BYTE v18[524]; // [esp+34h] [ebp-20Ch] BYREF

  v16 = 0;
  if ( result == result_success )
  {
    obj_ptr = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)a2[7].m_on_out_of_memory.functor.obj_ptr;
    if ( obj_ptr[2].functor.vostok_pointer_size_alignment[1] )
    {
      if ( assert_on_cook_failure == assert_on_fail_false )
        goto LABEL_16;
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&stru_7F94B0.m_string.m_buffer[28],
                                   (const char *)3),
            obj_ptr = v13,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          obj_ptr,
          &log_callback);
        v16 = 1;
        v7 = (const char **)((int (__thiscall *)(vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *, _BYTE *))a2->m_on_out_of_memory.vtable[1].manager)(
                              a2,
                              v18);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_query_result_finalization.cpp",
          0x10Eu,
          "void __thiscall vostok::resources::query_result_for_cook::finish_query_impl(enum vostok::resources::cook_base:"
          ":result_enum,const enum assert_on_fail_bool,enum vostok::resources::query_result_for_user::error_type_enum)",
          &stru_7F94B0.m_string.m_buffer[28],
          warning,
          "cook of %s failed",
          *v7);
      }
      if ( (v16 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)obj_ptr,
          (int *)&log_callback);
    }
    if ( assert_on_cook_failure == assert_on_fail_false
      || !vostok::command_line::key::is_set((vostok::command_line::key *)obj_ptr, (int)&s_assert_on_cook_failure) )
    {
      goto LABEL_16;
    }
    __debugbreak();
  }
  if ( result == (result_cannot_lock|result_success) )
  {
    a2[6].m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *)(!vostok::resources::query_result::is_translate_query((vostok::resources::query_result *)this, (int)a2) + 1);
    a2[5].m_on_out_of_memory.functor.vostok_pointer_size_alignment[2] = (void *)7;
    vostok::resources::get_out_of_memory_callback((boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&log_callback);
    if ( (log_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      vostok::resources::query_result::set_create_resource_result(
        (vostok::resources::query_result *)5,
        a2,
        error_code,
        v15);
      boost::function1<void,vostok::collision::object const &>::operator()(v8, &log_callback, a2);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v9,
        (int *)&log_callback);
      return;
    }
    result = result_success;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v14,
      (int *)&log_callback);
  }
LABEL_16:
  vostok::resources::query_result::set_create_resource_result(
    (vostok::resources::query_result *)result,
    a2,
    error_code,
    v15);
  if ( vostok::resources::query_result::is_translate_query(v11, v10) )
    vostok::resources::query_result::finish_translated_query(v12, (vostok::resources::query_result *)a2);
  else
    vostok::resources::query_result::finish_normal_query(v12, (vostok::resources::query_result *)a2, result);
}
