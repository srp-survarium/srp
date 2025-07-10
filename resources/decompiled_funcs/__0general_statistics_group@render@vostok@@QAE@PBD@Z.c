void __thiscall vostok::render::general_statistics_group::general_statistics_group(
        vostok::render::general_statistics_group *this,
        vostok::render::general_statistics_group *group_name)
{
  vostok::render::statistics *v3; // eax

  group_name->first_statistics = 0;
  group_name->m_name.m_begin = group_name->m_name.m_buffer;
  group_name->m_name.m_end = group_name->m_name.m_buffer;
  group_name->m_name.m_max_end = (char *)&group_name->m_next;
  group_name->m_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&group_name->m_name, "general statistics");
  v3 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  group_name->m_next = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v3->first_group = group_name;
  vostok::render::statistics_base::statistics_base(&group_name->render_frame_time, group_name, "render frame time");
  group_name->render_frame_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->render_frame_time.cpu_time, 0, 0);
  group_name->render_frame_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(&group_name->render_frame_time.gpu_time, 0, 0);
  group_name->render_frame_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    &group_name->cpu_render_frame_time,
    group_name,
    "cpu render frame time");
  group_name->cpu_render_frame_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &group_name->num_setted_shader_constants,
    group_name,
    "setted shader constants");
  group_name->num_setted_shader_constants.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(&group_name->fps, group_name, "FPS");
  group_name->fps.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(&group_name->cpu_fps, group_name, "FPS (CPU)");
  group_name->cpu_fps.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    &group_name->render_only_time,
    group_name,
    "render only time");
  group_name->render_only_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
}
