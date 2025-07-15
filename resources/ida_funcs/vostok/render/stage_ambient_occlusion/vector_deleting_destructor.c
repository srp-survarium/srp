vostok::render::stage_ambient_occlusion *__thiscall vostok::render::stage_ambient_occlusion::`vector deleting destructor'(
        vostok::render::stage_ambient_occlusion *this,
        char a2)
{
  vostok::render::stage_ambient_occlusion::~stage_ambient_occlusion(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
