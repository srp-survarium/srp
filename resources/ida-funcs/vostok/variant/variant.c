void __thiscall vostok::variant<32>::variant<32>(vostok::variant<32> *this, const vostok::variant<32> *other)
{
  this->m_helper = 0;
  this->m_type_id = other->m_type_id;
  vostok::variant<32>::operator=(this, other);
}


void __thiscall vostok::variant<32>::variant<32>(vostok::variant<32> *this)
{
  this->m_helper = 0;
  this->m_type_id = 0;
}
