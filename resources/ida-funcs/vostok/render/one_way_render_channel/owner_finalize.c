void __usercall vostok::render::one_way_render_channel::owner_finalize(
        vostok::render::one_way_render_channel *this@<ecx>,
        vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8> > *a2@<esi>)
{
  vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_next_frame_commands_queue; // ebx
  vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8> > *p_m_channel; // edi
  vostok::render::base_command *v4; // eax
  vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8> > *v5; // [esp-4h] [ebp-Ch]

  p_m_next_frame_commands_queue = &this->m_next_frame_commands_queue;
  p_m_channel = &this->m_channel;
  if ( this->m_next_frame_commands_queue.m_first )
  {
    v5 = a2;
    do
    {
      v4 = vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(p_m_next_frame_commands_queue);
      if ( v4 != p_m_channel->m_forward_queue.m_tail )
        vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8>>::delete_value(
          v4,
          v5);
    }
    while ( p_m_next_frame_commands_queue->m_first );
    a2 = v5;
  }
  vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8>>::owner_finalize(
    (vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8> > *)this,
    (int)p_m_channel,
    a2);
}
