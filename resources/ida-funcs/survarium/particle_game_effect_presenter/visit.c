void __userpurge survarium::particle_game_effect_presenter::visit(
        survarium::particle_game_effect_presenter *this@<ecx>,
        const char *a2@<edi>,
        const survarium::particle_game_effect *effect,
        const survarium::game_effect_state *state)
{
  float current_time; // xmm0_4
  const survarium::value_animation<float,survarium::particle_game_effect_emitter_cook> *m_animation; // edx
  const survarium::value_animation<float,survarium::particle_game_effect_emitter_cook>::key_frame *m_key_frames; // ecx
  int v7; // esi
  float *i; // edi
  float value; // xmm0_4
  float *p_value; // eax
  survarium::loose_ptr_data *m_pointer; // eax
  survarium::particle_game_effect_presenter *v12; // esi
  survarium::particle_game_effect_presenter::effect_data *m_end; // eax
  const survarium::particle_game_effect_presenter::effect_data *v14; // eax
  survarium::loose_ptr_data *v15; // ecx
  bool v18; // [esp+3h] [ebp-19h] BYREF
  float v19; // [esp+4h] [ebp-18h]
  survarium::particle_game_effect_presenter *v20; // [esp+8h] [ebp-14h]
  survarium::particle_game_effect_presenter::effect_data v21; // [esp+Ch] [ebp-10h] BYREF

  current_time = state->current_time;
  m_animation = effect->m_animation;
  v20 = this;
  m_key_frames = m_animation->m_key_frames;
  v7 = 0;
  for ( i = (float *)&m_animation->m_key_frames[1].time; ; i += 2 )
  {
    if ( *(i - 2) == current_time )
    {
      value = m_key_frames[v7].value;
      goto LABEL_7;
    }
    if ( *i > current_time )
      break;
    ++v7;
  }
  p_value = (float *)&m_key_frames[v7].value;
  value = (float)((float)(p_value[2] - *p_value)
                * (float)((float)(current_time - p_value[1]) / (float)(p_value[3] - p_value[1])))
        + *p_value;
LABEL_7:
  m_pointer = effect->m_pointer;
  v19 = value;
  v21.effect.m_object = m_pointer;
  if ( m_pointer )
    ++m_pointer->m_reference_count;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v21.particle_system,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&effect->m_particle_system);
  v12 = v20;
  m_end = v20->m_new_effects.m_end;
  v21.time_to_finish = effect->m_time_to_finish;
  v21.time = v19;
  if ( m_end >= v20->m_new_effects.m_max_end
    && !`vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    v18 = 0;
    vostok::debug::on_error(
      &v18,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::particle_game_effect_presenter::effect_data>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      a2);
    if ( vostok::debug::is_debugger_present() || v18 )
      __debugbreak();
  }
  v14 = v12->m_new_effects.m_end;
  if ( v14 )
    survarium::particle_game_effect_presenter::effect_data::effect_data(&v21, v14, (int)&v21);
  ++v12->m_new_effects.m_end;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21.particle_system);
  if ( v21.effect.m_object )
  {
    if ( v21.effect.m_object->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(v15, v21.effect.m_object);
  }
}
