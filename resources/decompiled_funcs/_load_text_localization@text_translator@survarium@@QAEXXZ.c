void __thiscall survarium::text_translator::load_text_localization(
        survarium::text_translator *this,
        boost::function1<void,vostok::resources::queries_result &> *a2)
{
  vostok::strings::detail::tuples *v2; // ecx
  void *v3; // esp
  vostok::strings::detail::tuples *v4; // ecx
  void (__cdecl *v5)(vostok::strings::detail::tuples::pair *, vostok::strings::detail::tuples::pair *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::text_translator,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::text_translator *>,boost::arg<1> > > v6; // [esp-8h] [ebp-54h]
  char v7[8]; // [esp+0h] [ebp-4Ch] BYREF
  vostok::strings::detail::tuples v8; // [esp+8h] [ebp-44h] BYREF
  vostok::resources::request requests; // [esp+40h] [ebp-Ch] BYREF

  vostok::strings::detail::tuples::tuples((vostok::strings::detail::tuples *)this, (int)&v8);
  v3 = alloca(vostok::strings::detail::tuples::size(v2, (unsigned int *)&v8));
  vostok::strings::detail::tuples::size(v4, (unsigned int *)&v8);
  vostok::strings::detail::tuples::concat(v7, &v8);
  v6.l_.a1_.t_ = (survarium::text_translator *)a2;
  requests.path = v7;
  v6.f_.f_ = (void (__thiscall *)(survarium::text_translator *, vostok::resources::queries_result *))survarium::text_translator::on_texts_ready;
  requests.id = binary_config_class_impl;
  v8.m_strings[2].first = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::text_translator,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::text_translator *>,boost::arg<1>>>>(
    a2,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::text_translator,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::text_translator *>,boost::arg<1> > > *)&v8.m_strings[2],
    v6);
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&v8.m_strings[2],
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    0,
    assert_on_fail_true);
  if ( v8.m_strings[2].first && ((int)v8.m_strings[2].first & 1) == 0 )
  {
    v5 = *(void (__cdecl **)(vostok::strings::detail::tuples::pair *, vostok::strings::detail::tuples::pair *, int))((int)v8.m_strings[2].first & 0xFFFFFFFE);
    if ( v5 )
      v5(&v8.m_strings[3], &v8.m_strings[3], 2);
  }
}
