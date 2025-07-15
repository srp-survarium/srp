void __thiscall vostok::sound::new_sound_propagator::set_voice_channel_matrix(
        vostok::sound::new_sound_propagator *this,
        vostok::sound::sound_voice *voice,
        const float *channel_matrix,
        float lp_coeff)
{
  vostok::sound::sound_voice::set_output_matrix(voice, channel_matrix);
  vostok::sound::sound_voice::set_low_pass_filter_params(voice, lp_coeff);
}
