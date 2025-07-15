void __thiscall vostok::render::user_render_model_instance::get_surfaces(
        vostok::render::user_render_model_instance *this,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float3 *view_pos,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *dest,
        bool visible_only,
        unsigned __int8 __formal,
        unsigned int a7)
{
  vostok::render::render_surface_instance *p_m_surface_instance; // [esp+4h] [ebp-4h] BYREF

  p_m_surface_instance = &this->m_surface_instance;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&this->m_surface_instance,
    (int)dest,
    &p_m_surface_instance);
}
