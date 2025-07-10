void __userpurge survarium::object_volumetric_sound::object_volumetric_sound(
        survarium::object_volumetric_sound *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = &survarium::link_resolver::`vftable';
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)a2 = &survarium::object_volumetric_sound::`vftable'{for `survarium::object_sound'};
  *(_DWORD *)(a2 + 352) = &survarium::object_volumetric_sound::`vftable'{for `survarium::link_resolver'};
  *(float *)(a2 + 360) = FLOAT_10_0;
}
