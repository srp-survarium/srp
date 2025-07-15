void __thiscall survarium::max_angular_velocity_command::execute(
        survarium::max_angular_velocity_command *this,
        const char *args)
{
  float v3[2]; // [esp+8h] [ebp-8h] BYREF

  vostok::console_commands::cc_float::execute(this, args);
  *(float *)&dword_A5F668 = (float)(this->m_value * 0.0055555557) * 3.1415927;
  this->m_engine->get_render_window_size(this->m_engine, (vostok::math::float2 *)v3);
  survarium::g_max_angular_velocity[0] = (float)(v3[0] / v3[1]) * *(float *)&dword_A5F668;
}
