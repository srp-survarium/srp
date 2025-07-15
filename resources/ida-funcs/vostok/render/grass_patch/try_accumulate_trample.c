void __userpurge vostok::render::grass_patch::try_accumulate_trample(
        vostok::render::trample_desc *desc@<eax>,
        vostok::render::res_effect *in_renderer@<ecx>,
        vostok::render::grass_patch *this,
        vostok::render::grass_world *in_grass_world,
        vostok::render::renderer_context *in_context)
{
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  vostok::render::res_effect *m_node; // eax
  vostok::render::res_effect *v11; // esi
  const char *m_conflicted_key_name; // esi
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v14; // [esp-1Ch] [ebp-60h]
  float pos_y; // [esp+0h] [ebp-44h]
  float size_x; // [esp+4h] [ebp-40h]
  float size_y; // [esp+Ch] [ebp-38h]
  unsigned int v18; // [esp+10h] [ebp-34h]
  D3D11_VIEWPORT view_port; // [esp+28h] [ebp-1Ch] BYREF
  float linear_radius; // [esp+48h] [ebp+4h]

  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 304) )
  {
    v7 = (float)((float)(desc->position.x - (float)(this->m_origin.x - 8.0)) * 0.0625) - 0.015873017;
    v8 = (float)((float)(desc->position.z - (float)(this->m_origin.z - 8.0)) * 0.0625) - 0.015873017;
    v9 = (float)((float)(desc->position.y - (float)(this->m_origin.y - 8.0)) * 0.0625) - 0.015873017;
    linear_radius = desc->radius * 0.0625;
    if ( v7 >= 0.0
      && v9 >= -0.25
      && v8 >= 0.0
      && *(float *)&clear_value >= v7
      && *(float *)&clear_value >= v9
      && *(float *)&clear_value >= v8 )
    {
      m_node = (vostok::render::res_effect *)in_renderer[1].m_fat_it.m_node;
      v11 = 0;
      if ( m_node )
      {
        v11 = (vostok::render::res_effect *)in_renderer[1].m_fat_it.m_node;
        _InterlockedExchangeAdd(&m_node->m_reference_count, 1u);
      }
      if ( v11->m_techniques._M_impl._M_finish - v11->m_techniques._M_impl._M_start )
      {
        v11->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(in_renderer, v18);
      }
      if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        in_grass_world->m_trample_parameters,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        (const vostok::math::float3 *)&desc->multiplier);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      view_port.Width = 64.0;
      view_port.Height = 64.0;
      view_port.TopLeftX = 0.0;
      view_port.TopLeftY = 0.0;
      view_port.MinDepth = 0.0;
      LODWORD(view_port.MaxDepth) = clear_value;
      v14 = 0;
      m_object = this->m_movement_rt.m_object;
      if ( m_object )
      {
        v14 = this->m_movement_rt.m_object;
        ++m_object->m_reference_count;
      }
      pos_y = v7 - linear_radius;
      size_x = v8 - linear_radius;
      size_y = linear_radius + linear_radius;
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v14,
        0,
        0,
        0,
        0,
        0,
        COERCE_FLOAT(&view_port),
        pos_y,
        size_x,
        size_y);
    }
  }
}
