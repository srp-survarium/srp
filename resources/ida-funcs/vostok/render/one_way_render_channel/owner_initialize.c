void __thiscall vostok::render::one_way_render_channel::owner_initialize(vostok::render::one_way_render_channel *this)
{
  vostok::memory::base_allocator *m_owner_allocator; // edi
  char *v3; // eax
  int v4; // eax
  vostok::memory::base_allocator *v5; // ecx
  vostok::memory::base_allocator *v6; // edi
  char *v7; // eax
  int v8; // eax
  vostok::render::base_command *v9; // edi
  vostok::render::base_command *v10; // [esp+28h] [ebp-4h]

  m_owner_allocator = this->m_owner_allocator;
  v3 = type_info::raw_name(&vostok::render::one_way_render_channel::null_render_command `RTTI Type Descriptor');
  v4 = (int)m_owner_allocator->call_malloc(
              m_owner_allocator,
              88u,
              v3,
              "vostok::render::one_way_render_channel::owner_initialize",
              "c:\\survarium.deploy\\sources\\vostok/render/facade/one_way_render_channel_inline.h",
              27u);
  if ( v4 )
  {
    v5 = this->m_owner_allocator;
    *(_DWORD *)(v4 + 84) = 0;
    *(_DWORD *)(v4 + 4) = v5;
    *(_BYTE *)(v4 + 16) = 0;
    *(_BYTE *)(v4 + 17) = 1;
    *(_DWORD *)v4 = &vostok::render::one_way_render_channel::null_render_command::`vftable';
    v10 = (vostok::render::base_command *)v4;
  }
  else
  {
    v10 = 0;
  }
  v6 = this->m_owner_allocator;
  v7 = type_info::raw_name(&vostok::render::one_way_render_channel::null_render_command `RTTI Type Descriptor');
  v8 = (int)v6->call_malloc(
              v6,
              88u,
              v7,
              "vostok::render::one_way_render_channel::owner_initialize",
              "c:\\survarium.deploy\\sources\\vostok/render/facade/one_way_render_channel_inline.h",
              26u);
  if ( v8 )
  {
    *(_DWORD *)(v8 + 4) = this->m_owner_allocator;
    *(_BYTE *)(v8 + 16) = 0;
    *(_BYTE *)(v8 + 17) = 1;
    *(_DWORD *)(v8 + 84) = 0;
    *(_DWORD *)v8 = &vostok::render::one_way_render_channel::null_render_command::`vftable';
    v9 = (vostok::render::base_command *)v8;
  }
  else
  {
    v9 = 0;
  }
  v10->next = 0;
  this->m_channel.m_forward_queue.m_tail = v10;
  this->m_channel.m_forward_queue.m_head = v10;
  _InterlockedExchange(&this->m_channel.m_backward_queue.m_pop_thread_id, GetCurrentThreadId());
  v9->next = 0;
  this->m_channel.m_backward_queue.m_tail = v9;
  this->m_channel.m_backward_queue.m_head = v9;
}
