void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_realloc(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        survarium::game_camera *pointer,
        unsigned int new_size)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(pointer);
}
