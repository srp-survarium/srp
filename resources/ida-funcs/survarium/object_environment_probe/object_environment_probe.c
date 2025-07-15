void __userpurge survarium::object_environment_probe::object_environment_probe(
        survarium::object_environment_probe *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  unsigned int v3; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  *(_DWORD *)a2 = &survarium::object_environment_probe::`vftable';
  *(_DWORD *)(a2 + 336) = a2 + 348;
  *(_DWORD *)(a2 + 340) = a2 + 348;
  *(_DWORD *)(a2 + 344) = a2 + 608;
  *(_BYTE *)(a2 + 348) = 0;
  *(_BYTE *)(a2 + 348) = 0;
  v3 = probe_ids;
  *(_DWORD *)(a2 + 612) = probe_ids;
  probe_ids = v3 + 1;
  *(_DWORD *)(a2 + 616) = 0;
}
