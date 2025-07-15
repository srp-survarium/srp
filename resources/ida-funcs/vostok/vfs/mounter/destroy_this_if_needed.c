void __thiscall vostok::vfs::mounter::destroy_this_if_needed(vostok::vfs::mounter *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::vfs::mounter *this_ptr; // [esp+18h] [ebp-4h] BYREF

  if ( this->m_args.submount_type == submount_type_subfat && !this->m_args.synchronous_device )
  {
    this_ptr = this;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
      v1,
      (vostok::sound::sound_order **)&this_ptr);
  }
}
