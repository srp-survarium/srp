vostok::render::stage_screen_space_reflections *__thiscall vostok::render::stage_accumulate_distortion::`vector deleting destructor'(
        vostok::render::stage_screen_space_reflections *this,
        char a2)
{
  this->__vftable = (vostok::render::stage_screen_space_reflections_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
