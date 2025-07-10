void __userpurge survarium::object_environment::object_environment(
        survarium::object_environment *this@<ecx>,
        vostok::resources::unmanaged_resource *a2@<esi>,
        survarium::base_game_scene *w)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a2, 1u);
  a2[1].__vftable = (vostok::resources::unmanaged_resource_vtbl *)w;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::object_environment::`vftable';
  a2[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
}
