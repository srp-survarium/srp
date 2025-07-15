void __thiscall survarium::simple_animation_controller::set_target(
        survarium::simple_animation_controller *this,
        const survarium::animation_controller_parameters *target)
{
  survarium::animation_controller_parameters_vtbl *v2; // edx
  survarium::animation_controller_parameters_vtbl *v3; // eax
  vostok::animation::animation_expression_emitter *m_object; // edx

  v2 = target[1].__vftable;
  v3 = 0;
  if ( v2 )
  {
    v3 = target[1].__vftable;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v2[52], 1u);
  }
  m_object = this->m_target_parameters.emitter.m_object;
  this->m_target_parameters.emitter.m_object = (vostok::animation::animation_expression_emitter *)v3;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
