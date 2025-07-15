int __thiscall vostok::render::use_pools(vostok::command_line::key *this)
{
  int result; // eax

  if ( vostok::command_line::key::is_set(this, (int)&s_force_use_pools) )
    return 1;
  result = 0;
  if ( !vostok::quasi_singleton<vostok::render::device>::pinst->m_is_editor )
    return 1;
  return result;
}
