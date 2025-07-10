int __thiscall vostok::render::skeleton_render_model_instance::get_locator(
        vostok::render::skeleton_render_model_instance *this,
        const char *locator_name,
        vostok::render::model_locator_item *result)
{
  return ((int (__thiscall *)(vostok::render::skeleton_render_model *, const char *, vostok::render::model_locator_item *))this->m_original.m_object->get_locator)(
           this->m_original.m_object,
           locator_name,
           result);
}
