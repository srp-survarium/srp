void __userpurge survarium::object_light::object_light(
        survarium::object_light *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  vostok::render::light_props *v3; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = w;
  *(_DWORD *)a2 = &survarium::object_light::`vftable';
  vostok::render::light_props::light_props(v3);
  *(_DWORD *)(a2 + 576) = ++survarium::light_ids;
}
