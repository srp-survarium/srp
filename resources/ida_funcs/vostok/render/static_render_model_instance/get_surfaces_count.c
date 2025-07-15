unsigned int __thiscall vostok::render::static_render_model_instance::get_surfaces_count(
        vostok::render::static_render_model_instance *this,
        unsigned int lod_id)
{
  return this->m_original.m_object->m_lods_descriptor->m_lod_surfaces_count[lod_id];
}


unsigned int __thiscall vostok::render::static_render_model_instance::get_surfaces_count(
        vostok::render::static_render_model_instance *this)
{
  return this->m_instances_count;
}
