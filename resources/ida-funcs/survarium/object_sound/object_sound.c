void __userpurge survarium::object_sound::object_sound(
        survarium::object_sound *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  *(_DWORD *)a2 = &survarium::object_sound::`vftable';
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
}
