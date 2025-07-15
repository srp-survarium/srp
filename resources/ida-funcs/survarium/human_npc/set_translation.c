void __userpurge survarium::human_npc::set_translation(
        survarium::human_npc *this@<ecx>,
        vostok::math::float3 *a2@<edi>,
        survarium::human_npc *new_translation,
        const vostok::math::float4x4 *new_translationa)
{
  float *p_x; // esi
  vostok::math::float4x4 *v5; // ecx
  const vostok::math::float3 *angles_xyz; // eax
  const vostok::math::float4x4 *v7; // eax
  float v8; // [esp+10h] [ebp-D0h]
  float v9; // [esp+14h] [ebp-CCh]
  float v10; // [esp+18h] [ebp-C8h]
  vostok::math::float4x4 new_transform; // [esp+1Ch] [ebp-C4h] BYREF
  vostok::math::float4x4 left; // [esp+5Ch] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+9Ch] [ebp-44h] BYREF

  p_x = &new_translation->m_transform.i.x;
  v8 = sqrtf(
         (float)((float)(new_translation->m_transform.i.y * new_translation->m_transform.i.y)
               + (float)(new_translation->m_transform.i.z * new_translation->m_transform.i.z))
       + (float)(new_translation->m_transform.i.x * new_translation->m_transform.i.x));
  v9 = sqrtf((float)((float)(p_x[5] * p_x[5]) + (float)(p_x[6] * p_x[6])) + (float)(p_x[4] * p_x[4]));
  v10 = sqrtf((float)((float)(p_x[10] * p_x[10]) + (float)(p_x[8] * p_x[8])) + (float)(p_x[9] * p_x[9]));
  memset((int)&new_transform, 0, sizeof(new_transform));
  new_transform.j.y = v9;
  new_transform.i.x = v8;
  new_transform.k.z = v10;
  LODWORD(new_transform.c.w) = clear_value;
  angles_xyz = vostok::math::float4x4::get_angles_xyz(v5, a2);
  v7 = vostok::math::create_rotation(&result, angles_xyz);
  vostok::math::mul4x3(&left, &new_transform, v7);
  vostok::math::mul4x3(&new_transform, &left, new_translationa);
  survarium::human_npc::set_transform(&new_transform, new_translation);
}
