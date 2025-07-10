void __userpurge vostok::render::hw_hiz_occlusion_manager::render_debug(
        const vostok::math::float3 *in_bounds@<ecx>,
        unsigned int in_num_bounds_and_results@<eax>,
        vostok::render::hw_hiz_occlusion_manager *this,
        vostok::render::renderer_context *in_context,
        const unsigned __int8 *in_results)
{
  vostok::render::hw_hiz_occlusion_manager *v5; // ebx
  const vostok::math::float4x4 *v7; // eax
  vostok::render::res_effect *v8; // ecx
  _DWORD *v9; // eax
  vostok::render::shader_constant_host *m_draw_color_parameter; // eax
  vostok::render::sphere_occluder_geometry *m_buffer_index; // ecx
  const char *m_conflicted_key_name; // esi
  unsigned int v13; // [esp+10h] [ebp-D8h]
  float scale; // [esp+14h] [ebp-D4h]
  char src_ptr[4]; // [esp+18h] [ebp-D0h] BYREF
  int v16; // [esp+1Ch] [ebp-CCh]
  int v17; // [esp+20h] [ebp-C8h]
  int v18; // [esp+24h] [ebp-C4h]
  vostok::math::float4x4 dst; // [esp+28h] [ebp-C0h] BYREF
  vostok::math::float4x4 m; // [esp+68h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+A8h] [ebp-40h] BYREF

  v5 = this;
  if ( this->m_hiz_occlusion_effect.m_object && in_num_bounds_and_results )
  {
    *(_DWORD *)src_ptr = 1008981770;
    v16 = 1008981770;
    v17 = 1008981770;
    v18 = 0;
    v13 = in_num_bounds_and_results;
    do
    {
      scale = in_bounds[1].x;
      memset((int)&dst, 0, sizeof(dst));
      dst.i.x = scale;
      dst.j.y = scale;
      dst.k.z = scale;
      LODWORD(dst.c.w) = clear_value;
      v7 = vostok::math::create_translation(&result, in_bounds);
      vostok::math::mul4x3(&m, &dst, v7);
      vostok::render::renderer_context::set_w((int)in_context, &m, in_context);
      v9 = &v5->m_hiz_occlusion_effect.m_object->__vftable;
      if ( (unsigned int)((v9[71] - v9[70]) >> 2) > 1 )
      {
        v9[69] = 1;
        vostok::render::res_effect::apply_pass(v8, (int)v9);
      }
      m_draw_color_parameter = v5->m_draw_color_parameter;
      m_buffer_index = (vostok::render::sphere_occluder_geometry *)m_draw_color_parameter->m_update_markers[1];
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( m_buffer_index == *((vostok::render::sphere_occluder_geometry **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                             + 573) )
      {
        m_buffer_index = (vostok::render::sphere_occluder_geometry *)m_draw_color_parameter->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != (vostok::render::sphere_occluder_geometry *)0xFFFF )
        {
          vostok::render::shader_constant_buffer::set_memory(
            m_draw_color_parameter->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_draw_color_parameter->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * (_DWORD)m_buffer_index),
            src_ptr);
          v5 = this;
        }
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::sphere_occluder_geometry::render(m_buffer_index);
      in_bounds = (const vostok::math::float3 *)((char *)in_bounds + 16);
      --v13;
    }
    while ( v13 );
  }
}
