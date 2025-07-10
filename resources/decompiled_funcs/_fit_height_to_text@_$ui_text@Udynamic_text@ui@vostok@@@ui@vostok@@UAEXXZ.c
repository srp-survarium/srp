void __usercall vostok::ui::ui_text<vostok::ui::dynamic_text>::fit_height_to_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this@<ecx>,
        int a2@<edi>)
{
  const char *v3; // ebx
  float v4; // ebp
  float *v5; // eax
  const vostok::ui::ui_font *v6; // ecx
  int v7; // ebp
  const vostok::math::float2 *v8; // eax
  float y; // xmm0_4
  float v10; // xmm1_4
  bool v11; // zf
  vostok::ui::window *v12; // edi
  const vostok::ui::ui_font *m_font; // [esp-10h] [ebp-34h]
  const char *next_word; // [esp+8h] [ebp-1Ch] BYREF
  const char *curr_word_len; // [esp+Ch] [ebp-18h] BYREF
  float length; // [esp+10h] [ebp-14h] BYREF
  float height; // [esp+14h] [ebp-10h]
  float x; // [esp+18h] [ebp-Ch] BYREF
  vostok::math::float2 new_size; // [esp+1Ch] [ebp-8h]
  float retaddr; // [esp+24h] [ebp+0h]

  if ( this->m_mode == tm_multiline )
  {
    v3 = (const char *)((int (__thiscall *)(vostok::ui::ui_text<vostok::ui::dynamic_text> *, int))this->get_text)(
                         this,
                         a2);
    LODWORD(v4) = (unsigned __int16)(LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin));
    v5 = (float *)this->m_font->get_height(this->m_font);
    m_font = this->m_font;
    x = *v5;
    length = 0.0;
    curr_word_len = 0;
    new_size.y = 0.0;
    retaddr = x;
    vostok::ui::parse_word(v3, m_font, &length, &curr_word_len);
    if ( v4 != 0.0 )
    {
      height = v4;
      do
      {
        v6 = this->m_font;
        HIBYTE(next_word) = *v3;
        v7 = v6->get_char_tc((struct vostok::ui::ui_font *)v6, (const unsigned __int8 *)&next_word + 3);
        if ( v3 == curr_word_len )
        {
          vostok::ui::parse_word(v3, this->m_font, &length, &curr_word_len);
          v8 = this->get_size(&this->vostok::ui::ui_window);
          y = new_size.y;
          if ( (float)(new_size.y + length) > v8->x )
          {
            y = 0.0;
            retaddr = retaddr + x;
          }
        }
        else
        {
          y = new_size.y;
        }
        v10 = *(float *)(v7 + 8);
        ++v3;
        v11 = LODWORD(height)-- == 1;
        new_size.y = v10 + y;
      }
      while ( !v11 );
    }
    v12 = this->w(this);
    x = this->get_size(&this->vostok::ui::ui_window)->x;
    new_size.x = retaddr;
    v12->set_size(v12, (const vostok::math::float2 *)&x);
  }
}
