void __thiscall vostok::sound::composite_sound::~composite_sound(vostok::sound::composite_sound *this)
{
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::composite_sound_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  vostok::buffer_vector<stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int>>>::clear(&this->m_collection);
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::composite_sound_vtbl *)&vostok::sound::sound_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
