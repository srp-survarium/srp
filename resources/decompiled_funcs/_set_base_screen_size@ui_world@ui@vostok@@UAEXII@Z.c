void __thiscall vostok::ui::ui_world::set_base_screen_size(
        vostok::ui::ui_world *this,
        unsigned int size_x,
        unsigned int size_y)
{
  this->m_base_screen_size.x = (float)size_x;
  this->m_base_screen_size.y = (float)size_y;
}
