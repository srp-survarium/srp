void __userpurge survarium::stats::draw(
        survarium::stats *this@<esi>,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view@<edx>,
        vostok::render::ui::renderer *w)
{
  vostok::ui::window *v3; // eax

  this->m_main_window->draw(this->m_main_window, w, scene_view);
  v3 = this->m_dispersion_components->w(this->m_dispersion_components);
  v3->set_visible(v3, 0);
}
