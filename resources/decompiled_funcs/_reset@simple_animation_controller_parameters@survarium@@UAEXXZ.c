void __thiscall survarium::simple_animation_controller_parameters::reset(
        survarium::simple_animation_controller_parameters *this)
{
  vostok::animation::animation_expression_emitter *m_object; // eax

  m_object = this->emitter.m_object;
  this->emitter.m_object = 0;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
