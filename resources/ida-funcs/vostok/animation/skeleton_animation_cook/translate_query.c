void __thiscall vostok::animation::skeleton_animation_cook::translate_query(
        vostok::animation::skeleton_animation_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // ecx
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &),boost::_bi::list1<boost::arg<1> > > v4; // [esp-8h] [ebp-40h]
  boost::_bi::list1<boost::arg<1> > v5; // [esp+Bh] [ebp-2Dh] BYREF
  vostok::variant<32> *user_data; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-20h] BYREF

  boost::_bi::list1<boost::arg<1>>::list1<boost::arg<1>>(&v5, *(_BYTE *)&1_263);
  *(_DWORD *)&v4.l_.boost::_bi::storage1<boost::arg<1> > = requests.id;
  v4.f_ = vostok::animation::skeleton_animation_cook::on_bi_spline_animation_arrived;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::resources::queries_result &),boost::_bi::list1<boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::queries_result &> *)requests.id,
    v4);
  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  requests.path = m_requery_path;
  requests.id = bi_spline_skeleton_animation_class;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    &vostok::memory::g_resources_helper_allocator,
    (const vostok::variant<32> **)&user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v3 )
      v3(&callback.functor, &callback.functor, 2);
  }
}
