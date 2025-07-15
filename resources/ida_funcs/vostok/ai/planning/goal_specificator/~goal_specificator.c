void __thiscall vostok::ai::planning::goal_specificator::~goal_specificator(
        vostok::ai::planning::goal_specificator *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_planner>(
    v1,
    &this->m_planner);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
