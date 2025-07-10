void __userpurge vostok::render::engine::world::update_skeleton(
        const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v@<ecx>,
        vostok::math::float4x4 *matrices@<eax>,
        vostok::render::engine::world *this,
        unsigned int count)
{
  vostok::render::skeleton_render_model_instance::update_render_matrices(
    (unsigned int)this,
    (vostok::render::skeleton_render_model_instance *)v->m_object,
    matrices);
}
