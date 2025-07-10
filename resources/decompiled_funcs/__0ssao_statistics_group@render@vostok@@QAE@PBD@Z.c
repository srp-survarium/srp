void __thiscall vostok::render::ssao_statistics_group::ssao_statistics_group(
        vostok::render::ssao_statistics_group *this,
        vostok::render::ssao_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "ssao statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(
    &group_name->ssao_accumulate_time,
    group_name,
    "ssao accumulate time");
  group_name->ssao_accumulate_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->ssao_accumulate_time.cpu_time, 0, 0);
  group_name->ssao_accumulate_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->ssao_accumulate_time.gpu_time, 0, 0);
  group_name->ssao_accumulate_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->ssao_blurring_time, group_name, "ssao blurring time");
  group_name->ssao_blurring_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->ssao_blurring_time.cpu_time, 0, 0);
  group_name->ssao_blurring_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->ssao_blurring_time.gpu_time, 0, 0);
  group_name->ssao_blurring_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
}
