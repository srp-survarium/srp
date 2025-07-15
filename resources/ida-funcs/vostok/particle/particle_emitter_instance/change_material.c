void __thiscall vostok::particle::particle_emitter_instance::change_material(
        vostok::particle::particle_emitter_instance *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *material)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_material,
    material);
  if ( this->m_render_instance )
    this->m_render_instance->change_material(this->m_render_instance, &this->m_material);
}
