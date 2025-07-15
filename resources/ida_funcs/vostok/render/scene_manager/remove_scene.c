void __thiscall vostok::render::scene_manager::remove_scene(
        vostok::render::scene_manager *this,
        vostok::render::scene_manager *in_scene,
        vostok::render::scene *in_scenea)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax

  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)in_scene->m_scenes._M_impl._M_finish;
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)in_scene->m_scenes._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&in_scenea);
  if ( v4 != M_finish )
  {
    if ( &v4[1] != M_finish )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(
        (void **)&v4[1].m_object,
        (void **)&M_finish->m_object,
        (void **)&v4->m_object);
    --in_scene->m_scenes._M_impl._M_finish;
  }
}
