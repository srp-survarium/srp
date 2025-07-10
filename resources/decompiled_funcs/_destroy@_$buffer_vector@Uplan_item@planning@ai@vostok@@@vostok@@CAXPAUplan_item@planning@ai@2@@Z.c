void __cdecl vostok::buffer_vector<vostok::ai::planning::plan_item>::destroy(vostok::ai::planning::plan_item *p)
{
  const void **i; // [esp+4h] [ebp-4h]

  for ( i = p->parameters.m_begin; i != p->parameters.m_end; ++i )
    ;
  p->parameters.m_end = p->parameters.m_begin;
}
