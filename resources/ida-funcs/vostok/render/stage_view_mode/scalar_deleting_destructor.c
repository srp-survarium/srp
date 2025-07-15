vostok::render::stage_view_mode *__thiscall vostok::render::stage_view_mode::`scalar deleting destructor'(
        vostok::render::stage_view_mode *this,
        char a2)
{
  vostok::render::stage_view_mode::~stage_view_mode(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
