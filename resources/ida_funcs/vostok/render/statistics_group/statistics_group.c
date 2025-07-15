void __userpurge vostok::render::statistics_group::statistics_group(
        vostok::render::statistics_group *this@<ecx>,
        vostok::render::statistics_group *a2@<esi>,
        const char *group_name)
{
  vostok::render::statistics *v3; // eax

  a2->first_statistics = 0;
  a2->m_name.m_begin = a2->m_name.m_buffer;
  a2->m_name.m_end = a2->m_name.m_buffer;
  a2->m_name.m_max_end = (char *)&a2->m_next;
  a2->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&a2->m_name, group_name);
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  a2->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = a2;
}
