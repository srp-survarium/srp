vostok::math::aabb *__thiscall vostok::render::user_render_model_instance::get_aabb(
        vostok::render::user_render_model_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax

  v2 = result;
  qmemcpy(result, &this->m_surface->m_aabbox, sizeof(vostok::math::aabb));
  return v2;
}
