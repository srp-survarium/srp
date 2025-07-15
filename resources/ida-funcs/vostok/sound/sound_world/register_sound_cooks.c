void __thiscall vostok::sound::sound_world::register_sound_cooks(vostok::sound::sound_world *this)
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    vostok::sound::ogg_source_cook::ogg_source_cook(&s_ogg_source_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_ogg_source_cook__);
  }
  vostok::resources::register_cook(&s_ogg_source_cook);
  if ( (_S5 & 2) == 0 )
  {
    _S5 |= 2u;
    vostok::sound::ogg_sound_cook::ogg_sound_cook(&s_ogg_sound_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_ogg_sound_cook__);
  }
  vostok::resources::register_cook(&s_ogg_sound_cook);
  if ( (_S5 & 4) == 0 )
  {
    _S5 |= 4u;
    vostok::sound::sound_rms_cook::sound_rms_cook(&s_sound_rms_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_rms_cook__);
  }
  vostok::resources::register_cook(&s_sound_rms_cook);
  if ( (_S5 & 8) == 0 )
  {
    _S5 |= 8u;
    vostok::sound::ogg_file_contents_cook::ogg_file_contents_cook(&s_ogg_file_contents_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_ogg_file_contents_cook__);
  }
  vostok::resources::register_cook(&s_ogg_file_contents_cook);
  if ( (_S5 & 0x10) == 0 )
  {
    _S5 |= 0x10u;
    vostok::sound::sound_collection_cook::sound_collection_cook(&s_sound_cll_cook, this);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_cll_cook__);
  }
  vostok::resources::register_cook(&s_sound_cll_cook);
  if ( (_S5 & 0x20) == 0 )
  {
    _S5 |= 0x20u;
    vostok::sound::composite_sound_cook::composite_sound_cook(&s_composite_sound_cook, this);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_composite_sound_cook__);
  }
  vostok::resources::register_cook(&s_composite_sound_cook);
  if ( (_S5 & 0x40) == 0 )
  {
    _S5 |= 0x40u;
    vostok::sound::single_sound_cook::single_sound_cook(&s_single_sound_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_single_sound_cook__);
  }
  vostok::resources::register_cook(&s_single_sound_cook);
  if ( (_S5 & 0x80) == 0 )
  {
    _S5 |= 0x80u;
    vostok::sound::encoded_sound_with_qualities_cook::encoded_sound_with_qualities_cook(&s_encoded_sound_with_qualities_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_encoded_sound_with_qualities_cook__);
  }
  vostok::resources::register_cook(&s_encoded_sound_with_qualities_cook);
  if ( (_S5 & 0x100) == 0 )
  {
    _S5 |= 0x100u;
    vostok::sound::ogg_encoded_sound_interface_cook::ogg_encoded_sound_interface_cook(&s_ogg_encoded_sound_interface_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_ogg_encoded_sound_interface_cook__);
  }
  vostok::resources::register_cook(&s_ogg_encoded_sound_interface_cook);
  if ( (_S5 & 0x200) == 0 )
  {
    _S5 |= 0x200u;
    vostok::sound::wav_encoded_sound_interface_cook::wav_encoded_sound_interface_cook(&s_wav_encoded_sound_interface_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_wav_encoded_sound_interface_cook__);
  }
  vostok::resources::register_cook(&s_wav_encoded_sound_interface_cook);
  if ( (_S5 & 0x400) == 0 )
  {
    _S5 |= 0x400u;
    vostok::sound::sound_spl_cook::sound_spl_cook(&s_sound_spl_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_spl_cook__);
  }
  vostok::resources::register_cook(&s_sound_spl_cook);
  if ( (_S5 & 0x800) == 0 )
  {
    _S5 |= 0x800u;
    vostok::sound::panning_lut_cook::panning_lut_cook(&s_panning_lut_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_panning_lut_cook__);
  }
  vostok::resources::register_cook(&s_panning_lut_cook);
  if ( (_S5 & 0x1000) == 0 )
  {
    _S5 |= 0x1000u;
    vostok::sound::sound_scene_cook::sound_scene_cook(&s_sound_scene_cook, this);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_scene_cook__);
  }
  if ( (_S5 & 0x2000) == 0 )
  {
    _S5 |= 0x2000u;
    vostok::sound::sound_environment_cook::sound_environment_cook(&s_sound_environment_cook);
    atexit(vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_environment_cook__);
  }
  vostok::resources::register_cook(&s_sound_scene_cook);
  vostok::resources::register_cook(&s_sound_environment_cook);
}
