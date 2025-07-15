vostok::ui::ui_image *__thiscall vostok::ui::ui_image::`scalar deleting destructor'(
        vostok::ui::ui_image *this,
        char a2)
{
  vostok::ui::ui_image::~ui_image(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
