vostok::render::stage_postprocess *__thiscall vostok::render::stage_postprocess::`vector deleting destructor'(
        vostok::render::stage_postprocess *this,
        char a2)
{
  vostok::render::stage_postprocess::~stage_postprocess(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
