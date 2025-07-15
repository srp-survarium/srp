void __userpurge survarium::options_item_base::options_item_base(
        survarium::options_item_base *this@<ecx>,
        int a2@<edi>,
        survarium::options_tab *parent_tab,
        char *console_command,
        unsigned __int8 option_item_id,
        survarium::option_item_type_enum type)
{
  vostok::console_commands::console_command *v6; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+8h] [ebp-28h] BYREF
  int v12; // [esp+2Ch] [ebp-4h]

  v12 = 0;
  survarium::flash_function_handler::flash_function_handler(this, (_DWORD *)a2);
  *(_DWORD *)(a2 + 12) = type;
  *(_DWORD *)(a2 + 16) = parent_tab;
  *(_DWORD *)a2 = &survarium::options_item_base::`vftable';
  *(_BYTE *)(a2 + 20) = option_item_id;
  v6 = vostok::console_commands::find(console_command);
  v7 = v9;
  *(_DWORD *)(a2 + 8) = v6;
  if ( !v6 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)3),
          v7 = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &v11);
      v12 = 1;
      vostok::logging::append(
        &v11,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\options_items.cpp",
        0x34u,
        "__thiscall survarium::options_item_base::options_item_base(class survarium::options_tab &,const char *,unsigned "
        "char,enum survarium::option_item_type_enum)",
        "game",
        warning,
        "Console command [%s] not found for options_item [%d]",
        console_command,
        type);
    }
    if ( (v12 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v11);
  }
}
