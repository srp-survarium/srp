void __thiscall vostok::animation::mixing::animation_interval::animation_interval(
        vostok::animation::mixing::animation_interval *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation,
        float start_time,
        float length)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &this->m_animation,
    animation);
  this->m_start_time = start_time;
  this->m_length = length;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
