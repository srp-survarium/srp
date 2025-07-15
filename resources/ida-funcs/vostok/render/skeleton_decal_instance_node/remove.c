void __thiscall vostok::render::skeleton_decal_instance_node::remove(
        vostok::render::skeleton_decal_instance_node *this)
{
  vostok::render::skeleton_render_model_instance::remove_bone_subscriber(
    (vostok::render::skeleton_render_model_instance *)this,
    (_RTL_CRITICAL_SECTION *)this->m_model.m_object,
    &this->m_bones_subscriber);
}
