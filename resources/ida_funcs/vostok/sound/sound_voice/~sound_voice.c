void __thiscall vostok::sound::sound_voice::~sound_voice(vostok::sound::sound_voice *this)
{
  vostok::sound::sound_world::free_voice(this->m_world_user->m_owner_world, this->m_voice);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_target_sound_quality);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_current_sound_quality);
}
