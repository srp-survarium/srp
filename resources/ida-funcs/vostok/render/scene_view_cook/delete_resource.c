void __thiscall vostok::render::scene_view_cook::delete_resource(
        vostok::render::scene_view_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *v2; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::render::vector<vostok::render::scene_view *> *p_m_views; // ebp
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  void **v6; // ecx
  vostok::render::grass_render_model *m_object; // edi
  char *v8; // esi
  char *v9; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  v2 = resource;
  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views._M_impl._M_finish;
  p_m_views = &vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views;
  v5 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&resource);
  if ( v5 != M_finish )
  {
    v6 = p_m_views->_M_impl._M_finish;
    if ( &v5[1] != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v6 )
    {
      LOBYTE(resource) = 0;
      stlp_std::priv::__copy_ptrs<void * *,void * *>((void **)&v5[1].m_object, v6, (void **)&v5->m_object);
    }
    --p_m_views->_M_impl._M_finish;
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( v2 )
  {
    v8 = __RTCastToVoid((void **)&v2->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))v2->~vostok::resources::resource_base)(v2, 0);
    if ( v8 )
    {
      v9 = v8;
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
    }
  }
}
