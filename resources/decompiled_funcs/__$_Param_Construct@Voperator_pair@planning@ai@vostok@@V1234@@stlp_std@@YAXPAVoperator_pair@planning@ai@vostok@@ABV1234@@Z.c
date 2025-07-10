void __cdecl stlp_std::_Param_Construct<vostok::ai::planning::operator_pair,vostok::ai::planning::operator_pair>(
        vostok::ai::planning::operator_pair *__p,
        const vostok::ai::planning::operator_pair *__val)
{
  vostok::ai::planning::operator_impl *m_operator; // ecx
  unsigned int *v3; // [esp+4h] [ebp-8h]

  v3 = (unsigned int *)operator new(8u, __p);
  if ( v3 )
  {
    m_operator = __val->m_operator;
    *v3 = __val->m_id;
    v3[1] = (unsigned int)m_operator;
  }
}
