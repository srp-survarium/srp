vostok::render::stage_pre_rain *__thiscall vostok::render::stage_pre_rain::`vector deleting destructor'(
        vostok::render::stage_pre_rain *this,
        char a2)
{
  vostok::render::stage_pre_rain::~stage_pre_rain(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
