void __thiscall vostok::ui::ui_progress_bar::set_range(
        vostok::ui::ui_progress_bar *this,
        unsigned int minimum,
        unsigned int maximum)
{
  this->m_minimum = minimum;
  this->m_maximum = maximum;
}
