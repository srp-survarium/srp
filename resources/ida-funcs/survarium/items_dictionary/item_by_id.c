survarium::dictionary_item *__thiscall survarium::items_dictionary::item_by_id(
        survarium::items_dictionary *this,
        survarium::items_dictionary_vtbl *item_dictionary_id)
{
  unsigned int m_items_count; // edx
  unsigned int v3; // eax
  survarium::items_dictionary *v4; // esi
  bool has_passed_filters; // al
  survarium::items_dictionary *v7; // [esp-4h] [ebp-34h]
  char v8; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+10h] [ebp-20h] BYREF

  m_items_count = this->m_items_count;
  v3 = 0;
  v8 = 0;
  if ( m_items_count )
  {
    this = (survarium::items_dictionary *)this->m_items_dict;
    v4 = this;
    while ( v4->__vftable != item_dictionary_id )
    {
      ++v3;
      v4 = (survarium::items_dictionary *)((char *)v4 + 380);
      if ( v3 >= m_items_count )
        goto LABEL_5;
    }
    return (survarium::dictionary_item *)((char *)this + 380 * v3);
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          this = v7,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v9);
      v8 = 1;
      vostok::logging::append(
        &v9,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "c:\\survarium.deploy\\sources\\vostok/game_core/items_dictionary_cook.h",
        0x39u,
        "struct survarium::dictionary_item *__thiscall survarium::items_dictionary::item_by_id(unsigned int) const",
        "game",
        error,
        "There is no item with id[%d]",
        item_dictionary_id);
    }
    if ( (v8 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v9);
    return 0;
  }
}
