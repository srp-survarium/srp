void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::buffer_vector<vostok::resources::creation_request>(
        vostok::buffer_vector<vostok::resources::creation_request> *this,
        vostok::resources::creation_request *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
}
