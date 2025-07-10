void __thiscall vostok::vfs::async_link_helper::delete_this(vostok::vfs::async_link_helper *this)
{
  vostok::memory::base_allocator *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->allocator);
  if ( this )
    vostok::memory::base_allocator::free_impl(v1, this);
}
