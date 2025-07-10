const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::encoded_sound_with_qualities::dbg_get_encoded_sound(
        vostok::sound::encoded_sound_with_qualities *this,
        unsigned int quality)
{
  vostok::sound::encoded_sound_interface *(__thiscall *v4)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_qualities[quality].m_object )
    v4 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v4 = 0;
  if ( v4 )
  {
    this->m_current_quality = quality;
    return &this->m_qualities[quality];
  }
  else
  {
    for ( i = 1;
          !(this->m_qualities[i].m_object
          ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
          : 0);
          --i )
    {
      ;
    }
    this->m_current_quality = quality;
    return &this->m_qualities[i];
  }
}
