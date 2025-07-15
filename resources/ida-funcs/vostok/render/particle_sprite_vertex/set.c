int __userpurge vostok::render::particle_sprite_vertex::set@<eax>(
        vostok::render::particle_sprite_vertex *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        vostok::math::float3 in_position,
        vostok::math::float4 in_color,
        vostok::math::float2 in_uv,
        vostok::math::float2 in_size,
        float in_old_position,
        struct vostok::math::float3 in_old_position_4)
{
  *(vostok::math::float3 *)result = in_position;
  *(vostok::math::float4 *)(result + 12) = in_color;
  *(float *)(result + 48) = in_old_position;
  *(float *)(result + 28) = in_uv.x;
  *(float *)(result + 52) = in_old_position_4.x;
  *(float *)(result + 32) = in_uv.y;
  *(float *)(result + 56) = in_old_position_4.y;
  *(vostok::math::float2 *)(result + 36) = in_size;
  *(_DWORD *)(result + 44) = a3;
  return result;
}
