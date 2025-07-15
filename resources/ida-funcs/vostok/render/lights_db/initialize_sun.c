void __usercall vostok::render::lights_db::initialize_sun(
        vostok::render::lights_db *this@<ecx>,
        vostok::render::light_data *light_to_add@<eax>)
{
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // esi

  p_m_sun = &this->m_sun;
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &light_to_add->light,
    &this->m_sun);
  *(_DWORD *)&p_m_sun->m_object->flags |= 0x10u;
}
