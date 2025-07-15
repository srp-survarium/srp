void __usercall vostok::particle::particle_emitter_instance::change_material(
        vostok::particle::particle_emitter_instance *this@<esi>,
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *material@<edi>)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    material,
    &this->m_material);
  if ( this->m_render_instance )
    this->m_render_instance->change_material(this->m_render_instance, &this->m_material);
}
