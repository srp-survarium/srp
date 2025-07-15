void __thiscall vostok::render::cascaded_sun_shadow_statistics_group::cascaded_sun_shadow_statistics_group(
        vostok::render::cascaded_sun_shadow_statistics_group *this,
        vostok::render::cascaded_sun_shadow_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "cascaded sun shadow statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(
    &group_name->execute_time_cascade_1,
    group_name,
    "execute time cascade # 1");
  group_name->execute_time_cascade_1.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_1.cpu_time, 0, 0);
  group_name->execute_time_cascade_1.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_1.gpu_time, 0, 0);
  group_name->execute_time_cascade_1.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(
    &group_name->execute_time_cascade_2,
    group_name,
    "execute time cascade # 2");
  group_name->execute_time_cascade_2.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_2.cpu_time, 0, 0);
  group_name->execute_time_cascade_2.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_2.gpu_time, 0, 0);
  group_name->execute_time_cascade_2.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(
    &group_name->execute_time_cascade_3,
    group_name,
    "execute time cascade # 3");
  group_name->execute_time_cascade_3.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_3.cpu_time, 0, 0);
  group_name->execute_time_cascade_3.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_3.gpu_time, 0, 0);
  group_name->execute_time_cascade_3.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(
    &group_name->execute_time_cascade_4,
    group_name,
    "execute time cascade # 4");
  group_name->execute_time_cascade_4.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_4.cpu_time, 0, 0);
  group_name->execute_time_cascade_4.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time_cascade_4.gpu_time, 0, 0);
  group_name->execute_time_cascade_4.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_cascade_1,
    group_name,
    "dips in cascade # 1");
  group_name->num_dips_cascade_1.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_cascade_2,
    group_name,
    "dips in cascade # 2");
  group_name->num_dips_cascade_2.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_cascade_3,
    group_name,
    "dips in cascade # 3");
  group_name->num_dips_cascade_3.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_dips_cascade_4,
    group_name,
    "dips in cascade # 4");
  group_name->num_dips_cascade_4.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(&group_name->num_dips, group_name, "dips");
  group_name->num_dips.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_clipped_dips,
    group_name,
    "clipped dips");
  group_name->num_clipped_dips.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(&group_name->num_triangles, group_name, "triangles");
  group_name->num_triangles.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
}
