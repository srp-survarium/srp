void __userpurge vostok::collision::collision_cook::query_triangle_mesh(
        survarium::animated_model_instance_cook *parent_query@<edi>,
        vostok::collision::collision_cook *this)
{
  unsigned __int8 *m_buffer; // ecx
  vostok::fs_new::virtual_path_string *m_next; // edx
  char *m_end; // eax
  int v5; // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v7; // [esp-8h] [ebp-280h]
  vostok::resources::request requests[2]; // [esp+8h] [ebp-270h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-260h] BYREF
  void (__thiscall *v10)(vostok::collision::collision_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *); // [esp+3Ch] [ebp-23Ch]
  vostok::collision::collision_cook *v11; // [esp+40h] [ebp-238h]
  vostok::fs_new::virtual_path_string vertices_path; // [esp+48h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string indices_path; // [esp+160h] [ebp-118h] BYREF

  m_buffer = (unsigned __int8 *)vertices_path.m_string.m_buffer;
  vertices_path.m_string.m_max_end = &vertices_path.m_separator;
  m_next = (vostok::fs_new::virtual_path_string *)parent_query[7].m_next;
  m_end = vertices_path.m_string.m_buffer;
  vertices_path.m_string.m_begin = vertices_path.m_string.m_buffer;
  vertices_path.m_string.m_end = vertices_path.m_string.m_buffer;
  vertices_path.m_string.m_buffer[0] = 0;
  vertices_path.m_separator = 47;
  if ( !m_next )
    m_next = (vostok::fs_new::virtual_path_string *)parent_query[7].m_flags.m_flags;
  if ( vertices_path.m_string.m_buffer != (char *)m_next )
  {
    m_end = vertices_path.m_string.m_buffer;
    vertices_path.m_string.m_end = vertices_path.m_string.m_buffer;
    vertices_path.m_string.m_buffer[0] = 0;
    if ( m_next )
    {
      for ( ; LOBYTE(m_next->m_string.m_begin); ++vertices_path.m_string.m_end )
      {
        if ( m_end >= vertices_path.m_string.m_max_end )
          break;
        *m_end = (char)m_next->m_string.m_begin;
        m_end = vertices_path.m_string.m_end + 1;
        m_next = (vostok::fs_new::virtual_path_string *)((char *)m_next + 1);
      }
      *m_end = 0;
      m_end = vertices_path.m_string.m_end;
      m_buffer = (unsigned __int8 *)vertices_path.m_string.m_begin;
    }
  }
  v5 = m_end - (char *)m_buffer;
  indices_path.m_string.m_begin = indices_path.m_string.m_buffer;
  indices_path.m_string.m_end = indices_path.m_string.m_buffer;
  indices_path.m_string.m_max_end = &indices_path.m_separator;
  memcpy((unsigned __int8 *)indices_path.m_string.m_buffer, m_buffer, m_end - (char *)m_buffer);
  indices_path.m_string.m_end += v5;
  *indices_path.m_string.m_end = 0;
  indices_path.m_separator = 47;
  *(_QWORD *)vertices_path.m_string.m_end = *(_QWORD *)aVertice;
  vertices_path.m_string.m_end[8] = 115;
  vertices_path.m_string.m_end += 9;
  *vertices_path.m_string.m_end = 0;
  *(_QWORD *)indices_path.m_string.m_end = *(_QWORD *)"/indices";
  indices_path.m_string.m_end += 8;
  *indices_path.m_string.m_end = 0;
  requests[0].path = vertices_path.m_string.m_begin;
  requests[0].id = raw_data_class;
  requests[1].id = raw_data_class;
  requests[1].path = indices_path.m_string.m_begin;
  v11 = this;
  v10 = vostok::collision::collision_cook::on_triangle_mesh_collision_loaded;
  v7.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))this;
  callback.vtable = 0;
  v7.l_.a1_.t_ = parent_query;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::collision::collision_cook::on_triangle_mesh_collision_loaded,
         v7) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::collision::collision_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::collision::collision_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resources(
    requests,
    2u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (vostok::resources::query_result_for_cook *)parent_query,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&callback.functor, &callback.functor, 2);
  }
}
