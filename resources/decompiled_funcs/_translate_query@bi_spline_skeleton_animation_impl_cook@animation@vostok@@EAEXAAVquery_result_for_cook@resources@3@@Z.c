void __thiscall vostok::animation::bi_spline_skeleton_animation_impl_cook::translate_query(
        vostok::animation::bi_spline_skeleton_animation_impl_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // edi
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  vostok::strings::detail::tuples *v6; // ecx
  void *v7; // esp
  vostok::strings::detail::tuples *v8; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v9; // ecx
  void (__cdecl *v10)(unsigned int *, unsigned int *, int); // eax
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::query_result_for_cook *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v11; // [esp-8h] [ebp-58h]
  int v12[3]; // [esp+0h] [ebp-50h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-44h] BYREF
  vostok::resources::request requests[2]; // [esp+40h] [ebp-10h] BYREF

  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, m_requery_path, ".b-spline");
  v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v5, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)v12, &STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, m_requery_path, ".bones_names");
  v7 = alloca(vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v8, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)v12, &STR_JOINA_tuples_unique_identifier);
  requests[1].path = (const char *)v12;
  v11.l_.a2_.t_ = parent;
  v11.f_ = (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::query_result_for_cook *))vostok::animation::bi_spline_skeleton_animation_impl_cook::on_resources_ready;
  requests[0].path = (const char *)v12;
  requests[0].id = bi_spline_skeleton_animation_baked_class;
  requests[1].id = binary_config_class_impl;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v9,
    v11,
    v12[0]);
  vostok::resources::query_resources(
    requests,
    2u,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&STR_JOINA_tuples_unique_identifier.m_strings[2].second,
    &vostok::memory::g_resources_helper_allocator,
    0,
    parent,
    assert_on_fail_true);
  if ( STR_JOINA_tuples_unique_identifier.m_strings[2].second
    && (STR_JOINA_tuples_unique_identifier.m_strings[2].second & 1) == 0 )
  {
    v10 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))(STR_JOINA_tuples_unique_identifier.m_strings[2].second
                                                                  & 0xFFFFFFFE);
    if ( v10 )
      v10(
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        2);
  }
}
