void __userpurge vostok::render::texture_cook_wrapper::query_converted_texture(
        vostok::resources::query_result_for_cook *parent@<edi>,
        vostok::render::texture_cook_wrapper *this)
{
  char *m_requery_path; // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_cook_wrapper,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_cook_wrapper *>,boost::arg<1> > > v4; // [esp-8h] [ebp-150h]
  char *other; // [esp+4h] [ebp-144h] BYREF
  vostok::resources::request requests; // [esp+8h] [ebp-140h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string converted_texture_path; // [esp+30h] [ebp-118h] BYREF

  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&converted_texture_path, (const char **)&other);
  vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>(&converted_texture_path);
  v4.l_.a1_.t_ = this;
  v4.f_.f_ = vostok::render::texture_cook_wrapper::on_texture_loaded;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_cook_wrapper,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_cook_wrapper *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::queries_result &> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_cook_wrapper,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_cook_wrapper *>,boost::arg<1> > > *)&callback,
    v4);
  requests.path = converted_texture_path.m_string.m_begin;
  requests.id = texture_class;
  other = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_mt_allocator,
    (const vostok::variant<32> **)&other,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v3 )
      v3(&callback.functor, &callback.functor, 2);
  }
}
