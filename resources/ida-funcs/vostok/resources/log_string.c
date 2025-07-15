vostok::fixed_string<512> *__usercall vostok::resources::log_string@<eax>(
        vostok::resources::resource_base *resource@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_string *v3; // [esp+0h] [ebp-4h]

  if ( ((unsigned __int8)((resource->m_flags.m_flags & 2) - 2) == 0 ? (unsigned int)resource : 0) != 0 )
    vostok::resources::logging_name_for_query(v3);
  else
    ((void (__thiscall *)(vostok::resources::resource_base *))resource->log_string)(resource);
  return (vostok::fixed_string<512> *)a2;
}
