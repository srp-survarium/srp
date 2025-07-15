void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::draw(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        vostok::render::ui::renderer *render,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_text<vostok::ui::dynamic_text>::draw_internal(this, render, scene_view, 0, 0, 0xFFFF0000);
}
