void __userpurge vostok::render::particle_sprite_vertex::set(
        vostok::render::particle_sprite_vertex *this@<ecx>,
        int a2@<eax>,
        vostok::math::float3 in_position,
        vostok::math::float4 in_color,
        vostok::math::float2 in_uv,
        vostok::math::float2 in_size,
        float in_rotation,
        float in_gravity,
        vostok::math::float3 in_old_position)
{
  *(_QWORD *)a2 = *(_QWORD *)&in_position.x;
  *(vostok::math::float4 *)(a2 + 12) = in_color;
  *(float *)(a2 + 8) = in_position.z;
  *(float *)(a2 + 28) = in_uv.x;
  *(float *)(a2 + 44) = in_rotation;
  *(float *)(a2 + 32) = in_uv.y;
  *(float *)(a2 + 36) = in_size.x;
  *(_QWORD *)(a2 + 52) = *(_QWORD *)&in_old_position.x;
  *(float *)(a2 + 40) = in_size.y;
  *(float *)(a2 + 60) = in_old_position.z;
  *(float *)(a2 + 48) = in_gravity;
}
