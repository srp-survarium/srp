bool __userpurge survarium::free_fly_camera::mouse_event_present@<al>(
        survarium::free_fly_camera *this@<ecx>,
        int a2@<eax>,
        int e)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v3; // esi

  v3 = *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 116);
  return stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 112),
           v3,
           (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&e) != v3;
}
