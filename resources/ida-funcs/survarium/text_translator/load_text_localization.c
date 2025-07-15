void __thiscall survarium::text_translator::load_text_localization(survarium::text_translator *this, unsigned int a2)
{
  vostok::strings::detail::tuples *v2; // ecx
  void *v3; // esp
  vostok::strings::detail::tuples *v4; // ecx
  vostok::particle::particle_action *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  const char *v7[2]; // [esp+0h] [ebp-54h] BYREF
  vostok::strings::detail::tuples v8; // [esp+8h] [ebp-4Ch] BYREF
  vostok::resources::request v9; // [esp+40h] [ebp-14h] BYREF
  vostok::strings::detail::tuples::pair v10; // [esp+48h] [ebp-Ch]

  vostok::strings::detail::tuples::tuples(
    (vostok::strings::detail::tuples *)this,
    &v8,
    g_localization_name.m_begin,
    "/localization",
    v7[0]);
  v3 = alloca(vostok::strings::detail::tuples::size(v2, (unsigned int *)&v8));
  vostok::strings::detail::tuples::concat(v4, (int)&v8, (char *)v7);
  v10.first = (const char *)survarium::text_translator::on_texts_ready;
  v10.second = a2;
  v9.path = (const char *)v7;
  v9.id = binary_config_class_impl;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v5) )
  {
    v8.m_strings[2].first = 0;
  }
  else
  {
    v8.m_strings[3] = v10;
    v8.m_strings[2].first = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::text_translator,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::text_translator *>,boost::arg<1>>>>'::`2'::stored_vtable
                          + 1;
  }
  vostok::resources::query_resources(&v9, 1u, survarium::g_allocator, 0, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v8.m_strings[2]);
}
