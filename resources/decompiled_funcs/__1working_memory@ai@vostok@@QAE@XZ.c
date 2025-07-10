void __thiscall vostok::ai::working_memory::~working_memory(vostok::ai::working_memory *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_allocator);
  boost::function1<void,vostok::ai::game_object const &>::clear(&this->m_subscription.m_subscription_callback.boost::function1<void,vostok::ai::game_object const &>);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_subscription);
  `vector destructor iterator'(
    (char *)this,
    0x30u,
    6,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
