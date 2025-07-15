__int64 __usercall vostok::ui::ui_text_edit::get_local_position@<xmm0>(
        vostok::ui::ui_text_edit *this@<esi>,
        unsigned __int16 pos@<di>)
{
  const char *v2; // eax
  __int64 result; // xmm0_8

  if ( !pos )
    return 0;
  v2 = this->get_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>);
  vostok::ui::calc_string_length_n(this->m_font, v2, pos);
  return result;
}
