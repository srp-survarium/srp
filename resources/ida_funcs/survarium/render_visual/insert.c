void __fastcall survarium::render_visual::insert(survarium::render_visual *this, int a2)
{
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v2; // eax

  v2 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(a2 + 64);
  if ( v2 )
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)LODWORD(this[2].matrix.k.x),
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this->matrix.lines[0].elements[1],
      v2 + 66,
      (const vostok::math::float4x4 *)a2);
}
