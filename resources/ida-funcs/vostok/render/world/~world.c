void __thiscall vostok::render::world::~world(
        vostok::render::world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  vostok::particle::particle_system_instance_impl *m_object; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::render::one_way_render_channel *v5; // ecx
  vostok::render::one_way_render_channel *v6; // ecx
  const char *v7; // [esp+0h] [ebp-14h]
  const char *v8; // [esp+4h] [ebp-10h]
  unsigned int v9; // [esp+8h] [ebp-Ch]

  v2 = vostok::render::g_allocator;
  m_object = a2[90].m_object;
  if ( m_object )
  {
    vostok::render::game::renderer::~renderer((vostok::render::game::renderer *)this, (int)m_object);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v2, m_object, v7, v8, v9);
    a2[90].m_object = 0;
  }
  if ( a2[89].m_object )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      a2[89].m_object,
      v7,
      v8,
      v9);
    a2[89].m_object = 0;
  }
  vostok::render::engine::world::~world(
    (vostok::render::engine::world *)this,
    (void **)&s_world_3.m_variable->m_renderer);
  s_world_3.m_initialized = 0;
  a2[88].m_object = 0;
  vostok::render::one_way_render_channel::~one_way_render_channel(v5, a2 + 44);
  vostok::render::one_way_render_channel::~one_way_render_channel(v6, a2);
}
