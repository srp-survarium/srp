void __thiscall vostok::ui::ui_text_edit::cut_to_clipboard(vostok::ui::ui_text_edit *this)
{
  bool has_passed_filters; // al
  vostok::ui::ui_text_edit *v2; // [esp-4h] [ebp-34h]
  char v3; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v4; // [esp+10h] [ebp-20h] BYREF

  v3 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"ui", (const char *)3),
        this = v2,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v4);
    v3 = 1;
    vostok::logging::append(
      &v4,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\ui_text_edit.cpp",
      0x112u,
      "void __thiscall vostok::ui::ui_text_edit::cut_to_clipboard(void)",
      "ui",
      warning,
      "ui_text_edit::cut_to_clipboard not implemented");
  }
  if ( (v3 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v4);
}
