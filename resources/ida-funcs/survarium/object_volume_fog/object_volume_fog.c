void __userpurge survarium::object_volume_fog::object_volume_fog(
        survarium::object_volume_fog *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  unsigned int v4; // eax
  __int64 v5; // [esp+4h] [ebp-Ch]

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  v3 = clear_value;
  *(_DWORD *)(a2 + 264) = w;
  v4 = volume_fog_ids;
  *(_DWORD *)(a2 + 336) = volume_fog_ids;
  LODWORD(v5) = v3;
  HIDWORD(v5) = v3;
  *(_QWORD *)(a2 + 340) = v5;
  volume_fog_ids = v4 + 1;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)a2 = &survarium::object_volume_fog::`vftable';
  *(_DWORD *)(a2 + 348) = v3;
  *(_DWORD *)(a2 + 352) = v3;
  *(_DWORD *)(a2 + 356) = v3;
  *(_DWORD *)(a2 + 384) = v3;
  *(_DWORD *)(a2 + 360) = v3;
  *(_DWORD *)(a2 + 364) = v3;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = v3;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
}
