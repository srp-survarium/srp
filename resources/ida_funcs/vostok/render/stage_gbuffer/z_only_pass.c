void __thiscall vostok::render::stage_gbuffer::z_only_pass(
        vostok::render::stage_gbuffer *this,
        unsigned int num_rendered)
{
  vostok::render::stage_gbuffer *v2; // ebp
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v3; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v4; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v5; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v6; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v7; // ecx
  void **M_finish; // esi
  vostok::render::render_surface_instance **v9; // eax
  void **v10; // eax
  void **v11; // esi
  vostok::render::render_surface_instance **v12; // eax
  void **v13; // eax
  void **v14; // esi
  void **M_start; // edi
  vostok::render::render_surface_instance **v16; // eax
  void **v17; // eax
  vostok::render::renderer_context *m_context; // eax
  vostok::render::grass_world *m_grass; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v21; // edx
  void *v22; // esi
  void **v23; // edx
  void *v24; // esi
  void **v25; // eax
  void *v26; // esi
  void **v27; // [esp-10h] [ebp-58h]
  void **v28; // [esp-10h] [ebp-58h]
  void **v29; // [esp-10h] [ebp-58h]
  float stencil_mask; // [esp+0h] [ebp-48h]
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *p_m_parent; // [esp+4h] [ebp-44h]
  bool v32; // [esp+8h] [ebp-40h]
  unsigned int v33; // [esp+Ch] [ebp-3Ch]
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_translucency_models; // [esp+18h] [ebp-30h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_skeletal_models; // [esp+24h] [ebp-24h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_static_models; // [esp+30h] [ebp-18h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_models; // [esp+3Ch] [ebp-Ch] BYREF

  v2 = (vostok::render::stage_gbuffer *)num_rendered;
  memset(&m_visible_models, 0, sizeof(m_visible_models));
  memset(&m_visible_static_models, 0, sizeof(m_visible_static_models));
  memset(&m_visible_skeletal_models, 0, sizeof(m_visible_skeletal_models));
  memset(&m_visible_translucency_models, 0, sizeof(m_visible_translucency_models));
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)this,
    (int)&m_visible_models,
    0x800u);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    v3,
    (int)&m_visible_static_models,
    0x400u);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    v4,
    (int)&m_visible_skeletal_models,
    0x400u);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    v5,
    (int)&m_visible_translucency_models,
    0x400u);
  p_m_parent = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&v2->m_context->m_scene_view.m_object[4].m_sub_fat.m_parent;
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    p_m_parent,
    (int)&m_visible_models,
    (unsigned int)p_m_parent);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    v6,
    (int)&m_visible_static_models,
    (unsigned int)&m_visible_models);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    v7,
    (int)&m_visible_skeletal_models,
    (unsigned int)&m_visible_models);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    &m_visible_models._M_impl,
    (int)&m_visible_translucency_models,
    (unsigned int)&m_visible_models);
  M_finish = m_visible_static_models._M_impl._M_finish;
  LOBYTE(num_rendered) = 0;
  v9 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_static_predicate>(
         (vostok::render::render_surface_instance **)m_visible_static_models._M_impl._M_start,
         (vostok::render::render_surface_instance **)m_visible_static_models._M_impl._M_finish);
  if ( v9 != (vostok::render::render_surface_instance **)M_finish )
  {
    v10 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_static_predicate>(
                     v9 + 1,
                     v9,
                     (vostok::render::render_surface_instance **)M_finish);
    if ( v10 != M_finish )
    {
      LOBYTE(num_rendered) = 0;
      v27 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, v10);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      m_visible_static_models._M_impl._M_finish = v27;
    }
  }
  v11 = m_visible_skeletal_models._M_impl._M_finish;
  LOBYTE(num_rendered) = 0;
  v12 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_skeletal_predicate>(
          (vostok::render::render_surface_instance **)m_visible_skeletal_models._M_impl._M_start,
          (vostok::render::render_surface_instance **)m_visible_skeletal_models._M_impl._M_finish);
  if ( v12 != (vostok::render::render_surface_instance **)v11 )
  {
    v13 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_skeletal_predicate>(
                     v12 + 1,
                     v12,
                     (vostok::render::render_surface_instance **)v11);
    if ( v13 != v11 )
    {
      LOBYTE(num_rendered) = 0;
      v28 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v11, v11, v13);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      m_visible_skeletal_models._M_impl._M_finish = v28;
    }
  }
  v14 = m_visible_translucency_models._M_impl._M_finish;
  M_start = m_visible_translucency_models._M_impl._M_start;
  LOBYTE(num_rendered) = 0;
  v16 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_translucency_predicate>(
          (vostok::render::render_surface_instance **)m_visible_translucency_models._M_impl._M_start,
          (vostok::render::render_surface_instance **)m_visible_translucency_models._M_impl._M_finish);
  if ( v16 != (vostok::render::render_surface_instance **)v14 )
  {
    v17 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_translucency_predicate>(
                     v16 + 1,
                     v16,
                     (vostok::render::render_surface_instance **)v14);
    if ( v17 != v14 )
    {
      LOBYTE(num_rendered) = 0;
      v29 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v14, v14, v17);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      m_visible_translucency_models._M_impl._M_finish = v29;
      M_start = m_visible_translucency_models._M_impl._M_start;
    }
  }
  num_rendered = 0;
  vostok::render::stage_gbuffer::render_models(&m_visible_static_models, v2, 0, &num_rendered, 1);
  vostok::render::stage_gbuffer::render_models(&m_visible_skeletal_models, v2, 0, &num_rendered, 1);
  vostok::render::stage_gbuffer::render_models(&m_visible_translucency_models, v2, 0, &num_rendered, 1);
  m_context = v2->m_context;
  m_grass = m_context->m_scene->m_grass;
  if ( m_grass )
  {
    stencil_mask = 1000000.0;
    vostok::render::grass_world::render(
      m_grass,
      (vostok::render::renderer_context *)m_grass,
      (const vostok::math::float3 *)m_context,
      (vostok::render::enum_render_stage_type)&m_context->m_view_pos,
      0,
      COERCE_CONST_FLOAT(8),
      SLOBYTE(stencil_mask),
      0,
      v32,
      v33);
  }
  vostok::render::stage_gbuffer::render_particles(
    (vostok::render::stage_gbuffer *)m_grass,
    (vostok::particle::render_particle_emitter_instance *const *)v2,
    1);
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v21 = m_visible_skeletal_models._M_impl._M_start;
  if ( m_visible_skeletal_models._M_impl._M_start )
  {
    v22 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v22, v21);
  }
  v23 = m_visible_static_models._M_impl._M_start;
  if ( m_visible_static_models._M_impl._M_start )
  {
    v24 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v24, v23);
  }
  v25 = m_visible_models._M_impl._M_start;
  if ( m_visible_models._M_impl._M_start )
  {
    v26 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v26, v25);
  }
}
