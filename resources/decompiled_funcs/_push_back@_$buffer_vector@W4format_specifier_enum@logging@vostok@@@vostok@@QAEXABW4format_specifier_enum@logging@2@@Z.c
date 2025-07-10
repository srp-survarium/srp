void __thiscall vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        vostok::buffer_vector<void const *> *this,
        const void **value)
{
  const void **v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (const void **)operator new(4u, this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}
