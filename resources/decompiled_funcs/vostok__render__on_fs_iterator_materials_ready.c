void __cdecl vostok::render::on_fs_iterator_materials_ready(
        const char *materials_path,
        const vostok::vfs::vfs_locked_iterator *fs_it,
        volatile int *waiting_for)
{
  vostok::fs_new::virtual_path_string *v3; // esi
  unsigned int children_count; // eax
  const char *v5; // edi
  char *m_begin; // edi
  vostok::fs_new::virtual_path_string *M_start; // edi
  vostok::fs_new::virtual_path_string *M_finish; // ebx
  char *m_end; // esi
  unsigned int v10; // esi
  stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *v11; // ecx
  int v12; // eax
  vostok::fs_new::virtual_path_string *v13; // esi
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  volatile int m_pending_queries_count; // eax
  char v16; // bl
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *m_object; // ecx
  vostok::fs_new::virtual_path_string *v19; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int8 *v21; // [esp-8h] [ebp-2C8h]
  const vostok::vfs::vfs_iterator *v22; // [esp-4h] [ebp-2C4h]
  vostok::render::vector<vostok::fs_new::virtual_path_string> query_names; // [esp+10h] [ebp-2B0h] BYREF
  vostok::render::vector<vostok::fs_new::virtual_path_string> out_material_names; // [esp+1Ch] [ebp-2A4h] BYREF
  int v25; // [esp+28h] [ebp-298h]
  vostok::vfs::vfs_iterator it; // [esp+2Ch] [ebp-294h] BYREF
  const vostok::fs_new::virtual_path_string *name_end; // [esp+3Ch] [ebp-284h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+40h] [ebp-280h] BYREF
  vostok::vfs::vfs_iterator end; // [esp+60h] [ebp-260h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+70h] [ebp-250h] BYREF
  vostok::vfs::vfs_iterator v31; // [esp+80h] [ebp-240h] BYREF
  vostok::fs_new::virtual_path_string name; // [esp+90h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string new_materials_path; // [esp+1A8h] [ebp-118h] BYREF

  v3 = 0;
  v25 = 0;
  children_count = vostok::vfs::vfs_iterator::get_children_count(&fs_it->vostok::vfs::vfs_iterator);
  if ( fs_it->m_node && children_count )
  {
    memset(&out_material_names, 0, sizeof(out_material_names));
    vostok::vfs::vfs_iterator::children_begin(&fs_it->vostok::vfs::vfs_iterator, &it);
    vostok::vfs::vfs_iterator::children_end(&fs_it->vostok::vfs::vfs_iterator, &end);
    if ( vostok::vfs::vfs_iterator::operator!=(&it, &end) )
    {
      do
      {
        v5 = vostok::vfs::vfs_iterator::get_name(&it);
        if ( vostok::vfs::vfs_iterator::is_folder(&it) )
        {
          new_materials_path.m_string.m_begin = new_materials_path.m_string.m_buffer;
          new_materials_path.m_string.m_end = new_materials_path.m_string.m_buffer;
          new_materials_path.m_string.m_max_end = &new_materials_path.m_separator;
          new_materials_path.m_string.m_buffer[0] = 0;
          new_materials_path.m_separator = 47;
          vostok::fs_new::path_string_impl::assignf(&new_materials_path, "%s/%s", materials_path, v5);
          m_begin = new_materials_path.m_string.m_begin;
          v22 = vostok::vfs::vfs_iterator::children_begin(&it, &result);
          vostok::render::on_fs_iterator_materials_ready_children(&out_material_names, m_begin, v22);
        }
        else
        {
          vostok::render::on_fs_iterator_materials_ready_children(&out_material_names, materials_path, &it);
        }
        vostok::vfs::vfs_iterator::operator++(&it, &v31);
      }
      while ( vostok::vfs::vfs_iterator::operator!=(&it, &end) );
      v3 = 0;
    }
    M_start = out_material_names._M_impl._M_start;
    M_finish = 0;
    name_end = out_material_names._M_impl._M_finish;
    memset(&query_names, 0, sizeof(query_names));
    if ( out_material_names._M_impl._M_start != out_material_names._M_impl._M_finish )
    {
      do
      {
        m_end = M_start->m_string.m_end;
        name.m_string.m_max_end = &name.m_separator;
        v10 = m_end - M_start->m_string.m_begin;
        v21 = (unsigned __int8 *)M_start->m_string.m_begin;
        name.m_string.m_begin = name.m_string.m_buffer;
        name.m_string.m_end = name.m_string.m_buffer;
        memcpy((unsigned __int8 *)name.m_string.m_buffer, v21, v10);
        name.m_string.m_end += v10;
        *name.m_string.m_end = 0;
        name.m_separator = 47;
        if ( (unsigned int)(name.m_string.m_end - name.m_string.m_begin) <= 0xC
          || (strstr((unsigned __int8 *)name.m_string.m_begin, (unsigned __int8 *)&stru_95F7AC.destroyer), !v12) )
        {
          stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
            (const stlp_std::__false_type *)&name,
            v11,
            &query_names._M_impl);
          M_finish = query_names._M_impl._M_finish;
          v13 = query_names._M_impl._M_start;
          if ( query_names._M_impl._M_finish - query_names._M_impl._M_start == 50 )
          {
            vostok::render::query_materials_and_wait(&query_names);
            if ( v13 != M_finish )
            {
              M_finish = stlp_std::priv::__copy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string *,int>(
                           M_finish,
                           M_finish,
                           v13);
              query_names._M_impl._M_finish = M_finish;
            }
          }
        }
        ++M_start;
      }
      while ( M_start != name_end );
      v3 = query_names._M_impl._M_start;
    }
    if ( M_finish - v3 )
      vostok::render::query_materials_and_wait(&query_names);
    if ( waiting_for )
      _InterlockedExchange(waiting_for, 0);
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v16 = v25;
    }
    else
    {
      v14 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      m_pending_queries_count = 0;
      if ( v14 )
      {
        log_callback.functor.obj_ptr = v14;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v16 = 1;
      if ( vostok::resources::g_resources_manager.m_initialized )
        m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_engine_world_pc_dx11.cpp",
        0x2DCu,
        "void __cdecl vostok::render::on_fs_iterator_materials_ready(const char *,const class vostok::vfs::vfs_locked_ite"
        "rator &,volatile long *)",
        "render_pc_dx11:",
        error,
        "pending qc:%d",
        m_pending_queries_count);
      v3 = query_names._M_impl._M_start;
    }
    if ( (v16 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v17 )
            v17(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    if ( v3 )
    {
      m_object = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v3);
    }
    v19 = out_material_names._M_impl._M_start;
    if ( out_material_names._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v19);
    }
  }
}
