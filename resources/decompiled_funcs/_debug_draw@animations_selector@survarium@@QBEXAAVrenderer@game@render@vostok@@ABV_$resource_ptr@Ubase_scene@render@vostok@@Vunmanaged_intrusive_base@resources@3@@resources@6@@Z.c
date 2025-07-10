void __userpurge survarium::animations_selector::debug_draw(
        survarium::animations_selector *this@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene@<edx>,
        vostok::render::game::renderer *render)
{
  if ( this->m_current_controller )
    this->m_current_controller->debug_draw(this->m_current_controller, render, scene);
}
