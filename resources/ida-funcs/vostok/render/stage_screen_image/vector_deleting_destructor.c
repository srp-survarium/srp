vostok::render::stage_screen_image *__thiscall vostok::render::stage_screen_image::`vector deleting destructor'(
        vostok::render::stage_screen_image *this,
        char a2)
{
  vostok::render::stage_screen_image::~stage_screen_image(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
