void __userpurge vostok::animation::legs_ik_solver::process(
        vostok::animation::legs_ik_solver *this@<ecx>,
        float a2@<xmm10>,
        float matrices,
        vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *a4)
{
  vostok::math::float4x4 *v5; // ebx
  vostok::math::float4x4 *v6; // edi
  vostok::animation::legs_ik_solver *v7; // ecx
  float v8; // xmm0_4
  vostok::animation::legs_ik_solver *v9; // ecx
  vostok::animation::legs_ik_solver *v10; // ecx
  vostok::animation::legs_ik_solver *v11; // ecx
  vostok::animation::legs_ik_solver *v12; // ecx
  vostok::math::float4x4 params; // [esp+10h] [ebp-14Ch] BYREF
  vostok::math::float4x4 v14; // [esp+50h] [ebp-10Ch] BYREF
  vostok::math::float4x4 bone; // [esp+90h] [ebp-CCh] BYREF
  vostok::math::float4x4 matricesa; // [esp+D0h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v17; // [esp+114h] [ebp-48h] BYREF
  float v18[2]; // [esp+154h] [ebp-8h] BYREF

  v5 = (vostok::math::float4x4 *)LODWORD(matrices);
  v6 = transform;
  vostok::animation::get_bone_matrix_in_object_space(
    *(const vostok::animation::skeleton **)LODWORD(matrices),
    &bone,
    *(const vostok::animation::skeleton_bone **)(LODWORD(matrices) + 120),
    transform);
  vostok::math::mul4x3(a4, &bone, &matricesa);
  matrices = 0.0;
  vostok::animation::legs_ik_solver::get_foot_fixed_transform(
    v7,
    a2,
    v5,
    &params,
    (const vostok::math::float4x4 *)&v5->lines[1],
    (int)&matricesa,
    &v6->i.x,
    &matrices);
  v18[0] = 0.0;
  vostok::animation::legs_ik_solver::get_foot_fixed_transform(
    (vostok::animation::legs_ik_solver *)&matricesa,
    a2,
    v5,
    &v14,
    v5 + 1,
    (int)&matricesa,
    &v6->i.x,
    v18);
  vostok::math::float4x4::try_invert(a4, &matricesa);
  if ( s_ik_adjust_hip_position_value && (matrices < 0.0 || v18[0] < 0.0) )
  {
    if ( (LOBYTE(v5->lines[3].elements[3]) || BYTE1(v5->lines[3].elements[3])) && matrices < 0.0 && v18[0] > 0.0 )
    {
      v8 = v6->c.y + matrices;
LABEL_9:
      v6->c.y = v8;
      qmemcpy(
        &bone,
        vostok::animation::get_bone_matrix_in_object_space(
          (const vostok::animation::skeleton *)LODWORD(v5->i.x),
          &v17,
          (const vostok::animation::skeleton_bone *)LODWORD(v5[1].c.z),
          v6),
        sizeof(bone));
      vostok::math::mul4x3(&matricesa, &params, &v17);
      vostok::animation::legs_ik_solver::process_leg(
        v9,
        (vostok::animation::legs_ik_solver::leg_params *)v5,
        (const vostok::math::float4x4 *)&v5->lines[1],
        (vostok::math::float3_pod *)&v17,
        &bone,
        transform,
        a4);
      vostok::math::mul4x3(&matricesa, &v14, &v17);
      vostok::animation::legs_ik_solver::process_leg(
        v10,
        (vostok::animation::legs_ik_solver::leg_params *)v5,
        v5 + 1,
        (vostok::math::float3_pod *)&v17,
        &bone,
        transform,
        a4);
      return;
    }
    if ( (LOBYTE(v5[1].lines[2].elements[3]) || BYTE1(v5[1].lines[2].elements[3])) && matrices > 0.0 && v18[0] < 0.0 )
    {
      v8 = v6->c.y + v18[0];
      goto LABEL_9;
    }
  }
  else
  {
    vostok::math::mul4x3(&matricesa, &params, &v17);
    vostok::animation::legs_ik_solver::process_leg(
      v11,
      (vostok::animation::legs_ik_solver::leg_params *)v5,
      (const vostok::math::float4x4 *)&v5->lines[1],
      (vostok::math::float3_pod *)&v17,
      &bone,
      v6,
      a4);
    vostok::math::mul4x3(&matricesa, &v14, &v17);
    vostok::animation::legs_ik_solver::process_leg(
      v12,
      (vostok::animation::legs_ik_solver::leg_params *)v5,
      v5 + 1,
      (vostok::math::float3_pod *)&v17,
      &bone,
      v6,
      a4);
  }
}
