vostok::sound::encoded_sound_interface *__thiscall vostok::configs::binary_config_value::key(
        vostok::configs::binary_config_value *this)
{
  return vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->id);
}
