void __thiscall survarium::protect_damage_predicate::operator()(
        survarium::protect_damage_predicate *this,
        survarium::damage_protector *const protector)
{
  if ( this->m_amount > 0.0
    && (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&protector->reduce_damage_functor)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    this->m_amount = boost::function4<float,char const *,char const *,float,float>::operator()(
                       &protector->reduce_damage_functor,
                       this->m_body_type_name,
                       this->m_damage_type,
                       this->m_amount,
                       this->m_armor_piercing);
  }
}
