void __usercall vostok::render::renderer_context::reset_matrices(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>)
{
  vostok::math::float4x4 *v3; // ecx
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 *v5; // ecx
  vostok::math::float4x4 *v6; // ecx
  vostok::math::float4x4 *v7; // ecx
  vostok::math::float4x4 *v8; // ecx
  vostok::math::float4x4 *v9; // ecx
  vostok::math::float4x4 *v10; // ecx
  vostok::math::float4x4 *v11; // ecx
  vostok::math::float4x4 *v12; // ecx
  vostok::math::float4x4 *v13; // ecx
  vostok::math::float4x4 *v14; // ecx
  vostok::math::float4x4 *v15; // ecx
  vostok::math::float4x4 *v16; // ecx

  vostok::math::float4x4::identity((vostok::math::float4x4 *)this, (vostok::math::float4x4 *)(a2 + 19380));
  vostok::math::float4x4::identity(v3, (vostok::math::float4x4 *)(a2 + 19444));
  vostok::math::float4x4::identity(v4, (vostok::math::float4x4 *)(a2 + 19508));
  vostok::math::float4x4::identity(v5, (vostok::math::float4x4 *)(a2 + 19572));
  vostok::math::float4x4::identity(v6, (vostok::math::float4x4 *)(a2 + 19636));
  vostok::math::float4x4::identity(v7, (vostok::math::float4x4 *)(a2 + 19700));
  vostok::math::float4x4::identity(v8, (vostok::math::float4x4 *)(a2 + 19828));
  vostok::math::float4x4::identity(v9, (vostok::math::float4x4 *)(a2 + 19892));
  vostok::math::float4x4::identity(v10, (vostok::math::float4x4 *)(a2 + 19956));
  vostok::math::float4x4::identity(v11, (vostok::math::float4x4 *)(a2 + 20020));
  vostok::math::float4x4::identity(v12, (vostok::math::float4x4 *)(a2 + 20084));
  vostok::math::float4x4::identity(v13, (vostok::math::float4x4 *)(a2 + 20148));
  vostok::math::float4x4::identity(v14, (vostok::math::float4x4 *)(a2 + 20212));
  vostok::math::float4x4::identity(v15, (vostok::math::float4x4 *)(a2 + 20276));
  vostok::math::float4x4::identity(v16, (vostok::math::float4x4 *)(a2 + 20340));
  *(_DWORD *)(a2 + 16224) = 0;
  *(_DWORD *)(a2 + 16228) = 0;
  *(_DWORD *)(a2 + 16232) = 0;
  *(_DWORD *)(a2 + 16236) = 0;
}
