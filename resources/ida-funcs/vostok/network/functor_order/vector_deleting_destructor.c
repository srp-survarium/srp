vostok::network::functor_order *__thiscall vostok::network::functor_order::`vector deleting destructor'(
        vostok::network::functor_order *this,
        char a2)
{
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_functor);
  this->__vftable = (vostok::network::functor_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
