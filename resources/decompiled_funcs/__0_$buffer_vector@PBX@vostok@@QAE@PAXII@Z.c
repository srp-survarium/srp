void __thiscall vostok::buffer_vector<void const *>::buffer_vector<void const *>(
        vostok::buffer_vector<void const *> *this,
        const void **buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  survarium::game_camera *v4; // ecx

  this->m_begin = buffer;
  v4 = (survarium::game_camera *)&buffer[live_count];
  this->m_end = (const void **)&v4->__vftable;
  survarium::weapon_user_dead_state::finalize(v4);
}
