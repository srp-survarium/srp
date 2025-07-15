vostok::render::res_effect *__thiscall vostok::render::res_effect::`vector deleting destructor'(
        vostok::render::res_effect *this,
        char a2)
{
  vostok::render::res_effect::~res_effect(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
