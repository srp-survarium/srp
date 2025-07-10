void __thiscall vostok::render::scene::remove_unused_environment_cubemaps(
        vostok::render::scene *this,
        vostok::render::scene *thisa)
{
  void **M_start; // eax
  void *v3; // eax
  int v4; // ecx
  unsigned __int8 *v5; // eax
  int v6; // esi
  char *v7; // eax
  int v8; // eax
  int v9; // esi
  unsigned __int8 *v10; // edi
  char *m_begin; // ecx
  char *m_buffer; // eax
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::scene,char *,vostok::vfs::vfs_locked_iterator const &>,boost::_bi::list3<boost::_bi::value<vostok::render::scene *>,boost::_bi::value<char *>,boost::arg<1> > > v14; // [esp-10h] [ebp-378h]
  int v15; // [esp+0h] [ebp-368h]
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &)> callback; // [esp+10h] [ebp-358h] BYREF
  vostok::fixed_string<260> path; // [esp+30h] [ebp-338h] BYREF
  char v18; // [esp+140h] [ebp-228h] BYREF
  vostok::fs_new::virtual_path_string v19; // [esp+144h] [ebp-224h] BYREF
  vostok::fixed_string<260> query_path; // [esp+258h] [ebp-110h] BYREF
  char vars0; // [esp+368h] [ebp+0h] BYREF

  M_start = thisa->m_environment_probes._M_impl._M_start;
  if ( M_start == thisa->m_environment_probes._M_impl._M_finish )
    return;
  v3 = *M_start;
  v4 = *((_DWORD *)v3 + 2);
  v5 = (unsigned __int8 *)*((_DWORD *)v3 + 1);
  v6 = v4 - (_DWORD)v5;
  path.m_begin = path.m_buffer;
  path.m_max_end = &v18;
  memcpy((unsigned __int8 *)path.m_buffer, v5, v4 - (_DWORD)v5);
  path.m_end = &path.m_buffer[v6];
  *path.m_end = 0;
  v7 = path.m_end - 1;
  if ( path.m_end - 1 < path.m_begin )
    goto LABEL_7;
  if ( *v7 != 47 )
  {
    while ( v7 != path.m_begin )
    {
      if ( *--v7 == 47 )
        goto LABEL_6;
    }
LABEL_7:
    v8 = -1;
    goto LABEL_8;
  }
LABEL_6:
  v8 = v7 - path.m_begin;
LABEL_8:
  path.m_end = &path.m_begin[v8];
  *path.m_end = 0;
  v9 = path.m_end - path.m_begin + 1;
  v10 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                             v9);
  memset((int)v10, 0, v9);
  memcpy(v10, (unsigned __int8 *)path.m_begin, v9);
  query_path.m_begin = query_path.m_buffer;
  query_path.m_end = query_path.m_buffer;
  query_path.m_max_end = &vars0;
  query_path.m_buffer[0] = 0;
  vostok::buffer_string::assignf(&query_path, "resources.sources/textures/%s", (const char *)v10);
  callback.vtable = (boost::detail::function::vtable_base *)vostok::render::scene::on_fs_iterator_probes_ready;
  (&callback.vtable)[1] = 0;
  v14.f_.f_ = (void (__thiscall *__ptr64)(vostok::render::scene *, char *, const vostok::vfs::vfs_locked_iterator *))(unsigned int)vostok::render::scene::on_fs_iterator_probes_ready;
  *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__((unsigned int)v10, (unsigned int)thisa);
  v14.l_ = (boost::_bi::list3<boost::_bi::value<vostok::render::scene *>,boost::_bi::value<char *>,boost::arg<1> >)__PAIR64__((unsigned int)v10, (unsigned int)thisa);
  boost::function1<void,vostok::vfs::vfs_locked_iterator const &>::function1<void,vostok::vfs::vfs_locked_iterator const &>(
    0,
    (int)&callback,
    v9,
    v14,
    v15);
  v19.m_string.m_max_end = &v19.m_separator;
  m_begin = query_path.m_begin;
  m_buffer = v19.m_string.m_buffer;
  v19.m_string.m_begin = v19.m_string.m_buffer;
  v19.m_string.m_end = v19.m_string.m_buffer;
  v19.m_string.m_buffer[0] = 0;
  if ( query_path.m_begin )
  {
    if ( *query_path.m_begin )
    {
      do
      {
        if ( m_buffer >= v19.m_string.m_max_end )
          break;
        *m_buffer = *m_begin;
        m_buffer = v19.m_string.m_end + 1;
        ++m_begin;
        ++v19.m_string.m_end;
      }
      while ( *m_begin );
    }
    *m_buffer = 0;
  }
  v19.m_separator = 47;
  vostok::resources::query_vfs_iterator(
    &v19,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    recursive_false,
    0);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v13 )
      v13(&callback.functor, &callback.functor, 2);
  }
}
