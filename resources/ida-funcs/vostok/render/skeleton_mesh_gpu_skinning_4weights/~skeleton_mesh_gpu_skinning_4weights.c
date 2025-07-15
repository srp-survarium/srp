void __thiscall vostok::render::skeleton_mesh_gpu_skinning_4weights::~skeleton_mesh_gpu_skinning_4weights(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this)
{
  this->__vftable = (vostok::render::skeleton_mesh_gpu_skinning_4weights_vtbl *)&vostok::render::skeleton_mesh_gpu_skinning_4weights::`vftable';
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_vertex_buffer,
    (vostok::render::hw_buffer_pool *)this);
  vostok::render::render_surface::~render_surface(this);
}
