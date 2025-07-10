void __thiscall vostok::ai::ai_world::register_cooks(vostok::ai::ai_world *this)
{
  if ( (_S3_13 & 1) == 0 )
  {
    _S3_13 |= 1u;
    vostok::ai::brain_unit_cook::brain_unit_cook(&s_brain_unit_cook, this);
    atexit(vostok::ai::ai_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_brain_unit_cook__);
  }
  if ( (_S3_13 & 2) == 0 )
  {
    _S3_13 |= 2u;
    vostok::ai::behaviour_cook::behaviour_cook(&s_behaviour_cook, this);
    atexit(vostok::ai::ai_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_behaviour_cook__);
  }
  vostok::resources::register_cook(&s_brain_unit_cook);
  vostok::resources::register_cook(&s_behaviour_cook);
}
