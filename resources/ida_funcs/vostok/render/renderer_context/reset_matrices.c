void __usercall vostok::render::renderer_context::reset_matrices(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<esi>)
{
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15492));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15556));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15620));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15684));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15748));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15812));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 15940));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16004));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16068));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16132));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16196));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16260));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16324));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16388));
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 16452));
  *(_QWORD *)(a2 + 12372) = 0;
  *(_QWORD *)(a2 + 12380) = 0;
}
