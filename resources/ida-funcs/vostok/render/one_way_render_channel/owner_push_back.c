void __usercall vostok::render::one_way_render_channel::owner_push_back(
        vostok::render::one_way_render_channel *this@<edx>,
        vostok::render::base_command *command@<eax>)
{
  vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8> > *p_m_channel; // ecx
  bool v3; // [esp+Fh] [ebp-1h]

  v3 = this->m_channel.m_forward_queue.m_tail->next == 0;
  command->next = 0;
  p_m_channel = &this->m_channel;
  while ( _InterlockedCompareExchange(
            (volatile signed __int32 *)&p_m_channel->m_forward_queue.m_head->next,
            (signed __int32)command,
            0) )
    ;
  _InterlockedExchange((volatile __int32 *)p_m_channel, (__int32)command);
  if ( v3 )
    SetEvent(*(HANDLE *)this->m_wait_form_command_event.m_event.m_event);
}
