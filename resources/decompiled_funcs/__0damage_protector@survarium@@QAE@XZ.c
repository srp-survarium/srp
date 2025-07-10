void __thiscall survarium::damage_protector::damage_protector(survarium::damage_protector *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->reduce_damage_functor);
  this->__vftable = (survarium::damage_protector_vtbl *)&survarium::damage_protector::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->reduce_damage_functor,
    &this->reduce_damage_functor.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->protect_affect_functor.vtable);
  this->next = 0;
}
