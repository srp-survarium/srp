void __thiscall vostok::ai::brain_unit::get_available_sounds(
        vostok::ai::brain_unit *this,
        vostok::fixed_vector<vostok::ai::sound_item const *,32> *destination)
{
  vostok::sound::encoded_sound_interface *(__thiscall *v3)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+Ch] [ebp-4h]

  if ( this->m_behaviour.m_object )
    v3 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v3 = 0;
  if ( v3 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::ai::behaviour::get_available_sounds(this->m_behaviour.m_object, destination);
  }
}
