void __thiscall vostok::animation::single_animation_cook::translate_query(
        vostok::animation::single_animation_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  char *m_request_path; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::single_animation_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::single_animation_cook *>,boost::arg<1> > > v6; // [esp-10h] [ebp-268h]
  int v7; // [esp+0h] [ebp-258h]
  vostok::resources::request arr[2]; // [esp+8h] [ebp-250h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-240h] BYREF
  vostok::fixed_string<260> animation_path; // [esp+38h] [ebp-220h] BYREF
  vostok::fixed_string<260> options_path; // [esp+148h] [ebp-110h] BYREF
  char vars0; // [esp+258h] [ebp+0h] BYREF

  animation_path.m_begin = animation_path.m_buffer;
  m_requery_path = parent->m_requery_path;
  animation_path.m_end = animation_path.m_buffer;
  animation_path.m_max_end = (char *)&options_path;
  animation_path.m_buffer[0] = 0;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::buffer_string::assignf(&animation_path, "resources/animations/single/%s", m_requery_path);
  options_path.m_max_end = &vars0;
  m_request_path = parent->m_requery_path;
  options_path.m_begin = options_path.m_buffer;
  options_path.m_end = options_path.m_buffer;
  options_path.m_buffer[0] = 0;
  if ( !m_request_path )
    m_request_path = parent->m_request_path;
  vostok::buffer_string::assignf(&options_path, "resources/animations/single/%s%s", m_request_path, ".options");
  arr[1].path = options_path.m_begin;
  callback.vtable = (boost::detail::function::vtable_base *)vostok::animation::single_animation_cook::on_sub_resources_loaded;
  (&callback.vtable)[1] = 0;
  callback.functor.obj_ptr = this;
  v6.f_.f_ = (void (__thiscall *__ptr64)(vostok::animation::single_animation_cook *, vostok::resources::queries_result *))(unsigned int)vostok::animation::single_animation_cook::on_sub_resources_loaded;
  arr[0].path = animation_path.m_begin;
  arr[0].id = animation_class;
  arr[1].id = binary_config_class_impl;
  *(_QWORD *)&v6.l_.a1_.t_ = *(_QWORD *)&callback.functor.obj_ptr;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)parent,
    v6,
    v7);
  vostok::resources::query_resources(
    arr,
    2u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v5 )
      v5(&callback.functor, &callback.functor, 2);
  }
}
