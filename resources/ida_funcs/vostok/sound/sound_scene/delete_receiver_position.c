void __thiscall vostok::sound::sound_scene::delete_receiver_position(
        vostok::sound::sound_scene *this,
        vostok::sound::atomic_half3 *pos)
{
  vostok::memory::delete_helper<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>,vostok::sound::atomic_half3>(
    this->m_receiver_positions_allocator.m_variable,
    &pos);
}
