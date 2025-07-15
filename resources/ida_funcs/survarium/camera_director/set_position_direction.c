void __userpurge survarium::camera_director::set_position_direction(
        const vostok::math::float3 *p@<eax>,
        const vostok::math::float3 *d@<ecx>,
        survarium::camera_director *this)
{
  vostok::math::float4x4 *v3; // eax
  vostok::math::float3 local_up_in_world_space; // [esp+10h] [ebp-8Ch] BYREF

  local_up_in_world_space.x = 0.0;
  *(_QWORD *)&local_up_in_world_space.elements[1] = (unsigned int)clear_value;
  v3 = vostok::math::create_camera_direction(p, d, &local_up_in_world_space);
  qmemcpy(
    (void *)&this->m_inverted_view,
    invert_impl(
      v3,
      (float)((float)((float)((float)(v3->j.y * v3->k.z) - (float)(v3->j.z * v3->k.y)) * v3->i.x)
            - (float)((float)((float)(v3->j.x * v3->k.z) - (float)(v3->k.x * v3->j.z)) * v3->i.y))
    + (float)((float)((float)(v3->j.x * v3->k.y) - (float)(v3->k.x * v3->j.y)) * v3->i.z)),
    sizeof(this->m_inverted_view));
}
