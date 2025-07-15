void __thiscall vostok::render::skeleton_decal_instance_node::on_model_updated(
        vostok::render::skeleton_decal_instance_node *this,
        const vostok::render::skeleton_render_model_instance *model)
{
  vostok::render::skeleton_render_model_instance *v3; // ecx
  vostok::render::decal_properties *m_object; // [esp-8h] [ebp-F8h]
  vostok::math::float4x4 result; // [esp+10h] [ebp-E0h] BYREF
  vostok::render::decal_properties v6; // [esp+50h] [ebp-A0h] BYREF
  vostok::math::float4x4 v7; // [esp+B0h] [ebp-40h] BYREF

  vostok::render::decal_properties::decal_properties(
    (vostok::render::decal_properties *)this,
    &v6,
    (int)&this->decal.m_object->m_properties);
  vostok::render::skeleton_render_model_instance::get_bone_matrix(v3, model, &result, this->bone_id, 0);
  vostok::math::mul4x3(&result, &this->bone_offset, &v7);
  vostok::math::mul4x3(&model->m_transform, &v7, &result);
  m_object = (vostok::render::decal_properties *)this->decal.m_object;
  qmemcpy(&v6, &result, 0x40u);
  vostok::render::decal_instance::set_properties(0, m_object, (char *)&v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6.material);
}
