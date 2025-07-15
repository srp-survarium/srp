vostok::render::scene *__thiscall vostok::render::scene::`vector deleting destructor'(
        vostok::render::scene *this,
        char a2)
{
  vostok::render::scene::~scene(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
