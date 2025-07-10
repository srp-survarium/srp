void __userpurge survarium::object_particle_visual::object_particle_visual(
        survarium::object_particle_visual *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  *(_DWORD *)a2 = &survarium::object_particle_visual::`vftable';
  *(_DWORD *)(a2 + 336) = 0;
}
