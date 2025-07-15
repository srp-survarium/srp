void __thiscall vostok::render::texture_gpu_converter_cook::compress_surface(
        vostok::render::texture_gpu_converter_cook *this,
        unsigned __int8 **in_out_mip_memory_start,
        unsigned __int8 **dxt_width,
        unsigned int dxt_height,
        unsigned int read_offset_x,
        __int64 read_scale_x,
        vostok::render::backend *temp_data,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a8)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::render::surfaces_cache *v9; // esi
  char *v10; // edi
  bool v11; // zf
  vostok::render::backend *v12; // ecx
  vostok::render::render_target *v13; // ecx
  vostok::render::texture_gpu_converter_cook *v14; // ecx
  vostok::render::res_texture *v15; // esi
  vostok::render::resource_manager *v16; // ecx
  vostok::particle::particle_system_instance_impl *v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edi
  unsigned int v20; // ebx
  unsigned __int8 *v21; // esi
  unsigned __int8 **v22; // ebx
  vostok::memory::doug_lea_allocator *v23; // ecx
  vostok::render::res_texture *v24; // esi
  vostok::render::resource_manager *v25; // ecx
  vostok::render::render_target *v26; // eax
  const vostok::render::shader_constant_host *v27; // [esp-8h] [ebp-28h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v28; // [esp-4h] [ebp-24h] BYREF
  unsigned int *v29; // [esp+0h] [ebp-20h]
  vostok::render::res_texture *v30; // [esp+4h] [ebp-1Ch]
  unsigned int v31; // [esp+8h] [ebp-18h]
  unsigned int v32; // [esp+Ch] [ebp-14h]
  vostok::render::render_target *rt; // [esp+10h] [ebp-10h] BYREF
  vostok::render::resource_manager *v34; // [esp+14h] [ebp-Ch] BYREF
  vostok::math::float3 arg; // [esp+18h] [ebp-8h] BYREF

  m_object = a8.m_object;
  HIBYTE(a8.m_object) = *(&a8.m_object->m_reconstruction_size + 1) == 77;
  v9 = (vostok::render::surfaces_cache *)(in_out_mip_memory_start + 8);
  v10 = (char *)(HIBYTE(a8.m_object) == 0 ? 12 : 3);
  vostok::render::surfaces_cache::get_rt(
    v10,
    (vostok::render::surfaces_cache *)(in_out_mip_memory_start + 8),
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt,
    dxt_height,
    (vostok::render::render_target *)read_offset_x,
    (bool)v29);
  vostok::render::surfaces_cache::get_tex(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v34,
    dxt_height,
    (const D3D11_SUBRESOURCE_DATA *)read_offset_x,
    (vostok::render::res_texture *)v10,
    (const unsigned int)v29);
  arg.y = 0.0;
  if ( HIBYTE(a8.m_object) )
  {
    v11 = LOBYTE(m_object->m_children_resources.m_thread_id) == 0;
    LODWORD(arg.y) = 1;
    if ( !v11 )
      LODWORD(arg.y) = 2;
  }
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a8,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&vostok::quasi_singleton<vostok::render::system_renderer>::pinst->m_block_compression_effect);
  vostok::render::res_effect::apply((vostok::render::res_effect *)LODWORD(arg.y), (int)a8.m_object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a8);
  vostok::render::backend::set_ps_texture(
    temp_data,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base_pixels",
    *(vostok::render::res_texture **)(m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                    + 4 * (_DWORD)temp_data));
  v28.m_object = (vostok::render::render_target *)&arg;
  v27 = (const vostok::render::shader_constant_host *)in_out_mip_memory_start[22];
  *(_QWORD *)&arg.x = read_scale_x;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v12,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v27,
    &arg);
  v28.m_object = v13;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v28,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::texture_gpu_converter_cook::fill_surface(
    v14,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)in_out_mip_memory_start,
    v28.m_object);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_out_mip_memory_start,
    &rt->m_texture);
  v15 = (vostok::render::res_texture *)in_out_mip_memory_start;
  vostok::render::resource_manager::copy2D(
    dxt_height,
    v34,
    (vostok::render::res_texture *)in_out_mip_memory_start,
    read_offset_x,
    (unsigned int)v29,
    v30,
    v31,
    v32,
    (unsigned int)rt,
    (unsigned int)v34,
    LODWORD(arg.x));
  if ( v15 )
  {
    v11 = v15->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        v16,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v15);
  }
  in_out_mip_memory_start = 0;
  v17 = (vostok::particle::particle_system_instance_impl *)vostok::render::res_texture::map2D(
                                                             (vostok::render::res_texture *)v16,
                                                             (int)v34,
                                                             &in_out_mip_memory_start,
                                                             0,
                                                             v29,
                                                             (bool)v30);
  v28.m_object = (vostok::render::render_target *)*(&m_object->m_reconstruction_size + 1);
  a8.m_object = v17;
  v18 = vostok::render::calc_bytes_per_block((DXGI_FORMAT)v28.m_object);
  v19 = read_offset_x * dxt_height * v18;
  if ( in_out_mip_memory_start == (unsigned __int8 **)dxt_height )
  {
    memcpy(*dxt_width, (unsigned __int8 *)a8.m_object, v19);
    v22 = dxt_width;
  }
  else
  {
    v20 = dxt_height * v18;
    v21 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                               (vostok::memory::doug_lea_allocator *)dxt_height,
                               (int)vostok::render::g_allocator,
                               read_offset_x * dxt_height * v18,
                               "dxt_blocks",
                               (const char *const)v29,
                               (const char *const)v30,
                               v31);
    for ( dxt_height = (unsigned int)v21; read_offset_x; --read_offset_x )
    {
      memcpy((unsigned __int8 *)dxt_height, (unsigned __int8 *)a8.m_object, v20);
      dxt_height += v20;
      a8.m_object = (vostok::particle::particle_system_instance_impl *)((char *)a8.m_object
                                                                      + (unsigned int)in_out_mip_memory_start);
    }
    v22 = dxt_width;
    memcpy(*dxt_width, v21, v19);
    if ( v21 )
      vostok::memory::doug_lea_allocator::free_impl(
        v23,
        (int)vostok::render::g_allocator,
        (char *)v21,
        (const char *const)v29,
        (const char *const)v30,
        v31);
  }
  v24 = (vostok::render::res_texture *)v34;
  *v22 += v19;
  vostok::render::res_texture::unmap2D((vostok::render::res_texture *)v23, (int)v24);
  if ( v24 )
  {
    v11 = v24->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        v25,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v24);
  }
  v26 = rt;
  if ( rt )
  {
    v11 = rt->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(v26, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
}
