void __thiscall survarium::profile_skin_visual_cook::translate_query(
        survarium::profile_skin_visual_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  _DWORD *v3; // ebx
  const char *path; // eax
  const char **v5; // eax
  char *m_begin; // ebx
  vostok::strings::detail::tuples *v7; // eax
  int i; // ecx
  vostok::strings::detail::tuples *v9; // ecx
  unsigned int v10; // eax
  void *v11; // esp
  vostok::strings::detail::tuples *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::vectora<vostok::resources::request> *v14; // ecx
  const vostok::resources::request *v15[3]; // [esp+0h] [ebp-88h] BYREF
  vostok::strings::detail::tuples v16; // [esp+Ch] [ebp-7Ch] BYREF
  const vostok::resources::request *v17; // [esp+40h] [ebp-48h] BYREF
  int v18; // [esp+44h] [ebp-44h]
  vostok::memory::doug_lea_allocator *v19; // [esp+48h] [ebp-40h]
  int v20; // [esp+4Ch] [ebp-3Ch]
  _DWORD v21[6]; // [esp+50h] [ebp-38h] BYREF
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v22; // [esp+68h] [ebp-20h] BYREF
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v23; // [esp+78h] [ebp-10h] BYREF

  m_user_data = parent->m_user_data;
  v3 = &this->__vftable;
  v22._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
  v23._M_impl._M_end_of_storage.m_allocator = 0;
  vostok::variant<32>::try_get<survarium::player_profile const *>(
    (vostok::variant<32> *)this,
    (int)m_user_data,
    (const survarium::player_profile **)&v23._M_impl._M_end_of_storage);
  v22._M_impl._M_end_of_storage._M_data = *(vostok::resources::request **)(v3[8] + 13908);
  v19 = survarium::g_allocator;
  v23._M_impl._M_start = (vostok::resources::request *)"resources/gameplay/bodyparts/default";
  v23._M_impl._M_finish = (vostok::resources::request *)32;
  v17 = 0;
  v18 = 0;
  v20 = 0;
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(&v23, v15[0]);
  v23._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)body_parts;
  v23._M_impl._M_finish = (vostok::resources::request *)7;
  do
  {
    path = v23._M_impl._M_end_of_storage._M_data->path;
    v21[5] = v23._M_impl._M_end_of_storage._M_data->id;
    v5 = &v23._M_impl._M_end_of_storage.m_allocator[3].m_arena_id + 4 * (_DWORD)path;
    if ( v5[2] )
    {
      m_begin = survarium::items_dictionary::item_by_id(
                  (survarium::items_dictionary *)v22._M_impl._M_end_of_storage._M_data,
                  (survarium::items_dictionary_vtbl *)*((unsigned __int16 *)v5 + 6))->item_cfg_name.m_begin;
      v7 = &v16;
      for ( i = 5; i >= 0; --i )
      {
        v7->m_strings[0].first = 0;
        v7->m_strings[0].second = 0;
        v7 = (vostok::strings::detail::tuples *)((char *)v7 + 8);
      }
      v16.m_count = 2;
      vostok::strings::detail::tuples::helper<0>::add_string<char const *>(&v16, "resources/");
      if ( m_begin )
        v10 = strlen(m_begin);
      else
        v10 = 0;
      v16.m_strings[1].second = v10;
      v16.m_strings[1].first = m_begin;
      v11 = alloca(vostok::strings::detail::tuples::size(v9, (unsigned int *)&v16));
      vostok::strings::detail::tuples::concat(v12, (int)&v16, (char *)v15);
      v22._M_impl._M_finish = (vostok::resources::request *)32;
      v22._M_impl._M_start = (vostok::resources::request *)v15;
      stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(&v22, v15[0]);
      v3 = &v22._M_impl._M_end_of_storage.m_allocator->__vftable;
    }
    ++v23._M_impl._M_end_of_storage._M_data;
    --v23._M_impl._M_finish;
  }
  while ( v23._M_impl._M_finish );
  v16.m_strings[4].first = 0;
  v16.m_strings[3].second = (unsigned int)survarium::profile_skin_visual_cook::on_configs_loaded;
  v16.m_strings[4].second = (unsigned int)v3;
  v16.m_strings[5].first = (const char *)parent;
  v16.m_strings[5].second = (unsigned int)v23._M_impl._M_end_of_storage.m_allocator;
  qmemcpy(v21, &v16.m_strings[3].second, sizeof(v21));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v16.m_strings[2].second = 0;
  }
  else
  {
    qmemcpy(&v16.m_strings[3].second, v21, 0x18u);
    v16.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,survarium::player_profile const *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<survarium::player_profile const *>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::resources::query_resources(
    v17,
    (v18 - (int)v17) >> 3,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)&v16.m_strings[2].second);
  vostok::vectora<vostok::resources::request>::~vectora<vostok::resources::request>(v14, (int)&v17);
}
