unsigned __int16 __userpurge vostok::ui::ui_text_edit::calc_left_word_position@<ax>(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<esi>,
        unsigned __int16 caret)
{
  unsigned __int16 v4; // di
  unsigned __int16 i; // ax
  vostok::ui::ui_text_edit *v6; // ecx

  if ( !*(_WORD *)(a2 + 678) )
    return 0;
  v4 = 0;
  for ( i = vostok::ui::ui_text_edit::calc_right_word_position(this, a2, 0);
        caret > i;
        i = vostok::ui::ui_text_edit::calc_right_word_position(v6, a2, i) )
  {
    v4 = i;
  }
  return v4;
}
