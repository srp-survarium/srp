void __userpurge vostok::render::scene::update_tracer(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        const vostok::math::float4x4 *instance,
        const vostok::math::float4x4 *new_transform)
{
  qmemcpy(
    &stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
       *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 840),
       *(vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 844),
       (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this)->m_object->movie,
    instance,
    0x40u);
}
