void __thiscall vostok::render::stage_ambient_occlusion::execute(vostok::render::stage_ambient_occlusion *this)
{
  char v2; // bl
  vostok::render::render_target *m_object; // eax
  ID3D11RenderTargetView *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  int v6; // eax
  vostok::render::backend *v7; // ecx
  vostok::render::render_target *v8; // eax
  vostok::render::render_target *v9; // ecx
  ID3D11RenderTargetView *v10; // eax
  vostok::render::backend *v11; // esi
  int v12; // edi
  vostok::render::backend *v13; // ecx
  vostok::render::render_target *v14; // eax
  vostok::render::render_target *v15; // ecx
  ID3D11RenderTargetView *v16; // edx
  vostok::render::backend *v17; // eax
  vostok::render::base_scene_view *v18; // esi
  const vostok::resources::memory_type *type; // xmm0_4
  unsigned int size; // xmm1_4
  const char *v21; // esi
  vostok::render::shader_constant_host *m_ao_parameters; // eax
  int v23; // ecx
  unsigned __int16 m_buffer_index; // cx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v26; // eax
  const char *v27; // eax
  int v28; // ecx
  bool v29; // zf
  vostok::render::backend *v30; // esi
  const vostok::math::float3 *v31; // eax
  vostok::render::enum_render_target_index v32; // ecx
  vostok::render::system_renderer *v33; // ecx
  int v34; // ecx
  survarium::game_action_id *M_start; // ecx
  vostok::render::backend *v36; // esi
  const vostok::math::float3 *v37; // eax
  vostok::render::render_target *v38; // ecx
  vostok::render::system_renderer *v39; // ecx
  unsigned int Height; // esi
  unsigned int Width; // edi
  vostok::render::res_texture *v42; // ebx
  vostok::render::resource_manager **t; // eax
  vostok::render::res_texture *v44; // ecx
  unsigned int v45; // esi
  unsigned int v46; // edi
  vostok::render::res_texture *v47; // ebx
  vostok::render::resource_manager **v48; // eax
  vostok::render::res_texture *v49; // ecx
  const char *v50; // esi
  int v51; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v52; // [esp-1Ch] [ebp-DCh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v53; // [esp-18h] [ebp-D8h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v54; // [esp-14h] [ebp-D4h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v55; // [esp-10h] [ebp-D0h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v56; // [esp-Ch] [ebp-CCh]
  int v57; // [esp-8h] [ebp-C8h]
  float v58; // [esp-4h] [ebp-C4h]
  float pos_y; // [esp+0h] [ebp-C0h]
  float size_x; // [esp+4h] [ebp-BCh]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> size_y; // [esp+8h] [ebp-B8h]
  vostok::render::renderer_context *a; // [esp+Ch] [ebp-B4h]
  vostok::render::enum_render_target_index v63; // [esp+10h] [ebp-B0h]
  unsigned int v64; // [esp+14h] [ebp-ACh]
  vostok::render::res_texture *v65; // [esp+18h] [ebp-A8h]
  unsigned int v66; // [esp+1Ch] [ebp-A4h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v67; // [esp+20h] [ebp-A0h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v68; // [esp+24h] [ebp-9Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v69; // [esp+28h] [ebp-98h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v70; // [esp+2Ch] [ebp-94h] BYREF
  char src_ptr[4]; // [esp+30h] [ebp-90h] BYREF
  unsigned int v72; // [esp+34h] [ebp-8Ch]
  int v73; // [esp+38h] [ebp-88h]
  int v74; // [esp+3Ch] [ebp-84h]
  vostok::math::float4x4 result; // [esp+40h] [ebp-80h] BYREF
  vostok::math::float4x4 v76; // [esp+80h] [ebp-40h] BYREF

  if ( !this->m_sh_ssao_accumulation.m_object
    || !this->m_sh_ssao_filter4x4.m_object
    || !this->m_sh_ssao_downsample_position_and_normal.m_object )
  {
    return;
  }
  v2 = *((_BYTE *)&this->m_context->m_scene_view.m_object[1].m_parent_resources + 25);
  if ( !this->is_enabled(this) || !v2 )
  {
    this->execute_disabled(this);
    return;
  }
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 292) )
  {
    m_object = vostok::render::renderer_context::get_rt(
                 (vostok::render::renderer_context *)0x13,
                 &v67,
                 this->m_context,
                 v63)->m_object;
    if ( m_object )
      m_rt = m_object->m_rt;
    else
      m_rt = 0;
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
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v67);
    v6 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    vostok::render::backend::clear_render_targets(
      v7,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
      (vostok::math::color)v6);
  }
  v8 = this->m_context->m_targets->m_family[17].target.m_object;
  v9 = 0;
  if ( v8 )
  {
    v9 = this->m_context->m_targets->m_family[17].target.m_object;
    ++v8->m_reference_count;
    v10 = v8->m_rt;
  }
  else
  {
    v10 = 0;
  }
  v11 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != v10 )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v10;
    v11->m_dirty_targets.render_targets[0] = 1;
  }
  if ( v11->m_targets[1] )
  {
    v11->m_targets[1] = 0;
    v11->m_dirty_targets.render_targets[1] = 1;
  }
  if ( v11->m_targets[2] )
  {
    v11->m_targets[2] = 0;
    v11->m_dirty_targets.render_targets[2] = 1;
  }
  if ( v11->m_targets[3] )
  {
    v11->m_targets[3] = 0;
    v11->m_dirty_targets.render_targets[3] = 1;
  }
  if ( v9 )
  {
    if ( !--v9->m_reference_count )
    {
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v9,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v9);
      v11 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v12 = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0);
  vostok::render::backend::clear_render_targets(v13, v11, (vostok::math::color)v12);
  v14 = this->m_context->m_targets->m_family[18].target.m_object;
  v15 = 0;
  if ( v14 )
  {
    v15 = this->m_context->m_targets->m_family[18].target.m_object;
    ++v14->m_reference_count;
    v16 = v14->m_rt;
  }
  else
  {
    v16 = 0;
  }
  v17 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != v16 )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v16;
    v17->m_dirty_targets.render_targets[0] = 1;
  }
  if ( v17->m_targets[1] )
  {
    v17->m_targets[1] = 0;
    v17->m_dirty_targets.render_targets[1] = 1;
  }
  if ( v17->m_targets[2] )
  {
    v17->m_targets[2] = 0;
    v17->m_dirty_targets.render_targets[2] = 1;
  }
  if ( v17->m_targets[3] )
  {
    v17->m_targets[3] = 0;
    v17->m_dirty_targets.render_targets[3] = 1;
  }
  if ( v15 )
  {
    if ( !--v15->m_reference_count )
    {
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v15);
      v17 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  vostok::render::backend::clear_render_targets((vostok::render::backend *)v15, v17, (vostok::math::color)v12);
  v18 = this->m_context->m_scene_view.m_object;
  vostok::render::res_effect::apply(0, &this->m_sh_ssao_accumulation.m_object->__vftable);
  type = v18[1].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type;
  size = v18[1].m_memory_usage_self.size;
  v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_ao_parameters = this->m_ao_parameters;
  v23 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
  *(_DWORD *)src_ptr = type;
  v72 = size;
  v73 = 0;
  v74 = 0;
  if ( m_ao_parameters->m_update_markers[1] == v23 )
  {
    m_buffer_index = m_ao_parameters->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_ao_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_ao_parameters->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
  }
  ++*((_DWORD *)v21 + 23);
  a = this->m_context;
  m_targets = a->m_targets;
  *(float *)&size_y.m_object = 0.0;
  v26 = m_targets->m_family[17].target.m_object;
  if ( v26 )
  {
    size_y.m_object = v26;
    ++v26->m_reference_count;
  }
  vostok::render::fill_surface_0(size_y, a);
  if ( (_S7_2 & 1) == 0 )
  {
    _S7_2 |= 1u;
    qmemcpy((void *)&prev_view, vostok::math::float4x4::identity(&v76), sizeof(prev_view));
  }
  v27 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v28 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
  v29 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v28;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v28;
  *((_BYTE *)v27 + 167) |= !v29;
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 291) )
  {
    vostok::render::res_effect::apply(0, &this->m_sh_ssao_filter4x4.m_object->__vftable);
LABEL_61:
    *(float *)&a = 1.0;
    *(float *)&size_y.m_object = 1.0;
    size_x = 0.0;
    pos_y = 0.0;
    v58 = 0.0;
    v57 = 1;
    v56.m_object = 0;
    v55.m_object = 0;
    v54.m_object = 0;
    v52.m_object = (vostok::render::render_target *)M_start;
    v53.m_object = 0;
    goto LABEL_62;
  }
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 292) )
    goto LABEL_55;
  vostok::render::res_effect::apply((vostok::render::res_effect *)2, &this->m_sh_ssao_filter4x4.m_object->__vftable);
  v30 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    this->m_context->m_eye_rays,
    this->m_c_eye_ray_corner);
  v31 = (const vostok::math::float3 *)vostok::math::transpose(&result, &prev_view);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v30, v31, this->m_prev_view_parameter);
  *(float *)&a = 1.0;
  *(float *)&size_y.m_object = 1.0;
  size_x = 0.0;
  pos_y = 0.0;
  v58 = 0.0;
  v57 = 0;
  v56.m_object = 0;
  v55.m_object = 0;
  v54.m_object = 0;
  v53.m_object = 0;
  vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)0x13, &v52, this->m_context, v32);
  vostok::render::system_renderer::fill_surface(
    v33,
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    v52,
    v53,
    v54,
    v55,
    v56,
    (D3D11_VIEWPORT *)v57,
    v58,
    pos_y,
    size_x,
    *(float *)&size_y.m_object,
    *(float *)&a);
  v34 = 4;
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 292) )
LABEL_55:
    v34 = 3;
  vostok::render::res_effect::apply((vostok::render::res_effect *)v34, &this->m_sh_ssao_filter4x4.m_object->__vftable);
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 292) )
    goto LABEL_61;
  v36 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    this->m_context->m_eye_rays,
    this->m_c_eye_ray_corner);
  v37 = (const vostok::math::float3 *)vostok::math::transpose(&result, &prev_view);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v36, v37, this->m_prev_view_parameter);
  *(float *)&a = 1.0;
  *(float *)&size_y.m_object = 1.0;
  size_x = 0.0;
  pos_y = 0.0;
  v58 = 0.0;
  v57 = 1;
  v56.m_object = 0;
  v55.m_object = 0;
  v53.m_object = v38;
  v54.m_object = 0;
  vostok::render::renderer_context::get_rt(
    (vostok::render::renderer_context *)0x15,
    &v53,
    this->m_context,
    (vostok::render::enum_render_target_index)v38);
LABEL_62:
  vostok::render::renderer_context::get_rt(
    (vostok::render::renderer_context *)0x12,
    &v52,
    this->m_context,
    (vostok::render::enum_render_target_index)v52.m_object);
  vostok::render::system_renderer::fill_surface(
    v39,
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    v52,
    v53,
    v54,
    v55,
    v56,
    (D3D11_VIEWPORT *)v57,
    v58,
    pos_y,
    size_x,
    *(float *)&size_y.m_object,
    *(float *)&a);
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 292) )
  {
    Height = vostok::render::renderer_context::get_t(
               (vostok::render::renderer_context *)0x12,
               (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v67,
               this->m_context,
               v63)->m_object->m_desc.Height;
    Width = vostok::render::renderer_context::get_t(
              (vostok::render::renderer_context *)0x12,
              &v69,
              this->m_context,
              v63)->m_object->m_desc.Width;
    v42 = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0x12, &v70, this->m_context, v63)->m_object;
    t = (vostok::render::resource_manager **)vostok::render::renderer_context::get_t(
                                               (vostok::render::renderer_context *)0x14,
                                               &v68,
                                               this->m_context,
                                               v63);
    vostok::render::resource_manager::copy2D(
      Width,
      Height,
      *t,
      v42,
      v63,
      v64,
      v65,
      v66,
      (unsigned int)v67.m_object,
      (unsigned int)v68.m_object,
      (unsigned int)v69.m_object);
    if ( v68.m_object )
    {
      v29 = v68.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v44, v68.m_object);
    }
    if ( v70.m_object )
    {
      v29 = v70.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v44, v70.m_object);
    }
    if ( v69.m_object )
    {
      v29 = v69.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v44, v69.m_object);
    }
    if ( v67.m_object )
    {
      v29 = v67.m_object->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v44, (const vostok::render::res_texture *)v67.m_object);
    }
    v45 = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0x15, &v68, this->m_context, v63)->m_object->m_desc.Height;
    v46 = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0x15, &v70, this->m_context, v63)->m_object->m_desc.Width;
    v47 = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0x15, &v69, this->m_context, v63)->m_object;
    v48 = (vostok::render::resource_manager **)vostok::render::renderer_context::get_t(
                                                 (vostok::render::renderer_context *)0x16,
                                                 (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v67,
                                                 this->m_context,
                                                 v63);
    vostok::render::resource_manager::copy2D(
      v46,
      v45,
      *v48,
      v47,
      v63,
      v64,
      v65,
      v66,
      (unsigned int)v67.m_object,
      (unsigned int)v68.m_object,
      (unsigned int)v69.m_object);
    if ( v67.m_object )
    {
      v29 = v67.m_object->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v49, (const vostok::render::res_texture *)v67.m_object);
    }
    if ( v69.m_object )
    {
      v29 = v69.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v49, v69.m_object);
    }
    if ( v70.m_object )
    {
      v29 = v70.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v49, v70.m_object);
    }
    if ( v68.m_object )
    {
      v29 = v68.m_object->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::res_texture::destroy_impl(v49, v68.m_object);
    }
  }
  qmemcpy((void *)&prev_view, &this->m_context->m_v, sizeof(prev_view));
  v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    0,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v51 = *((_DWORD *)v50 + 547);
  v29 = *((_DWORD *)v50 + 539) == v51;
  *((_DWORD *)v50 + 539) = v51;
  *((_BYTE *)v50 + 167) |= !v29;
}
