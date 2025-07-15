void __userpurge vostok::buffer_vector<unsigned char>::push_back(
        vostok::buffer_vector<unsigned char> *this@<ecx>,
        int a2@<esi>,
        const unsigned __int8 *value)
{
  _BYTE *v3; // eax
  vostok::buffer_vector<unsigned char> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<unsigned char>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<unsigned char>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_BYTE **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  ++*(_DWORD *)(a2 + 4);
}


void __userpurge vostok::buffer_vector<unsigned short>::push_back(
        vostok::buffer_vector<unsigned short> *this@<ecx>,
        int a2@<esi>,
        const unsigned __int16 *value)
{
  _WORD *v3; // eax
  vostok::buffer_vector<unsigned short> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<unsigned short>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<unsigned short>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_WORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 2;
}


void __userpurge vostok::buffer_vector<int>::push_back(
        vostok::buffer_vector<int> *this@<ecx>,
        int a2@<esi>,
        const int *value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<int> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<int>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<int>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<unsigned int>::push_back(
        vostok::buffer_vector<unsigned int> *this@<ecx>,
        int a2@<esi>,
        const unsigned int *value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<unsigned int> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<unsigned int>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<unsigned int>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<float>::push_back(
        vostok::buffer_vector<float> *this@<ecx>,
        int a2@<esi>,
        float *value)
{
  float *v3; // eax
  vostok::buffer_vector<float> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<float>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<float>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(float **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::ambient_light *>::push_back(
        vostok::buffer_vector<vostok::render::ambient_light *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::ambient_light **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::ambient_light *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::ambient_light *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::ambient_light *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::ambient_volume *>::push_back(
        vostok::buffer_vector<vostok::render::ambient_volume *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::ambient_volume **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::ambient_volume *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::ambient_volume *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::ambient_volume *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::environment_probe *>::push_back(
        vostok::buffer_vector<vostok::render::environment_probe *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::environment_probe **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::environment_probe *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::environment_probe *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::environment_probe *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::grass_patch *>::push_back(
        vostok::buffer_vector<vostok::render::grass_patch *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::grass_patch **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::grass_patch *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::grass_patch *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::grass_patch *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::push_back(
        vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *this@<ecx>,
        int a2@<esi>,
        vostok::particle::render_particle_emitter_instance **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !LOBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[3]) )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::particle::render_particle_emitter_instance *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::render_surface_instance **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::render_surface_instance *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::render_surface_instance *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::push_back(
        vostok::buffer_vector<vostok::render::sky_ambient_occlusion *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::sky_ambient_occlusion **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::sky_ambient_occlusion *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::sky_ambient_occlusion *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<survarium::bullet *>::push_back(
        vostok::buffer_vector<survarium::bullet *> *this@<ecx>,
        int a2@<esi>,
        survarium::bullet **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<survarium::bullet *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<survarium::bullet *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class survarium::bullet *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __thiscall vostok::buffer_vector<vostok::resources::cook_base *>::push_back(
        vostok::buffer_vector<vostok::resources::cook_base *> *this,
        vostok::resources::cook_base **value)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // [esp-2h] [ebp-4h] BYREF

  v2 = this;
  if ( s_cooks_registry.m_end >= s_cooks_registry.m_max_end
    && !`vostok::buffer_vector<vostok::resources::cook_base *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v2) = 0;
    vostok::debug::on_error(
      (bool *)&v2 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::resources::cook_base *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v2);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v2) )
      __debugbreak();
  }
  if ( s_cooks_registry.m_end )
    *s_cooks_registry.m_end = *value;
  ++s_cooks_registry.m_end;
}


void __userpurge vostok::buffer_vector<vostok::ai::planning::generalized_action *>::push_back(
        vostok::buffer_vector<vostok::ai::planning::generalized_action *> *this@<ecx>,
        int a2@<esi>,
        vostok::ai::planning::generalized_action **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::ai::planning::generalized_action *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::ai::planning::generalized_action *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::ai::planning::generalized_action *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::resources::query_result *>::push_back(
        vostok::buffer_vector<vostok::resources::query_result *> *this@<ecx>,
        int a2@<esi>,
        vostok::resources::query_result **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::resources::query_result *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::resources::query_result *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::resources::query_result *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::render_output_window *>::push_back(
        vostok::buffer_vector<vostok::render::render_output_window *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::render_output_window **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::render_output_window *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::render_output_window *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::render_output_window *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<survarium::respawn_point_core *>::push_back(
        vostok::buffer_vector<survarium::respawn_point_core *> *this@<ecx>,
        int a2@<esi>,
        survarium::respawn_point_core **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<survarium::respawn_point_core *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<survarium::respawn_point_core *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class survarium::respawn_point_core *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::scene *>::push_back(
        vostok::buffer_vector<vostok::render::scene *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::scene **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::scene *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::scene *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::scene *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::render::scene_view *>::push_back(
        vostok::buffer_vector<vostok::render::scene_view *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::scene_view **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::render::scene_view *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::scene_view *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::scene_view *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::network_core::udp_match_packet *>::push_back(
        vostok::buffer_vector<vostok::network_core::udp_match_packet *> *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::udp_match_packet **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::network_core::udp_match_packet *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::network_core::udp_match_packet *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::network_core::udp_match_packet *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<char const *>::push_back(
        vostok::buffer_vector<char const *> *this@<ecx>,
        int a2@<esi>,
        const char **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<char const *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<char const *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<char const *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::collision::object const *>::push_back(
        vostok::buffer_vector<vostok::collision::object const *> *this@<ecx>,
        int a2@<esi>,
        const vostok::collision::object **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::collision::object const *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::collision::object const *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::collision::object const *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::push_back(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<ecx>,
        int a2@<esi>,
        const vostok::variant<32> **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<vostok::variant<32> const *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::variant<32> const *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::variant<32> const *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<void const *>::push_back(
        vostok::buffer_vector<void const *> *this@<ecx>,
        int a2@<esi>,
        const void **value)
{
  _DWORD *v3; // eax
  vostok::buffer_vector<void const *> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<void const *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<void const *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __thiscall vostok::buffer_vector<vostok::render::additional_material_parameter>::push_back(
        vostok::buffer_vector<vostok::render::additional_material_parameter> *this,
        const vostok::render::additional_material_parameter *value,
        const void *a3)
{
  const vostok::render::additional_material_parameter *v3; // ebx
  void *v4; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( *(_DWORD *)&value->data[4] >= *(_DWORD *)&value->data[8]
    && !`vostok::buffer_vector<vostok::render::additional_material_parameter>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::additional_material_parameter>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  v4 = *(void **)&v3->data[4];
  if ( v4 )
    qmemcpy(v4, a3, 0x48u);
  *(_DWORD *)&v3->data[4] += 72;
}


void __thiscall vostok::buffer_vector<allocator_data>::push_back(
        vostok::buffer_vector<allocator_data> *this,
        const allocator_data *value,
        const void *a3)
{
  const allocator_data *v3; // ebx
  void *v4; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( *((_DWORD *)&value->allocator + 1) >= LODWORD(value->arena_size)
    && !`vostok::buffer_vector<allocator_data>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct allocator_data>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  v4 = (void *)*((_DWORD *)&v3->allocator + 1);
  if ( v4 )
    qmemcpy(v4, a3, 0x18u);
  *((_DWORD *)&v3->allocator + 1) += 24;
}


void __userpurge vostok::buffer_vector<survarium::animations_registry::animations_tuple>::push_back(
        vostok::buffer_vector<survarium::animations_registry::animations_tuple> *this@<ecx>,
        int a2@<esi>,
        const survarium::animations_registry::animations_tuple *value)
{
  const survarium::animations_registry::animations_tuple *v3; // eax
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<survarium::animations_registry::animations_tuple>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::animations_registry::animations_tuple>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(const survarium::animations_registry::animations_tuple **)(a2 + 4);
  if ( v3 )
    survarium::animations_registry::animations_tuple::animations_tuple(
      (survarium::animations_registry::animations_tuple *)this,
      v3,
      (int)value);
  *(_DWORD *)(a2 + 4) += 12;
}


void __thiscall vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back(
        vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage> *this,
        const survarium::booby_trap_set_core::apply_damage *value,
        const void *a3)
{
  const survarium::booby_trap_set_core::apply_damage *v3; // ebx
  void *v4; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( *(_DWORD *)&value->body_part[4] >= *(_DWORD *)&value->body_part[8]
    && !`vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::booby_trap_set_core::apply_damage>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  v4 = *(void **)&v3->body_part[4];
  if ( v4 )
    qmemcpy(v4, a3, 0x1Cu);
  *(_DWORD *)&v3->body_part[4] += 28;
}


void __thiscall vostok::buffer_vector<survarium::`anonymous namespace'::artefact>::push_back(
        vostok::buffer_vector<survarium::artefact> *this,
        const survarium::artefact *value,
        _DWORD *a3)
{
  const survarium::artefact *v3; // ebx
  _DWORD *weight; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->weight >= value->count
    && !`vostok::buffer_vector<survarium::`anonymous namespace'::artefact>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::`anonymous namespace'::artefact>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  weight = (_DWORD *)v3->weight;
  if ( weight )
  {
    v5 = a3;
    *weight = *a3;
    ++v5;
    v6 = weight + 1;
    *v6 = *v5;
    v6[1] = v5[1];
  }
  v3->weight += 12;
}


void __thiscall vostok::buffer_vector<vostok::animation::bone_transform>::push_back(
        vostok::buffer_vector<vostok::animation::bone_transform> *this,
        const vostok::animation::bone_transform *value,
        const void *a3)
{
  const vostok::animation::bone_transform *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->translation.y) >= LODWORD(value->translation.z)
    && !`vostok::buffer_vector<vostok::animation::bone_transform>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::animation::bone_transform>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->translation.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x2Cu);
  LODWORD(v3->translation.y) += 44;
}


void __usercall vostok::buffer_vector<vostok::render::caster_model>::push_back(
        vostok::buffer_vector<vostok::render::caster_model> *this@<esi>,
        const vostok::render::caster_model *value@<edi>)
{
  vostok::render::caster_model *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::render::caster_model>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::caster_model>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __usercall vostok::buffer_vector<vostok::render::data_indexer>::push_back(
        vostok::buffer_vector<vostok::render::data_indexer> *this@<esi>,
        const vostok::render::data_indexer *value@<edi>)
{
  vostok::render::data_indexer *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::render::data_indexer>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::data_indexer>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>::push_back(
        vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct> *this,
        const vostok::render::effect_manager::effect_to_recompile_struct *value,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a3)
{
  const vostok::render::effect_manager::effect_to_recompile_struct *v3; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *descriptor; // ebx
  const char *v5; // [esp+0h] [ebp-10h]
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  v3 = value;
  if ( value->descriptor >= (vostok::render::effect_descriptor *)value->config.m_object
    && !`vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v6 = 0;
    vostok::debug::on_error(
      &v6,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::effect_manager::effect_to_recompile_struct>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || v6 )
      __debugbreak();
  }
  descriptor = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)value->descriptor;
  if ( descriptor )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)value->descriptor,
      a3);
    descriptor[1].m_object = a3[1].m_object;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      descriptor + 2,
      a3 + 2);
    descriptor[3].m_object = a3[3].m_object;
    descriptor[4].m_object = a3[4].m_object;
    descriptor[5].m_object = a3[5].m_object;
    descriptor[6].m_object = a3[6].m_object;
    v3 = value;
    descriptor[7].m_object = a3[7].m_object;
  }
  v3->descriptor += 8;
}


void __thiscall vostok::buffer_vector<vostok::render::geometry_batch>::push_back(
        vostok::buffer_vector<vostok::render::geometry_batch> *this,
        const vostok::render::geometry_batch *value,
        int a3)
{
  const vostok::render::geometry_batch *v3; // esi
  float y; // ebx
  const char *v5; // [esp+0h] [ebp-10h]
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  v3 = value;
  if ( LODWORD(value->bbox.min.y) >= LODWORD(value->bbox.min.z)
    && !`vostok::buffer_vector<vostok::render::geometry_batch>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v6 = 0;
    vostok::debug::on_error(
      &v6,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::geometry_batch>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || v6 )
      __debugbreak();
  }
  y = value->bbox.min.y;
  if ( y != 0.0 )
  {
    qmemcpy((void *)LODWORD(y), (const void *)a3, 0x18u);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(y) + 24),
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a3 + 24));
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(y) + 28),
      (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a3 + 28));
    v3 = value;
    *(_DWORD *)(LODWORD(y) + 32) = *(_DWORD *)(a3 + 32);
  }
  LODWORD(v3->bbox.min.y) += 36;
}


void __userpurge vostok::buffer_vector<vostok::render::grass_patch>::push_back(
        vostok::buffer_vector<vostok::render::grass_patch> *this@<ecx>,
        int a2@<esi>,
        const vostok::render::grass_patch *value)
{
  const vostok::render::grass_patch *v3; // eax
  vostok::buffer_vector<vostok::render::grass_patch> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::grass_patch>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::grass_patch>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(const vostok::render::grass_patch **)(a2 + 4);
  if ( v3 )
    vostok::render::grass_patch::grass_patch((vostok::render::grass_patch *)this, v3, (int)value);
  *(_DWORD *)(a2 + 4) += 16568;
}


void __thiscall vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(
        vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *this,
        const vostok::render::hw_buffer_pool_range *value,
        _DWORD *a3)
{
  const vostok::render::hw_buffer_pool_range *v3; // ebx
  _DWORD *begin_offset; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->begin_offset >= (unsigned int)value->end_offset
    && !`vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::hw_buffer_pool_range>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  begin_offset = (_DWORD *)v3->begin_offset;
  if ( begin_offset )
  {
    v5 = a3;
    *begin_offset = *a3;
    ++v5;
    v6 = begin_offset + 1;
    *v6 = *v5;
    v6[1] = v5[1];
  }
  v3->begin_offset += 12;
}


void __thiscall vostok::buffer_vector<vostok::render::lpv_vertex>::push_back(
        vostok::buffer_vector<vostok::render::lpv_vertex> *this,
        const vostok::render::lpv_vertex *value,
        const void *a3)
{
  const vostok::render::lpv_vertex *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-8h]

  v3 = value;
  if ( LODWORD(value->position.y) >= LODWORD(value->position.z)
    && !`vostok::buffer_vector<vostok::render::lpv_vertex>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::lpv_vertex>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->position.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x14u);
  LODWORD(v3->position.y) += 20;
}


void __thiscall vostok::buffer_vector<vostok::render::potential_request>::push_back(
        vostok::buffer_vector<vostok::render::potential_request> *this,
        const vostok::render::potential_request *value,
        const void *a3)
{
  const vostok::render::potential_request *v3; // ebx
  void *texture_index; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->texture_index >= value->resident_mips
    && !`vostok::buffer_vector<vostok::render::potential_request>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::potential_request>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  texture_index = (void *)v3->texture_index;
  if ( texture_index )
    qmemcpy(texture_index, a3, 0x70u);
  v3->texture_index += 112;
}


void __thiscall vostok::buffer_vector<vostok::render::culling::portal_sector_system::quad>::push_back(
        vostok::buffer_vector<vostok::render::culling::portal_sector_system::quad> *this,
        const vostok::render::culling::portal_sector_system::quad *value,
        const void *a3)
{
  const vostok::render::culling::portal_sector_system::quad *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->vertices[0].y) >= LODWORD(value->vertices[0].z)
    && !`vostok::buffer_vector<vostok::render::culling::portal_sector_system::quad>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::culling::portal_sector_system::quad>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->vertices[0].y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x30u);
  LODWORD(v3->vertices[0].y) += 48;
}


void __thiscall vostok::buffer_vector<vostok::render::ray>::push_back(
        vostok::buffer_vector<vostok::render::ray> *this,
        const vostok::render::ray *value,
        const void *a3)
{
  const vostok::render::ray *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->direction.y) >= LODWORD(value->direction.z)
    && !`vostok::buffer_vector<vostok::render::ray>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::ray>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->direction.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x18u);
  LODWORD(v3->direction.y) += 24;
}


void __usercall vostok::buffer_vector<vostok::collision::ray_object_result>::push_back(
        vostok::buffer_vector<vostok::collision::ray_object_result> *this@<esi>,
        const vostok::collision::ray_object_result *value@<edi>)
{
  vostok::collision::ray_object_result *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::collision::ray_object_result>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::collision::ray_object_result>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::collision::ray_triangle_result>::push_back(
        vostok::buffer_vector<vostok::collision::ray_triangle_result> *this,
        const vostok::collision::ray_triangle_result *value,
        _DWORD *a3)
{
  const vostok::collision::ray_triangle_result *v3; // ebx
  _DWORD *triangle_id; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->triangle_id >= LODWORD(value->distance)
    && !`vostok::buffer_vector<vostok::collision::ray_triangle_result>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::collision::ray_triangle_result>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  triangle_id = (_DWORD *)v3->triangle_id;
  if ( triangle_id )
  {
    v5 = a3;
    *triangle_id = *a3;
    ++v5;
    v6 = triangle_id + 1;
    *v6 = *v5;
    v6[1] = v5[1];
  }
  v3->triangle_id += 12;
}


void __thiscall vostok::buffer_vector<vostok::memory::platform::region>::push_back(
        vostok::buffer_vector<vostok::memory::platform::region> *this,
        const vostok::memory::platform::region *value,
        _DWORD *a3)
{
  const vostok::memory::platform::region *v3; // ebx
  _DWORD *size_high; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( (void *)HIDWORD(value->size) >= value->address
    && !`vostok::buffer_vector<vostok::memory::platform::region>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::memory::platform::region>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  size_high = (_DWORD *)HIDWORD(v3->size);
  if ( size_high )
  {
    v5 = a3;
    *size_high = *a3;
    ++v5;
    v6 = size_high + 1;
    *v6 = *v5++;
    *++v6 = *v5;
    v6[1] = v5[1];
  }
  HIDWORD(v3->size) += 16;
}


void __userpurge vostok::buffer_vector<survarium::artefact_lifebone_core::removed_affect>::push_back(
        vostok::buffer_vector<survarium::artefact_lifebone_core::removed_affect> *this@<ecx>,
        int a2@<edi>,
        const survarium::artefact_lifebone_core::removed_affect *value)
{
  vostok::fixed_string<16> *v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<survarium::artefact_lifebone_core::removed_affect>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::artefact_lifebone_core::removed_affect>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  v3 = *(vostok::fixed_string<16> **)(a2 + 4);
  if ( v3 )
  {
    vostok::fixed_string<16>::fixed_string<16>(v3, &value->body_part);
    v3[1].m_begin = (char *)value->affect;
  }
  *(_DWORD *)(a2 + 4) += 32;
}


void __usercall vostok::buffer_vector<vostok::resources::request>::push_back(
        vostok::buffer_vector<vostok::resources::request> *this@<esi>,
        const vostok::resources::request *value@<edi>)
{
  vostok::resources::request *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::resources::request>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::resources::request>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __userpurge vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info>::push_back(
        vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info> *this@<ecx>,
        int a2@<esi>,
        const vostok::render::effect_compiler::shader_cache_info *value)
{
  const vostok::render::effect_compiler::shader_cache_info *v3; // eax
  vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::effect_compiler::shader_cache_info>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(const vostok::render::effect_compiler::shader_cache_info **)(a2 + 4);
  if ( v3 )
    vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
      (vostok::render::effect_compiler::shader_cache_info *)this,
      v3,
      (int)value);
  *(_DWORD *)(a2 + 4) += 880;
}


void __userpurge vostok::buffer_vector<vostok::render::shader_macro>::push_back(
        vostok::buffer_vector<vostok::render::shader_macro> *this@<ecx>,
        int a2@<edi>,
        const vostok::render::shader_macro *value)
{
  int v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::shader_macro>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::shader_macro>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 )
  {
    vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)v3, &value->name.m_string);
    *(_BYTE *)(v3 + 272) = 47;
    vostok::fixed_string<256>::fixed_string<256>((vostok::fixed_string<256> *)(v3 + 276), &value->definition);
  }
  *(_DWORD *)(a2 + 4) += 544;
}


void __thiscall vostok::buffer_vector<vostok::render::shadow_vertex>::push_back(
        vostok::buffer_vector<vostok::render::shadow_vertex> *this,
        const vostok::render::shadow_vertex *value,
        float *a3)
{
  const vostok::render::shadow_vertex *v3; // ebx
  float y; // eax
  float *v5; // ecx
  float *v6; // esi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->position.y) >= LODWORD(value->position.z)
    && !`vostok::buffer_vector<vostok::render::shadow_vertex>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::shadow_vertex>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->position.y;
  if ( y != 0.0 )
  {
    v5 = a3;
    v6 = a3;
    *(_DWORD *)LODWORD(y) = *(_DWORD *)a3;
    *(float *)(LODWORD(y) + 4) = *++v6;
    *(float *)(LODWORD(y) + 8) = v6[1];
    *(float *)(LODWORD(y) + 12) = v5[3];
    *(float *)(LODWORD(y) + 16) = v5[4];
    *(float *)(LODWORD(y) + 20) = v5[5];
    *(float *)(LODWORD(y) + 24) = v5[6];
    *(float *)(LODWORD(y) + 28) = v5[7];
  }
  LODWORD(v3->position.y) += 32;
}


void __usercall vostok::buffer_vector<survarium::player_shootmarks_storage::sm>::push_back(
        vostok::buffer_vector<survarium::player_shootmarks_storage::sm> *this@<esi>,
        const survarium::player_shootmarks_storage::sm *value@<edi>)
{
  survarium::player_shootmarks_storage::sm *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<survarium::player_shootmarks_storage::sm>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::player_shootmarks_storage::sm>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __userpurge vostok::buffer_vector<vostok::render::streamable_texture_info>::push_back(
        vostok::buffer_vector<vostok::render::streamable_texture_info> *this@<ecx>,
        int a2@<esi>,
        const vostok::render::streamable_texture_info *value)
{
  const vostok::render::streamable_texture_info *v3; // eax
  vostok::buffer_vector<vostok::render::streamable_texture_info> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !HIBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[3]) )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::streamable_texture_info>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(const vostok::render::streamable_texture_info **)(a2 + 4);
  if ( v3 )
    vostok::render::streamable_texture_info::streamable_texture_info(
      (vostok::render::streamable_texture_info *)this,
      v3,
      (int)value);
  *(_DWORD *)(a2 + 4) += 328;
}


void __userpurge vostok::buffer_vector<vostok::render::streaming_ready_texture>::push_back(
        vostok::buffer_vector<vostok::render::streaming_ready_texture> *this@<ecx>,
        int a2@<esi>,
        const vostok::render::streaming_ready_texture *value)
{
  const vostok::render::streaming_ready_texture *v3; // eax
  vostok::buffer_vector<vostok::render::streaming_ready_texture> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::streaming_ready_texture>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::streaming_ready_texture>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(const vostok::render::streaming_ready_texture **)(a2 + 4);
  if ( v3 )
    vostok::render::streaming_ready_texture::streaming_ready_texture(
      (vostok::render::streaming_ready_texture *)this,
      v3,
      (int)value);
  *(_DWORD *)(a2 + 4) += 288;
}


void __userpurge vostok::buffer_vector<vostok::render::sun_cascade>::push_back(
        vostok::buffer_vector<vostok::render::sun_cascade> *this@<ecx>,
        int a2@<esi>,
        vostok::render::ray *value)
{
  vostok::render::sun_cascade *v3; // eax
  vostok::buffer_vector<vostok::render::sun_cascade> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::sun_cascade>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::sun_cascade>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(vostok::render::sun_cascade **)(a2 + 4);
  if ( v3 )
    vostok::render::sun_cascade::sun_cascade((vostok::render::sun_cascade *)this, v3, value);
  *(_DWORD *)(a2 + 4) += 280;
}


void __usercall vostok::buffer_vector<vostok::render::texture_named_instance>::push_back(
        vostok::buffer_vector<vostok::render::texture_named_instance> *this@<edi>,
        const vostok::render::texture_named_instance *value@<eax>)
{
  vostok::render::texture_named_instance *m_end; // ecx
  const char *v4; // [esp+0h] [ebp-8h]
  bool v5; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::render::texture_named_instance>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::texture_named_instance>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
  {
    m_end->texture = value->texture;
    vostok::fixed_string<260>::fixed_string<260>(&m_end->path, &value->path);
  }
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::render::texture_pool_slot>::push_back(
        vostok::buffer_vector<vostok::render::texture_pool_slot> *this,
        const vostok::render::texture_pool_slot *value,
        _DWORD *a3)
{
  const vostok::render::texture_pool_slot *v3; // ebx
  _DWORD *num_bytes; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->num_bytes >= *(_DWORD *)&value->occupied
    && !`vostok::buffer_vector<vostok::render::texture_pool_slot>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::texture_pool_slot>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  num_bytes = (_DWORD *)v3->num_bytes;
  if ( num_bytes )
  {
    v5 = a3;
    *num_bytes = *a3;
    ++v5;
    v6 = num_bytes + 1;
    *v6 = *v5;
    v6[1] = v5[1];
  }
  v3->num_bytes += 12;
}


void __userpurge vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::push_back(
        vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc> *this@<ecx>,
        int a2@<esi>,
        const vostok::render::effect_compiler::texture_query_desc *value)
{
  const char *v3; // [esp+0h] [ebp-Ch]
  bool v4; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::effect_compiler::texture_query_desc>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::construct(
    *(vostok::render::effect_compiler::texture_query_desc **)(a2 + 4),
    value);
  *(_DWORD *)(a2 + 4) += 552;
}


void __usercall vostok::buffer_vector<vostok::collision::triangle_result>::push_back(
        vostok::buffer_vector<vostok::collision::triangle_result> *this@<esi>,
        const vostok::collision::triangle_result *value@<edi>)
{
  vostok::collision::triangle_result *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::collision::triangle_result>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::collision::triangle_result>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::render::vertex_colored>::push_back(
        vostok::buffer_vector<vostok::render::vertex_colored> *this,
        const vostok::render::vertex_colored *value,
        _DWORD *a3)
{
  const vostok::render::vertex_colored *v3; // ebx
  float y; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->position.y) >= LODWORD(value->position.z)
    && !`vostok::buffer_vector<vostok::render::vertex_colored>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::vertex_colored>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->position.y;
  if ( y != 0.0 )
  {
    v5 = a3;
    *(_DWORD *)LODWORD(y) = *a3;
    ++v5;
    v6 = (_DWORD *)(LODWORD(y) + 4);
    *v6 = *v5++;
    *++v6 = *v5;
    v6[1] = v5[1];
  }
  LODWORD(v3->position.y) += 16;
}


void __thiscall vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::push_back(
        vostok::buffer_vector<survarium::victory_items_container::victory_item_transform> *this,
        const survarium::victory_items_container::victory_item_transform *value,
        const void *a3)
{
  const survarium::victory_items_container::victory_item_transform *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->position.y) >= LODWORD(value->position.z)
    && !`vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::victory_items_container::victory_item_transform>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->position.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x18u);
  LODWORD(v3->position.y) += 24;
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float>>::push_back(
        vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *this,
        const stlp_std::pair<vostok::math::float3,float> *value,
        float *a3)
{
  const stlp_std::pair<vostok::math::float3,float> *v3; // ebx
  float y; // eax
  float *v5; // ecx
  float *v6; // esi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->first.y) >= LODWORD(value->first.z)
    && !`vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct stlp_std::pair<class vostok::math::float3,float> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->first.y;
  if ( y != 0.0 )
  {
    v5 = a3;
    v6 = a3;
    *(_DWORD *)LODWORD(y) = *(_DWORD *)a3;
    *(float *)(LODWORD(y) + 4) = *++v6;
    *(float *)(LODWORD(y) + 8) = v6[1];
    *(float *)(LODWORD(y) + 12) = v5[3];
  }
  LODWORD(v3->first.y) += 16;
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::math::quaternion,float>>::push_back(
        vostok::buffer_vector<stlp_std::pair<vostok::math::quaternion,float> > *this,
        const stlp_std::pair<vostok::math::quaternion,float> *value,
        float *a3)
{
  const stlp_std::pair<vostok::math::quaternion,float> *v3; // ebx
  float y; // eax
  float *v5; // ecx
  float *v6; // esi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->first.y) >= LODWORD(value->first.z)
    && !`vostok::buffer_vector<stlp_std::pair<vostok::math::quaternion,float>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct stlp_std::pair<class vostok::math::quaternion,float> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->first.y;
  if ( y != 0.0 )
  {
    v5 = a3;
    v6 = a3;
    *(_DWORD *)LODWORD(y) = *(_DWORD *)a3;
    *(float *)(LODWORD(y) + 4) = *++v6;
    *(float *)(LODWORD(y) + 8) = *++v6;
    *(float *)(LODWORD(y) + 12) = v6[1];
    *(float *)(LODWORD(y) + 16) = v5[4];
  }
  LODWORD(v3->first.y) += 20;
}


void __usercall vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::push_back(
        vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *this@<esi>,
        const stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *value@<edi>)
{
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __usercall vostok::buffer_vector<vostok::render::culling::aab_rect>::push_back(
        vostok::buffer_vector<vostok::render::culling::aab_rect> *this@<esi>,
        const vostok::render::culling::aab_rect *value@<edi>)
{
  vostok::render::culling::aab_rect *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::render::culling::aab_rect>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::culling::aab_rect>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this,
        const vostok::animation::mixing::animation_interval *value,
        int a3)
{
  const vostok::animation::mixing::animation_interval *v3; // esi
  vostok::resources::managed_resource *m_object; // ebx
  const char *v5; // [esp+0h] [ebp-10h]
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  v3 = value;
  if ( value->m_third_view_animation.m_object >= (vostok::resources::managed_resource *)value->m_animation_id
    && !`vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v6 = 0;
    vostok::debug::on_error(
      &v6,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::animation::mixing::animation_interval>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || v6 )
      __debugbreak();
  }
  m_object = value->m_third_view_animation.m_object;
  if ( m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)value->m_third_view_animation.m_object,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)a3);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&m_object->type,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a3 + 4));
    v3 = value;
    m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = *(_DWORD *)(a3 + 8);
    *((float *)&m_object->vostok::resources::resource_flags + 3) = *(float *)(a3 + 12);
    *(float *)&m_object->m_reconstruction_info_actuality_tick = *(float *)(a3 + 16);
  }
  v3->m_third_view_animation.m_object = (vostok::resources::managed_resource *)((char *)v3->m_third_view_animation.m_object
                                                                              + 20);
}


void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::push_back(
        vostok::buffer_vector<vostok::resources::creation_request> *this,
        const vostok::resources::creation_request *value,
        _DWORD *a3)
{
  const vostok::resources::creation_request *v3; // ebx
  char *m_data; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( value->m_data.m_data >= (const char *)value->m_data.m_size
    && !`vostok::buffer_vector<vostok::resources::creation_request>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::resources::creation_request>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  m_data = (char *)v3->m_data.m_data;
  if ( m_data )
  {
    v5 = a3;
    *(_DWORD *)m_data = *a3;
    ++v5;
    v6 = m_data + 4;
    *v6 = *v5++;
    *++v6 = *v5;
    v6[1] = v5[1];
  }
  v3->m_data.m_data += 16;
}


void __thiscall vostok::buffer_vector<vostok::math::float3>::push_back(
        vostok::buffer_vector<vostok::math::float3> *this,
        const vostok::math::float3 *value,
        _DWORD *a3)
{
  const vostok::math::float3 *v3; // ebx
  float y; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->y) >= LODWORD(value->z)
    && !`vostok::buffer_vector<vostok::math::float3>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::float3>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->y;
  if ( y != 0.0 )
  {
    v5 = a3;
    *(_DWORD *)LODWORD(y) = *a3;
    ++v5;
    v6 = (_DWORD *)(LODWORD(y) + 4);
    *v6 = *v5;
    v6[1] = v5[1];
  }
  LODWORD(v3->y) += 12;
}


void __thiscall vostok::buffer_vector<vostok::math::float4>::push_back(
        vostok::buffer_vector<vostok::math::float4> *this,
        const vostok::math::float4 *value,
        _DWORD *a3)
{
  const vostok::math::float4 *v3; // ebx
  float y; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->y) >= LODWORD(value->z)
    && !`vostok::buffer_vector<vostok::math::float4>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::float4>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->y;
  if ( y != 0.0 )
  {
    v5 = a3;
    *(_DWORD *)LODWORD(y) = *a3;
    ++v5;
    v6 = (_DWORD *)(LODWORD(y) + 4);
    *v6 = *v5++;
    *++v6 = *v5;
    v6[1] = v5[1];
  }
  LODWORD(v3->y) += 16;
}


void __thiscall vostok::buffer_vector<vostok::math::float4x4>::push_back(
        vostok::buffer_vector<vostok::math::float4x4> *this,
        const vostok::math::float4x4 *value,
        const void *a3)
{
  const vostok::math::float4x4 *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->i.y) >= LODWORD(value->i.z)
    && !`vostok::buffer_vector<vostok::math::float4x4>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::float4x4>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->i.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x40u);
  LODWORD(v3->i.y) += 64;
}


void __thiscall vostok::buffer_vector<vostok::math::frustum>::push_back(
        vostok::buffer_vector<vostok::math::frustum> *this,
        const vostok::math::frustum *value,
        const void *a3)
{
  const vostok::math::frustum *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->m_planes[0].plane.normal.y) >= LODWORD(value->m_planes[0].plane.normal.z)
    && !`vostok::buffer_vector<vostok::math::frustum>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::frustum>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->m_planes[0].plane.normal.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x78u);
  LODWORD(v3->m_planes[0].plane.normal.y) += 120;
}


void __thiscall vostok::buffer_vector<vostok::math::plane>::push_back(
        vostok::buffer_vector<vostok::math::plane> *this,
        const vostok::math::plane *value,
        _DWORD *a3)
{
  const vostok::math::plane *v3; // ebx
  float y; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->normal.y) >= LODWORD(value->normal.z)
    && !`vostok::buffer_vector<vostok::math::plane>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::plane>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v7);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->normal.y;
  if ( y != 0.0 )
  {
    v5 = a3;
    *(_DWORD *)LODWORD(y) = *a3;
    ++v5;
    v6 = (_DWORD *)(LODWORD(y) + 4);
    *v6 = *v5++;
    *++v6 = *v5;
    v6[1] = v5[1];
  }
  LODWORD(v3->normal.y) += 16;
}


void __thiscall vostok::buffer_vector<vostok::render::culling::portal>::push_back(
        vostok::buffer_vector<vostok::render::culling::portal> *this,
        const vostok::render::culling::portal *value,
        const void *a3)
{
  const vostok::render::culling::portal *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->m_plane.normal.y) >= LODWORD(value->m_plane.normal.z)
    && !`vostok::buffer_vector<vostok::render::culling::portal>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::culling::portal>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->m_plane.normal.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x4Cu);
  LODWORD(v3->m_plane.normal.y) += 76;
}


void __usercall vostok::buffer_vector<vostok::render::shader_constant>::push_back(
        vostok::buffer_vector<vostok::render::shader_constant> *this@<esi>,
        const vostok::render::shader_constant *value@<edi>)
{
  vostok::render::shader_constant *m_end; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_end >= this->m_max_end
    && !`vostok::buffer_vector<vostok::render::shader_constant>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v4 = 0;
    vostok::debug::on_error(
      &v4,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::shader_constant>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v3);
    if ( vostok::debug::is_debugger_present() || v4 )
      __debugbreak();
  }
  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::render::shader_constant_binding>::push_back(
        vostok::buffer_vector<vostok::render::shader_constant_binding> *this,
        const vostok::render::shader_constant_binding *value,
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *a3)
{
  const vostok::render::shader_constant_binding *v3; // esi
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *m_size; // ebx
  const char *v5; // [esp+0h] [ebp-10h]
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  v3 = value;
  if ( (vostok::strings::shared::profile *)value->m_source.m_size >= value->m_name.m_pointer.m_object
    && !`vostok::buffer_vector<vostok::render::shader_constant_binding>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v6 = 0;
    vostok::debug::on_error(
      &v6,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::shader_constant_binding>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || v6 )
      __debugbreak();
  }
  m_size = (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)value->m_source.m_size;
  if ( m_size )
  {
    m_size->m_object = a3->m_object;
    m_size[1].m_object = a3[1].m_object;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>(
      m_size + 2,
      a3 + 2);
    v3 = value;
    m_size[3].m_object = a3[3].m_object;
    m_size[4].m_object = a3[4].m_object;
  }
  v3->m_source.m_size += 20;
}


void __thiscall vostok::buffer_vector<vostok::render::culling::spatial_sector>::push_back(
        vostok::buffer_vector<vostok::render::culling::spatial_sector> *this,
        const vostok::render::culling::spatial_sector *value,
        const void *a3)
{
  const vostok::render::culling::spatial_sector *v3; // ebx
  float y; // edi
  const char *v5; // [esp+0h] [ebp-10h]

  v3 = value;
  if ( LODWORD(value->m_aabb.min.y) >= LODWORD(value->m_aabb.min.z)
    && !`vostok::buffer_vector<vostok::render::culling::spatial_sector>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(value) = 0;
    vostok::debug::on_error(
      (bool *)&value + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::culling::spatial_sector>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(value) )
      __debugbreak();
  }
  y = v3->m_aabb.min.y;
  if ( y != 0.0 )
    qmemcpy((void *)LODWORD(y), a3, 0x20u);
  LODWORD(v3->m_aabb.min.y) += 32;
}


void __userpurge vostok::buffer_vector<vostok::fs_new::virtual_path_string>::push_back(
        vostok::buffer_vector<vostok::fs_new::virtual_path_string> *this@<ecx>,
        int a2@<edi>,
        const vostok::fs_new::virtual_path_string *value)
{
  int v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool do_debug_break; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::fs_new::virtual_path_string>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::fs_new::virtual_path_string>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 )
  {
    vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)v3, &value->m_string);
    *(_BYTE *)(v3 + 272) = 47;
  }
  *(_DWORD *)(a2 + 4) += 276;
}


void __userpurge vostok::buffer_vector<vostok::fixed_string<260>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<260> > *this@<ecx>,
        int a2@<edi>,
        const vostok::fixed_string<260> *value)
{
  vostok::fixed_string<260> *v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::fixed_string<260>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::fixed_string<260> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  v3 = *(vostok::fixed_string<260> **)(a2 + 4);
  if ( v3 )
    vostok::fixed_string<260>::fixed_string<260>(v3, value);
  *(_DWORD *)(a2 + 4) += 272;
}


void __userpurge vostok::buffer_vector<vostok::fixed_string<128>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<128> > *this@<ecx>,
        int a2@<edi>,
        const vostok::fixed_string<128> *value)
{
  vostok::fixed_string<128> *v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::fixed_string<128>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::fixed_string<128> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  v3 = *(vostok::fixed_string<128> **)(a2 + 4);
  if ( v3 )
    vostok::fixed_string<128>::fixed_string<128>(v3, value);
  *(_DWORD *)(a2 + 4) += 140;
}


void __userpurge vostok::buffer_vector<vostok::variant<32>>::push_back(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        int a2@<edi>,
        const vostok::variant<32> *value)
{
  vostok::variant<32> *v3; // esi
  const char *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::variant<32>>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v5 = 0;
    vostok::debug::on_error(
      &v5,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::variant<32> >::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v4);
    if ( vostok::debug::is_debugger_present() || v5 )
      __debugbreak();
  }
  v3 = *(vostok::variant<32> **)(a2 + 4);
  if ( v3 )
    vostok::variant<32>::variant<32>(v3, value, (vostok::variant<32> *)this);
  *(_DWORD *)(a2 + 4) += 48;
}


void __userpurge vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        vostok::buffer_vector<enum vostok::logging::format_specifier_enum> *this@<ecx>,
        int a2@<esi>,
        vostok::logging::format_specifier_enum *value)
{
  vostok::logging::format_specifier_enum *v3; // eax
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(vostok::logging::format_specifier_enum **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}


void __userpurge vostok::buffer_vector<enum survarium::game_action_id>::push_back(
        vostok::buffer_vector<enum survarium::game_action_id> *this@<ecx>,
        int a2@<esi>,
        survarium::game_action_id *value)
{
  survarium::game_action_id *v3; // eax
  vostok::buffer_vector<enum survarium::game_action_id> *v4; // [esp-2h] [ebp-4h] BYREF

  v4 = this;
  if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<enum survarium::game_action_id>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v4) = 0;
    vostok::debug::on_error(
      (bool *)&v4 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<enum survarium::game_action_id>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v4) )
      __debugbreak();
  }
  v3 = *(survarium::game_action_id **)(a2 + 4);
  if ( v3 )
    *v3 = *value;
  *(_DWORD *)(a2 + 4) += 4;
}
