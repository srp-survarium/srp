vostok::ui::ui_text<vostok::ui::static_text> *__thiscall vostok::ui::ui_text<vostok::ui::static_text>::`vector deleting destructor'(
        vostok::ui::ui_text<vostok::ui::static_text> *this,
        char a2)
{
  vostok::ui::ui_window *v3; // edi
  vostok::strings::shared::profile *m_object; // eax

  v3 = &this->vostok::ui::ui_window;
  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::static_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::text'};
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::ui_window'};
  m_object = this->m_text.m_text.m_pointer.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::ui::ui_window::~ui_window(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
