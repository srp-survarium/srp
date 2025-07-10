void __thiscall vostok::render::static_render_model_instance_cook::translate_query(
        vostok::render::static_render_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  boost::function1<void,vostok::resources::queries_result &> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::static_render_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::static_render_model_instance_cook *>,boost::arg<1> > > v6; // [esp-8h] [ebp-158h]
  char *other; // [esp+Ch] [ebp-144h] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-140h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string render_path; // [esp+38h] [ebp-118h] BYREF

  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&render_path, (const char **)&other);
  v6.l_.a1_.t_ = this;
  v6.f_.f_ = vostok::render::static_render_model_instance_cook::on_sub_resources_loaded;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::static_render_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::static_render_model_instance_cook *>,boost::arg<1>>>>(
    v4,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::static_render_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::static_render_model_instance_cook *>,boost::arg<1> > > *)&callback,
    v6);
  requests.path = render_path.m_string.m_begin;
  requests.id = static_render_model_class;
  other = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)&other,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v5 )
      v5(&callback.functor, &callback.functor, 2);
  }
}
