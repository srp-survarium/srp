void __usercall vostok::render::material_effects_instance::material_effects_instance(
        vostok::render::material_effects_instance *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::material_effects *v2; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &stru_960AE0.m_effects_deleted_in_pending._M_impl._M_finish;
  vostok::render::material_effects::material_effects(v2);
  *(_DWORD *)(a2 + 1176) = a2 + 1188;
  *(_DWORD *)(a2 + 1180) = a2 + 1188;
  *(_DWORD *)(a2 + 1184) = a2 + 1448;
  *(_BYTE *)(a2 + 1188) = 0;
  *(_BYTE *)(a2 + 1188) = 0;
  *(_BYTE *)(a2 + 1448) = 47;
}
