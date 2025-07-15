void __userpurge vostok::render::light::light(
        vostok::collision::space_partitioning_tree *tree@<eax>,
        vostok::render::light *this)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  vostok::math::float4x4 *shadow_distribution_sides; // ecx
  unsigned int *previous_static_shadow_visible_objects_count; // eax
  vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 *v7; // edi
  bool v8; // zf
  vostok::math::float4x4 v9; // [esp+4h] [ebp-5Ch] BYREF
  int v10; // [esp+44h] [ebp-1Ch]
  __int64 v11; // [esp+48h] [ebp-18h]
  int v12; // [esp+50h] [ebp-10h]
  vostok::math::float4x4 *m_view_to_light; // [esp+54h] [ebp-Ch]
  bool *v14; // [esp+58h] [ebp-8h]
  unsigned int *v15; // [esp+68h] [ebp+8h]

  this->m_occlusion_info_index = -1;
  this->m_collision_tree = tree;
  this->shadow_transparency = FLOAT_0_1;
  this->m_reference_count = 0;
  this->m_lod = 0;
  this->m_occluded = 0;
  this->static_shadows = 0;
  this->m_force_refresh = 1;
  this->m_enabled = 1;
  this->m_particle_light = 0;
  this->m_collision_geometry = 0;
  this->m_collision_object = 0;
  memset(this->m_shadow_depth_stencil, 0, sizeof(this->m_shadow_depth_stencil));
  memset(this->m_shadow_depth_stencil_texture, 0, sizeof(this->m_shadow_depth_stencil_texture));
  this->m_color_curve.points.max_storage = 0;
  this->m_current_animation_time = 0.0;
  this->is_shadower = 0;
  this->use_with_lpv = 0;
  this->occluded = 0;
  this->sun_shadow_map_size = 2048;
  this->num_sun_cascades = 4;
  this->shadow_z_bias = epsilon_3_4;
  this->shadow_map_size = 1024;
  this->lighting_model = 1;
  vostok::math::create_zero_aabb(&this->m_aabb);
  this->m_shadow_map_size_index = 0;
  this->m_quality_shadow_map_size_index = 0;
  *(_DWORD *)&this->flags &= 0xFFFFFF80;
  v11 = 0;
  this->previous_direction.x = 0.0;
  *(_QWORD *)&this->previous_direction.elements[1] = v11;
  v10 = 0;
  v11 = LODWORD(FLOAT_N1000_0);
  v2 = s_bm_current_air_resistance;
  this->position.x = 0.0;
  *(_QWORD *)&this->position.elements[1] = v11;
  *(_QWORD *)&this->direction.x = 0;
  this->direction.z = v2;
  *(_QWORD *)&this->right.elements[1] = 0;
  v3 = gran1;
  this->right.x = v2;
  this->range = v3;
  this->color.x = v2;
  this->color.y = v2;
  this->color.z = v2;
  vostok::math::curve_line_color::set_defaults(&this->m_color_curve);
  shadow_distribution_sides = (vostok::math::float4x4 *)this->shadow_distribution_sides;
  m_view_to_light = this->m_view_to_light;
  previous_static_shadow_visible_objects_count = this->previous_static_shadow_visible_objects_count;
  v14 = this->shadow_distribution_sides;
  v15 = this->previous_static_shadow_visible_objects_count;
  v12 = 6;
  while ( 1 )
  {
    BYTE2(shadow_distribution_sides[-4].lines[1].elements[0]) = 1;
    LOBYTE(shadow_distribution_sides->i.x) = 1;
    previous_static_shadow_visible_objects_count[6] = 0;
    *previous_static_shadow_visible_objects_count = 0;
    v6 = vostok::math::float4x4::identity(shadow_distribution_sides, &v9);
    v7 = m_view_to_light;
    ++v15;
    ++v14;
    ++m_view_to_light;
    v8 = v12-- == 1;
    qmemcpy(v7, v6, sizeof(vostok::math::float4x4));
    if ( v8 )
      break;
    shadow_distribution_sides = (vostok::math::float4x4 *)v14;
    previous_static_shadow_visible_objects_count = v15;
  }
}
