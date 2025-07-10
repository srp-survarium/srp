void __usercall vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        survarium::player *object@<edi>,
        survarium::profile_player_character *a3@<ecx>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
      (vostok::memory::detail::call_destructor_predicate *)this,
      a3);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
