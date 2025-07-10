void __thiscall vostok::fixed_vector<vostok::ai::planning::plan_item,32>::fixed_vector<vostok::ai::planning::plan_item,32>(
        vostok::fixed_vector<vostok::ai::planning::plan_item,32> *this)
{
  this->m_begin = (vostok::ai::planning::plan_item *)this->m_buffer;
  this->m_end = (vostok::ai::planning::plan_item *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
