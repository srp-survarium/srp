void __userpurge survarium::options_item_base::options_item_base(
        survarium::options_item_base *this@<edi>,
        const char *console_command@<eax>,
        survarium::options_tab *parent_tab,
        unsigned __int8 option_item_id,
        survarium::option_item_type_enum type)
{
  Scaleform::MemoryHeap *v5; // ecx
  char v6; // bl
  survarium::flash_function_handler_impl *v8; // eax
  vostok::console_commands::console_command *v9; // eax
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v5 = Scaleform::Memory::pGlobalHeap;
  v6 = 0;
  this->__vftable = (survarium::options_item_base_vtbl *)&survarium::flash_function_handler::`vftable';
  v8 = (survarium::flash_function_handler_impl *)v5->Alloc(v5, 12u, 0);
  if ( v8 )
  {
    v8->__vftable = (survarium::flash_function_handler_impl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->__vftable = (survarium::flash_function_handler_impl_vtbl *)&survarium::flash_function_handler_impl::`vftable';
    v8->owner = this;
  }
  else
  {
    v8 = 0;
  }
  this->impl = v8;
  this->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_base::`vftable';
  this->m_type = type;
  this->m_parent_tab = parent_tab;
  this->m_option_item_id = option_item_id;
  v9 = vostok::console_commands::find(console_command);
  this->m_console_command = v9;
  if ( !v9 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v10 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v10 )
      {
        log_callback.functor.obj_ptr = v10;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v6 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\options_items.cpp",
        0x6Fu,
        "__thiscall survarium::options_item_base::options_item_base(class survarium::options_tab &,const char *,unsigned "
        "char,enum survarium::option_item_type_enum)",
        "game:",
        error,
        "Console command [%s] not found for options_item [%d]",
        console_command,
        type);
    }
    if ( (v6 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}
