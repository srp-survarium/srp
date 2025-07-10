void __thiscall vostok::render::distortion_pass_statistics_group::distortion_pass_statistics_group(
        vostok::render::distortion_pass_statistics_group *this,
        vostok::render::distortion_pass_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "distortion pass statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(&group_name->accumulate_time, group_name, "accumulate time");
  group_name->accumulate_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->accumulate_time.cpu_time, 0, 0);
  group_name->accumulate_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->accumulate_time.gpu_time, 0, 0);
  group_name->accumulate_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->apply_time, group_name, "apply time");
  group_name->apply_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->apply_time.cpu_time, 0, 0);
  group_name->apply_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->apply_time.gpu_time, 0, 0);
  group_name->apply_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
}
