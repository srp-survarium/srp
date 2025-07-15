vostok::render::stage_rain *__thiscall vostok::render::stage_rain::`scalar deleting destructor'(
        vostok::render::stage_rain *this,
        char a2)
{
  vostok::render::stage_rain::~stage_rain(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
