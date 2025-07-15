void __usercall vostok::render::light::light(
        vostok::render::light *this@<eax>,
        vostok::collision::space_partitioning_tree *tree@<edi>)
{
  const vostok::math::float4x4 *v2; // xmm1_4

  this->m_reference_count = 0;
  this->m_occluded = 0;
  this->static_shadows = 0;
  this->m_collision_geometry = 0;
  this->m_collision_object = 0;
  this->shadow_transparency = FLOAT_0_1;
  this->m_occlusion_info_index = -1;
  this->m_collision_tree = tree;
  this->need_refresh_static_shadows = 1;
  this->m_enabled = 1;
  this->m_shadow_depth_stencil.m_object = 0;
  this->m_shadow_depth_stencil_texture.m_object = 0;
  this->m_color_curve.points.max_storage = 0;
  this->m_color_curve.num_points = 0;
  this->m_color_curve.m_evaluate_type = age_evaluate_type;
  this->shadow_z_bias = epsilon_3_11;
  this->is_shadower = 0;
  this->use_with_lpv = 0;
  this->shadow_map_size_index = 0;
  this->occluded = 0;
  this->m_current_animation_time = 0.0;
  this->sun_shadow_map_size = 2048;
  this->num_sun_cascades = 4;
  this->shadow_map_size = 1024;
  this->old_shadow_map_size_index = -1;
  this->lighting_model = 1;
  *(_QWORD *)&this->m_aabb.min.x = 0;
  this->m_aabb.min.z = 0.0;
  *(_QWORD *)&this->m_aabb.max.x = 0;
  this->m_aabb.max.z = 0.0;
  *(_DWORD *)&this->flags &= 0xFFFFFF80;
  *(_QWORD *)&this->previous_direction.x = 0;
  this->previous_direction.z = 0.0;
  *(_QWORD *)&this->position.x = 0xC47A000000000000uLL;
  v2 = clear_value;
  this->position.z = 0.0;
  *(_QWORD *)&this->direction.x = 0;
  LODWORD(this->direction.z) = v2;
  *(_QWORD *)&this->right.elements[1] = 0;
  LODWORD(this->right.x) = v2;
  this->range = 8.0;
  LODWORD(this->color.x) = v2;
  LODWORD(this->color.y) = v2;
  LODWORD(this->color.z) = v2;
  this->shadow_distribution_sides[0] = 1;
}
