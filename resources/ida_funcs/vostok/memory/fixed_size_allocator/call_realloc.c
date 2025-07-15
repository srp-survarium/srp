void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_realloc(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        survarium::game_camera *pointer,
        unsigned int new_size)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(pointer);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_realloc(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        void *pointer,
        survarium::game_camera *new_size)
{
  survarium::weapon_user_dead_state::finalize(new_size);
  JUMPOUT(0x4F782);
}
