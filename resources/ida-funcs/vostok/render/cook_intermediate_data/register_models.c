void __usercall vostok::render::cook_intermediate_data::register_models(
        vostok::render::cook_intermediate_data *this@<esi>,
        vostok::vfs::vfs_iterator *fs_it@<eax>)
{
  unsigned int children_count; // eax
  unsigned int v4; // ebx
  void *v5; // esp
  int m_num_render_models; // ebx
  int v7; // edi
  char *v8; // eax
  vostok::render::model_asset *v9; // ebx
  unsigned int v10; // ebx
  char *v11; // ecx
  vostok::fs_new::virtual_path_string *p_m_surface_name; // eax
  char *m_begin; // edx
  char *m_end; // edi
  unsigned int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-48h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+Ch] [ebp-3Ch] BYREF
  vostok::vfs::vfs_iterator end; // [esp+1Ch] [ebp-2Ch] BYREF
  vostok::vfs::vfs_iterator it; // [esp+2Ch] [ebp-1Ch] BYREF
  _DWORD *v20; // [esp+3Ch] [ebp-Ch]
  unsigned int v21; // [esp+40h] [ebp-8h]

  children_count = vostok::vfs::vfs_iterator::get_children_count(fs_it);
  v4 = children_count;
  if ( fs_it->m_node && children_count )
  {
    vostok::vfs::vfs_iterator::children_begin(fs_it, &it);
    vostok::vfs::vfs_iterator::children_end(fs_it, &end);
    v5 = alloca(4 * v4);
    v20 = v16;
    while ( vostok::vfs::vfs_iterator::operator!=(&it, &end) )
    {
      if ( vostok::vfs::vfs_iterator::is_folder(&it) )
        v16[this->m_num_render_models++] = vostok::vfs::vfs_iterator::get_name(&it);
      vostok::vfs::vfs_iterator::operator++(&it, &result);
    }
    m_num_render_models = this->m_num_render_models;
    v7 = 288 * m_num_render_models;
    v8 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                   288 * m_num_render_models + 8);
    *(_DWORD *)v8 = m_num_render_models;
    v8 += 4;
    v9 = (vostok::render::model_asset *)(v8 + 4);
    *(_DWORD *)v8 = 288;
    vostok::memory::detail::call_constructor_helper<vostok::render::model_asset,0>::call(
      (vostok::render::model_asset *const)(v8 + 4),
      (vostok::render::model_asset *const)&v8[v7 + 4]);
    this->assets = v9;
    v10 = 0;
    if ( this->m_num_render_models )
    {
      v21 = 0;
      do
      {
        v11 = (char *)v20[v10];
        p_m_surface_name = &this->assets[v21 / 0x120].m_surface_name;
        m_begin = p_m_surface_name->m_string.m_begin;
        if ( p_m_surface_name->m_string.m_begin != v11 )
        {
          this->assets[v21 / 0x120].m_surface_name.m_string.m_end = m_begin;
          *m_begin = 0;
          if ( v11 )
          {
            for ( ; *v11; ++v11 )
            {
              m_end = p_m_surface_name->m_string.m_end;
              if ( m_end >= p_m_surface_name->m_string.m_max_end )
                break;
              *m_end = *v11;
              ++p_m_surface_name->m_string.m_end;
            }
            *p_m_surface_name->m_string.m_end = 0;
          }
        }
        v15 = this->m_num_render_models;
        v21 += 288;
        ++v10;
      }
      while ( v10 < v15 );
    }
  }
}
