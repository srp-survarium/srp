survarium::simple_animation_controller_parameters *__usercall survarium::simple_animation_controller_parameters::operator=@<eax>(
        survarium::simple_animation_controller_parameters *this@<ecx>,
        int a2@<esi>)
{
  vostok::animation::animation_expression_emitter *m_object; // ecx
  vostok::animation::animation_expression_emitter *v3; // eax
  vostok::resources::unmanaged_resource *v4; // edx

  m_object = this->emitter.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = *(vostok::resources::unmanaged_resource **)(a2 + 4);
  *(_DWORD *)(a2 + 4) = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (survarium::simple_animation_controller_parameters *)a2;
}
