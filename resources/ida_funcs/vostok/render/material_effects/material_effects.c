void __usercall vostok::render::material_effects::material_effects(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  __int64 v4; // xmm0_8
  __int64 v5; // [esp+8h] [ebp-10h]
  __int64 v6; // [esp+10h] [ebp-8h]

  vostok::render::post_process_parameters::post_process_parameters(&this->m_post_process_stage_parameters);
  `vector constructor iterator'(
    (char *)(a2 + 796),
    4u,
    29,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  *(_DWORD *)(a2 + 788) = 0;
  *(_DWORD *)(a2 + 792) = 1;
  *(_QWORD *)(a2 + 724) = 0;
  *(_QWORD *)(a2 + 732) = 0;
  *(_QWORD *)(a2 + 740) = 0;
  v3 = clear_value;
  *(_DWORD *)(a2 + 748) = 0;
  *(_BYTE *)(a2 + 752) = 0;
  LODWORD(v5) = v3;
  HIDWORD(v5) = v3;
  LODWORD(v6) = v3;
  HIDWORD(v6) = v3;
  *(_QWORD *)(a2 + 772) = v5;
  v4 = v6;
  *(_BYTE *)(a2 + 754) = 0;
  *(_BYTE *)(a2 + 757) = 0;
  *(_BYTE *)(a2 + 759) = 0;
  *(_BYTE *)(a2 + 762) = 0;
  *(_BYTE *)(a2 + 760) = 0;
  *(_BYTE *)(a2 + 758) = 0;
  *(_BYTE *)(a2 + 753) = 0;
  *(_BYTE *)(a2 + 761) = 0;
  *(_BYTE *)(a2 + 763) = 0;
  *(_BYTE *)(a2 + 764) = 0;
  *(_BYTE *)(a2 + 755) = 0;
  *(_DWORD *)(a2 + 768) = 0;
  *(_BYTE *)(a2 + 756) = 1;
  *(_QWORD *)(a2 + 780) = v4;
}
