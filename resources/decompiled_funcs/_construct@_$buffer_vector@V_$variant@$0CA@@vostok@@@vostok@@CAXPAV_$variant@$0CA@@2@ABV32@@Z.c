void __cdecl vostok::buffer_vector<vostok::variant<32>>::construct(
        vostok::variant<32> *p,
        const vostok::variant<32> *value)
{
  if ( p )
  {
    p->m_helper = 0;
    p->m_type_id = value->m_type_id;
    vostok::variant<32>::operator=(p, value);
  }
}
