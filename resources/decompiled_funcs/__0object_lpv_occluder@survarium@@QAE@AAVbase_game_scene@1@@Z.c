void __userpurge survarium::object_lpv_occluder::object_lpv_occluder(
        survarium::object_lpv_occluder *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  unsigned int v3; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  v3 = occluder_ids;
  *(_DWORD *)(a2 + 336) = occluder_ids;
  occluder_ids = v3 + 1;
  *(_DWORD *)a2 = &survarium::object_lpv_occluder::`vftable';
}
