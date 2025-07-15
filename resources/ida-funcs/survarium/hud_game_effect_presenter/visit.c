void __userpurge survarium::hud_game_effect_presenter::visit(
        survarium::hud_game_effect_presenter *this@<ecx>,
        const char *a2@<edi>,
        const survarium::hud_game_effect *effect,
        const survarium::game_effect_state *state)
{
  float current_time; // xmm0_4
  const survarium::value_animation<float,survarium::hud_game_effect_emitter_cook>::key_frame *m_key_frames; // ecx
  int v7; // esi
  float *i; // edi
  float value; // xmm0_4
  float *p_value; // eax
  const survarium::hud_game_effect *v11; // ecx
  survarium::loose_ptr_data *m_pointer; // esi
  survarium::hud_game_effect_presenter::effect_data *m_end; // eax
  survarium::hud_game_effect_presenter::effect_data *v14; // eax
  survarium::hud_game_effect_presenter::effect_data __that; // [esp+0h] [ebp-Ch] BYREF

  current_time = state->current_time;
  m_key_frames = effect->m_animation->m_key_frames;
  v7 = 0;
  for ( i = (float *)&m_key_frames[1].time; ; i += 2 )
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
  v11 = effect;
  m_pointer = effect->m_pointer;
  __that.effect.m_object = m_pointer;
  if ( m_pointer )
  {
    ++m_pointer->m_reference_count;
    m_pointer = __that.effect.m_object;
  }
  __that.effect_type = v11->m_type;
  m_end = this->m_new_effects.m_end;
  __that.frame_id = value;
  if ( m_end >= this->m_new_effects.m_max_end
    && !`vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(effect) = 0;
    vostok::debug::on_error(
      (bool *)&effect + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::hud_game_effect_presenter::effect_data>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      a2);
    if ( vostok::debug::is_debugger_present() || HIBYTE(effect) )
      __debugbreak();
  }
  v14 = this->m_new_effects.m_end;
  if ( v14 )
    survarium::hud_game_effect_presenter::effect_data::effect_data(v14, &__that);
  ++this->m_new_effects.m_end;
  if ( m_pointer )
  {
    if ( m_pointer->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(
        (survarium::loose_ptr_data *)v11,
        __that.effect.m_object);
  }
}
