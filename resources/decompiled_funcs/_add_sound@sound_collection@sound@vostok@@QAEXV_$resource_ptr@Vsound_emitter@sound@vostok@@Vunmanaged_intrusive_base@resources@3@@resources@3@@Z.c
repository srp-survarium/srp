void __thiscall vostok::sound::sound_collection::add_sound(
        vostok::sound::sound_collection *this,
        vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> sound)
{
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_sounds,
    &sound);
  this->m_old_address = (unsigned __int64)this->get_sound_propagator_emitter(this);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&sound);
}
