const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::encoded_sound_with_qualities::get_encoded_sound(
        vostok::sound::encoded_sound_with_qualities *this)
{
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 1;
        !(this->m_qualities[i].m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0);
        --i )
  {
    ;
  }
  this->m_current_quality = i;
  return &this->m_qualities[i];
}
