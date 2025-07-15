void __thiscall vostok::render::engine::world::reset_renderer(vostok::render::engine::world *this, bool async_effects)
{
  char *m_renderer; // ebx
  vostok::memory::doug_lea_allocator *v4; // esi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::renderer *v10; // ecx
  vostok::render::renderer *v11; // eax
  const char *v12; // [esp+0h] [ebp-10h]
  const char *v13; // [esp+4h] [ebp-Ch]
  unsigned int v14; // [esp+8h] [ebp-8h]

  m_renderer = (char *)this->m_renderer;
  if ( this->m_renderer )
  {
    v4 = vostok::render::g_allocator;
    vostok::render::renderer::~renderer((vostok::render::renderer *)this, (vostok::ai::fsm_state *)this->m_renderer);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v4, m_renderer, v12, v13, v14);
    this->m_renderer = 0;
  }
  v6 = vostok::render::g_allocator;
  vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync = !async_effects;
  v7 = type_info::raw_name(&vostok::render::renderer `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x330u, v7, v12, v13, v14);
  if ( v9 )
    vostok::render::renderer::renderer(v10, (vostok::render *)this, (vostok::render::renderer_context *)v9, this);
  else
    v11 = 0;
  this->m_renderer = v11;
  vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync = 0;
}
