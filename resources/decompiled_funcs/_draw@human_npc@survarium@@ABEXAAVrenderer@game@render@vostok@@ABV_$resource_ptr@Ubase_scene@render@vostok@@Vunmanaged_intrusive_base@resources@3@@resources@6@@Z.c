void __userpurge survarium::human_npc::draw(
        survarium::human_npc *this@<ecx>,
        int render,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v3; // ebp
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  vostok::render::debug::renderer *m_flags; // eax
  vostok::render::base_scene *m_object; // ecx
  int (__thiscall *m_reconstruction_info_actuality_tick_high)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float3 *); // edx
  vostok::render::debug::renderer *v11; // esi
  const vostok::math::float3 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  vostok::render::base_scene *v14; // eax
  vostok::render::debug::renderer *v15; // [esp-8h] [ebp-70h]
  bool v16; // [esp+0h] [ebp-68h]
  bool v17; // [esp+0h] [ebp-68h]
  vostok::math::float3 start_point; // [esp+10h] [ebp-58h] BYREF
  vostok::math::float3 end_point; // [esp+1Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 result; // [esp+28h] [ebp-40h] BYREF

  v3 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)render;
  survarium::human_npc::draw_damage_model(this, render);
  vostok::render::debug::renderer::draw_origin(v3 + 157, 1);
  ((void (__thiscall *)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float3 *))HIDWORD(v3->m_object->m_reconstruction_info_actuality_tick))(
    v3,
    &start_point);
  v4 = (float *)((int (__thiscall *)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float3 *))LODWORD(v3->m_object->m_reconstruction_info_actuality_tick))(
                  v3,
                  &end_point);
  v5 = v4[1] * 2.0;
  v6 = v4[2] * 2.0;
  v7 = start_point.x + (float)(*v4 * 2.0);
  m_flags = (vostok::render::debug::renderer *)v3[86].m_object->m_flags.m_flags;
  end_point.y = start_point.y + v5;
  end_point.x = v7;
  end_point.z = start_point.z + v6;
  render = -16776961;
  vostok::render::debug::renderer::draw_arrow(
    m_flags,
    v3 + 157,
    &start_point,
    &end_point,
    (const vostok::math::color *)&render,
    (const vostok::math::color *)&render,
    v16);
  if ( LOBYTE(v3[176].m_object) )
  {
    m_object = v3[86].m_object;
    m_reconstruction_info_actuality_tick_high = (int (__thiscall *)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float3 *))HIDWORD(v3->m_object->m_reconstruction_info_actuality_tick);
    render = -16776961;
    v11 = (vostok::render::debug::renderer *)m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    v12 = (const vostok::math::float3 *)m_reconstruction_info_actuality_tick_high(v3, &end_point);
    v13 = vostok::math::create_translation(&result, v12);
    vostok::render::debug::renderer::draw_line_ellipsoid(v11, v3 + 157, v13, (const vostok::math::color *)&render, v17);
    LOBYTE(v3[176].m_object) = 0;
  }
  if ( BYTE1(v3[176].m_object) )
  {
    v15 = (vostok::render::debug::renderer *)v3[86].m_object->m_flags.m_flags;
    render = -16711936;
    vostok::render::debug::renderer::draw_line_ellipsoid(
      v15,
      v3 + 157,
      (const vostok::math::float4x4 *)&v3[140],
      (const vostok::math::color *)&render,
      v17);
    BYTE1(v3[176].m_object) = 0;
  }
  v14 = v3[161].m_object;
  if ( v14->m_sub_fat.m_object )
    ((void (__thiscall *)(vostok::resources::vfs_sub_fat_resource *, vostok::render::base_scene *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *))v14->m_sub_fat.m_object->increase_quality_to_target)(
      v14->m_sub_fat.m_object,
      v3[86].m_object,
      v3 + 157);
}
