vostok::render::scene_view *__thiscall vostok::render::scene_view::`vector deleting destructor'(
        vostok::render::scene_view *this,
        char a2)
{
  vostok::render::scene_view::~scene_view(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
