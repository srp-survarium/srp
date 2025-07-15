void __usercall vostok::ui::ui_text<vostok::ui::static_text>::fit_height_to_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this@<ecx>,
        int a2@<edi>)
{
  int v3; // eax
  const vostok::ui::ui_font *m_font; // ecx
  char *v5; // ebx
  float v6; // xmm1_4
  int v7; // ecx
  const vostok::ui::ui_font *v8; // ecx
  int v9; // ecx
  const vostok::math::float2 *v10; // eax
  float v11; // xmm0_4
  bool v12; // zf
  vostok::ui::window *v13; // edi
  vostok::ui::ui_font *v14; // [esp-Ch] [ebp-34h]
  float v15; // [esp+4h] [ebp-24h]
  float v16; // [esp+8h] [ebp-20h]
  float x; // [esp+Ch] [ebp-1Ch] BYREF
  int v18; // [esp+10h] [ebp-18h]
  float v19; // [esp+14h] [ebp-14h]
  int v20; // [esp+18h] [ebp-10h]
  float v21; // [esp+1Ch] [ebp-Ch] BYREF
  char *v22; // [esp+20h] [ebp-8h] BYREF
  char v23; // [esp+27h] [ebp-1h] BYREF

  if ( this->m_mode == tm_multiline )
  {
    v3 = ((int (__thiscall *)(vostok::ui::ui_text<vostok::ui::dynamic_text> *, int))this->get_text)(this, a2);
    m_font = this->m_font;
    v5 = (char *)v3;
    v20 = (unsigned __int16)(LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin));
    v6 = *m_font->get_height(m_font);
    v22 = 0;
    v14 = (vostok::ui::ui_font *)this->m_font;
    v19 = v6;
    v21 = 0.0;
    v15 = 0.0;
    v16 = v6;
    vostok::ui::parse_word(v5, &v21, v7, v14, &v22);
    if ( v20 )
    {
      do
      {
        v8 = this->m_font;
        v23 = *v5;
        v18 = v8->get_char_tc((struct vostok::ui::ui_font *)v8, (const unsigned __int8 *)&v23);
        if ( v5 == v22 )
        {
          vostok::ui::parse_word(v5, &v21, v9, (vostok::ui::ui_font *)this->m_font, &v22);
          v10 = this->get_size(&this->vostok::ui::ui_window);
          if ( (float)(v15 + v21) > v10->x )
          {
            v15 = 0.0;
            v16 = v16 + v19;
          }
        }
        v11 = *(float *)(v18 + 8) + v15;
        ++v5;
        v12 = v20-- == 1;
        v15 = v11;
      }
      while ( !v12 );
    }
    v13 = this->w(this);
    x = this->get_size(&this->vostok::ui::ui_window)->x;
    v18 = LODWORD(v16);
    v13->set_size(v13, (const vostok::math::float2 *)&x);
  }
}
