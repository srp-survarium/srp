vostok::math::float4 *__thiscall vostok::particle::color_matrix::evaluate(
        vostok::particle::color_matrix *this,
        vostok::math::float4 *result,
        float x,
        float y,
        const vostok::math::float4 *default_value)
{
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  survarium::game_camera *v14; // ecx
  float v15; // xmm0_4
  survarium::game_camera *pointer; // [esp+44h] [ebp-94h]
  vostok::math::float4_pod v18; // [esp+50h] [ebp-88h] BYREF
  vostok::math::float4 v19; // [esp+60h] [ebp-78h] BYREF
  vostok::particle::color_matrix_point_type *v20; // [esp+70h] [ebp-68h]
  vostok::particle::color_matrix_point_type *v21; // [esp+74h] [ebp-64h]
  unsigned int row_index; // [esp+78h] [ebp-60h]
  const vostok::particle::color_matrix_point_type *curr; // [esp+7Ch] [ebp-5Ch]
  const vostok::particle::color_matrix_point_type *prev; // [esp+80h] [ebp-58h]
  unsigned int column_index; // [esp+84h] [ebp-54h]
  float dist_y; // [esp+88h] [ebp-50h]
  vostok::math::float4 resulta; // [esp+8Ch] [ebp-4Ch] BYREF
  float alpha_y; // [esp+9Ch] [ebp-3Ch]
  unsigned int upper_row; // [esp+A0h] [ebp-38h]
  float alpha_x; // [esp+A4h] [ebp-34h]
  const vostok::particle::color_matrix_point_type *upper_left_point; // [esp+A8h] [ebp-30h]
  const vostok::particle::color_matrix_point_type *lower_left_point; // [esp+ACh] [ebp-2Ch]
  unsigned int lower_row; // [esp+B0h] [ebp-28h]
  bool found_rows; // [esp+B7h] [ebp-21h]
  float dist_x; // [esp+B8h] [ebp-20h]
  const vostok::particle::color_matrix_point_type *lower_right_point; // [esp+BCh] [ebp-1Ch]
  unsigned int left_column; // [esp+C0h] [ebp-18h]
  unsigned int right_column; // [esp+C4h] [ebp-14h]
  const vostok::particle::color_matrix_point_type *upper_right_point; // [esp+C8h] [ebp-10h]
  float y_scaled; // [esp+CCh] [ebp-Ch]
  bool found_columns; // [esp+D3h] [ebp-5h]
  float x_scaled; // [esp+D4h] [ebp-4h]

  vostok::math::clamp<float>(&x, 0.0, 1.0);
  vostok::math::clamp<float>(&y, 0.0, 1.0);
  if ( this->m_evaluate_type == random_evaluate_type )
    x = vostok::particle::random_float(0.0, 1.0);
  x_scaled = x * *(float *)&clear_value;
  y_scaled = y * *(float *)&clear_value;
  left_column = 0;
  right_column = 0;
  found_columns = 0;
  for ( column_index = 1; column_index < this->m_num_columns; ++column_index )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    survarium::weapon_user_dead_state::finalize(v6);
    pointer = (survarium::game_camera *)this->m_points.pointer;
    curr = &this->m_points.pointer[column_index];
    survarium::weapon_user_dead_state::finalize(pointer);
    survarium::weapon_user_dead_state::finalize(v7);
    prev = &this->m_points.pointer[column_index - 1];
    if ( x_scaled >= prev->position.x && curr->position.x >= x_scaled )
    {
      left_column = column_index - 1;
      right_column = column_index;
      found_columns = 1;
      break;
    }
    v5 = (survarium::game_camera *)(column_index + 1);
  }
  if ( found_columns )
  {
    upper_row = 0;
    lower_row = 0;
    found_rows = 0;
    for ( row_index = 1; row_index < this->m_num_rows; ++row_index )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      survarium::weapon_user_dead_state::finalize(v9);
      v20 = &this->m_points.pointer[this->m_num_columns * row_index];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      survarium::weapon_user_dead_state::finalize(v10);
      v21 = &this->m_points.pointer[this->m_num_columns * (row_index - 1)];
      if ( y_scaled >= v21->position.y && v20->position.y >= y_scaled )
      {
        upper_row = row_index - 1;
        lower_row = row_index;
        found_rows = 1;
        break;
      }
    }
    if ( found_rows )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)found_rows);
      survarium::weapon_user_dead_state::finalize(v11);
      upper_left_point = &this->m_points.pointer[left_column + this->m_num_columns * upper_row];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      survarium::weapon_user_dead_state::finalize(v12);
      upper_right_point = &this->m_points.pointer[right_column + this->m_num_columns * upper_row];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      survarium::weapon_user_dead_state::finalize(v13);
      lower_left_point = &this->m_points.pointer[left_column + this->m_num_columns * lower_row];
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      survarium::weapon_user_dead_state::finalize(v14);
      lower_right_point = &this->m_points.pointer[right_column + this->m_num_columns * lower_row];
      dist_x = upper_right_point->position.x - upper_left_point->position.x;
      dist_y = lower_right_point->position.y - upper_right_point->position.y;
      v15 = dist_y;
      vostok::math::abs();
      if ( dist_y <= 0.0000099999997 )
      {
        v15 = *(float *)&clear_value;
        dist_x = *(float *)&clear_value;
      }
      vostok::math::abs();
      if ( v15 <= 0.0000099999997 )
        dist_y = *(float *)&clear_value;
      alpha_x = (float)(x_scaled - upper_left_point->position.x) / dist_x;
      alpha_y = (float)(y_scaled - upper_right_point->position.y) / dist_y;
      v19 = (vostok::math::float4)*vostok::particle::bilinear_interpolation<vostok::math::float4_pod>(
                                     &v18,
                                     upper_left_point->color,
                                     upper_right_point->color,
                                     lower_left_point->color,
                                     lower_right_point->color,
                                     alpha_x,
                                     alpha_y);
      vostok::math::float4::float4(&v19, &resulta);
      *result = resulta;
      return result;
    }
    else
    {
      *result = *default_value;
      return result;
    }
  }
  else
  {
    *result = *default_value;
    return result;
  }
}
