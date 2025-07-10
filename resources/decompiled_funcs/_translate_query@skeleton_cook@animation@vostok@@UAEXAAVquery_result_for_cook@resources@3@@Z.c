void __thiscall vostok::animation::skeleton_cook::translate_query(
        vostok::animation::skeleton_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // edi
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > v7; // [esp-10h] [ebp-84h] BYREF
  int v8[3]; // [esp+0h] [ebp-74h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-68h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+40h] [ebp-34h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > v11; // [esp+60h] [ebp-14h] BYREF
  vostok::animation::skeleton_cook *v12; // [esp+70h] [ebp-4h]

  m_requery_path = parent->m_requery_path;
  v12 = this;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, m_requery_path, ".skeleton");
  v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v5, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)v8, &STR_JOINA_tuples_unique_identifier);
  *((_DWORD *)&v7.l_ + 1) = (unsigned __int8)1_265;
  v7.l_.a1_.t_ = v12;
  HIDWORD(v7.f_.f_) = 0;
  v7 = *boost::bind<void,survarium::empty_hands_cook,vostok::resources::queries_result &,survarium::empty_hands_cook *,boost::arg<1>>(
          &v11,
          (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > *)vostok::animation::skeleton_cook::on_sub_resources_loaded,
          *(void (__thiscall *__ptr64 *)(vostok::animation::skeleton_cook *, vostok::resources::queries_result *))((char *)&v7.f_.f_ + 4));
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)&v7,
    (int)&callback,
    (int)v8,
    v7,
    v8[0]);
  vostok::resources::query_resource(
    (const char *)v8,
    binary_config_class_impl,
    &callback,
    &vostok::memory::g_resources_helper_allocator,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&callback.functor, &callback.functor, 2);
  }
}
