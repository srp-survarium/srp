void __thiscall vostok::render::particles_statistics_group::particles_statistics_group(
        vostok::render::particles_statistics_group *this,
        vostok::render::particles_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "particles statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(&group_name->execute_time, group_name, "execute time");
  group_name->execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time.cpu_time, 0, 0);
  group_name->execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->execute_time.gpu_time, 0, 0);
  group_name->execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(
    &group_name->sprites_execute_time,
    group_name,
    "sprites execute time");
  group_name->sprites_execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->sprites_execute_time.cpu_time, 0, 0);
  group_name->sprites_execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->sprites_execute_time.gpu_time, 0, 0);
  group_name->sprites_execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(
    &group_name->beamtrails_execute_time,
    group_name,
    "beams and trails execute time");
  group_name->beamtrails_execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    &group_name->beamtrails_execute_time.cpu_time,
    0,
    0);
  group_name->beamtrails_execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    &group_name->beamtrails_execute_time.gpu_time,
    0,
    0);
  group_name->beamtrails_execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_base::statistics_base(&group_name->meshes_execute_time, group_name, "meshes execute time");
  group_name->meshes_execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->meshes_execute_time.cpu_time, 0, 0);
  group_name->meshes_execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->meshes_execute_time.gpu_time, 0, 0);
  group_name->meshes_execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_total_instances,
    group_name,
    "total instances");
  group_name->num_total_instances.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
}
