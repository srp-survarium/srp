vostok::ui::ui_progress_bar *__thiscall vostok::ui::ui_progress_bar::`vector deleting destructor'(
        vostok::ui::ui_progress_bar *this,
        char a2)
{
  vostok::ui::ui_progress_bar::~ui_progress_bar(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::ui::ui_progress_bar *__thiscall vostok::ui::ui_progress_bar::`vector deleting destructor'(char *this, char a2)
{
  return vostok::ui::ui_progress_bar::`vector deleting destructor'((vostok::ui::ui_progress_bar *)(this - 4), a2);
}
