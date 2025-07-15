// attributes: thunk
void __thiscall vostok::ui::ui_scroll_view::draw(
        vostok::ui::ui_scroll_view *this,
        vostok::render::ui::renderer *renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_window::draw((vostok::ui::ui_window *)this, renderer, scene_view);
}
