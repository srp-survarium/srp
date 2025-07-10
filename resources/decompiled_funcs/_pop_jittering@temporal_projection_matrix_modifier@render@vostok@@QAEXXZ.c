void __usercall vostok::render::temporal_projection_matrix_modifier::pop_jittering(
        vostok::render::temporal_projection_matrix_modifier *this@<ecx>,
        int a2@<edi>)
{
  const vostok::math::float4x4 *v2; // esi

  if ( *(_BYTE *)(a2 + 12) )
  {
    v2 = *(const vostok::math::float4x4 **)a2;
    vostok::render::renderer_context::set_p(
      (vostok::render::renderer_context *)this,
      *(const vostok::math::float4x4 **)a2);
    LODWORD(v2[226].i.x) -= 64;
    *(_BYTE *)(a2 + 13) = 0;
  }
}
