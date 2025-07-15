void __thiscall vostok::render::render_model_cook::on_fs_iterator_ready_submeshes(
        vostok::render::render_model_cook *this,
        vostok::render::cook_intermediate_data *cook_data,
        const vostok::vfs::vfs_locked_iterator *fs_it)
{
  vostok::buffer_string *v4; // ecx
  vostok::render::render_model_cook *v5; // ecx
  int v6; // eax
  unsigned int v7; // edi
  vostok::resources::request *v8; // ebx
  vostok::fs_new::virtual_path_string *v9; // edi
  vostok::buffer_string *v10; // ecx
  vostok::vfs::vfs_iterator *v11; // ecx
  vostok::buffer_string *v12; // ecx
  vostok::fs_new::virtual_path_string *v13; // edi
  vostok::vfs::vfs_iterator *v14; // ecx
  vostok::fs_new::virtual_path_string *p_m_surface_name; // eax
  vostok::vfs::base_node<1> *m_begin; // ecx
  char *m_name; // esi
  vostok::fs_new::virtual_path_string *v18; // edi
  vostok::buffer_string *v19; // ecx
  int v20; // esi
  vostok::fs_new::virtual_path_string *v21; // edi
  vostok::resources::request *v22; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  vostok::memory::doug_lea_allocator *v24; // ecx
  vostok::memory::doug_lea_allocator *v25; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > v26; // [esp-10h] [ebp-188h]
  char *v27; // [esp-4h] [ebp-17Ch]
  const char *v28; // [esp+0h] [ebp-178h]
  const char *v29; // [esp+0h] [ebp-178h]
  const char *v30; // [esp+4h] [ebp-174h]
  const char *v31; // [esp+4h] [ebp-174h]
  unsigned int v32; // [esp+8h] [ebp-170h]
  unsigned int v33; // [esp+8h] [ebp-170h]
  int v34; // [esp+10h] [ebp-168h]
  int v35; // [esp+14h] [ebp-164h]
  int __formal; // [esp+1Ch] [ebp-15Ch]
  vostok::fs_new::virtual_path_string *v37; // [esp+20h] [ebp-158h]
  vostok::vfs::vfs_iterator v39; // [esp+28h] [ebp-150h] BYREF
  unsigned int v40; // [esp+38h] [ebp-140h]
  char *v41; // [esp+3Ch] [ebp-13Ch]
  vostok::vfs::vfs_iterator f[2]; // [esp+40h] [ebp-138h] BYREF
  vostok::fixed_string<260> v43; // [esp+60h] [ebp-118h] BYREF
  char v44; // [esp+170h] [ebp-8h]

  vostok::fixed_string<260>::fixed_string<260>(&v43, &cook_data->root_model_path.m_string);
  v44 = 47;
  vostok::buffer_string::append(v4, (int)&v43, "/render");
  vostok::render::cook_intermediate_data::register_models(&fs_it->vostok::vfs::vfs_iterator, cook_data);
  LOBYTE(v5) = cook_data->m_num_render_models;
  if ( (_BYTE)v5 )
  {
    v6 = 1;
    if ( this->m_class_id == skeleton_render_model_class )
      v6 = 2;
    v7 = v6 + 2 * (unsigned __int8)v5;
    v40 = v7;
    v8 = vostok::memory::new_array_helper<vostok::resources::request>::call<vostok::memory::doug_lea_allocator>(
           vostok::render::g_allocator,
           v7);
    __formal = 0;
    v9 = vostok::memory::new_array_helper<vostok::fs_new::virtual_path_string>::call<vostok::memory::doug_lea_allocator>(
           vostok::render::g_allocator,
           v7);
    v37 = v9;
    vostok::fs_new::path_string_impl::assignf(
      v9,
      v10,
      (vostok::buffer_string *)"resources/models/%s/export_properties",
      v43.m_begin);
    v8->id = binary_config_class_impl;
    v35 = 1;
    v8->path = v9->m_string.m_begin;
    vostok::vfs::vfs_iterator::children_begin(v11, &v39.m_hashset, &fs_it->vostok::vfs::vfs_iterator);
    if ( v39.m_node )
    {
      v34 = 0;
      v13 = v9 + 1;
      do
      {
        if ( vostok::vfs::vfs_iterator::is_folder(&v39) )
        {
          p_m_surface_name = &cook_data->assets[v34].m_surface_name;
          m_begin = (vostok::vfs::base_node<1> *)p_m_surface_name->m_string.m_begin;
          m_name = v39.m_node->m_name;
          v41 = v39.m_node->m_name;
          if ( m_begin != (vostok::vfs::base_node<1> *)v39.m_node->m_name )
          {
            p_m_surface_name->m_string.m_end = (char *)m_begin;
            LOBYTE(m_begin->m_mount_root.pointer) = 0;
            vostok::buffer_string::operator+=(&p_m_surface_name->m_string, m_name);
          }
          vostok::fs_new::path_string_impl::assignf(
            v13,
            (vostok::buffer_string *)m_begin,
            (vostok::buffer_string *)"resources/models/%s/%s/converted_model",
            v43.m_begin,
            m_name);
          v27 = v41;
          v8[v35].id = raw_data_class;
          v8[v35].path = v13->m_string.m_begin;
          v18 = v13 + 1;
          v20 = v35 + 1;
          vostok::fs_new::path_string_impl::assignf(
            v18,
            v19,
            (vostok::buffer_string *)"resources/models/%s/%s/export_properties",
            v43.m_begin,
            v27);
          v8[v20].id = binary_config_class_impl;
          v8[v20].path = v18->m_string.m_begin;
          v13 = v18 + 1;
          ++__formal;
          ++v34;
          v35 += 2;
        }
        vostok::vfs::vfs_iterator::operator++(v14, &v39, f);
      }
      while ( v39.m_node );
      v9 = v37;
    }
    if ( this->m_class_id == skeleton_render_model_class )
    {
      v21 = &v9[v35];
      vostok::fs_new::path_string_impl::assignf(
        v21,
        v12,
        (vostok::buffer_string *)"resources/models/%s/bind_pose",
        v43.m_begin,
        __formal);
      v22 = &v8[v35];
      v22->id = raw_data_class;
      v12 = (vostok::buffer_string *)v21->m_string.m_begin;
      v22->path = v21->m_string.m_begin;
    }
    v39.m_node = (vostok::vfs::base_node<1> *)this;
    v39.m_link_target = (vostok::vfs::base_node<1> *)cook_data;
    v39.m_hashset = (vostok::vfs::vfs_hashset *)vostok::render::render_model_cook::on_subresources_loaded;
    v26.l_.a1_.t_ = (vostok::render::render_model_cook *)vostok::render::render_model_cook::on_subresources_loaded;
    v26.l_.a3_.t_ = (vostok::render::cook_intermediate_data *)this;
    v26.f_.f_ = (void (__thiscall *)(vostok::render::render_model_cook *, vostok::resources::queries_result *, vostok::render::cook_intermediate_data *))f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      (boost::function<void __cdecl(vostok::resources::queries_result &)> *)v12,
      v26,
      (int)cook_data);
    vostok::resources::query_resources(
      v8,
      v40,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)cook_data->parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v23,
      (int *)f);
    vostok::memory::doug_lea_allocator::free_impl(
      v24,
      (int)vostok::render::g_allocator,
      &v37[-1].m_string.m_buffer[256],
      v28,
      v30,
      v32);
    vostok::memory::doug_lea_allocator::free_impl(v25, (int)vostok::render::g_allocator, (char *)&v8[-1], v29, v31, v33);
  }
  else
  {
    cook_data->status_failed = 1;
    cook_data->render_model_data_ready = 1;
    vostok::render::render_model_cook::query_materail_effects(
      v5,
      (vostok::render::cook_intermediate_data *)this,
      cook_data);
  }
}
