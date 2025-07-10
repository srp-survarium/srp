void __userpurge vostok::render::debug::renderer::draw_line(
        const vostok::math::float3 *start_point@<ecx>,
        const vostok::math::float3 *end_point@<eax>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::color *color,
        bool use_depth)
{
  float x; // xmm3_4
  float v9; // xmm2_4
  __int64 v10; // xmm0_8
  float v11; // edx
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::render::debug::draw_lines_command *v13; // esi
  __int32 v14; // eax
  vostok::render::one_way_render_channel *m_channel; // ecx
  bool v16; // zf
  unsigned __int16 indices[2]; // [esp+Ch] [ebp-54h] BYREF
  __int64 v18; // [esp+10h] [ebp-50h]
  float z; // [esp+18h] [ebp-48h]
  __int64 v20; // [esp+1Ch] [ebp-44h]
  vostok::math::cuboid *z_low; // [esp+24h] [ebp-3Ch]
  vostok::math::aabb aabb; // [esp+28h] [ebp-38h] BYREF
  vostok::render::vertex_colored vertices[2]; // [esp+40h] [ebp-20h] BYREF

  x = end_point->x;
  v9 = start_point->x;
  if ( start_point->x <= end_point->x )
    *(float *)&v20 = end_point->x;
  else
    *(float *)&v20 = start_point->x;
  if ( start_point->y <= end_point->y )
    HIDWORD(v20) = LODWORD(end_point->y);
  else
    HIDWORD(v20) = LODWORD(start_point->y);
  if ( start_point->z <= end_point->z )
    z_low = (vostok::math::cuboid *)LODWORD(end_point->z);
  else
    z_low = (vostok::math::cuboid *)LODWORD(start_point->z);
  if ( x <= v9 )
    *(float *)&v18 = x;
  else
    *(float *)&v18 = v9;
  if ( end_point->y <= start_point->y )
    HIDWORD(v18) = LODWORD(end_point->y);
  else
    HIDWORD(v18) = LODWORD(start_point->y);
  if ( end_point->z <= start_point->z )
    z = end_point->z;
  else
    z = start_point->z;
  *(_QWORD *)&aabb.min.x = v18;
  aabb.min.z = z;
  *(_QWORD *)&aabb.max.x = v20;
  LODWORD(aabb.max.z) = z_low;
  if ( vostok::math::cuboid::test_inexact(z_low, this->frustum.m_planes, &aabb) != 2 )
  {
    v10 = *(_QWORD *)&start_point->x;
    v11 = end_point->z;
    vertices[0].position.z = start_point->z;
    vertices[0].color = *color;
    vertices[1].color.m_value = vertices[0].color.m_value;
    *(_QWORD *)&vertices[0].position.x = v10;
    indices[1] = 1;
    m_allocator = this->m_allocator;
    indices[0] = 0;
    *(_QWORD *)&vertices[1].position.x = *(_QWORD *)&end_point->x;
    vertices[1].position.z = v11;
    v13 = (vostok::render::debug::draw_lines_command *)m_allocator->call_malloc(m_allocator, 124u);
    if ( v13 )
      vostok::render::debug::draw_lines_command::draw_lines_command(
        v13,
        (const vostok::render::vertex_colored (*)[2])vertices,
        use_depth,
        scene,
        this->m_render_engine_world,
        this->m_allocator,
        (const unsigned __int16 (*)[2])indices);
    else
      v14 = 0;
    m_channel = this->m_channel;
    v16 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
    *(_DWORD *)(v14 + 4) = 0;
    _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, v14);
    m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v14;
    if ( v16 )
      SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
  }
}
