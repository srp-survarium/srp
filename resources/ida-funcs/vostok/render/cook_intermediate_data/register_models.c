void __userpurge vostok::render::cook_intermediate_data::register_models(
        vostok::vfs::vfs_iterator *fs_it@<eax>,
        vostok::render::cook_intermediate_data *this)
{
  int children_count; // eax
  vostok::vfs::vfs_iterator *v5; // ecx
  int v6; // edi
  void *v7; // esp
  unsigned __int8 *p_m_num_render_models; // ecx
  unsigned __int8 m_num_render_models; // al
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // eax
  vostok::render::model_asset *v14; // esi
  int v15; // edi
  vostok::render::model_asset *v16; // eax
  bool i; // zf
  int v18; // esi
  vostok::fs_new::virtual_path_string *v19; // edi
  const char *v20[3]; // [esp+0h] [ebp-34h] BYREF
  vostok::vfs::vfs_iterator v21; // [esp+Ch] [ebp-28h] BYREF
  vostok::vfs::vfs_iterator v22; // [esp+1Ch] [ebp-18h] BYREF
  const char **v23; // [esp+2Ch] [ebp-8h]
  int v24; // [esp+3Ch] [ebp+8h]
  vostok::render::model_asset *v25; // [esp+3Ch] [ebp+8h]
  unsigned int v26; // [esp+3Ch] [ebp+8h]

  children_count = vostok::vfs::vfs_iterator::get_children_count(fs_it);
  v6 = children_count;
  if ( fs_it->m_node && children_count )
  {
    vostok::vfs::vfs_iterator::children_begin(v5, &v22.m_hashset, fs_it);
    v7 = alloca(4 * v6);
    v23 = v20;
    while ( v22.m_node )
    {
      if ( vostok::vfs::vfs_iterator::is_folder(&v22) )
      {
        p_m_num_render_models = &this->m_num_render_models;
        m_num_render_models = this->m_num_render_models;
        v20[m_num_render_models] = v22.m_node->m_name;
        this->m_num_render_models = m_num_render_models + 1;
      }
      vostok::vfs::vfs_iterator::operator++((vostok::vfs::vfs_iterator *)p_m_num_render_models, &v22, &v21);
    }
    v10 = vostok::render::g_allocator;
    v24 = this->m_num_render_models;
    v11 = type_info::raw_name(&vostok::render::model_asset `RTTI Type Descriptor');
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(
            v12,
            (int)v10,
            288 * v24 + 8,
            v11,
            v20[0],
            v20[1],
            (const unsigned int)v20[2]);
    *(_DWORD *)v13 = v24;
    v13 += 4;
    v14 = (vostok::render::model_asset *)(v13 + 4);
    v15 = (int)&v13[288 * v24 + 4];
    *(_DWORD *)v13 = 288;
    v16 = v14;
    for ( i = v14 == (vostok::render::model_asset *)v15; ; i = v16 == (vostok::render::model_asset *)v15 )
    {
      v25 = v16;
      if ( i )
        break;
      if ( v16 )
      {
        v16->converted_model_buffer.m_object = 0;
        v16->material.m_object = 0;
        v16->export_properties_config.m_object = 0;
        vostok::fs_new::virtual_path_string::virtual_path_string(0, (int)&v16->m_surface_name);
        v16 = v25;
      }
      ++v16;
    }
    this->assets = v14;
    v18 = 0;
    v26 = 0;
    if ( this->m_num_render_models )
    {
      v19 = (vostok::fs_new::virtual_path_string *)v23;
      do
      {
        vostok::fs_new::virtual_path_string::operator=<char const *>(v19, &this->assets[v18].m_surface_name);
        ++v26;
        v19 = (vostok::fs_new::virtual_path_string *)((char *)v19 + 4);
        ++v18;
      }
      while ( v26 < this->m_num_render_models );
    }
  }
}
