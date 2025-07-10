void __usercall vostok::render::render_model::render_model(vostok::render::render_model *this@<ecx>, int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  __int64 v3; // [esp+0h] [ebp-Ch]

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &stru_962594.m_signatures;
  *(_QWORD *)(a2 + 264) = 0xBF800000BF800000uLL;
  v2 = clear_value;
  *(_DWORD *)(a2 + 272) = -1082130432;
  LODWORD(v3) = v2;
  HIDWORD(v3) = v2;
  *(_QWORD *)(a2 + 276) = v3;
  *(_DWORD *)(a2 + 284) = v2;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_WORD *)(a2 + 292) = 0;
}
