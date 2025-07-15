void __usercall vostok::variant<32>::variant<32>(
        vostok::variant<32> *this@<esi>,
        const vostok::variant<32> *other@<eax>,
        vostok::variant<32> *a3@<ecx>)
{
  this->m_helper = 0;
  this->m_type_id = other->m_type_id;
  vostok::variant<32>::operator=(this, other, a3);
}
