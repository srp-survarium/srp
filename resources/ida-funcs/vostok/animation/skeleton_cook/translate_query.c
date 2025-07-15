void __thiscall vostok::animation::skeleton_cook::translate_query(
        vostok::animation::skeleton_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::strings::detail::tuples *v4; // ecx
  vostok::strings::detail::tuples *v5; // ecx
  void *v6; // esp
  vostok::strings::detail::tuples *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  void (__thiscall *v10)(vostok::animation::skeleton_cook *, vostok::resources::queries_result *); // [esp+Ch] [ebp-44h]
  vostok::strings::detail::tuples::pair v11; // [esp+10h] [ebp-40h]
  const char *m_count; // [esp+18h] [ebp-38h]
  vostok::strings::detail::tuples v13; // [esp+1Ch] [ebp-34h] BYREF

  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::strings::detail::tuples::tuples(v4, &v13, requested_path, ".skeleton");
  v6 = alloca(vostok::strings::detail::tuples::size(v5, (unsigned int *)&v13));
  vostok::strings::detail::tuples::concat(v7, (int)&v13, v9);
  v13.m_strings[5].second = (unsigned int)this;
  v13.m_strings[4].second = (unsigned int)vostok::animation::skeleton_cook::on_sub_resources_loaded;
  v13.m_strings[5].first = 0;
  v10 = vostok::animation::skeleton_cook::on_sub_resources_loaded;
  v11.first = 0;
  v11.second = (unsigned int)this;
  m_count = (const char *)v13.m_count;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v13.m_strings[2].second = 0;
  }
  else
  {
    v13.m_strings[3].second = (unsigned int)v10;
    v13.m_strings[4] = v11;
    v13.m_strings[5].first = m_count;
    v13.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::resources::query_resource(
    v9,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v13.m_strings[2].second);
}
