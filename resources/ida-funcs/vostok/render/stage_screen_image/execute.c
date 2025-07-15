void __thiscall vostok::render::stage_screen_image::execute(
        vostok::render::stage_screen_image *this,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> t_image)
{
  vostok::render::backend *v3; // ecx
  float z; // esi
  bool v5; // zf
  vostok::render::res_effect *v6; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::backend *v8; // ecx
  float v9; // esi
  char *v10; // eax
  unsigned int v11; // xmm0_4
  unsigned int *v12; // edi
  float v13; // eax
  vostok::render::vertex_buffer *v14; // ecx
  float v15; // edi
  vostok::render::backend *v16; // ecx
  vostok::render::resource_manager *v17; // ecx
  pix_event_wrapper_dx11 wszName; // [esp+13h] [ebp-15h] BYREF
  unsigned int wszName_1[2]; // [esp+14h] [ebp-14h] BYREF
  float v20; // [esp+1Ch] [ebp-Ch]
  unsigned int v21; // [esp+20h] [ebp-8h]
  unsigned int v22; // [esp+24h] [ebp-4h]

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, &wszName, (int)L"stage_screen_image");
  if ( this->is_effects_ready(this) )
  {
    if ( this->is_enabled(this) )
    {
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        v3,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v5 = *(_DWORD *)(LODWORD(z) + 7384) == 0;
      *(_DWORD *)(LODWORD(z) + 7384) = 0;
      LOBYTE(v6) = !v5;
      *(_BYTE *)(LODWORD(z) + 117) |= !v5;
      m_object = this->m_present_effect.m_object;
      m_object->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v6, (int)m_object);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &t_image,
        (vostok::render::res_texture *)this->m_textures.m_container.m_begin);
      vostok::render::backend::set_ps_texture(
        v8,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        "t_base",
        t_image.m_object);
      v9 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_declaration(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        this->m_decl_ptr.m_object);
      v10 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(v9), wszName_1, 4u, 0x10u);
      v11 = LODWORD(s_bm_current_air_resistance);
      v20 = s_bm_current_air_resistance;
      v21 = 0;
      v22 = 0;
      *(float *)v10 = FLOAT_N1_0;
      *((float *)v10 + 1) = v20;
      *((_DWORD *)v10 + 2) = v21;
      *((_DWORD *)v10 + 3) = v22;
      v20 = *(float *)&v11;
      v21 = v11;
      v22 = 0;
      *((_DWORD *)v10 + 4) = v11;
      *((float *)v10 + 5) = v20;
      *((_DWORD *)v10 + 6) = v21;
      *((_DWORD *)v10 + 7) = v22;
      v20 = FLOAT_N1_0;
      v21 = 0;
      v22 = v11;
      *((float *)v10 + 8) = FLOAT_N1_0;
      *((float *)v10 + 9) = v20;
      *((_DWORD *)v10 + 10) = v21;
      *((_DWORD *)v10 + 11) = v22;
      wszName_1[1] = v11;
      v20 = FLOAT_N1_0;
      v21 = v11;
      v22 = v11;
      v12 = (unsigned int *)(v10 + 48);
      v13 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *v12++ = v11;
      *(float *)v12++ = v20;
      *v12 = v21;
      v12[1] = v22;
      vostok::render::vertex_buffer::unlock(v14, (int *)LODWORD(v13));
      v15 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_vb(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        0x10u);
      vostok::render::backend::render(
        (vostok::render::backend *)LODWORD(v15),
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
        v16,
        4u,
        wszName_1[0]);
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
  if ( t_image.m_object )
  {
    v5 = t_image.m_object->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        t_image.m_object);
  }
}
