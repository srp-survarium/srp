void __thiscall survarium::bullet_manager::play_sound_impl(
        survarium::bullet_manager *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *sound,
        const vostok::math::float3 *position)
{
  this->m_engine->play_sound(this->m_engine, sound, position);
}
