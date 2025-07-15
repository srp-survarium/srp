void __thiscall vostok::render::scene_cook::delete_resource(
        vostok::render::scene_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *v2; // ebp
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  void ***p_M_finish; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::render::grass_render_model *m_object; // edi
  char *v7; // esi
  char *v8; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  v2 = resource;
  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes._M_impl._M_finish;
  p_M_finish = &vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes._M_impl._M_finish;
  v5 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&resource);
  if ( v5 != M_finish )
  {
    if ( &v5[1] != M_finish )
    {
      LOBYTE(resource) = 0;
      stlp_std::priv::__copy_ptrs<void * *,void * *>(
        (void **)&v5[1].m_object,
        (void **)&M_finish->m_object,
        (void **)&v5->m_object);
    }
    --*p_M_finish;
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( v2 )
  {
    v7 = __RTCastToVoid((void **)&v2->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))v2->~vostok::resources::resource_base)(v2, 0);
    if ( v7 )
    {
      v8 = v7;
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
    }
  }
}
