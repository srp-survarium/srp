void __thiscall vostok::network::order::order(vostok::network::order *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->next_for_orders);
  this->__vftable = (vostok::network::order_vtbl *)&vostok::network::order::`vftable';
}
