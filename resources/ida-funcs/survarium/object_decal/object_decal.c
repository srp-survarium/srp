void __userpurge survarium::object_decal::object_decal(
        survarium::object_decal *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  unsigned int v3; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  v3 = decal_ids;
  *(_DWORD *)a2 = &survarium::object_decal::`vftable';
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 336) = v3;
  decal_ids = v3 + 1;
}
