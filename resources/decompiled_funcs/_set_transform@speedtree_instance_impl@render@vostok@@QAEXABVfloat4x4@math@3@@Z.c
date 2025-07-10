void __thiscall vostok::render::speedtree_instance_impl::set_transform(
        vostok::render::speedtree_instance_impl *this,
        vostok::render::speedtree_instance_impl *transform,
        const vostok::math::float4x4 *transforma)
{
  float v4; // eax
  float z; // ecx
  float v6; // xmm0_4
  vostok::math::float3 *v7; // [esp+4h] [ebp-34h]
  vostok::math::axis_rotation_order v8; // [esp+8h] [ebp-30h]
  float scale; // [esp+14h] [ebp-24h]
  float scale_4; // [esp+18h] [ebp-20h]
  float scale_8; // [esp+1Ch] [ebp-1Ch]
  float rotation_angles_4; // [esp+30h] [ebp-8h]

  qmemcpy((void *)&transform->m_transform, transforma, sizeof(transform->m_transform));
  vostok::math::float4x4::get_angles(0, v7, v8);
  scale = sqrtf(
            (float)((float)(transforma->i.z * transforma->i.z) + (float)(transforma->i.x * transforma->i.x))
          + (float)(transforma->i.y * transforma->i.y));
  scale_4 = sqrtf(
              (float)((float)(transforma->j.z * transforma->j.z) + (float)(transforma->j.x * transforma->j.x))
            + (float)(transforma->j.y * transforma->j.y));
  scale_8 = sqrtf(
              (float)((float)(transforma->k.y * transforma->k.y) + (float)(transforma->k.z * transforma->k.z))
            + (float)(transforma->k.x * transforma->k.x));
  v4 = *(float *)&transform->m_speedtree_instance;
  z = transforma->c.z;
  *(_QWORD *)LODWORD(v4) = *(_QWORD *)&transforma->lines[3].x;
  *(float *)(LODWORD(v4) + 8) = z;
  SpeedTree::CInstance::SetRotation(transform->m_speedtree_instance, -rotation_angles_4);
  if ( scale_4 <= (double)scale_8 )
    v6 = scale_8;
  else
    v6 = scale_4;
  if ( scale > v6 )
    v6 = scale;
  transform->m_speedtree_instance->m_fScale = v6;
}
