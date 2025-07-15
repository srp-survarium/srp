unsigned int __thiscall vostok::render::grass_world::add_template(
        vostok::render::grass_world *this,
        const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *in_render_model)
{
  const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  vostok::render::grass_render_model *m_object; // eax
  const char *v5; // [esp+0h] [ebp-44h]
  vostok::render::grass_template value; // [esp+10h] [ebp-34h] BYREF
  int v7; // [esp+34h] [ebp-10h]
  int v8; // [esp+38h] [ebp-Ch]
  int v9; // [esp+3Ch] [ebp-8h]
  unsigned int v10; // [esp+40h] [ebp-4h]

  ++g_template_counter;
  v2 = in_render_model;
  v10 = g_template_counter;
  value.m_instances.m_size = 0;
  value.m_instances.m_first = 0;
  value.m_instances.m_last = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value.m_render_model,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  value.m_index = v10;
  m_object = v2[68].m_object;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  memset(&value.m_sizes, 0, sizeof(value.m_sizes));
  if ( m_object >= v2[69].m_object
    && !`vostok::buffer_vector<vostok::render::grass_template>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(in_render_model) = 0;
    vostok::debug::on_error(
      (bool *)&in_render_model + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::grass_template>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(in_render_model) )
      __debugbreak();
  }
  vostok::buffer_vector<vostok::render::grass_template>::construct(
    (vostok::render::grass_template *)v2[68].m_object,
    &value);
  v2[68].m_object = (vostok::render::grass_render_model *)((char *)v2[68].m_object + 36);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value.m_render_model);
  return v10;
}
