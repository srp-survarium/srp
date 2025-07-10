void __thiscall vostok::network_core::handler_allocator::handler_allocator(
        vostok::network_core::handler_allocator *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->in_use_ = 0;
}
