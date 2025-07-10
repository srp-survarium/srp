void __userpurge vostok::render::debug::renderer::draw_cross(
        float *a1@<eax>,
        unsigned int *a2@<ecx>,
        float a3@<xmm5>,
        vostok::render::debug::renderer *const this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        bool use_depth)
{
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  __int64 v9; // xmm6_8
  unsigned int v10; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::render::debug::draw_lines_command *v12; // esi
  __int32 v13; // eax
  vostok::render::one_way_render_channel *m_channel; // ecx
  bool v15; // zf
  unsigned __int16 indices[6]; // [esp+8h] [ebp-6Ch] BYREF
  vostok::render::vertex_colored vertices[6]; // [esp+14h] [ebp-60h] BYREF

  v6 = *a1;
  v7 = a1[2];
  *(float *)indices = *a1 - a3;
  v8 = a1[1];
  *(float *)&indices[2] = v8;
  *(_QWORD *)&vertices[0].position.x = *(_QWORD *)indices;
  *(float *)&indices[2] = v8;
  *(float *)indices = v6 + a3;
  *(_QWORD *)&vertices[1].position.x = *(_QWORD *)indices;
  *(float *)indices = v6;
  *(float *)&indices[2] = v8 - a3;
  v9 = *(_QWORD *)indices;
  *(float *)&indices[2] = v8 + a3;
  *(float *)&indices[4] = v7;
  *(float *)indices = v6;
  vertices[0].position.z = v7;
  v10 = *a2;
  vertices[1].position.z = v7;
  *(_QWORD *)&vertices[3].position.x = *(_QWORD *)indices;
  vertices[2].position.z = v7;
  vertices[3].position.z = v7;
  *(float *)&indices[4] = v7 + a3;
  vertices[4].position.z = v7 - a3;
  *(_QWORD *)indices = __PAIR64__(LODWORD(v8), LODWORD(v6));
  vertices[0].color.m_value = v10;
  vertices[1].color.m_value = v10;
  vertices[2].color.m_value = v10;
  vertices[3].color.m_value = v10;
  vertices[4].color.m_value = v10;
  vertices[5].position.z = v7 + a3;
  vertices[5].color.m_value = v10;
  *(_QWORD *)&vertices[4].position.x = __PAIR64__(LODWORD(v8), LODWORD(v6));
  indices[1] = 1;
  indices[0] = 0;
  indices[2] = 2;
  indices[4] = 4;
  m_allocator = this->m_allocator;
  *(_QWORD *)&vertices[2].position.x = v9;
  *(_QWORD *)&vertices[5].position.x = __PAIR64__(LODWORD(v8), LODWORD(v6));
  indices[3] = 3;
  indices[5] = 5;
  v12 = (vostok::render::debug::draw_lines_command *)m_allocator->call_malloc(m_allocator, 124u);
  if ( v12 )
    vostok::render::debug::draw_lines_command::draw_lines_command(
      v12,
      (const vostok::render::vertex_colored (*)[6])vertices,
      use_depth,
      scene,
      this->m_render_engine_world,
      this->m_allocator,
      (const unsigned __int16 (*)[6])indices);
  else
    v13 = 0;
  m_channel = this->m_channel;
  v15 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
  *(_DWORD *)(v13 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, v13);
  m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v13;
  if ( v15 )
    SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
}
