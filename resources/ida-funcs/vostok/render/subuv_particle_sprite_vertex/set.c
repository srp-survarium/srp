void __userpurge vostok::render::subuv_particle_sprite_vertex::set(
        vostok::render::subuv_particle_sprite_vertex *this@<ecx>,
        float a2@<edi>,
        vostok::math::float3 in_position,
        vostok::math::float4 in_color,
        vostok::math::float2 in_uv,
        vostok::math::float2 in_size,
        unsigned int in_rotation,
        vostok::math::float3 in_old_position,
        vostok::math::float2 in_size_uv,
        vostok::math::float4 in_blend_uv,
        int a11)
{
  vostok::math::float3 v11; // [esp-44h] [ebp-44h]
  vostok::math::float4 v12; // [esp-38h] [ebp-38h]
  struct vostok::math::float3 v13; // [esp-14h] [ebp-14h]

  v13.z = a2;
  *(_QWORD *)&v13.x = __PAIR64__(LODWORD(in_uv.x), LODWORD(in_color.w));
  *(_QWORD *)&v12.x = __PAIR64__(LODWORD(in_size.x), LODWORD(in_uv.y));
  *(_QWORD *)&v12.elements[2] = __PAIR64__(in_rotation, LODWORD(in_size.y));
  v11.x = in_position.y;
  *(_QWORD *)&v11.elements[1] = __PAIR64__(LODWORD(in_color.x), LODWORD(in_position.z));
  vostok::render::particle_sprite_vertex::set(
    this,
    SLODWORD(in_position.x),
    SLODWORD(in_color.y),
    v11,
    v12,
    *(vostok::math::float2 *)&in_old_position.x,
    (vostok::math::float2)__PAIR64__(LODWORD(in_size_uv.x), LODWORD(in_old_position.z)),
    in_color.z,
    v13);
  *(float *)(LODWORD(in_position.x) + 68) = in_blend_uv.y;
  *(float *)(LODWORD(in_position.x) + 72) = in_blend_uv.z;
  *(float *)(LODWORD(in_position.x) + 76) = in_blend_uv.w;
  *(_DWORD *)(LODWORD(in_position.x) + 80) = a11;
  *(float *)(LODWORD(in_position.x) + 60) = in_size_uv.y;
  *(float *)(LODWORD(in_position.x) + 64) = in_blend_uv.x;
}
