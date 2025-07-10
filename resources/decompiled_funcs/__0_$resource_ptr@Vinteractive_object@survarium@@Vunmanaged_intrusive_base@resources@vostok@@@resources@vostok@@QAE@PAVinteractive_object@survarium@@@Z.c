void __usercall vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> **a2@<eax>)
{
  *a2 = 0;
  if ( this )
  {
    *a2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[52], 1u);
  }
}
