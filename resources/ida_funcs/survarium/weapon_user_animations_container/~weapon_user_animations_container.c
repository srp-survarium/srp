void __thiscall survarium::weapon_user_animations_container::~weapon_user_animations_container(
        survarium::weapon_user_animations_container *this)
{
  survarium::game_camera *v1; // ecx

  `vector destructor iterator'(
    (char *)this->m_jump_animations,
    4u,
    200,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_sprint_animations,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_aimed_crouch_hands_only_animations,
    4u,
    12,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_aimed_crouch_animations,
    4u,
    54,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_crouch_hands_only_animations,
    4u,
    12,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_crouch_animations,
    4u,
    54,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_aimed_stand_hands_only_animations,
    4u,
    12,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_aimed_stand_animations,
    4u,
    54,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_stand_hands_only_animations,
    4u,
    12,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  `vector destructor iterator'(
    (char *)this->m_stand_animations,
    4u,
    54,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
