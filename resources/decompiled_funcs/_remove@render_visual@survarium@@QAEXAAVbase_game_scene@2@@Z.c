void __usercall survarium::render_visual::remove(survarium::render_visual *this@<ecx>, int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 64) )
    vostok::render::scene_renderer::remove_model(
      *(vostok::render::scene_renderer **)(LODWORD(this[2].matrix.k.x) + 148),
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(LODWORD(this[2].matrix.k.x) + 148) + 16),
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&this->matrix.lines[0].elements[1]);
}
