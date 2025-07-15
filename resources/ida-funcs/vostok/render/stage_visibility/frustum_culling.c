void __thiscall vostok::render::stage_visibility::frustum_culling(
        vostok::render::stage_visibility *this,
        vostok::render::stage_visibility *thisa)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::scene *m_scene; // ecx
  vostok::render::base_scene_view *m_object; // ebp
  void **m_flags; // eax
  void **type; // ecx
  void **v7; // esi
  void **v8; // eax
  void **v9; // ecx
  void **v10; // esi
  void **v11; // eax
  void **v12; // ecx
  void **v13; // esi
  void **v14; // eax
  void **v15; // ecx
  void **v16; // esi
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_next_in_global_list; // eax
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v18; // esi
  void **v19; // eax
  void **m_reference_count; // ecx
  void **v21; // edi
  void **m_reconstruction_info_actuality_tick_high; // eax
  void **m_reconstruction_info_actuality_tick; // ecx
  void **v24; // esi
  void **m_memory_type_data; // eax
  void **m_construct_thread_id; // ecx
  void **v27; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v28; // ecx
  vostok::particle::world *v29; // ecx
  const void **M_start; // eax
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *M_finish; // ecx
  const vostok::collision::object *const *v32; // ebx
  vostok::render::light *m_user_data; // eax
  vostok::render::light *v34; // esi
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v35; // eax
  vostok::render::grass_render_model *v37; // ebx
  vostok::render::light *v38; // eax
  void *v39; // esi
  vostok::render::scene *v40; // edi
  const void **v41; // eax
  vostok::render::light *v42; // ecx
  char *m_prev_in_global_delay_delete_list; // esi
  int v44; // eax
  unsigned int v45; // eax
  char v46; // dl
  const vostok::collision::object *const **p_e; // ecx
  unsigned int v48; // ecx
  const vostok::collision::object *const **v49; // eax
  const vostok::collision::object *const *v50; // ecx
  vostok::render::grass_render_model *v51; // eax
  unsigned int v52; // ecx
  unsigned __int8 *v53; // edi
  unsigned __int8 *m_next_in_global_delay_delete_list; // eax
  unsigned int v55; // esi
  int v56; // eax
  _DWORD *v57; // eax
  vostok::resources::unmanaged_resource *v58; // ebx
  vostok::resources::unmanaged_resource *v59; // eax
  void *v60; // esi
  unsigned __int8 *v61; // eax
  const void **v62; // eax
  vostok::render::light *v63; // ecx
  char *v64; // esi
  int v65; // ebx
  unsigned int v66; // eax
  char v67; // dl
  vostok::render::ambient_volume ***p_end; // ecx
  unsigned int v69; // ecx
  vostok::render::ambient_volume ***v70; // eax
  vostok::render::ambient_volume **v71; // ecx
  vostok::render::grass_render_model *v72; // eax
  unsigned int v73; // ecx
  unsigned __int8 *v74; // edi
  unsigned __int8 *v75; // eax
  unsigned int v76; // esi
  int v77; // eax
  unsigned __int8 *v78; // eax
  _DWORD *v79; // ebx
  void *v80; // eax
  void *v81; // esi
  vostok::render::scene *v82; // edi
  void **v83; // ebx
  char *v84; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v85; // ecx
  void **v86; // eax
  vostok::render::vector<vostok::render::render_surface_instance *> *v87; // esi
  void **v88; // [esp+18h] [ebp-D0h]
  unsigned int m_size; // [esp+1Ch] [ebp-CCh]
  unsigned int v90; // [esp+1Ch] [ebp-CCh]
  vostok::render::render_surface_instance **v91; // [esp+1Ch] [ebp-CCh]
  const stlp_std::__false_type *v92; // [esp+20h] [ebp-C8h]
  unsigned int v93; // [esp+24h] [ebp-C4h]
  bool v94; // [esp+28h] [ebp-C0h]
  vostok::render::ambient_volume **end; // [esp+38h] [ebp-B0h] BYREF
  const vostok::collision::object *const *i; // [esp+3Ch] [ebp-ACh] BYREF
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> __x; // [esp+40h] [ebp-A8h] BYREF
  vostok::render::scene *render_scene; // [esp+44h] [ebp-A4h]
  const vostok::collision::object *const *e; // [esp+48h] [ebp-A0h] BYREF
  int v100; // [esp+4Ch] [ebp-9Ch] BYREF
  vostok::vectora<vostok::collision::object const *> probe_objects; // [esp+50h] [ebp-98h] BYREF
  __int64 v102; // [esp+60h] [ebp-88h]
  const void **v103; // [esp+68h] [ebp-80h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> *selection; // [esp+6Ch] [ebp-7Ch]
  vostok::math::frustum view_frustum; // [esp+70h] [ebp-78h] BYREF

  vostok::math::frustum::frustum(&view_frustum, &thisa->m_context->m_vp);
  m_context = thisa->m_context;
  m_scene = m_context->m_scene;
  m_object = m_context->m_scene_view.m_object;
  m_flags = (void **)m_object[5].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  render_scene = m_scene;
  type = (void **)m_object[5].type;
  if ( type != m_flags )
  {
    v7 = stlp_std::priv::__copy_ptrs<void * *,void * *>(m_flags, m_flags, type);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    m_object[5].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = (volatile int)v7;
  }
  v8 = (void **)&m_object[4].m_prev_in_global_delay_delete_list->vostok::resources::unmanaged_resource::__vftable;
  v9 = (void **)&m_object[4].m_next_in_global_delay_delete_list->vostok::resources::unmanaged_resource::__vftable;
  if ( v9 != v8 )
  {
    v10 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v8, v8, v9);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    m_object[4].m_prev_in_global_delay_delete_list = (vostok::resources::unmanaged_resource *)v10;
  }
  v11 = *(void ***)&m_object[4].m_inlined_in_fat;
  v12 = (void **)m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags;
  if ( v12 != v11 )
  {
    v13 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v11, v11, v12);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    *(_DWORD *)&m_object[4].m_inlined_in_fat = v13;
  }
  v14 = (void **)&m_object[4].next_scene_view.m_object->__vftable;
  v15 = (void **)&m_object[4].last_command->__vftable;
  if ( v15 != v14 )
  {
    v16 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v14, v14, v15);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    m_object[4].next_scene_view.m_object = (vostok::render::base_scene_view *)v16;
  }
  m_next_in_global_list = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_next_in_global_list;
  if ( (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_next_delay_delete != m_next_in_global_list )
  {
    v18 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
            m_next_in_global_list,
            m_next_in_global_list,
            (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_next_delay_delete);
    stlp_std::__destroy_range_aux<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
      v18,
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_next_in_global_list);
    m_object[4].m_next_in_global_list = (vostok::resources::unmanaged_resource *)v18;
  }
  v19 = (void **)m_object[4].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
  m_reference_count = (void **)m_object[4].m_reference_count;
  selection = (vostok::render::vector<vostok::render::render_surface_instance *> *)&m_object[4].vostok::resources::unmanaged_intrusive_base;
  if ( m_reference_count != v19 )
  {
    v21 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v19, v19, m_reference_count);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    m_object[4].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags = (volatile int)v21;
  }
  m_reconstruction_info_actuality_tick_high = (void **)HIDWORD(m_object[5].m_reconstruction_info_actuality_tick);
  m_reconstruction_info_actuality_tick = (void **)m_object[5].m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick != m_reconstruction_info_actuality_tick_high )
  {
    v24 = stlp_std::priv::__copy_ptrs<void * *,void * *>(
            m_reconstruction_info_actuality_tick_high,
            m_reconstruction_info_actuality_tick_high,
            m_reconstruction_info_actuality_tick);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    HIDWORD(m_object[5].m_reconstruction_info_actuality_tick) = v24;
  }
  m_memory_type_data = (void **)m_object[4].m_memory_type_data;
  m_construct_thread_id = (void **)m_object[4].m_construct_thread_id;
  if ( m_construct_thread_id != m_memory_type_data )
  {
    v27 = stlp_std::priv::__copy_ptrs<void * *,void * *>(m_memory_type_data, m_memory_type_data, m_construct_thread_id);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    m_object[4].m_memory_type_data = (vostok::resources::memory_type *)v27;
  }
  if ( render_scene->m_grass )
  {
    vostok::render::grass_world::process_culling(
      (vostok::render::grass_world *)thisa,
      thisa->m_context,
      *(const float *)&v92);
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
      v28,
      (int)&m_object[5].type,
      (unsigned int)&render_scene->m_grass->m_visible_patches);
  }
  v29 = render_scene->m_particle_world.m_object;
  if ( v29 )
    v29->get_render_emitter_instances(
      v29,
      &thisa->m_context->m_vp,
      (vostok::vectora<vostok::particle::render_particle_emitter_instance *> *)&m_object[4].last_command);
  probe_objects._M_impl._M_start = 0;
  probe_objects._M_impl._M_finish = 0;
  probe_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  probe_objects._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)vostok::render::g_allocator.m_object,
    &probe_objects._M_impl,
    0x400u);
  render_scene->m_lights.m_object->m_lights_tree->cuboid_query(
    render_scene->m_lights.m_object->m_lights_tree,
    -1u,
    &view_frustum,
    &probe_objects);
  M_start = probe_objects._M_impl._M_start;
  M_finish = (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)probe_objects._M_impl._M_finish;
  v32 = (const vostok::collision::object *const *)probe_objects._M_impl._M_start;
  i = (const vostok::collision::object *const *)probe_objects._M_impl._M_start;
  e = (const vostok::collision::object *const *)probe_objects._M_impl._M_finish;
  if ( probe_objects._M_impl._M_start != probe_objects._M_impl._M_finish )
  {
    do
    {
      m_user_data = (vostok::render::light *)(*v32)->m_user_data;
      v34 = 0;
      __x.m_object = 0;
      if ( m_user_data )
      {
        ++m_user_data->m_reference_count;
        v34 = m_user_data;
        __x.m_object = m_user_data;
      }
      v35 = (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_next_in_global_list;
      if ( v35 == (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[4].m_prev_in_global_list )
      {
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_insert_overflow_aux(
          M_finish,
          (int)&m_object[4].232,
          v35,
          &__x,
          v92,
          v93,
          v94);
      }
      else
      {
        if ( v35 )
        {
          v35->m_object = 0;
          vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
            &__x,
            (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v35,
            &__x);
        }
        m_object[4].m_next_in_global_list = (vostok::resources::unmanaged_resource *)((char *)m_object[4].m_next_in_global_list
                                                                                    + 4);
      }
      if ( v34 )
      {
        if ( v34->m_reference_count-- == 1 )
        {
          v37 = vostok::render::g_allocator.m_object;
          vostok::render::light::~light((vostok::render::light *)M_finish, (int)v34);
          v38 = v34;
          v39 = (void *)HIDWORD(v37->m_reconstruction_info_actuality_tick);
          BYTE2(v37->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v39, v38);
          v32 = i;
        }
      }
      i = ++v32;
    }
    while ( v32 != e );
    M_start = probe_objects._M_impl._M_start;
  }
  if ( M_start )
    probe_objects._M_impl._M_end_of_storage.m_allocator->call_free(
      probe_objects._M_impl._M_end_of_storage.m_allocator,
      M_start);
  v40 = render_scene;
  m_size = render_scene->m_decals.m_size;
  probe_objects._M_impl._M_start = 0;
  probe_objects._M_impl._M_finish = 0;
  probe_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  probe_objects._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)vostok::render::g_allocator.m_object,
    &probe_objects._M_impl,
    m_size);
  v40->m_decals_tree->cuboid_query(v40->m_decals_tree, -1u, &view_frustum, &probe_objects);
  v41 = probe_objects._M_impl._M_start;
  v42 = (vostok::render::light *)probe_objects._M_impl._M_start;
  __x.m_object = (vostok::render::light *)probe_objects._M_impl._M_start;
  end = (vostok::render::ambient_volume **)probe_objects._M_impl._M_finish;
  if ( probe_objects._M_impl._M_start != probe_objects._M_impl._M_finish )
  {
    do
    {
      m_prev_in_global_delay_delete_list = (char *)m_object[4].m_prev_in_global_delay_delete_list;
      v44 = *(_DWORD *)(v42->m_reference_count + 36);
      v100 = v44;
      if ( m_prev_in_global_delay_delete_list == (char *)m_object[4].m_deallocation_thread_id )
      {
        v45 = (m_prev_in_global_delay_delete_list - (char *)m_object[4].m_next_in_global_delay_delete_list) >> 2;
        v46 = 1;
        i = (const vostok::collision::object *const *)1;
        e = (const vostok::collision::object *const *)v45;
        if ( v45 == 0x3FFFFFFF )
LABEL_66:
          stlp_std::__stl_throw_length_error("vector");
        p_e = &e;
        if ( v45 <= 1 )
          p_e = &i;
        v48 = (unsigned int)*p_e + v45;
        i = (const vostok::collision::object *const *)v48;
        if ( v48 > 0x3FFFFFFF || v48 < v45 )
        {
          v48 = 0x3FFFFFFF;
          i = (const vostok::collision::object *const *)0x3FFFFFFF;
        }
        v103 = (const void **)v48;
        e = (const vostok::collision::object *const *)1;
        v49 = &e;
        if ( v48 )
          v49 = (const vostok::collision::object *const **)&v103;
        v50 = *v49;
        v51 = vostok::render::g_allocator.m_object;
        v52 = 4 * (_DWORD)v50;
        if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v52 )
          v46 = 0;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v46;
        if ( v52 )
          v53 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v51->m_reconstruction_info_actuality_tick), v52);
        else
          v53 = 0;
        m_next_in_global_delay_delete_list = (unsigned __int8 *)m_object[4].m_next_in_global_delay_delete_list;
        v55 = m_prev_in_global_delay_delete_list - (char *)m_next_in_global_delay_delete_list;
        if ( v55 )
        {
          memmove(v53, m_next_in_global_delay_delete_list, v55);
          v57 = (_DWORD *)(v55 + v56);
        }
        else
        {
          v57 = v53;
        }
        *v57 = v100;
        v58 = (vostok::resources::unmanaged_resource *)(v57 + 1);
        v59 = m_object[4].m_next_in_global_delay_delete_list;
        if ( v59 )
        {
          v60 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v60, v59);
        }
        v42 = __x.m_object;
        v61 = &v53[4 * (_DWORD)i];
        m_object[4].m_next_in_global_delay_delete_list = (vostok::resources::unmanaged_resource *)v53;
        v40 = render_scene;
        m_object[4].m_prev_in_global_delay_delete_list = v58;
        m_object[4].m_deallocation_thread_id = (unsigned int)v61;
      }
      else
      {
        *(_DWORD *)m_prev_in_global_delay_delete_list = v44;
        m_object[4].m_prev_in_global_delay_delete_list = (vostok::resources::unmanaged_resource *)((char *)m_object[4].m_prev_in_global_delay_delete_list
                                                                                                 + 4);
      }
      v42 = (vostok::render::light *)((char *)v42 + 4);
      __x.m_object = v42;
    }
    while ( v42 != (vostok::render::light *)end );
    v41 = probe_objects._M_impl._M_start;
  }
  if ( v41 )
    probe_objects._M_impl._M_end_of_storage.m_allocator->call_free(
      probe_objects._M_impl._M_end_of_storage.m_allocator,
      v41);
  v90 = v40->m_environment_probes._M_impl._M_finish - v40->m_environment_probes._M_impl._M_start;
  probe_objects._M_impl._M_start = 0;
  probe_objects._M_impl._M_finish = 0;
  probe_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  probe_objects._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)vostok::render::g_allocator.m_object,
    &probe_objects._M_impl,
    v90);
  v40->m_environment_probes_tree->cuboid_query(v40->m_environment_probes_tree, -1u, &view_frustum, &probe_objects);
  v62 = probe_objects._M_impl._M_start;
  v63 = (vostok::render::light *)probe_objects._M_impl._M_start;
  __x.m_object = (vostok::render::light *)probe_objects._M_impl._M_start;
  v103 = probe_objects._M_impl._M_finish;
  if ( probe_objects._M_impl._M_start != probe_objects._M_impl._M_finish )
  {
    do
    {
      v64 = *(char **)&m_object[4].m_inlined_in_fat;
      v65 = *(_DWORD *)(v63->m_reference_count + 36);
      if ( v64 == (char *)m_object[4].first_command )
      {
        v66 = (int)&v64[-m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags] >> 2;
        v67 = 1;
        v100 = 1;
        end = (vostok::render::ambient_volume **)v66;
        if ( v66 == 0x3FFFFFFF )
          goto LABEL_66;
        p_end = &end;
        if ( v66 <= 1 )
          p_end = (vostok::render::ambient_volume ***)&v100;
        v69 = (unsigned int)*p_end + v66;
        i = (const vostok::collision::object *const *)v69;
        if ( v69 > 0x3FFFFFFF || v69 < v66 )
        {
          v69 = 0x3FFFFFFF;
          i = (const vostok::collision::object *const *)0x3FFFFFFF;
        }
        v100 = v69;
        end = (vostok::render::ambient_volume **)1;
        v70 = &end;
        if ( v69 )
          v70 = (vostok::render::ambient_volume ***)&v100;
        v71 = *v70;
        v72 = vostok::render::g_allocator.m_object;
        v73 = 4 * (_DWORD)v71;
        if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v73 )
          v67 = 0;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v67;
        if ( v73 )
          v74 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v72->m_reconstruction_info_actuality_tick), v73);
        else
          v74 = 0;
        v75 = (unsigned __int8 *)m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags;
        v76 = v64 - (char *)v75;
        if ( v76 )
        {
          memmove(v74, v75, v76);
          v78 = (unsigned __int8 *)(v76 + v77);
        }
        else
        {
          v78 = v74;
        }
        *(_DWORD *)v78 = v65;
        v79 = v78 + 4;
        v80 = (void *)m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags;
        if ( v80 )
        {
          v81 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v81, v80);
        }
        m_object[4].first_command = (vostok::render::base_command *)&v74[4 * (_DWORD)i];
        v63 = __x.m_object;
        m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags = (unsigned int)v74;
        *(_DWORD *)&m_object[4].m_inlined_in_fat = v79;
      }
      else
      {
        *(_DWORD *)v64 = v65;
        *(_DWORD *)&m_object[4].m_inlined_in_fat += 4;
      }
      v63 = (vostok::render::light *)((char *)v63 + 4);
      __x.m_object = v63;
    }
    while ( v63 != (vostok::render::light *)v103 );
    v62 = probe_objects._M_impl._M_start;
  }
  if ( v62 )
    probe_objects._M_impl._M_end_of_storage.m_allocator->call_free(
      probe_objects._M_impl._M_end_of_storage.m_allocator,
      v62);
  v82 = render_scene;
  v83 = render_scene->m_ambient_volumes._M_impl._M_start;
  for ( end = (vostok::render::ambient_volume **)render_scene->m_ambient_volumes._M_impl._M_finish;
        v83 != (void **)end;
        ++v83 )
  {
    v84 = (char *)*v83;
    probe_objects = *(vostok::vectora<vostok::collision::object const *> *)((char *)*v83 + 76);
    v102 = *(_QWORD *)(v84 + 92);
    if ( vostok::math::cuboid::test_inexact(
           (vostok::math::cuboid *)&probe_objects,
           (const vostok::math::aabb *)&probe_objects) != intersection_outside )
    {
      v86 = (void **)HIDWORD(m_object[5].m_reconstruction_info_actuality_tick);
      if ( v86 == (void **)m_object[5].m_reconstruction_size )
      {
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
          v85,
          (int)&m_object[5].vostok::resources::resource_reconstruction_info,
          v86,
          v83,
          (const stlp_std::__true_type *)1,
          1,
          (bool)v92);
        v82 = render_scene;
      }
      else
      {
        *v86 = v84;
        HIDWORD(m_object[5].m_reconstruction_info_actuality_tick) += 4;
      }
    }
  }
  vostok::render::scene::select_models(
    v82,
    &thisa->m_context->m_vp,
    selection,
    (const vostok::math::float3 *)&thisa->m_context->m_view_pos,
    1u,
    0);
  vostok::render::scene::select_models(
    v82,
    &thisa->m_context->m_vp,
    (vostok::render::vector<vostok::render::render_surface_instance *> *)&m_object[4].m_construct_thread_id,
    (const vostok::math::float3 *)&thisa->m_context->m_view_pos,
    1u,
    1);
  if ( LODWORD(blend_alpha.z) )
  {
    v87 = selection;
    v91 = (vostok::render::render_surface_instance **)m_object[4].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
    v88 = selection->_M_impl._M_start;
    end = 0;
    stlp_std::random_shuffle<vostok::render::render_surface_instance * *,vostok::math::random32>(
      (vostok::math::random32 *)&end,
      (vostok::render::render_surface_instance **)v88,
      v91);
    if ( (unsigned int)(v87->_M_impl._M_finish - v87->_M_impl._M_start) > LODWORD(blend_alpha.z) )
    {
      end = 0;
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::resize(
        &v87->_M_impl,
        LODWORD(blend_alpha.z),
        (void *const *)&end);
    }
  }
}
