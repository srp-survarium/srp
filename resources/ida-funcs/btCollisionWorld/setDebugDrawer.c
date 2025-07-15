void __thiscall btCollisionWorld::setDebugDrawer(
        vostok::ui::ui_text<vostok::ui::static_text> *this,
        vostok::ui::enum_text_mode tm)
{
  this->m_mode = tm;
}
