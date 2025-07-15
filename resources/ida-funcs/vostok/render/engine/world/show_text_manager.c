void __thiscall vostok::render::engine::world::show_text_manager(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view,
        survarium::flash_text_manager *tm)
{
  scene_view->m_object[5].m_children_resources.m_lock = (unsigned int)tm;
}
