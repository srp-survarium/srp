void __thiscall vostok::render::scene::on_fs_iterator_probes_ready(
        vostok::render::scene *this,
        char *path,
        const vostok::vfs::vfs_locked_iterator *fs_it)
{
  void **M_start; // esi
  void **M_finish; // edi
  _DWORD *v6; // ecx
  unsigned int v7; // edx
  _BYTE *v8; // eax
  int v9; // eax
  stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *v10; // ecx
  char *m_buffer; // eax
  const char *name; // eax
  char *m_begin; // edx
  char *m_end; // ecx
  char *v15; // eax
  int v16; // eax
  vostok::fs_new::path_string_impl *v17; // esi
  vostok::fs_new::path_string_impl *v18; // esi
  stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *v19; // ecx
  void **v20; // eax
  char *v21; // eax
  int v22; // eax
  vostok::fixed_string<260> *v23; // edi
  int v24; // esi
  char *v25; // eax
  char *v26; // ecx
  int v27; // esi
  char *v28; // eax
  char *v29; // ecx
  vostok::animation::mixing::animation_interval *v30; // eax
  vostok::fs_new::device_file_system_proxy_base *v31; // eax
  vostok::animation::mixing::animation_interval *v32; // eax
  vostok::fs_new::device_file_system_proxy_base *v33; // eax
  vostok::render::grass_render_model *m_object; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::fixed_string<260> *v36; // eax
  void *v37; // esi
  vostok::fixed_string<260> *v38; // eax
  void *v39; // esi
  const char *v40; // [esp-4h] [ebp-7E4h]
  vostok::fs_new::synchronous_device_interface *devicea; // [esp+Ch] [ebp-7D4h]
  vostok::render::vector<vostok::fixed_string<260> > remove_names; // [esp+10h] [ebp-7D0h] BYREF
  vostok::render::vector<vostok::fixed_string<260> > used_names; // [esp+1Ch] [ebp-7C4h] BYREF
  vostok::vfs::vfs_iterator names_it; // [esp+28h] [ebp-7B8h] BYREF
  vostok::vfs::vfs_iterator names_end; // [esp+38h] [ebp-7A8h] BYREF
  vostok::fixed_string<260> logical_name_tga; // [esp+48h] [ebp-798h] BYREF
  vostok::fs_new::path_string_impl v48; // [esp+158h] [ebp-688h] BYREF
  vostok::fs_new::path_string_impl v49; // [esp+26Ch] [ebp-574h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+380h] [ebp-460h] BYREF
  vostok::fixed_string<260> probes_path; // [esp+390h] [ebp-450h] BYREF
  vostok::fs_new::native_path_string physical_path_options; // [esp+4A0h] [ebp-340h] BYREF
  vostok::fs_new::native_path_string physical_path_tga; // [esp+5B8h] [ebp-228h] BYREF
  vostok::fixed_string<260> logical_name_options; // [esp+6D0h] [ebp-110h] BYREF
  char vars0; // [esp+7E0h] [ebp+0h] BYREF

  if ( !fs_it->m_node || !vostok::vfs::vfs_iterator::get_children_count(&fs_it->vostok::vfs::vfs_iterator) )
    return;
  vostok::vfs::vfs_iterator::children_begin(&fs_it->vostok::vfs::vfs_iterator, &names_it);
  vostok::vfs::vfs_iterator::children_end(&fs_it->vostok::vfs::vfs_iterator, &names_end);
  M_start = this->m_environment_probes._M_impl._M_start;
  M_finish = this->m_environment_probes._M_impl._M_finish;
  memset(&used_names, 0, sizeof(used_names));
  memset(&remove_names, 0, sizeof(remove_names));
  if ( M_start != M_finish )
  {
    while ( 1 )
    {
      v6 = *M_start;
      logical_name_tga.m_begin = logical_name_tga.m_buffer;
      logical_name_tga.m_end = logical_name_tga.m_buffer;
      logical_name_tga.m_max_end = (char *)&v48;
      logical_name_tga.m_buffer[0] = 0;
      v7 = v6[1];
      v8 = (_BYTE *)(v6[2] - 1);
      if ( (unsigned int)v8 < v7 )
        goto LABEL_9;
      if ( *v8 != 47 )
        break;
LABEL_8:
      v9 = (int)&v8[-v7];
LABEL_10:
      v10 = (stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *)(v7 + v9 + 1);
      m_buffer = logical_name_tga.m_buffer;
      logical_name_tga.m_end = logical_name_tga.m_buffer;
      logical_name_tga.m_buffer[0] = 0;
      if ( v10 )
      {
        for ( ; LOBYTE(v10->_M_start); ++logical_name_tga.m_end )
        {
          if ( m_buffer >= logical_name_tga.m_max_end )
            break;
          *m_buffer = (char)v10->_M_start;
          m_buffer = logical_name_tga.m_end + 1;
          v10 = (stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *)((char *)v10 + 1);
        }
        *m_buffer = 0;
      }
      stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::push_back(
        (const stlp_std::__false_type *)&logical_name_tga,
        v10,
        &used_names._M_impl);
      if ( ++M_start == M_finish )
        goto LABEL_16;
    }
    while ( v8 != (_BYTE *)v7 )
    {
      if ( *--v8 == 47 )
        goto LABEL_8;
    }
LABEL_9:
    v9 = -1;
    goto LABEL_10;
  }
LABEL_16:
  while ( vostok::vfs::vfs_iterator::operator!=(&names_it, &names_end) )
  {
    name = vostok::vfs::vfs_iterator::get_name(&names_it);
    m_begin = logical_name_tga.m_buffer;
    m_end = logical_name_tga.m_buffer;
    logical_name_tga.m_begin = logical_name_tga.m_buffer;
    logical_name_tga.m_end = logical_name_tga.m_buffer;
    logical_name_tga.m_max_end = (char *)&v48;
    logical_name_tga.m_buffer[0] = 0;
    if ( name )
    {
      for ( ; *name; ++logical_name_tga.m_end )
      {
        if ( m_end >= logical_name_tga.m_max_end )
          break;
        *m_end = *name;
        m_end = logical_name_tga.m_end + 1;
        ++name;
      }
      *m_end = 0;
      m_end = logical_name_tga.m_end;
      m_begin = logical_name_tga.m_begin;
    }
    v15 = m_end - 1;
    if ( m_end - 1 >= m_begin )
    {
      if ( *v15 == 46 )
      {
LABEL_26:
        v16 = v15 - m_begin;
        goto LABEL_28;
      }
      while ( v15 != m_begin )
      {
        if ( *--v15 == 46 )
          goto LABEL_26;
      }
    }
    v16 = -1;
LABEL_28:
    logical_name_tga.m_end = &m_begin[v16];
    *logical_name_tga.m_end = 0;
    if ( !vostok::vfs::vfs_iterator::is_folder(&names_it) )
    {
      v17 = (vostok::fs_new::path_string_impl *)used_names._M_impl._M_finish;
      if ( stlp_std::priv::__find<vostok::fixed_string<260> *,vostok::fixed_string<260>>(
             (vostok::fs_new::path_string_impl *)used_names._M_impl._M_start,
             used_names._M_impl._M_finish,
             (vostok::fs_new::path_string_impl *)&logical_name_tga) == v17 )
      {
        v18 = (vostok::fs_new::path_string_impl *)remove_names._M_impl._M_finish;
        if ( stlp_std::priv::__find<vostok::fixed_string<260> *,vostok::fixed_string<260>>(
               (vostok::fs_new::path_string_impl *)remove_names._M_impl._M_start,
               remove_names._M_impl._M_finish,
               (vostok::fs_new::path_string_impl *)&logical_name_tga) == v18 )
          stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::push_back(
            (const stlp_std::__false_type *)&logical_name_tga,
            v19,
            &remove_names._M_impl);
      }
    }
    vostok::vfs::vfs_iterator::operator++(&names_it, &result);
  }
  probes_path.m_begin = probes_path.m_buffer;
  probes_path.m_end = probes_path.m_buffer;
  v20 = this->m_environment_probes._M_impl._M_start;
  probes_path.m_max_end = (char *)&physical_path_options;
  probes_path.m_buffer[0] = 0;
  vostok::fixed_string<260>::operator=(&probes_path, (vostok::fixed_string<260> *)((char *)*v20 + 4));
  v21 = probes_path.m_end - 1;
  if ( probes_path.m_end - 1 < probes_path.m_begin )
    goto LABEL_38;
  if ( *v21 != 47 )
  {
    while ( v21 != probes_path.m_begin )
    {
      if ( *--v21 == 47 )
        goto LABEL_37;
    }
LABEL_38:
    v22 = -1;
    goto LABEL_39;
  }
LABEL_37:
  v22 = v21 - probes_path.m_begin;
LABEL_39:
  v23 = remove_names._M_impl._M_start;
  probes_path.m_end = &probes_path.m_begin[v22];
  probes_path.m_begin[v22] = 0;
  for ( devicea = s_core_synchronous_device.m_variable; v23 != remove_names._M_impl._M_finish; ++v23 )
  {
    logical_name_tga.m_begin = logical_name_tga.m_buffer;
    logical_name_tga.m_end = logical_name_tga.m_buffer;
    logical_name_options.m_begin = logical_name_options.m_buffer;
    v40 = v23->m_begin;
    logical_name_tga.m_max_end = (char *)&v48;
    logical_name_options.m_end = logical_name_options.m_buffer;
    logical_name_options.m_max_end = &vars0;
    logical_name_tga.m_buffer[0] = 0;
    logical_name_options.m_buffer[0] = 0;
    vostok::buffer_string::assignf(&logical_name_tga, "resources.sources/textures/%s/%s.tga", probes_path.m_begin, v40);
    vostok::buffer_string::assignf(
      &logical_name_options,
      "resources.sources/textures/%s/%s.options",
      probes_path.m_begin,
      v23->m_begin);
    physical_path_tga.m_string.m_max_end = &physical_path_tga.m_separator;
    physical_path_options.m_string.m_max_end = &physical_path_options.m_separator;
    v49.m_string.m_max_end = &v49.m_separator;
    physical_path_tga.m_string.m_begin = physical_path_tga.m_string.m_buffer;
    physical_path_tga.m_string.m_end = physical_path_tga.m_string.m_buffer;
    v24 = logical_name_tga.m_end - logical_name_tga.m_begin;
    physical_path_options.m_string.m_begin = physical_path_options.m_string.m_buffer;
    physical_path_options.m_string.m_end = physical_path_options.m_string.m_buffer;
    physical_path_tga.m_string.m_buffer[0] = 0;
    physical_path_tga.m_separator = 92;
    physical_path_options.m_string.m_buffer[0] = 0;
    physical_path_options.m_separator = 92;
    v49.m_string.m_begin = v49.m_string.m_buffer;
    v49.m_string.m_end = v49.m_string.m_buffer;
    memcpy(
      (unsigned __int8 *)v49.m_string.m_buffer,
      (unsigned __int8 *)logical_name_tga.m_begin,
      logical_name_tga.m_end - logical_name_tga.m_begin);
    v49.m_string.m_end += v24;
    *v49.m_string.m_end = 0;
    v49.m_separator = 47;
    if ( (unsigned int)(v49.m_string.m_end - v49.m_string.m_begin) > 1
      && vostok::fs_new::path_string_impl::operator[](&v49, 0) == 64 )
    {
      v25 = v48.m_string.m_buffer;
      v48.m_string.m_max_end = &v48.m_separator;
      v26 = v49.m_string.m_begin + 1;
      v48.m_string.m_begin = v48.m_string.m_buffer;
      v48.m_string.m_end = v48.m_string.m_buffer;
      v48.m_string.m_buffer[0] = 0;
      v48.m_separator = 92;
      if ( v48.m_string.m_buffer != v49.m_string.m_begin + 1 )
      {
        v48.m_string.m_end = v48.m_string.m_buffer;
        v48.m_string.m_buffer[0] = 0;
        if ( v49.m_string.m_begin != (char *)-1 )
        {
          for ( ; *v26; ++v48.m_string.m_end )
          {
            if ( v25 >= v48.m_string.m_max_end )
              break;
            *v25 = *v26;
            v25 = v48.m_string.m_end + 1;
            ++v26;
          }
          *v25 = 0;
          v25 = v48.m_string.m_end;
        }
      }
      vostok::fs_new::path_string_impl::convert(&v48, v48.m_string.m_begin, v25);
      vostok::fs_new::virtual_path_string::operator=(
        (vostok::fs_new::virtual_path_string *)&physical_path_tga,
        (vostok::fs_new::virtual_path_string *)&v48);
    }
    else
    {
      vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(
        (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                           + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        &physical_path_tga,
        (const vostok::fs_new::virtual_path_string *)&v49,
        "sources");
    }
    v49.m_string.m_max_end = &v49.m_separator;
    v27 = logical_name_options.m_end - logical_name_options.m_begin;
    v49.m_string.m_begin = v49.m_string.m_buffer;
    v49.m_string.m_end = v49.m_string.m_buffer;
    memcpy(
      (unsigned __int8 *)v49.m_string.m_buffer,
      (unsigned __int8 *)logical_name_options.m_begin,
      logical_name_options.m_end - logical_name_options.m_begin);
    v49.m_string.m_end += v27;
    *v49.m_string.m_end = 0;
    v49.m_separator = 47;
    if ( (unsigned int)(v49.m_string.m_end - v49.m_string.m_begin) > 1
      && vostok::fs_new::path_string_impl::operator[](&v49, 0) == 64 )
    {
      v28 = v48.m_string.m_buffer;
      v48.m_string.m_max_end = &v48.m_separator;
      v29 = v49.m_string.m_begin + 1;
      v48.m_string.m_begin = v48.m_string.m_buffer;
      v48.m_string.m_end = v48.m_string.m_buffer;
      v48.m_string.m_buffer[0] = 0;
      v48.m_separator = 92;
      if ( v48.m_string.m_buffer != v49.m_string.m_begin + 1 )
      {
        v48.m_string.m_end = v48.m_string.m_buffer;
        v48.m_string.m_buffer[0] = 0;
        if ( v49.m_string.m_begin != (char *)-1 )
        {
          for ( ; *v29; ++v48.m_string.m_end )
          {
            if ( v28 >= v48.m_string.m_max_end )
              break;
            *v28 = *v29;
            v28 = v48.m_string.m_end + 1;
            ++v29;
          }
          *v28 = 0;
          v28 = v48.m_string.m_end;
        }
      }
      vostok::fs_new::path_string_impl::convert(&v48, v48.m_string.m_begin, v28);
      vostok::fs_new::virtual_path_string::operator=(
        (vostok::fs_new::virtual_path_string *)&physical_path_options,
        (vostok::fs_new::virtual_path_string *)&v48);
    }
    else
    {
      vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(
        (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                           + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        &physical_path_options,
        (const vostok::fs_new::virtual_path_string *)&v49,
        "sources");
    }
    v30 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(devicea);
    v31 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v30);
    vostok::fs_new::device_file_system_proxy_base::erase(v31, &physical_path_tga);
    v32 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(devicea);
    v33 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v32);
    vostok::fs_new::device_file_system_proxy_base::erase(v33, &physical_path_options);
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( path )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, path);
    m_object = vostok::render::g_allocator.m_object;
  }
  v36 = remove_names._M_impl._M_start;
  if ( remove_names._M_impl._M_start )
  {
    v37 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v37, v36);
    m_object = vostok::render::g_allocator.m_object;
  }
  v38 = used_names._M_impl._M_start;
  if ( used_names._M_impl._M_start )
  {
    v39 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v39, v38);
  }
}
