void __thiscall vostok::engine::editor_console::tick(
        vostok::engine::editor_console *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::console_impl::tick(this, (int)&this[-1].m_self_deactivate, scene_view);
}
