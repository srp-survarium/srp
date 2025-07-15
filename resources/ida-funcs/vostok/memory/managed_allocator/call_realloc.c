void __thiscall vostok::memory::managed_allocator::call_realloc(
        vostok::memory::managed_allocator *this,
        void *pointer,
        survarium::game_camera *new_size)
{
  survarium::weapon_user_dead_state::finalize(new_size);
  JUMPOUT(0x666FB2);
}
