void __thiscall vostok::render::one_way_render_channel::owner_finalize(vostok::render::one_way_render_channel *this)
{
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_finalize<vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>>(
    &this->m_channel,
    &this->m_next_frame_commands_queue);
}
