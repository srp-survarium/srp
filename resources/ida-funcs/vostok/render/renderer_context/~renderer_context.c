void __thiscall vostok::render::renderer_context::~renderer_context(vostok::render::renderer_context *this)
{
  *(_DWORD *)&s_system_renderer_buffer.m_p_stack.m_buffer[6].m_store[8] = *(_DWORD *)&s_system_renderer_buffer.m_p_stack.m_buffer[6].m_store[4];
  *(_DWORD *)&s_system_renderer_buffer.m_v_stack.m_buffer[6].m_store[8] = *(_DWORD *)&s_system_renderer_buffer.m_v_stack.m_buffer[6].m_store[4];
  *(_DWORD *)&s_system_renderer_buffer.m_w_stack.m_buffer[6].m_store[8] = *(_DWORD *)&s_system_renderer_buffer.m_w_stack.m_buffer[6].m_store[4];
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&s_system_renderer_buffer.m_w_stack.m_buffer[6]);
  `vector destructor iterator'(
    &s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[108],
    0x8CCu,
    2,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::sun_cascade,8>::~fixed_vector<vostok::render::sun_cascade,8>);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[96]);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[92]);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[88]);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[84]);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&s_system_renderer_buffer.m_sun_cascades[0].m_buffer[1].m_store[80]);
  `vector destructor iterator'(
    (char *)&s_system_renderer_buffer.m_family[2].name.m_end,
    0xA0u,
    73,
    (void (__thiscall *)(void *))vostok::render::render_target_instance::~render_target_instance);
}
