void __thiscall vostok::sound::sound_collection::~sound_collection(vostok::sound::sound_collection *this)
{
  this->__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_collection::`vftable';
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>>::clear(&this->m_sounds);
  this->__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
