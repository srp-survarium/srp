vostok::math::aabb *__thiscall vostok::render::static_render_model_instance::get_aabb(
        vostok::render::static_render_model_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax

  v2 = result;
  qmemcpy(result, &this->m_original.m_object->m_aabbox, sizeof(vostok::math::aabb));
  return v2;
}
