void __thiscall vostok::ai::planning::goal_selector::~goal_selector(vostok::ai::planning::goal_selector *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal_specificator>(
    v1,
    &this->m_specificator);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
