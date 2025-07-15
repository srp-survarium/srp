vostok::math::float4x4 *__thiscall vostok::animation::hand_to_weapon_ik_solver::get_hand_target_transform(
        vostok::animation::hand_to_weapon_ik_solver *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *h,
        _DWORD *current_time_in_ms,
        const vostok::math::float4x4 *item_transform,
        const vostok::math::float4x4 *character_matrices,
        vostok::math::float4x4 *item_matrices,
        struct vostok::math::float4x4 *is_first_view,
        char a9)
{
  const vostok::math::float4x4 *v9; // eax
  vostok::math::float4x4 *v10; // eax
  const vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 *bone_matrix_in_object_space; // eax
  vostok::math::float4x4 *locator_transform_in_item_space; // eax
  vostok::math::float4x4 *v14; // esi
  const vostok::math::float4x4 *v15; // eax
  vostok::math::float4x4 *v16; // eax
  vostok::math::float4x4 *v17; // eax
  double v18; // st7
  float v20; // [esp+4h] [ebp-154h]
  vostok::math::float4x4 bone; // [esp+18h] [ebp-140h] BYREF
  vostok::math::float4x4 v22; // [esp+58h] [ebp-100h] BYREF
  vostok::math::float4x4 v23; // [esp+98h] [ebp-C0h] BYREF
  vostok::math::float4x4 v24; // [esp+D8h] [ebp-80h] BYREF
  vostok::math::float4x4 v25; // [esp+118h] [ebp-40h] BYREF
  float is_first_viewa; // [esp+178h] [ebp+20h]

  if ( (unsigned int)item_transform - current_time_in_ms[150] < 0x12C )
  {
    v11 = (const vostok::math::float4x4 *)current_time_in_ms[155];
    if ( v11 == (const vostok::math::float4x4 *)4 )
    {
      bone_matrix_in_object_space = vostok::animation::get_bone_matrix_in_object_space(
                                      (const vostok::animation::skeleton *)LODWORD(result[19].c.y),
                                      &bone,
                                      (const vostok::animation::skeleton_bone *)(LODWORD(result[19].c.y)
                                                                               + 272
                                                                               + 28 * current_time_in_ms[151]),
                                      item_matrices);
    }
    else
    {
      if ( (int)v11 <= 2 )
      {
        locator_transform_in_item_space = vostok::animation::hand_to_weapon_ik_solver::get_locator_transform_in_item_space(
                                            (vostok::math::float4x4 *)this,
                                            &v25,
                                            (vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum)current_time_in_ms,
                                            v11,
                                            (int)is_first_view,
                                            a9);
      }
      else
      {
        qmemcpy(&v25, &is_first_view[current_time_in_ms[153]], sizeof(v25));
        locator_transform_in_item_space = &v25;
      }
      vostok::math::mul4x3(character_matrices, locator_transform_in_item_space, &v24);
      bone_matrix_in_object_space = &v24;
    }
    v14 = bone_matrix_in_object_space;
    v15 = (const vostok::math::float4x4 *)current_time_in_ms[154];
    qmemcpy(&v22, v14, sizeof(v22));
    if ( v15 == (const vostok::math::float4x4 *)4 )
    {
      v16 = vostok::animation::get_bone_matrix_in_object_space(
              (const vostok::animation::skeleton *)LODWORD(result[19].c.y),
              &bone,
              (const vostok::animation::skeleton_bone *)(LODWORD(result[19].c.y) + 272 + 28 * current_time_in_ms[151]),
              item_matrices);
    }
    else
    {
      if ( (int)v15 <= 2 )
      {
        v17 = vostok::animation::hand_to_weapon_ik_solver::get_locator_transform_in_item_space(
                0,
                &v25,
                (vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum)current_time_in_ms,
                v15,
                (int)is_first_view,
                a9);
      }
      else
      {
        qmemcpy(&v25, &is_first_view[current_time_in_ms[153]], sizeof(v25));
        v17 = &v25;
      }
      vostok::math::mul4x3(character_matrices, v17, &v24);
      v16 = &v24;
    }
    v18 = (double)((unsigned int)item_transform - current_time_in_ms[150]);
    qmemcpy(&v23, v16, sizeof(v23));
    v20 = v18 * 0.001;
    is_first_viewa = ((double (__stdcall *)(_DWORD))*(_DWORD *)LODWORD(result[19].k.z))(LODWORD(v20));
    vostok::animation::mix_transformations(
      &v22,
      &v23,
      is_first_viewa,
      h,
      (struct vostok::math::float4x4 *)LODWORD(is_first_viewa));
  }
  else
  {
    v9 = (const vostok::math::float4x4 *)current_time_in_ms[154];
    if ( (int)v9 <= 2 )
    {
      v10 = vostok::animation::hand_to_weapon_ik_solver::get_locator_transform_in_item_space(
              (vostok::math::float4x4 *)this,
              &v25,
              (vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum)current_time_in_ms,
              v9,
              (int)is_first_view,
              a9);
    }
    else
    {
      qmemcpy(&v25, &is_first_view[current_time_in_ms[153]], sizeof(v25));
      v10 = &v25;
    }
    vostok::math::mul4x3(character_matrices, v10, h);
  }
  return h;
}
