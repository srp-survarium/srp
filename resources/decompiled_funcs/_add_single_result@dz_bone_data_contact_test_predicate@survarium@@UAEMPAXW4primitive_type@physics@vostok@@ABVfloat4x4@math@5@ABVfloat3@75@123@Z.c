double __thiscall survarium::dz_bone_data_contact_test_predicate::add_single_result(
        survarium::dz_bone_data_contact_test_predicate *this,
        vostok::collision::bone_collision_data *user_data,
        vostok::physics::primitive_type first_shape_type,
        const vostok::math::float4x4 *first_shape_transform,
        const vostok::math::float3 *first_shape_dimension,
        survarium::game_camera *second_shape_type,
        const vostok::math::float4x4 *second_shape_transform,
        const vostok::math::float3 *second_shape_dimension)
{
  _BYTE *v8; // eax
  float *v10; // eax
  survarium::game_camera *v11; // ecx
  const vostok::math::float3 *v12; // eax
  const vostok::math::float3 *v13; // eax
  float *v14; // eax
  const vostok::math::float3 *v15; // eax
  float *v16; // eax
  const vostok::math::float3_pod *v17; // eax
  const vostok::math::float3_pod *v18; // esi
  survarium::game_camera *v19; // ecx
  const vostok::math::float3_pod *v20; // eax
  vostok::math::float3 *v21; // eax
  vostok::math::float3_pod *v22; // ecx
  float index; // [esp+4h] [ebp-64h]
  float indexa; // [esp+4h] [ebp-64h]
  const vostok::math::float3 *radius; // [esp+8h] [ebp-60h]
  const vostok::math::float3 *radiusa; // [esp+8h] [ebp-60h]
  vostok::fixed_string<16> *M_finish; // [esp+40h] [ebp-28h]
  vostok::math::float3 v29; // [esp+44h] [ebp-24h] BYREF
  survarium::compare_body_parts_predicate __pred; // [esp+50h] [ebp-18h]
  char v31; // [esp+57h] [ebp-11h]
  stlp_std::pair<vostok::collision::bone_collision_data *,float> result; // [esp+58h] [ebp-10h] BYREF
  float d_1; // [esp+60h] [ebp-8h]
  float max_distance; // [esp+64h] [ebp-4h]

  v31 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v8 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(first_shape_dimension->y));
  result.second = *(float *)&FLOAT_0_0;
  result.first = user_data;
  if ( this->m_body_parts_filter )
  {
    M_finish = this->m_body_parts_filter->_M_impl._M_finish;
    __pred.m_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                    (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)M_finish,
                                    (int)&result.first->body_part_name);
    if ( M_finish == stlp_std::find_if<vostok::fixed_string<16> const *,survarium::compare_body_parts_predicate>(
                       this->m_body_parts_filter->_M_impl._M_start,
                       this->m_body_parts_filter->_M_impl._M_finish,
                       __pred) )
      return 0.0;
  }
  max_distance = *(float *)&FLOAT_0_0;
  switch ( (unsigned int)second_shape_type )
  {
    case 0u:
      v10 = (float *)vostok::math::float3_pod::operator[](0, (int)second_shape_dimension);
      max_distance = survarium::distance_from_sphere_center_to_point_on_shape(*v10);
      break;
    case 1u:
      survarium::weapon_user_dead_state::finalize(second_shape_type);
      max_distance = survarium::distance_from_box_center_to_point_on_shape(
                       second_shape_transform,
                       second_shape_dimension,
                       v12);
      break;
    case 2u:
      survarium::weapon_user_dead_state::finalize(second_shape_type);
      radiusa = v15;
      indexa = *vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)1, (int)second_shape_dimension);
      v16 = (float *)vostok::math::float3_pod::operator[](0, (int)second_shape_dimension);
      max_distance = survarium::distance_from_cylinder_center_to_point_on_shape(
                       second_shape_transform,
                       *v16,
                       indexa,
                       radiusa);
      break;
    case 3u:
      survarium::weapon_user_dead_state::finalize(second_shape_type);
      radius = v13;
      index = *vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)1, (int)second_shape_dimension);
      v14 = (float *)vostok::math::float3_pod::operator[](0, (int)second_shape_dimension);
      max_distance = survarium::distance_from_capsule_center_to_point_on_shape(
                       second_shape_transform,
                       *v14,
                       index,
                       radius);
      break;
  }
  survarium::weapon_user_dead_state::finalize(v11);
  v18 = v17;
  survarium::weapon_user_dead_state::finalize(v19);
  v21 = vostok::math::operator-(v18, v20, &v29);
  d_1 = vostok::math::float3_pod::length(v22, &v21->x);
  result.second = d_1 / max_distance;
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::collision::bone_collision_data *,float>,vostok::vectora_allocator<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>::push_back(
    &this->m_result->_M_impl,
    &result);
  return 0.0;
}
