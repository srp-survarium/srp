void __usercall vostok::render::one_way_render_channel::~one_way_render_channel(
        vostok::render::one_way_render_channel *this@<ecx>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<esi>)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(a2 + 41);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(a2 + 40);
  CloseHandle(a2[34].m_object);
}
