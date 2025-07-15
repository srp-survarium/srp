void __userpurge survarium::text_translator::translate_text(
        survarium::text_translator *this@<eax>,
        char *text_id@<edi>,
        wchar_t *translated_text)
{
  char v4; // bl
  vostok::configs::binary_config_value *v5; // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char *pointer; // eax
  vostok::configs::binary_config_value *v9; // eax
  char *v10; // [esp+0h] [ebp-34h]
  unsigned int pConvertedChars; // [esp+10h] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+14h] [ebp-20h] BYREF

  v4 = 0;
  pConvertedChars = 0;
  v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 this->m_text_data.m_object->m_root,
                                                 "strings");
  if ( vostok::configs::binary_config_value::value_exists(v5, v10) )
  {
    v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   this->m_text_data.m_object->m_root,
                                                   "strings");
    pointer = (char *)vostok::configs::binary_config_value::operator[](v9, text_id)->data.pointer;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
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
      v4 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\text_translator.cpp",
        0x38u,
        "void __thiscall survarium::text_translator::translate_text(const char *,wchar_t [])",
        "game:",
        info,
        "There is no available localization for [%s] !!!",
        text_id);
    }
    if ( (v4 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v7 )
            v7(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    pointer = text_id;
  }
  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, translated_text, 0x200u, pointer, 0xFFFFFFFF);
}
