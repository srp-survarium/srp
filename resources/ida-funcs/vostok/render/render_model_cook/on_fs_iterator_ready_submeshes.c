void __thiscall vostok::render::render_model_cook::on_fs_iterator_ready_submeshes(
        vostok::render::render_model_cook *this,
        vostok::render::cook_intermediate_data *cook_data,
        const vostok::vfs::vfs_locked_iterator *fs_it)
{
  char *m_end; // edi
  unsigned int v5; // edi
  vostok::render::render_model_cook *v6; // ecx
  unsigned __int8 m_num_render_models; // al
  int v8; // ecx
  unsigned int v9; // ebx
  unsigned int *v10; // eax
  const vostok::resources::request *v11; // edi
  unsigned int *v12; // eax
  int v13; // esi
  vostok::fs_new::path_string_impl *v14; // ebx
  const char *name; // eax
  vostok::fs_new::virtual_path_string *p_m_surface_name; // ecx
  char *v17; // edx
  vostok::fs_new::path_string_impl *v18; // ebx
  int v19; // esi
  void (__cdecl *v20)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v22; // esi
  unsigned __int8 *m_begin; // [esp-8h] [ebp-1A0h]
  vostok::fs_new::virtual_path_string *v24; // [esp+10h] [ebp-188h]
  unsigned int model_index; // [esp+14h] [ebp-184h]
  int v26; // [esp+18h] [ebp-180h]
  unsigned int num_requests; // [esp+1Ch] [ebp-17Ch]
  const char *sname; // [esp+24h] [ebp-174h]
  vostok::vfs::vfs_iterator result; // [esp+2Ch] [ebp-16Ch] BYREF
  vostok::vfs::vfs_iterator it; // [esp+40h] [ebp-158h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+50h] [ebp-148h] BYREF
  vostok::vfs::vfs_iterator it_e; // [esp+70h] [ebp-128h] BYREF
  vostok::fs_new::virtual_path_string render_dir; // [esp+80h] [ebp-118h] BYREF

  m_end = cook_data->root_model_path.m_string.m_end;
  render_dir.m_string.m_begin = render_dir.m_string.m_buffer;
  v5 = m_end - cook_data->root_model_path.m_string.m_begin;
  m_begin = (unsigned __int8 *)cook_data->root_model_path.m_string.m_begin;
  render_dir.m_string.m_max_end = &render_dir.m_separator;
  memcpy((unsigned __int8 *)render_dir.m_string.m_buffer, m_begin, v5);
  render_dir.m_string.m_end = &render_dir.m_string.m_buffer[v5];
  *render_dir.m_string.m_end = 0;
  render_dir.m_separator = 47;
  *(_DWORD *)render_dir.m_string.m_end = *(_DWORD *)aRen;
  *((_WORD *)render_dir.m_string.m_end + 2) = 25956;
  render_dir.m_string.m_end[6] = 114;
  render_dir.m_string.m_end += 7;
  *render_dir.m_string.m_end = 0;
  vostok::render::cook_intermediate_data::register_models(cook_data, &fs_it->vostok::vfs::vfs_iterator);
  m_num_render_models = cook_data->m_num_render_models;
  if ( m_num_render_models )
  {
    v8 = 1;
    if ( this->m_class_id == skeleton_render_model_class )
      v8 = 2;
    v9 = v8 + 2 * m_num_render_models;
    num_requests = v9;
    v10 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            8 * v9 + 8);
    *v10++ = v9;
    v11 = (const vostok::resources::request *)(v10 + 1);
    *v10 = 8;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10[2 * v9 + 1]);
    v12 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            276 * v9 + 8);
    *v12++ = v9;
    *v12 = 276;
    v24 = (vostok::fs_new::virtual_path_string *)(v12 + 1);
    vostok::memory::detail::call_constructor_helper<vostok::fs_new::virtual_path_string,0>::call(v24, &v24[v9]);
    model_index = 0;
    vostok::fs_new::path_string_impl::assignf(v24, "resources/models/%s/export_properties", render_dir.m_string.m_begin);
    v11->id = binary_config_class_impl;
    v11->path = v24->m_string.m_begin;
    v13 = 1;
    vostok::vfs::vfs_iterator::children_begin(&fs_it->vostok::vfs::vfs_iterator, &it);
    vostok::vfs::vfs_iterator::children_end(&fs_it->vostok::vfs::vfs_iterator, &it_e);
    if ( vostok::vfs::vfs_iterator::operator!=(&it, &it_e) )
    {
      v26 = 0;
      v14 = v24 + 1;
      do
      {
        if ( vostok::vfs::vfs_iterator::is_folder(&it) )
        {
          name = vostok::vfs::vfs_iterator::get_name(&it);
          p_m_surface_name = &cook_data->assets[v26].m_surface_name;
          v17 = p_m_surface_name->m_string.m_begin;
          sname = name;
          if ( p_m_surface_name->m_string.m_begin != name )
          {
            cook_data->assets[v26].m_surface_name.m_string.m_end = v17;
            *v17 = 0;
            vostok::buffer_string::operator+=(&p_m_surface_name->m_string, name);
            name = sname;
          }
          vostok::fs_new::path_string_impl::assignf(
            v14,
            "resources/models/%s/%s/converted_model",
            render_dir.m_string.m_begin,
            name);
          v11[v13].id = raw_data_class;
          v11[v13].path = v14->m_string.m_begin;
          v18 = v14 + 1;
          v19 = v13 + 1;
          vostok::fs_new::path_string_impl::assignf(
            v18,
            "resources/models/%s/%s/export_properties",
            render_dir.m_string.m_begin,
            sname);
          ++model_index;
          v11[v19].id = binary_config_class_impl;
          v11[v19].path = v18->m_string.m_begin;
          v13 = v19 + 1;
          v14 = v18 + 1;
          ++v26;
        }
        vostok::vfs::vfs_iterator::operator++(&it, &result);
      }
      while ( vostok::vfs::vfs_iterator::operator!=(&it, &it_e) );
      v9 = num_requests;
    }
    if ( this->m_class_id == skeleton_render_model_class )
    {
      vostok::fs_new::path_string_impl::assignf(&v24[v13], "resources/models/%s/bind_pose", render_dir.m_string.m_begin);
      v11[v13].id = raw_data_class;
      v11[v13].path = v24[v13].m_string.m_begin;
    }
    result.m_link_target = (vostok::vfs::base_node<1> *)cook_data;
    result.m_hashset = (vostok::vfs::vfs_hashset *)vostok::render::render_model_cook::on_subresources_loaded;
    result.m_node = (vostok::vfs::base_node<1> *)this;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      callback.vtable = 0;
    }
    else
    {
      *(_QWORD *)&callback.functor.obj_ptr = *(_QWORD *)&result.m_hashset;
      callback.functor.vostok_pointer_size_alignment[2] = result.m_link_target;
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    vostok::resources::query_resources(
      v11,
      v9,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      0,
      cook_data->parent_query,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v20 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v20 )
        v20(&callback.functor, &callback.functor, 2);
    }
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, &v24[-1].m_string.m_buffer[256]);
    v22 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v22, (void *)&v11[-1]);
  }
  else
  {
    cook_data->status_failed = 1;
    cook_data->render_model_data_ready = 1;
    vostok::render::render_model_cook::query_materail_effects(
      v6,
      (vostok::render::cook_intermediate_data *)this,
      cook_data);
  }
}
