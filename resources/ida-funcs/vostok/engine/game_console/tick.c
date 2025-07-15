void __thiscall vostok::engine::game_console::tick(
        vostok::engine::editor_console *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::console_impl::tick(
    (vostok::engine::editor_console *)((char *)this - 616),
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_self_deactivate,
    (int)scene_view);
}
