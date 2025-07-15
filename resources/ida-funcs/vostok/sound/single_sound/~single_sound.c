void __thiscall vostok::sound::single_sound::~single_sound(vostok::sound::single_sound *this)
{
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::single_sound_vtbl *)&vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_spl);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_spl_config);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_rms);
  vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed((vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *)&this->m_encoded_sound);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_encoded_sound);
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::single_sound_vtbl *)&vostok::sound::sound_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
