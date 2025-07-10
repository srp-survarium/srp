void __thiscall survarium::profile_skin_visual_cook::translate_query(
        survarium::profile_skin_visual_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::request *M_finish; // ebx
  survarium::slot_def *v5; // ecx
  survarium::profile_slot *v6; // eax
  unsigned int dict_id; // esi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *p_m_items_dict; // ecx
  vostok::strings::detail::tuples *v10; // ecx
  void *v11; // esp
  vostok::strings::detail::tuples *v12; // ecx
  bool v13; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,survarium::player_profile const *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<survarium::player_profile const *> > > *v14; // eax
  void (__thiscall *__ptr64 f)(survarium::profile_skin_visual_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, const survarium::player_profile *); // xmm0_8
  __int64 v16; // xmm2_8
  vostok::resources::request *M_start; // esi
  void (__cdecl *v18)(unsigned int *, unsigned int *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,survarium::game_object_ &,survarium::simple_game_project *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<survarium::simple_game_project *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v19; // [esp-14h] [ebp-A4h] BYREF
  unsigned int v20; // [esp+4h] [ebp-8Ch]
  bool v21; // [esp+8h] [ebp-88h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,survarium::player_profile const *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<survarium::player_profile const *> > > v22; // [esp+Ch] [ebp-84h] BYREF
  survarium::slot_def current; // [esp+24h] [ebp-6Ch]
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+2Ch] [ebp-64h] BYREF
  vostok::collision::ray_object_result v25; // [esp+60h] [ebp-30h] BYREF
  survarium::items_dictionary *items_dictionary; // [esp+68h] [ebp-28h]
  survarium::profile_skin_visual_cook *a1; // [esp+6Ch] [ebp-24h]
  vostok::vectora<vostok::resources::request> requests; // [esp+70h] [ebp-20h] BYREF
  vostok::collision::ray_object_result __x; // [esp+80h] [ebp-10h] BYREF
  survarium::slot_def *v30; // [esp+88h] [ebp-8h]
  const survarium::player_profile *profile; // [esp+8Ch] [ebp-4h] BYREF

  m_user_data = parent->m_user_data;
  a1 = this;
  profile = 0;
  vostok::variant<32>::try_get<survarium::player_profile const *>(
    (vostok::variant<32> *)parent,
    (int)m_user_data,
    &profile);
  items_dictionary = this->m_game->m_items_dictionary.m_object;
  requests._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  requests._M_impl._M_start = 0;
  requests._M_impl._M_finish = 0;
  requests._M_impl._M_end_of_storage._M_data = 0;
  __x.object = (const vostok::collision::object *)"resources/gameplay/bodyparts/default";
  LODWORD(__x.distance) = 34;
  stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
    (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)0x22,
    (unsigned __int8 **)&requests,
    0,
    &__x,
    *((const stlp_std::__true_type **)&v19.l_ + 3),
    v20,
    v21);
  M_finish = requests._M_impl._M_finish;
  v5 = body_parts;
  v30 = body_parts;
  LODWORD(__x.distance) = 7;
  do
  {
    v6 = &profile->slots[v5->slot];
    current.table_name = v5->table_name;
    if ( v6->item.id )
    {
      dict_id = v6->item.dict_id;
      M_parent = items_dictionary->m_items_dict._M_t._M_header._M_data._M_parent;
      p_m_items_dict = &items_dictionary->m_items_dict;
      if ( M_parent )
      {
        do
        {
          if ( *(_DWORD *)&M_parent[1]._M_color < dict_id )
          {
            M_parent = M_parent->_M_right;
          }
          else
          {
            p_m_items_dict = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)M_parent;
            M_parent = M_parent->_M_left;
          }
        }
        while ( M_parent );
        if ( p_m_items_dict != &items_dictionary->m_items_dict && dict_id < p_m_items_dict->_M_t._M_node_count )
          p_m_items_dict = &items_dictionary->m_items_dict;
      }
      vostok::strings::detail::tuples::tuples(
        &STR_JOINA_tuples_unique_identifier,
        "resources/",
        (const char *)&p_m_items_dict[1]._M_t._M_header._M_data._M_parent->_M_color);
      v11 = alloca(vostok::strings::detail::tuples::size(v10, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      vostok::strings::detail::tuples::size(v12, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      vostok::strings::detail::tuples::concat((char *)&v19.l_ + 12, &STR_JOINA_tuples_unique_identifier);
      v25.object = (const vostok::collision::object *)(&v19.l_ + 1);
      LODWORD(v25.distance) = 34;
      if ( M_finish == requests._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)&v25,
          (unsigned __int8 **)&requests,
          (int)M_finish,
          &v25,
          *((const stlp_std::__true_type **)&v19.l_ + 3),
          v20,
          v21);
        M_finish = requests._M_impl._M_finish;
      }
      else
      {
        M_finish->path = (const char *)(&v19.l_ + 1);
        M_finish->id = binary_config_class_impl;
        requests._M_impl._M_finish = ++M_finish;
      }
    }
    v5 = v30 + 1;
    v13 = LODWORD(__x.distance)-- == 1;
    ++v30;
  }
  while ( !v13 );
  v14 = boost::bind<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,survarium::player_profile const *,survarium::profile_skin_visual_cook *,boost::arg<1>,vostok::resources::query_result_for_cook *,survarium::player_profile const *>(
          a1,
          &v22,
          (void (__thiscall *__ptr64)(survarium::profile_skin_visual_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, const survarium::player_profile *))(unsigned int)survarium::profile_skin_visual_cook::on_configs_loaded,
          1_82,
          parent,
          profile);
  f = v14->f_.f_;
  v16 = *(_QWORD *)&v14->l_.a4_.t_;
  LODWORD(v19.f_.f_) = HIDWORD(v14->f_.f_);
  *(void (__thiscall *__ptr64 *)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))((char *)&v19.f_.f_ + 4) = (void (__thiscall *__ptr64)(survarium::project_cooker_simple *, survarium::game_object_ *, survarium::simple_game_project *, vostok::resources::query_result_for_cook *))v14->l_.boost::_bi::storage3<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> >;
  STR_JOINA_tuples_unique_identifier.m_strings[2].second = 0;
  *(_QWORD *)&v19.l_.a3_.t_ = v16;
  if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>(
         (boost::detail::function::function_buffer *)&STR_JOINA_tuples_unique_identifier.m_strings[3].second,
         (boost::detail::function::basic_vtable1<void,survarium::game_object_ &> *)f,
         v19) )
  {
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,survarium::player_profile const *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<survarium::player_profile const *>>>>'::`2'::stored_vtable
                                                           + 1;
  }
  else
  {
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = 0;
  }
  M_start = requests._M_impl._M_start;
  vostok::resources::query_resources(
    requests._M_impl._M_start,
    M_finish - requests._M_impl._M_start,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&STR_JOINA_tuples_unique_identifier.m_strings[2].second,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    parent,
    assert_on_fail_true);
  if ( STR_JOINA_tuples_unique_identifier.m_strings[2].second )
  {
    if ( (STR_JOINA_tuples_unique_identifier.m_strings[2].second & 1) == 0 )
    {
      v18 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))(STR_JOINA_tuples_unique_identifier.m_strings[2].second
                                                                    & 0xFFFFFFFE);
      if ( v18 )
        v18(
          &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
          &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
          2);
    }
  }
  if ( M_start )
    requests._M_impl._M_end_of_storage.m_allocator->call_free(
      requests._M_impl._M_end_of_storage.m_allocator,
      (void *)M_start);
}
