void __userpurge vostok::render::statistics_group::statistics_group(
        vostok::render::statistics_group *this@<ecx>,
        vostok::render::statistics_group *a2@<edi>,
        char *group_name,
        const vostok::math::color *group_color)
{
  vostok::render::statistics *v4; // eax

  a2->first_statistics = 0;
  vostok::fixed_string<128>::fixed_string<128>((vostok::fixed_string<128> *)this, &a2->m_name, group_name);
  a2->m_group_color = *group_color;
  v4 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  a2->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v4->first_group = a2;
}
