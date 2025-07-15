const survarium::quest_descriptor *__thiscall survarium::items_dictionary::get_quest_descriptor(
        survarium::items_dictionary *this,
        survarium::items_dictionary_vtbl *quest_dict_id)
{
  unsigned int m_quests_count; // edx
  unsigned int v3; // eax
  survarium::items_dictionary *v4; // esi
  bool has_passed_filters; // al
  survarium::items_dictionary *v7; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v8; // [esp+10h] [ebp-24h] BYREF

  m_quests_count = this->m_quests_count;
  v3 = 0;
  if ( m_quests_count )
  {
    this = (survarium::items_dictionary *)this->m_quests;
    v4 = this;
    while ( v4->__vftable != quest_dict_id )
    {
      ++v3;
      v4 = (survarium::items_dictionary *)((char *)v4 + 176);
      if ( v3 >= m_quests_count )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game_core",
                                 (const char *)2),
          this = v7,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v8);
      vostok::logging::append(
        &v8,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\items_dictionary_cook.cpp",
        0xF6u,
        "const struct survarium::quest_descriptor &__thiscall survarium::items_dictionary::get_quest_descriptor(const uns"
        "igned int) const",
        "game_core",
        error,
        "quest %d not found in library",
        quest_dict_id);
    }
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v8);
  }
  return (const survarium::quest_descriptor *)((char *)this + 176 * v3);
}
