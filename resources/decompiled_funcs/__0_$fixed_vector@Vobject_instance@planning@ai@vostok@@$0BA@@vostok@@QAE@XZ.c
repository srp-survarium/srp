void __thiscall vostok::fixed_vector<vostok::ai::planning::object_instance,16>::fixed_vector<vostok::ai::planning::object_instance,16>(
        vostok::fixed_vector<vostok::ai::planning::object_instance,16> *this)
{
  this->m_begin = (vostok::ai::planning::object_instance *)this->m_buffer;
  this->m_end = (vostok::ai::planning::object_instance *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
