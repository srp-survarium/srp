void __userpurge vostok::render::debug::renderer::draw_lines(
        const unsigned __int16 *pairs@<ecx>,
        unsigned int pair_count@<eax>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::float4x4 *matrix,
        const float *vertices,
        vostok::buffer_vector<vostok::render::vertex_colored> *vertex_count,
        const vostok::math::color *color,
        bool use_depth)
{
  unsigned int v9; // eax
  const unsigned __int16 *v10; // ebx
  void *v11; // esp
  int v12; // eax
  void *v13; // esp
  vostok::render::vertex_colored *m_begin; // eax
  vostok::render::vertex_colored *m_end; // edx
  float *v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float y; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  unsigned int m_value; // edi
  vostok::render::debug::draw_lines_command *v24; // esi
  __int32 v25; // eax
  vostok::render::one_way_render_channel *m_channel; // ecx
  bool v27; // zf
  _WORD v28[10]; // [esp+0h] [ebp-3Ch] BYREF
  __int64 v29; // [esp+14h] [ebp-28h]
  __int64 v30; // [esp+1Ch] [ebp-20h]
  float v31; // [esp+24h] [ebp-18h]
  vostok::buffer_vector<unsigned short> indices; // [esp+28h] [ebp-14h] BYREF
  vostok::buffer_vector<vostok::render::vertex_colored> size; // [esp+30h] [ebp-Ch] BYREF

  v9 = 2 * pair_count;
  v10 = &pairs[v9];
  v11 = alloca(v9 * 2);
  indices.m_begin = v28;
  indices.m_end = &v28[(int)(v9 * 2) >> 1];
  if ( pairs != &pairs[v9] )
  {
    v12 = (char *)v28 - (char *)pairs;
    do
    {
      if ( (const unsigned __int16 *)((char *)pairs + v12) )
        *(const unsigned __int16 *)((char *)pairs + v12) = *pairs;
      ++pairs;
    }
    while ( pairs != v10 );
  }
  v13 = alloca(16 * (_DWORD)vertex_count);
  size.m_begin = (vostok::render::vertex_colored *)v28;
  size.m_end = (vostok::render::vertex_colored *)v28;
  vostok::buffer_vector<vostok::render::vertex_colored>::resize(vertex_count, &size);
  m_begin = size.m_begin;
  m_end = size.m_end;
  if ( size.m_begin != size.m_end )
  {
    v16 = (float *)(vertices + 2);
    do
    {
      v17 = *v16;
      v18 = *(v16 - 1);
      v19 = *(v16 - 2);
      y = matrix->k.y;
      *(float *)&v30 = (float)((float)((float)(*v16 * matrix->k.x) + (float)(v18 * matrix->j.x))
                             + (float)(v19 * matrix->i.x))
                     + matrix->c.x;
      v21 = matrix->i.y * v19;
      v22 = v19 * matrix->i.z;
      *((float *)&v30 + 1) = (float)((float)(v21 + (float)(y * v17)) + (float)(matrix->j.y * v18)) + matrix->c.y;
      v31 = (float)((float)((float)(matrix->k.z * v17) + (float)(matrix->j.z * v18)) + v22) + matrix->c.z;
      *(float *)&v29 = v31;
      m_value = color->m_value;
      *(_QWORD *)&m_begin->position.x = v30;
      HIDWORD(v29) = m_value;
      *(_QWORD *)&m_begin->position.elements[2] = v29;
      ++m_begin;
      v16 += 3;
    }
    while ( m_begin != m_end );
  }
  v24 = (vostok::render::debug::draw_lines_command *)this->m_allocator->call_malloc(this->m_allocator, 124);
  if ( v24 )
    vostok::render::debug::draw_lines_command::draw_lines_command(
      v24,
      &size,
      use_depth,
      scene,
      this->m_render_engine_world,
      this->m_allocator,
      &indices);
  else
    v25 = 0;
  m_channel = this->m_channel;
  v27 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
  *(_DWORD *)(v25 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, v25);
  m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v25;
  if ( v27 )
    SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
}
