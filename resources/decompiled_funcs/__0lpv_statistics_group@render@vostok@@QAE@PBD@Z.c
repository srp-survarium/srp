void __thiscall vostok::render::lpv_statistics_group::lpv_statistics_group(
        vostok::render::lpv_statistics_group *this,
        vostok::render::lpv_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "light propagation volumes statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(&group_name->lpv_lookup_time, group_name, "LPV lookup time");
  group_name->lpv_lookup_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->lpv_lookup_time.cpu_time, 0, 0);
  group_name->lpv_lookup_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->lpv_lookup_time.gpu_time, 0, 0);
  group_name->lpv_lookup_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->propagation_time, group_name, "propagation time");
  group_name->propagation_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->propagation_time.cpu_time, 0, 0);
  group_name->propagation_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->propagation_time.gpu_time, 0, 0);
  group_name->propagation_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->gv_injection_time, group_name, "GV injection time");
  group_name->gv_injection_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->gv_injection_time.cpu_time, 0, 0);
  group_name->gv_injection_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->gv_injection_time.gpu_time, 0, 0);
  group_name->gv_injection_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->vpl_injection_time, group_name, "VPL injection time");
  group_name->vpl_injection_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->vpl_injection_time.cpu_time, 0, 0);
  group_name->vpl_injection_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->vpl_injection_time.gpu_time, 0, 0);
  group_name->vpl_injection_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->rsm_downsample_time, group_name, "RSM downsample time");
  group_name->rsm_downsample_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->rsm_downsample_time.cpu_time, 0, 0);
  group_name->rsm_downsample_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->rsm_downsample_time.gpu_time, 0, 0);
  group_name->rsm_downsample_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->rsm_rendering_time, group_name, "RSM rendering time");
  group_name->rsm_rendering_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->rsm_rendering_time.cpu_time, 0, 0);
  group_name->rsm_rendering_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->rsm_rendering_time.gpu_time, 0, 0);
  group_name->rsm_rendering_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(&group_name->num_dips, group_name, "dips");
  group_name->num_dips.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_in_cascade_0,
    group_name,
    "dips in cascade #1");
  group_name->num_dips_in_cascade_0.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_in_cascade_1,
    group_name,
    "dips in cascade #2");
  group_name->num_dips_in_cascade_1.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_in_cascade_2,
    group_name,
    "dips in cascade #3");
  group_name->num_dips_in_cascade_2.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_clipped_dips,
    group_name,
    "clipped dips");
  group_name->num_clipped_dips.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
}
