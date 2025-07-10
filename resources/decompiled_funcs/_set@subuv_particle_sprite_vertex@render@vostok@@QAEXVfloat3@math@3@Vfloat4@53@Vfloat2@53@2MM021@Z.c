// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::render::subuv_particle_sprite_vertex::set(
        vostok::render::subuv_particle_sprite_vertex *this@<ecx>,
        int a2@<esi>,
        vostok::math::float3 in_position,
        vostok::math::float4 in_color,
        vostok::math::float2 in_uv,
        vostok::math::float2 in_size,
        float in_rotation,
        unsigned int in_gravity,
        vostok::math::float3 in_old_position,
        vostok::math::float2 in_size_uv,
        vostok::math::float4 in_blend_uv)
{
  __int64 v11; // xmm0_8
  vostok::math::float4 v12; // [esp-20h] [ebp-34h]
  vostok::math::float3 v13; // [esp+8h] [ebp-Ch]

  *(_QWORD *)&v13.x = *(_QWORD *)&in_color.elements[2];
  v13.z = in_uv.x;
  *(vostok::math::float2 *)&v12.x = *(vostok::math::float2 *)((char *)&in_uv + 4);
  *(vostok::math::float2 *)&v12.elements[2] = *(vostok::math::float2 *)((char *)&in_size + 4);
  vostok::render::particle_sprite_vertex::set(
    (vostok::render::particle_sprite_vertex *)LODWORD(in_uv.x),
    a2,
    in_position,
    v12,
    (vostok::math::float2)__PAIR64__(LODWORD(in_old_position.x), in_gravity),
    *(vostok::math::float2 *)&in_old_position.elements[1],
    in_color.x,
    in_color.y,
    v13);
  *(_QWORD *)(a2 + 72) = *(_QWORD *)&in_blend_uv.x;
  v11 = *(_QWORD *)&in_blend_uv.elements[2];
  *(vostok::math::float2 *)(a2 + 64) = in_size_uv;
  *(_QWORD *)(a2 + 80) = v11;
}
