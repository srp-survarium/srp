void __userpurge vostok::render::hw_hiz_occlusion_manager::downsample_occlusion_buffer(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        vostok::render::res_texture wszName)
{
  vostok::render::res_texture_vtbl *v2; // ebx
  void (__thiscall *v3)(vostok::render::res_texture *); // ecx
  int z_low; // esi
  vostok::render::backend *v5; // ecx
  vostok::render::backend *v6; // ecx
  vostok::render::res_pass *v7; // ecx
  void (__thiscall *v8)(vostok::render::res_texture *); // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  vostok::render::res_pass *v11; // eax
  vostok::render::effect_manager *v12; // ecx
  vostok::render::res_pass *v13; // eax
  bool v14; // al
  vostok::memory::doug_lea_allocator *v15; // ecx
  vostok::render::res_texture *v16; // ecx
  vostok::render::res_texture *v17; // eax
  vostok::render::backend *v18; // ecx
  vostok::render::res_texture *m_object; // esi
  vostok::render::render_target *v20; // ecx
  void (__thiscall *v21)(vostok::render::res_texture *); // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v22; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // esi
  vostok::render::res_texture_vtbl *v24; // eax
  vostok::render::res_pass *v25; // edi
  vostok::render::effect_manager *v26; // ecx
  vostok::render::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> > *p_m_techniques; // edi
  stlp_std::priv::_Rb_tree_node_base **p_M_left; // esi
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  stlp_std::priv::_Rb_tree_node_base *v30; // eax
  vostok::memory::doug_lea_allocator *v31; // ecx
  vostok::memory::doug_lea_allocator *v32; // esi
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v33; // ecx
  vostok::memory::doug_lea_allocator *v34; // ecx
  vostok::render::render_target *m_reference_count; // esi
  float z; // esi
  vostok::render::resource_manager *v37; // ecx
  bool v38; // zf
  vostok::render::res_texture *v39; // eax
  vostok::render::system_renderer *v40; // [esp-10h] [ebp-70h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v41; // [esp-Ch] [ebp-6Ch] BYREF
  vostok::render::render_target *v42; // [esp-8h] [ebp-68h]
  vostok::render::render_target *v43; // [esp-4h] [ebp-64h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v44; // [esp+0h] [ebp-60h]
  vostok::render::render_target *v45; // [esp+4h] [ebp-5Ch]
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v46; // [esp+8h] [ebp-58h]
  const D3D11_VIEWPORT *v47; // [esp+Ch] [ebp-54h]
  const char *v48; // [esp+10h] [ebp-50h]
  float v49; // [esp+14h] [ebp-4Ch]
  float v50; // [esp+18h] [ebp-48h]
  D3D11_VIEWPORT v51; // [esp+1Ch] [ebp-44h] BYREF
  D3D11_VIEWPORT v52; // [esp+34h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v53; // [esp+4Ch] [ebp-14h]
  unsigned int v54; // [esp+50h] [ebp-10h]
  vostok::render::res_pass *pass; // [esp+54h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object; // [esp+58h] [ebp-8h]

  v2 = wszName.__vftable;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName.__vftable + 3,
    (int)L"downsample_occlusion_buffer");
  if ( !s_hiz2 )
  {
    pass = (vostok::render::res_pass *)1;
    if ( (char *)v2[56].~vostok::render::res_texture > (char *)1 )
    {
      wszName.__vftable = v2 + 35;
      do
      {
        qmemcpy(
          (void *)&v51,
          (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
          sizeof(v51));
        v3 = wszName.~vostok::render::res_texture;
        v52.Width = (float)*((unsigned int *)wszName.~vostok::render::res_texture + 8);
        v53.m_object = (vostok::render::render_target *)*((_DWORD *)v3 + 9);
        v52.Height = (float)(unsigned int)v53.m_object;
        v52.MinDepth = 0.0;
        v52.MaxDepth = s_bm_current_air_resistance;
        v52.TopLeftX = 0.0;
        v52.TopLeftY = 0.0;
        vostok::render::backend::set_viewports(
          (vostok::render::backend *)&v52,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &v52,
          v47);
        z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::render_target *)wszName.~vostok::render::res_texture,
          0,
          0,
          0);
        vostok::render::backend::clear_render_targets(v5, z_low, SLODWORD(s_bm_current_air_resistance), 1.0, 1.0, 1.0);
        vostok::render::backend::set_viewports(
          v6,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &v51,
          v47);
        pass = (vostok::render::res_pass *)((char *)pass + 1);
        ++wszName.__vftable;
      }
      while ( (char *)pass < (char *)v2[56].~vostok::render::res_texture );
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[51]);
    v54 = 1;
    if ( (char *)v2[56].~vostok::render::res_texture > (char *)1 )
    {
      v52.MinDepth = 0.0;
      v52.MaxDepth = 0.0;
      object = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[19];
      do
      {
        v8 = v2[1].~vostok::render::res_texture;
        *((_DWORD *)v8 + 5512) = 4;
        v9 = *(_DWORD **)(*((_DWORD *)v8 + 5513) + 16);
        v10 = 0;
        if ( v9 )
        {
          v10 = v9;
          ++*v9;
        }
        v11 = *(vostok::render::res_pass **)v10[2];
        pass = 0;
        if ( v11 )
        {
          ++v11->m_reference_count;
          pass = v11;
        }
        vostok::render::res_pass::apply(v7, (int)pass);
        v13 = pass;
        if ( pass )
        {
          --pass->m_reference_count;
          if ( !v13->m_reference_count )
            vostok::render::effect_manager::delete_pass(
              v12,
              (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
              v13);
        }
        if ( !--*v10 )
        {
          if ( *((_BYTE *)v10 + 148) )
          {
            v14 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
                    (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques,
                    (const vostok::render::res_pass *)v10);
            v12 = (vostok::render::effect_manager *)v46;
            if ( v14 )
            {
              pass = (vostok::render::res_pass *)vostok::render::g_allocator;
              vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
                v46,
                (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)v10
              + 2);
              vostok::memory::doug_lea_allocator::free_impl(
                v15,
                (int)pass,
                (char *)v10,
                (const char *const)v47,
                v48,
                LODWORD(v49));
            }
          }
        }
        vostok::render::backend::set_ps_texture(
          (vostok::render::backend *)v12,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "hiz_depth_texture",
          (vostok::render::res_texture *)wszName.__vftable);
        v17 = (vostok::render::res_texture *)vostok::render::res_texture::height(v16, (int)wszName.__vftable);
        v53.m_object = (vostok::render::render_target *)vostok::render::res_texture::width(v17, (int)wszName.__vftable);
        v52.Width = (float)(unsigned int)v53.m_object;
        v52.Height = (float)(unsigned int)v18;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v18,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v2[63].~vostok::render::res_texture,
          (const vostok::math::float3 *)&v52.Width);
        v46 = 0;
        v45 = 0;
        v44.m_object = 0;
        v43 = 0;
        v42 = 0;
        m_object = object[-16].m_object;
        v41.m_object = v20;
        v40 = (vostok::render::system_renderer *)v20;
        pass = (vostok::render::res_pass *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v41,
          (vostok::render::render_target *)m_object);
        vostok::render::system_renderer::fill_surface(
          v40,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)pass,
          v41.m_object,
          v42,
          v43,
          v44,
          v45,
          (D3D11_VIEWPORT *)v46,
          *(float *)&v47,
          *(float *)&v48,
          v49,
          v50);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          object,
          &wszName);
        ++v54;
        ++object;
      }
      while ( (char *)v54 < (char *)v2[56].~vostok::render::res_texture );
    }
    v54 = 1;
    if ( (char *)v2[56].~vostok::render::res_texture > (char *)1 )
    {
      pass = (vostok::render::res_pass *)&v2[35];
      do
      {
        v21 = v2[1].~vostok::render::res_texture;
        *((_DWORD *)v21 + 5512) = 5;
        v22 = *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(*((_DWORD *)v21 + 5513) + 20);
        v23 = 0;
        object = 0;
        if ( v22 )
        {
          ++v22->m_object;
          object = v22;
          v23 = v22;
        }
        v53.m_object = (vostok::render::render_target *)&v23[2];
        v24 = v23[2].m_object->__vftable;
        v25 = 0;
        if ( v24 )
        {
          v25 = (vostok::render::res_pass *)v23[2].m_object->__vftable;
          ++v24->~vostok::render::res_texture;
        }
        vostok::render::res_pass::apply(v7, (int)v25);
        if ( v25 )
        {
          if ( !--v25->m_reference_count )
            vostok::render::effect_manager::delete_pass(
              v26,
              (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
              v25);
        }
        if ( !--v23->m_object && LOBYTE(v23[37].m_object) )
        {
          p_m_techniques = &vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques;
          p_M_left = &vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques._M_t._M_header._M_data._M_left;
          M_left = vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques._M_t._M_header._M_data._M_left;
          while ( 1 )
          {
            LOBYTE(v26) = M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_techniques;
            if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_techniques )
              break;
            if ( *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&M_left[1]._M_color == object )
            {
              v30 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                      M_left,
                      &p_m_techniques->_M_t._M_header._M_data._M_parent,
                      p_M_left,
                      &p_m_techniques->_M_t._M_header._M_data._M_right);
              vostok::memory::doug_lea_allocator::free_impl(
                v31,
                (int)vostok::render::g_allocator,
                (char *)&v30->_M_color,
                (const char *const)v47,
                v48,
                LODWORD(v49));
              --p_m_techniques->_M_t._M_node_count;
              v32 = vostok::render::g_allocator;
              vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
                v33,
                (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)v53.m_object);
              vostok::memory::doug_lea_allocator::free_impl(
                v34,
                (int)v32,
                (char *)object,
                (const char *const)v47,
                v48,
                LODWORD(v49));
              break;
            }
            M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
            v26 = (vostok::render::effect_manager *)v46;
          }
        }
        vostok::render::backend::set_ps_texture(
          (vostok::render::backend *)v26,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "hiz_depth_texture",
          (vostok::render::res_texture *)pass[-3].m_input_layout.m_object);
        v46 = 0;
        v45 = 0;
        v44.m_object = 0;
        v43 = 0;
        v42 = 0;
        m_reference_count = (vostok::render::render_target *)pass->m_reference_count;
        v41.m_object = 0;
        v53.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v41,
          m_reference_count);
        vostok::render::system_renderer::fill_surface(
          0,
          v53,
          v41.m_object,
          v42,
          v43,
          v44,
          v45,
          (D3D11_VIEWPORT *)v46,
          *(float *)&v47,
          *(float *)&v48,
          v49,
          v50);
        ++v54;
        pass = (vostok::render::res_pass *)((char *)pass + 4);
      }
      while ( (char *)v54 < (char *)v2[56].~vostok::render::res_texture );
    }
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)v7,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v37 = *(vostok::render::resource_manager **)(LODWORD(z) + 7440);
    v38 = *(_DWORD *)(LODWORD(z) + 7384) == (_DWORD)v37;
    *(_DWORD *)(LODWORD(z) + 7384) = v37;
    v39 = (vostok::render::res_texture *)wszName.__vftable;
    *(_BYTE *)(LODWORD(z) + 117) |= !v38;
    if ( v39 )
    {
      v38 = v39->m_reference_count-- == 1;
      if ( v38 )
        vostok::render::resource_manager::release(
          v37,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v39);
    }
  }
  D3DPERF_EndEvent();
}
