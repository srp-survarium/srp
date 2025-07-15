vostok::render::stage_gbuffer *__thiscall vostok::render::stage_gbuffer::`vector deleting destructor'(
        vostok::render::stage_gbuffer *this,
        char a2)
{
  vostok::render::stage_gbuffer::~stage_gbuffer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
