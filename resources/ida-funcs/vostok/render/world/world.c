void __userpurge vostok::render::world::world(
        vostok::memory::base_allocator *logic_allocator@<eax>,
        vostok::render::one_way_render_channel *editor_allocator@<ecx>,
        vostok::render::world *this,
        vostok::render::engine::world *in_config,
        bool is_editor)
{
  vostok::render::one_way_render_channel *v6; // ecx
  vostok::render::engine::renderer *v7; // eax
  int *v8; // eax
  vostok::render::game::renderer *v9; // eax

  vostok::render::one_way_render_channel::one_way_render_channel(editor_allocator, (int)this, logic_allocator);
  vostok::render::one_way_render_channel::one_way_render_channel(
    v6,
    (int)&this->m_editor_channel,
    (vostok::memory::base_allocator *)editor_allocator);
  this->m_is_editor_frame_ended = editor_allocator == 0;
  this->m_is_logic_enabled = 1;
  this->m_is_logic_frame_ended = 0;
  this->m_is_editor = editor_allocator != 0;
  vostok::render::engine::world::world(
    in_config,
    (int)&s_world_1,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)in_config,
    is_editor);
  _InterlockedExchange(&s_world_1.m_initialized, 1);
  this->m_render_engine_world = s_world_1.m_variable;
  v7 = (vostok::render::engine::renderer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             4u);
  if ( v7 )
    v7->m_render_engine_world = this->m_render_engine_world;
  else
    v7 = 0;
  this->m_engine_renderer = v7;
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x14u);
  if ( v8 )
    vostok::render::game::renderer::renderer((vostok::render::game::renderer *)v8, this->m_render_engine_world, this);
  else
    v9 = 0;
  this->m_game_renderer = v9;
  this->m_editor_renderer = 0;
}
