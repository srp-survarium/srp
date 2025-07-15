void __thiscall survarium::protect_affect_predicate::operator()(
        survarium::protect_affect_predicate *this,
        survarium::damage_protector *const protector)
{
  if ( !this->m_result
    && (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&protector->protect_affect_functor)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    this->m_result = boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
                       &protector->protect_affect_functor,
                       this->m_body_type_name,
                       this->m_affect_type);
  }
}
