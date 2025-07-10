void __userpurge survarium::game_object_::game_object_(
        survarium::game_object_ *this@<ecx>,
        vostok::resources::unmanaged_resource *a2@<esi>,
        survarium::base_game_scene *s)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a2, 1u);
  a2[1].__vftable = (vostok::resources::unmanaged_resource_vtbl *)s;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::game_object_::`vftable';
}
