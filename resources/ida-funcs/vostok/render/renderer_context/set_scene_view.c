void __userpurge vostok::render::renderer_context::set_scene_view(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> view_ptr)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  vostok::render::renderer_context *v4; // ecx

  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    &view_ptr,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(a2 + 16268));
  m_object = view_ptr.m_object;
  vostok::render::renderer_context::set_v(
    v4,
    (const vostok::math::float4x4 *)a2,
    (const vostok::math::float4x4 *)&view_ptr.m_object[1].grm_satisfaction_tree_hook.color_);
  vostok::render::renderer_context::set_p(
    (const vostok::math::float4x4 *)&m_object[1].m_lods[0].m_emitter_instance_list.m_first,
    (vostok::render::renderer_context *)a2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&view_ptr);
}
