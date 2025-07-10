void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::set_font(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        vostok::ui::enum_font fnt)
{
  this->m_font = &this->m_ui_world->m_font_manager.m_font;
}
