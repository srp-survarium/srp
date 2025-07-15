void __thiscall vostok::animation::bi_spline_skeleton_animation_impl_cook::translate_query(
        vostok::animation::bi_spline_skeleton_animation_impl_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // ebx
  vostok::strings::detail::tuples *v3; // ecx
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  vostok::strings::detail::tuples *v7; // ecx
  vostok::strings::detail::tuples *v8; // ecx
  void *v9; // esp
  vostok::strings::detail::tuples *v10; // ecx
  vostok::particle::particle_action *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  char v13[12]; // [esp+0h] [ebp-58h] BYREF
  vostok::strings::detail::tuples v14; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::resources::request v15; // [esp+40h] [ebp-18h] BYREF
  char *v16; // [esp+48h] [ebp-10h]
  int v17; // [esp+4Ch] [ebp-Ch]
  void (__cdecl *v18)(vostok::resources::queries_result *, vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *); // [esp+50h] [ebp-8h]
  const char *v19; // [esp+54h] [ebp-4h]

  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::strings::detail::tuples::tuples(v3, &v14, requested_path, ".b-spline");
  v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&v14));
  vostok::strings::detail::tuples::concat(v6, (int)&v14, v13);
  vostok::strings::detail::tuples::tuples(v7, &v14, requested_path, ".bones_names");
  v9 = alloca(vostok::strings::detail::tuples::size(v8, (unsigned int *)&v14));
  vostok::strings::detail::tuples::concat(v10, (int)&v14, v13);
  v18 = vostok::animation::bi_spline_skeleton_animation_impl_cook::on_resources_ready;
  v15.path = v13;
  v15.id = bi_spline_skeleton_animation_baked_class;
  v16 = v13;
  v17 = 32;
  v19 = (const char *)parent;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v11) )
  {
    v14.m_strings[2].second = 0;
  }
  else
  {
    v14.m_strings[3].second = (unsigned int)v18;
    v14.m_strings[4].first = v19;
    v14.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::resources::queries_result &,vostok::resources::query_result_for_cook *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::resources::query_resources(
    &v15,
    2u,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v14.m_strings[2].second);
}
