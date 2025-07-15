void __thiscall vostok::render::stage_shadow_direct::draw_debug(
        vostok::render::stage_shadow_direct *this,
        vostok::render::stage_shadow_direct *in_cascade_id)
{
  const vostok::math::float4x4 *v2; // eax
  vostok::math::float4x4 v3; // [esp+0h] [ebp-40h] BYREF

  v2 = vostok::math::float4x4::identity(&v3);
  vostok::render::renderer_context::set_w(in_cascade_id->m_context, v2);
}
