vostok::render::stage_lights *__thiscall vostok::render::stage_lights::`scalar deleting destructor'(
        vostok::render::stage_lights *this,
        char a2)
{
  vostok::render::stage_lights::~stage_lights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
