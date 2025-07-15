void __thiscall vostok::render::engine::world::reload_shaders(vostok::render::engine::world *this)
{
  vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_loading_incomplete = 0;
}
