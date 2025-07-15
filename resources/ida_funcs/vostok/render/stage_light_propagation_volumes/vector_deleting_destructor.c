vostok::render::stage_light_propagation_volumes *__thiscall vostok::render::stage_light_propagation_volumes::`vector deleting destructor'(
        vostok::render::stage_light_propagation_volumes *this,
        char a2)
{
  vostok::render::stage_light_propagation_volumes::~stage_light_propagation_volumes(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
