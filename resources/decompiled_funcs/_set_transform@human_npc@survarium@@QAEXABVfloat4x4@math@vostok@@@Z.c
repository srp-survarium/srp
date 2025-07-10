void __userpurge survarium::human_npc::set_transform(
        const vostok::math::float4x4 *transform@<eax>,
        survarium::human_npc *this)
{
  vostok::math::float4_pod *p_c; // eax
  survarium::animated_model_instance *m_object; // ecx
  vostok::animation::mixing::n_ary_tree *v5; // ecx

  p_c = &transform->c;
  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
  m_object = this->m_model_instance.m_object;
  *(_QWORD *)&this->m_feet_target.x = *(_QWORD *)&p_c->x;
  this->m_feet_target.z = p_c->z;
  vostok::render::scene_renderer::update_model(
    (vostok::render::scene_renderer *)this->m_renderer,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_renderer->m_scene,
    (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&this->m_scene,
    (const vostok::math::float4x4 *)&m_object->m_render_model.m_object->m_model);
  vostok::animation::mixing::n_ary_tree::set_object_transform(v5, 0, &this->m_transform);
}
