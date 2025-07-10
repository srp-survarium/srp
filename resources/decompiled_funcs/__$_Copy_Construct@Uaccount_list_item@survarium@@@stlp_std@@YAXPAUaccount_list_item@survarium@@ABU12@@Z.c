void __usercall stlp_std::_Copy_Construct<survarium::account_list_item>(
        survarium::account_list_item *__p@<esi>,
        const survarium::account_list_item *__val@<edi>)
{
  char *m_begin; // edx
  char *v3; // ecx
  char *v4; // ebx

  if ( __p )
  {
    __p->account_id = __val->account_id;
    m_begin = __val->account_name.m_begin;
    v3 = (char *)(__val->account_name.m_end - m_begin);
    __p->account_name.m_max_end = (char *)&__p->online;
    v4 = v3;
    __p->account_name.m_begin = __p->account_name.m_buffer;
    __p->account_name.m_end = __p->account_name.m_buffer;
    memcpy((unsigned __int8 *)__p->account_name.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v3);
    __p->account_name.m_end += (unsigned int)v4;
    *__p->account_name.m_end = 0;
    __p->online = __val->online;
  }
}
