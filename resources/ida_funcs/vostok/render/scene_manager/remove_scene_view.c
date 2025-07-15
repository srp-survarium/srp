void __thiscall vostok::render::scene_manager::remove_scene_view(
        vostok::render::scene_manager *this,
        vostok::render::scene_manager *in_scene_view,
        vostok::render::scene_view *in_scene_viewa)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax

  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)in_scene_view->m_views._M_impl._M_finish;
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)in_scene_view->m_views._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&in_scene_viewa);
  if ( v4 != M_finish )
  {
    if ( &v4[1] != M_finish )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(
        (void **)&v4[1].m_object,
        (void **)&M_finish->m_object,
        (void **)&v4->m_object);
    --in_scene_view->m_views._M_impl._M_finish;
  }
}
