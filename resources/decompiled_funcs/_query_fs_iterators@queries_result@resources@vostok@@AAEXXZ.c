void __thiscall vostok::resources::queries_result::query_fs_iterators(
        vostok::resources::queries_result *this,
        vostok::resources::queries_result *thisa)
{
  vostok::resources::class_id_enum *p_m_class_id; // edi
  vostok::resources::class_id_enum v3; // eax
  const char *v4; // ecx
  vostok::resources::recursive_bool v5; // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned int m_size; // [esp+Ch] [ebp-154h]
  const char *request_path; // [esp+10h] [ebp-150h] BYREF
  __int64 v9; // [esp+14h] [ebp-14Ch]
  vostok::resources::class_id_enum *v10; // [esp+1Ch] [ebp-144h]
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &)> callback; // [esp+20h] [ebp-140h] BYREF
  __int64 v12; // [esp+40h] [ebp-120h]
  vostok::fs_new::virtual_path_string path; // [esp+4Ch] [ebp-114h] BYREF

  thisa->m_fs_iterator_requests_left = vostok::resources::queries_result::calculate_fs_iterator_requests_count(
                                         this,
                                         (int)thisa);
  if ( thisa->m_size )
  {
    p_m_class_id = &thisa->m_queries[0].m_class_id;
    m_size = thisa->m_size;
    do
    {
      v3 = *p_m_class_id;
      if ( *p_m_class_id == fs_iterator_class || v3 == fs_iterator_recursive_class )
      {
        v4 = (const char *)*((_DWORD *)p_m_class_id + 30);
        if ( !v4 )
          v4 = (const char *)*((_DWORD *)p_m_class_id + 29);
        request_path = v4;
        LODWORD(v12) = vostok::resources::queries_result::on_fs_iterator_ready;
        HIDWORD(v12) = thisa;
        v5 = v3 == fs_iterator_recursive_class;
        v9 = v12;
        v10 = p_m_class_id - 33;
        if ( survarium::generate_shaders_world::is_loading() )
        {
          callback.vtable = 0;
        }
        else
        {
          *(_QWORD *)&callback.functor.obj_ptr = v9;
          callback.functor.vostok_pointer_size_alignment[2] = v10;
          callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::queries_result,vostok::vfs::vfs_locked_iterator const &,vostok::resources::query_result *>,boost::_bi::list3<boost::_bi::value<vostok::resources::queries_result *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result *>>>>'::`2'::stored_vtable
                                                                   + 1);
        }
        vostok::fs_new::virtual_path_string::virtual_path_string(&path, &request_path);
        vostok::resources::query_vfs_iterator(
          &path,
          &callback,
          &vostok::memory::g_mt_allocator,
          v5,
          thisa->m_parent_query);
        if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
        {
          v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
          if ( v6 )
            v6(&callback.functor, &callback.functor, 2);
        }
      }
      p_m_class_id += 180;
      --m_size;
    }
    while ( m_size );
  }
}
