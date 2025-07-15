void __thiscall survarium::scaleform_movie_cook::translate_query(
        survarium::scaleform_movie_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::scaleform_movie_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::scaleform_movie_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v4; // [esp-10h] [ebp-50h]
  int v5; // [esp+0h] [ebp-40h]
  vostok::variant<32> *user_data; // [esp+Ch] [ebp-34h] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-30h] BYREF
  unsigned __int64 v8; // [esp+18h] [ebp-28h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-20h] BYREF

  requests.path = (const char *)survarium::scaleform_movie_cook::on_raw_data_loaded;
  requests.id = unknown_data_class;
  v4.f_.f_ = (void (__thiscall *__ptr64)(survarium::scaleform_movie_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *))(unsigned int)survarium::scaleform_movie_cook::on_raw_data_loaded;
  v8 = __PAIR64__((unsigned int)parent, (unsigned int)this);
  v4.l_ = (boost::_bi::list3<boost::_bi::value<survarium::scaleform_movie_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> >)__PAIR64__((unsigned int)parent, (unsigned int)this);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)this,
    (int)&callback,
    (int)parent,
    v4,
    v5);
  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  requests.path = m_requery_path;
  requests.id = raw_data_class;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
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
