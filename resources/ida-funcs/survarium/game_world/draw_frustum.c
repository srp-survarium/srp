void __userpurge survarium::game_world::draw_frustum(
        survarium::game_world *this@<ecx>,
        float a2@<edi>,
        bool a3@<sil>,
        float fov_in_radians,
        float far_plane_distance,
        float aspect_ratio,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        vostok::math::color color)
{
  vostok::math::float3 v9; // [esp+18h] [ebp-1Ch]
  int v10; // [esp+28h] [ebp-Ch]
  const vostok::math::float4x4 *v11; // [esp+2Ch] [ebp-8h]
  int v12; // [esp+30h] [ebp-4h]

  v9.z = a2;
  v12 = 0;
  v10 = 0;
  v11 = clear_value;
  *(_QWORD *)&v9.x = (unsigned int)clear_value;
  vostok::render::debug::renderer::draw_frustum(
    (vostok::render::debug::renderer *)this[-1].m_victory_items._M_impl._M_start[37].m_object->m_usable_object_users.m_size,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_enemies_for_team_2,
    fov_in_radians,
    far_plane_distance,
    aspect_ratio,
    *(float *)&position,
    direction,
    0,
    v9,
    &color,
    a3);
}
