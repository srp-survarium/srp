void __thiscall vostok::render::stage_lights::debug_render(vostok::render::stage_lights *this)
{
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v3; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  vostok::render::lights_db *v7; // eax
  vostok::render::light_data *M_finish; // edi
  vostok::render::light_data *M_start; // ebx
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  __int64 v13; // xmm0_8
  __int64 v14; // [esp+10h] [ebp-138h]
  __int64 v15; // [esp+24h] [ebp-124h]
  float v16; // [esp+48h] [ebp-100h]
  const vostok::render::light_data *e; // [esp+6Ch] [ebp-DCh]
  float v18; // [esp+7Ch] [ebp-CCh]
  vostok::math::color color; // [esp+80h] [ebp-C8h] BYREF
  float v20; // [esp+84h] [ebp-C4h]
  vostok::math::float4x4 transform; // [esp+88h] [ebp-C0h] BYREF
  vostok::render::vertex_colored vertices[8]; // [esp+C8h] [ebp-80h] BYREF
  unsigned __int16 indices_begin; // [esp+148h] [ebp+0h] BYREF

  if ( s_debug_render )
  {
    m_object = this->m_context->m_targets->m_family[45].target.m_object;
    v3 = 0;
    if ( m_object )
    {
      v3 = this->m_context->m_targets->m_family[45].target.m_object;
      ++m_object->m_reference_count;
      m_rt = m_object->m_rt;
    }
    else
    {
      m_rt = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    if ( v3 )
    {
      if ( v3->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v3);
    }
    v7 = this->m_context->m_scene->m_lights.m_object;
    M_finish = v7->m_lights._M_impl._M_finish;
    M_start = v7->m_lights._M_impl._M_start;
    e = M_finish;
    if ( v7->m_lights._M_impl._M_start != M_finish )
    {
      color = (vostok::math::color)-16776961;
      do
      {
        vostok::render::system_renderer::draw_aabb(
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          &M_start->light.m_object->m_aabb,
          &color);
        if ( (*(_BYTE *)&M_start->light.m_object->flags & 0xF) == 6 )
        {
          qmemcpy((void *)&transform, &M_start->light.m_object->m_xform, sizeof(transform));
          v20 = transform.i.x * -1.0;
          *(float *)&v14 = (float)(transform.c.x + transform.j.x)
                         + (float)((float)(transform.i.x * -1.0) + (float)(transform.k.x * -1.0));
          v18 = (float)(transform.i.y * -1.0) + (float)(transform.k.y * -1.0);
          *((float *)&v14 + 1) = (float)(transform.c.y + transform.j.y) + v18;
          v16 = (float)(transform.i.z * -1.0) + (float)(transform.k.z * -1.0);
          *(_QWORD *)&vertices[0].position.x = v14;
          *(float *)&v15 = (float)(transform.j.z + v16) + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[0].position.elements[2] = v15;
          v10 = transform.i.x + (float)(transform.k.x * -1.0);
          *(float *)&v14 = (float)((float)(transform.j.x * -1.0) + v10) + transform.c.x;
          v11 = transform.i.y + (float)(transform.k.y * -1.0);
          *((float *)&v14 + 1) = (float)((float)(transform.j.y * -1.0) + v11) + transform.c.y;
          v12 = transform.i.z + (float)(transform.k.z * -1.0);
          *(_QWORD *)&vertices[1].position.x = v14;
          *(float *)&v15 = (float)((float)(transform.j.z * -1.0) + v12) + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[1].position.elements[2] = v15;
          *(float *)&v14 = (float)((float)(transform.j.x * -1.0) + transform.c.x)
                         + (float)((float)(transform.i.x * -1.0) + (float)(transform.k.x * -1.0));
          *((float *)&v14 + 1) = (float)((float)(transform.j.y * -1.0) + transform.c.y) + v18;
          v13 = v14;
          *((float *)&v14 + 1) = (float)(v11 + transform.c.y) + transform.j.y;
          *(_QWORD *)&vertices[2].position.x = v13;
          *(float *)&v14 = (float)(v10 + transform.c.x) + transform.j.x;
          *(_QWORD *)&vertices[2].position.elements[2] = COERCE_UNSIGNED_INT((float)((float)(transform.j.z * -1.0) + v16) + transform.c.z)
                                                       | 0xFF20FF0000000000uLL;
          *(float *)&v15 = (float)(v12 + transform.j.z) + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[3].position.x = v14;
          *(_QWORD *)&vertices[3].position.elements[2] = v15;
          *(float *)&v14 = (float)((float)(transform.k.x + (float)(transform.i.x * -1.0)) + transform.c.x)
                         + transform.j.x;
          *((float *)&v14 + 1) = (float)((float)(transform.k.y + (float)(transform.i.y * -1.0)) + transform.c.y)
                               + transform.j.y;
          *(_QWORD *)&vertices[4].position.x = v14;
          *(float *)&v15 = (float)((float)(transform.k.z + (float)(transform.i.z * -1.0)) + transform.j.z)
                         + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[4].position.elements[2] = v15;
          *(float *)&v14 = (float)((float)(transform.k.x + transform.i.x) + transform.c.x) + transform.j.x;
          *((float *)&v14 + 1) = (float)((float)(transform.k.y + transform.i.y) + transform.c.y) + transform.j.y;
          *(float *)&v15 = (float)((float)(transform.k.z + transform.i.z) + transform.j.z) + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[5].position.x = v14;
          *((float *)&v14 + 1) = (float)((float)(transform.k.y + (float)(transform.i.y * -1.0))
                                       + (float)(transform.j.y * -1.0))
                               + transform.c.y;
          *(_QWORD *)&vertices[5].position.elements[2] = v15;
          *(float *)&v14 = (float)((float)(transform.k.x + (float)(transform.i.x * -1.0)) + (float)(transform.j.x * -1.0))
                         + transform.c.x;
          *(_QWORD *)&vertices[6].position.x = v14;
          *(float *)&v15 = (float)((float)(transform.k.z + (float)(transform.i.z * -1.0)) + (float)(transform.j.z * -1.0))
                         + transform.c.z;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[6].position.elements[2] = v15;
          *(float *)&v14 = (float)((float)(transform.k.x + transform.i.x) + (float)(transform.j.x * -1.0))
                         + transform.c.x;
          *((float *)&v14 + 1) = (float)((float)(transform.k.y + transform.i.y) + (float)(transform.j.y * -1.0))
                               + transform.c.y;
          *(float *)&v15 = (float)((float)(transform.k.z + transform.i.z) + (float)(transform.j.z * -1.0))
                         + transform.c.z;
          *(_QWORD *)&vertices[7].position.x = v14;
          HIDWORD(v15) = -14614784;
          *(_QWORD *)&vertices[7].position.elements[2] = v15;
          vostok::render::system_renderer::draw_triangles(
            (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
            (const vostok::render::vertex_colored *const)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
            vertices,
            &indices_begin,
            vostok::geometry_utils::cube_solid::faces,
            (bool)vostok::geometry_utils::rectangle_solid::vertices);
          M_finish = (vostok::render::light_data *)e;
        }
        ++M_start;
      }
      while ( M_start != M_finish );
    }
  }
}
