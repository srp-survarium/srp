void __usercall vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *other@<edi>,
        survarium::profile_player_character *a3@<ecx>)
{
  survarium::player *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
      (vostok::memory::detail::call_destructor_predicate *)this,
      a3);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}
