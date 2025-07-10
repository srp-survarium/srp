void __thiscall vostok::physics::animated_model_instance_cook::translate_query(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // ecx
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::memory::base_allocator *m_allocator; // [esp-10h] [ebp-48h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > v6; // [esp-8h] [ebp-40h]
  vostok::variant<32> *user_data; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-20h] BYREF

  v6.l_.a1_.t_ = this;
  v6.f_.f_ = vostok::physics::animated_model_instance_cook::on_config_loaded;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::queries_result &> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
    v6);
  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  requests.path = m_requery_path;
  m_allocator = this->m_allocator;
  requests.id = binary_config_class_impl;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    m_allocator,
    (const vostok::variant<32> **)&user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v4 )
      v4(&callback.functor, &callback.functor, 2);
  }
}
