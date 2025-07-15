void __thiscall vostok::vfs::async_callbacks_data::delete_this(vostok::vfs::async_callbacks_data *this)
{
  vostok::memory::base_allocator *v1; // eax

  vostok::vfs::async_callbacks_data::~async_callbacks_data(this);
  survarium::weapon_user_dead_state::finalize(0);
  if ( this )
    vostok::memory::base_allocator::free_impl(v1, this);
}
