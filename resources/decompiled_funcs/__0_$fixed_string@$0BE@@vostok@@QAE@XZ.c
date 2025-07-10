void __thiscall vostok::fixed_string<20>::fixed_string<20>(vostok::fixed_string<20> *this)
{
  survarium::game_camera *v1; // ecx
  _DWORD *v2; // eax
  unsigned int max_count; // [esp+Ch] [ebp-4h] BYREF

  max_count = 20;
  vostok::buffer_string::buffer_string(this, this->m_buffer, &max_count);
  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v2 )
    this->m_buffer[0] = 0;
}
