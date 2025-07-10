void __thiscall vostok::ai::planning::operator_impl::operator_impl(
        vostok::ai::planning::operator_impl *this,
        const char *id,
        unsigned int cost)
{
  vostok::ai::planning::operator_base::operator_base(this);
  this->__vftable = (vostok::ai::planning::operator_impl_vtbl *)&vostok::ai::planning::operator_impl::`vftable';
  vostok::fixed_string<64>::fixed_string<64>(&this->m_id, id);
  this->m_object = 0;
  this->m_cost = cost;
  this->m_first_execute = 0;
}
