void __userpurge survarium::sound_game_effect_presenter::visit(
        survarium::sound_game_effect_presenter *this@<ecx>,
        long double a2@<esi:edi>,
        const survarium::sound_game_effect *effect,
        float state)
{
  float v4; // xmm0_4
  const survarium::value_animation<survarium::sound_game_effect::properties,survarium::sound_game_effect_emitter_cook>::key_frame *m_key_frames; // edx
  int v7; // ecx
  float *i; // edi
  int v9; // ecx
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float offset; // xmm0_4
  float v14; // xmm0_4
  survarium::loose_ptr_data *m_pointer; // esi
  survarium::sound_game_effect_presenter::effect_data *m_end; // eax
  survarium::loose_ptr_data *v17; // ecx
  long double v19; // [esp-Ch] [ebp-18h]
  survarium::sound_game_effect_presenter::effect_data v20; // [esp+0h] [ebp-Ch] BYREF

  v4 = *(float *)(LODWORD(state) + 16);
  m_key_frames = effect->m_animation->m_key_frames;
  v19 = a2;
  v7 = 0;
  for ( i = (float *)&m_key_frames[1].time; ; i += 3 )
  {
    if ( *(i - 3) == v4 )
    {
      v9 = v7;
      v20.offset = m_key_frames[v9].value.mean_offset;
      v20.sound.m_object = (vostok::sound::sound_instance_proxy *)LODWORD(m_key_frames[v9].value.max_offset);
      goto LABEL_7;
    }
    if ( *i > v4 )
      break;
    ++v7;
  }
  v10 = v7;
  v11 = (float)(v4 - (float)m_key_frames[v10].time)
      / (float)((float)m_key_frames[v10 + 1].time - (float)m_key_frames[v10].time);
  v12 = (float)((float)(m_key_frames[v10 + 1].value.max_offset - m_key_frames[v10].value.max_offset) * v11)
      + m_key_frames[v10].value.max_offset;
  v20.offset = (float)((float)(m_key_frames[v10 + 1].value.mean_offset - m_key_frames[v10].value.mean_offset) * v11)
             + m_key_frames[v10].value.mean_offset;
  *(float *)&v20.sound.m_object = v12;
LABEL_7:
  offset = 0.0;
  if ( v20.offset != 0.0 )
  {
    state = s_bm_current_air_resistance / v20.offset;
    v14 = s_bm_current_air_resistance
        - boost::random::detail::new_uniform_01<float>::operator()<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(
            &this->m_random_generator,
            (boost::random::detail::new_uniform_01<float> *)LODWORD(v19));
    __libm_sse2_log(v19);
    offset = (float)(v14 / state) * -1.0;
  }
  if ( offset > *(float *)&v20.sound.m_object )
    offset = v20.offset;
  m_pointer = effect->m_pointer;
  v20.effect.m_object = m_pointer;
  if ( m_pointer )
  {
    ++m_pointer->m_reference_count;
    m_pointer = v20.effect.m_object;
  }
  m_end = this->m_new_effects.m_end;
  v20.sound.m_object = 0;
  v20.offset = offset;
  if ( m_end >= this->m_new_effects.m_max_end
    && !`vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(effect) = 0;
    vostok::debug::on_error(
      (bool *)&effect + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct survarium::sound_game_effect_presenter::effect_data>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      (const char *)LODWORD(v19));
    if ( vostok::debug::is_debugger_present() || HIBYTE(effect) )
      __debugbreak();
  }
  if ( this->m_new_effects.m_end )
    survarium::sound_game_effect_presenter::effect_data::effect_data(&v20, this->m_new_effects.m_end);
  ++this->m_new_effects.m_end;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(&v20.sound);
  if ( m_pointer )
  {
    if ( m_pointer->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(v17, v20.effect.m_object);
  }
}
