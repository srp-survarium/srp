void __fastcall vostok::animation::animation_collection::add_animation(
        vostok::animation::animation_collection *this,
        int a2,
        vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> emitter)
{
  vostok::animation::animation_expression_emitter **v3; // ecx
  vostok::animation::animation_expression_emitter *m_object; // eax

  v3 = *(vostok::animation::animation_expression_emitter ***)(a2 + 268);
  if ( v3 )
  {
    *v3 = 0;
    m_object = emitter.m_object;
    if ( !emitter.m_object )
      goto LABEL_6;
    *v3 = emitter.m_object;
    _InterlockedExchangeAdd(&emitter.m_object->m_reference_count, 1u);
  }
  m_object = emitter.m_object;
LABEL_6:
  *(_DWORD *)(a2 + 268) += 4;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &emitter.m_object->vostok::resources::unmanaged_intrusive_base,
        emitter.m_object);
  }
}
