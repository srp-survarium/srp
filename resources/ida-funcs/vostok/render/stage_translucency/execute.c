void __thiscall vostok::render::stage_translucency::execute(vostok::render::stage_translucency *this)
{
  unsigned int v2; // edi
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v4; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v6; // ebx
  vostok::render::constants_handler<1> *m_conflicted_key_name; // esi
  vostok::render::renderer_context *m_context; // eax
  const vostok::math::float4x4 *p_m_v2shadow1; // eax
  const vostok::math::float3 *v10; // eax
  float *v11; // eax
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  unsigned int m_diff_range_start; // ecx
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  vostok::render::shader_constant_host *m_c_sun_direction; // eax
  unsigned __int16 m_buffer_index; // cx
  long double v25; // st7
  float intensity; // xmm0_4
  vostok::render::shader_constant_host *m_c_sun_color; // eax
  unsigned int v28; // ecx
  unsigned __int16 v29; // cx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v31; // eax
  vostok::render::backend *v32; // ecx
  vostok::render::light *v33; // ecx
  vostok::render::grass_render_model *v35; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp-1Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v37; // [esp-18h] [ebp-90h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v38; // [esp-14h] [ebp-8Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v39; // [esp-10h] [ebp-88h]
  BOOL v40; // [esp-Ch] [ebp-84h]
  int v41; // [esp-8h] [ebp-80h]
  float v42; // [esp-4h] [ebp-7Ch]
  float pos_y; // [esp+0h] [ebp-78h]
  float size_x; // [esp+4h] [ebp-74h]
  float _X; // [esp+8h] [ebp-70h]
  float _Y; // [esp+Ch] [ebp-6Ch]
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> sun; // [esp+24h] [ebp-54h] BYREF
  float v48; // [esp+28h] [ebp-50h]
  char src_ptr[4]; // [esp+2Ch] [ebp-4Ch] BYREF
  float v50; // [esp+30h] [ebp-48h]
  float v51; // [esp+34h] [ebp-44h]
  vostok::math::float4x4 result; // [esp+38h] [ebp-40h] BYREF

  v2 = 0;
  if ( this->m_translucency_effect.m_object )
  {
    m_object = this->m_context->m_scene->m_lights.m_object;
    v4 = m_object->m_sun.m_object;
    p_m_sun = &m_object->m_sun;
    if ( v4
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && !v4->m_enabled )
    {
      v6 = 0;
    }
    else
    {
      *(float *)&sun.m_object = 0.0;
      vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
        &sun,
        p_m_sun);
      v6 = sun.m_object;
    }
    if ( this->is_enabled(this) && v6 )
    {
      vostok::render::res_effect::apply(0, &this->m_translucency_effect.m_object->__vftable);
      m_conflicted_key_name = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      do
      {
        m_context = this->m_context;
        switch ( v2 )
        {
          case 1u:
            p_m_v2shadow1 = &m_context->m_v2shadow1;
            break;
          case 2u:
            p_m_v2shadow1 = &m_context->m_v2shadow2;
            break;
          case 3u:
            p_m_v2shadow1 = &m_context->m_v2shadow3;
            break;
          default:
            p_m_v2shadow1 = &m_context->m_v2shadow0;
            break;
        }
        v10 = (const vostok::math::float3 *)vostok::math::transpose(&result, p_m_v2shadow1);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          this->m_shadow[v2],
          m_conflicted_key_name + 123,
          v10);
        ++m_conflicted_key_name[7].m_current.m_object;
        ++v2;
      }
      while ( v2 < 4 );
      v11 = (float *)this->m_context;
      y = v6->direction.y;
      z = v6->direction.z;
      x = v6->direction.x;
      v15 = v11[3909];
      v16 = v11[3913];
      m_diff_range_start = m_conflicted_key_name[191].m_diff_range_start;
      v11 += 3905;
      v18 = (float)((float)(v15 * y) + (float)(v16 * z)) + (float)(x * *v11);
      v19 = v11[5];
      *(float *)src_ptr = v18;
      v50 = (float)((float)(v11[1] * x) + (float)(v19 * y)) + (float)(v11[9] * z);
      v20 = v11[2] * x;
      v21 = v11[6] * y;
      v22 = v11[10];
      m_c_sun_direction = this->m_c_sun_direction;
      v51 = (float)(v20 + v21) + (float)(v22 * z);
      if ( m_c_sun_direction->m_update_markers[1] == m_diff_range_start )
      {
        m_buffer_index = m_c_sun_direction->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_c_sun_direction->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_c_sun_direction->m_shader_slots[1].m_class_id,
            m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
            src_ptr);
      }
      _Y = 3.0;
      ++m_conflicted_key_name[7].m_current.m_object;
      v48 = powf(v6->color.z, _Y);
      *(float *)&sun.m_object = powf(v6->color.y, 3.0);
      v25 = powf(v6->color.x, 3.0);
      intensity = v6->intensity;
      *(float *)src_ptr = v25;
      m_c_sun_color = this->m_c_sun_color;
      v28 = m_conflicted_key_name[191].m_diff_range_start;
      *(float *)src_ptr = intensity * *(float *)src_ptr;
      v50 = intensity * *(float *)&sun.m_object;
      v51 = intensity * v48;
      if ( m_c_sun_color->m_update_markers[1] == v28 )
      {
        v29 = m_c_sun_color->m_shader_slots[1].m_buffer_index;
        if ( v29 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_c_sun_color->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_c_sun_color->m_shader_slots[1].m_class_id,
            m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v29].m_object,
            src_ptr);
      }
      ++m_conflicted_key_name[7].m_current.m_object;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_eye_ray_corner,
        m_conflicted_key_name + 123,
        this->m_context->m_eye_rays);
      ++m_conflicted_key_name[7].m_current.m_object;
      _Y = 1.0;
      _X = 1.0;
      size_x = 0.0;
      pos_y = 0.0;
      v42 = 0.0;
      v41 = 1;
      v40 = 0;
      v39.m_object = 0;
      v38.m_object = 0;
      v37.m_object = 0;
      m_targets = this->m_context->m_targets;
      v36.m_object = 0;
      v31 = m_targets->m_family[26].target.m_object;
      if ( v31 )
      {
        v36.m_object = v31;
        ++v31->m_reference_count;
      }
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)&v36,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        v36,
        v37,
        v38,
        v39,
        v40,
        (D3D11_VIEWPORT *)v41,
        v42,
        pos_y,
        size_x,
        _X);
      vostok::render::backend::reset_render_targets(
        v32,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    }
    else
    {
      this->execute_disabled(this);
      if ( !v6 )
        return;
    }
    if ( v6->m_reference_count-- == 1 )
    {
      v35 = vostok::render::g_allocator.m_object;
      vostok::render::light::~light(v33, (int)v6);
      BYTE2(v35->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v35->m_reconstruction_info_actuality_tick), v6);
    }
  }
}
