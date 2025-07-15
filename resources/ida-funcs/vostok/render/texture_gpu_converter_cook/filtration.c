void __thiscall vostok::render::texture_gpu_converter_cook::filtration(
        vostok::render::texture_gpu_converter_cook *this,
        vostok::render::compress_temp_data *temp_data,
        int a3)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  vostok::render::res_pass *v6; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // eax
  vostok::render::res_pass *v8; // eax
  vostok::render::res_pass *v9; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::res_pass *v11; // edi
  vostok::render::effect_manager *v12; // ecx
  bool v13; // zf
  vostok::render::render_target *v14; // ecx
  vostok::render::texture_gpu_converter_cook *v15; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_object; // edi
  vostok::render::res_texture *v17; // esi
  vostok::render::resource_manager *v18; // ecx
  vostok::render::res_texture *v19; // eax
  vostok::render::render_target *v20; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v21; // [esp-4h] [ebp-34h] BYREF
  bool v22; // [esp+0h] [ebp-30h]
  unsigned int v23; // [esp+10h] [ebp-20h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v24; // [esp+14h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+18h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+1Ch] [ebp-14h] BYREF
  vostok::render::render_target *rt; // [esp+20h] [ebp-10h] BYREF
  unsigned int v28; // [esp+24h] [ebp-Ch]
  unsigned int v29; // [esp+28h] [ebp-8h]
  unsigned int i; // [esp+2Ch] [ebp-4h]
  int v31; // [esp+3Ch] [ebp+Ch]

  v4 = *(_DWORD *)(a3 + 32);
  v5 = *(_DWORD *)(a3 + 40);
  v31 = 0;
  v28 = v4;
  v29 = *(_DWORD *)(a3 + 36);
  v23 = v5;
  for ( i = 1; i < v23; ++i )
  {
    v29 >>= 1;
    v28 >>= 1;
    vostok::render::surfaces_cache::get_rt(
      (char *)0x1C,
      (vostok::render::surfaces_cache *)&temp_data->width,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt,
      v28,
      (vostok::render::render_target *)v29,
      v22);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v26,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&vostok::quasi_singleton<vostok::render::system_renderer>::pinst->m_block_compression_effect);
    m_object = v26.m_object;
    LODWORD(v26.m_object[28].m_current_satisfaction_update_tick) = 4;
    v8 = *(vostok::render::res_pass **)(HIDWORD(m_object[28].m_current_satisfaction_update_tick) + 16);
    v9 = 0;
    if ( v8 )
    {
      v9 = v8;
      ++v8->m_reference_count;
    }
    m_reference_count = (_DWORD *)v9->m_vs.m_object->m_reference_count;
    v11 = 0;
    if ( m_reference_count )
    {
      v11 = (vostok::render::res_pass *)v9->m_vs.m_object->m_reference_count;
      ++*m_reference_count;
    }
    vostok::render::res_pass::apply(v6, (int)v11);
    if ( v11 )
    {
      v13 = v11->m_reference_count-- == 1;
      if ( v13 )
        vostok::render::effect_manager::delete_pass(
          v12,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          v11);
    }
    v13 = v9->m_reference_count-- == 1;
    if ( v13 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v9);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    vostok::render::backend::set_ps_texture(
      *(vostok::render::backend **)(a3 + 8),
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_base_pixels",
      *(vostok::render::res_texture **)(*(_DWORD *)(a3 + 8) + 4 * i - 4));
    v21.m_object = v14;
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &v21,
      (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::texture_gpu_converter_cook::fill_surface(
      v15,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)temp_data,
      v21.m_object);
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    if ( rt
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v31 |= 1u;
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &v24,
        &rt->m_texture);
      p_object = &v24;
      v17 = object.m_object;
    }
    else
    {
      v31 |= 2u;
      v17 = 0;
      object.m_object = 0;
      p_object = &object;
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      p_object,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(4 * i + *(_DWORD *)(a3 + 8)));
    if ( (v31 & 2) != 0 )
    {
      v31 &= ~2u;
      if ( v17 )
      {
        v13 = v17->m_reference_count-- == 1;
        if ( v13 )
          vostok::render::resource_manager::release(
            v18,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v17);
      }
    }
    if ( (v31 & 1) != 0 )
    {
      v19 = v24.m_object;
      v31 &= ~1u;
      if ( v24.m_object )
      {
        v13 = v24.m_object->m_reference_count-- == 1;
        if ( v13 )
          vostok::render::resource_manager::release(
            v18,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v19);
      }
    }
    v20 = rt;
    if ( rt )
    {
      v13 = rt->m_reference_count-- == 1;
      if ( v13 )
        vostok::render::resource_manager::release(v20, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
  }
}
