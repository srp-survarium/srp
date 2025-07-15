void __userpurge vostok::ui::ui_text<vostok::ui::static_text>::split_and_set_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        char *str,
        float width,
        const char **ret_str)
{
  char *v8; // ebx
  int v9; // ecx
  vostok::ui::ui_font *m_font; // [esp-14h] [ebp-424h]
  vostok::ui::ui_font *v11; // [esp-14h] [ebp-424h]
  int v12; // [esp-10h] [ebp-420h]
  int v13; // [esp-10h] [ebp-420h]
  char _Dst[1028]; // [esp+0h] [ebp-410h] BYREF
  float v18; // [esp+404h] [ebp-Ch]
  char *v19; // [esp+408h] [ebp-8h] BYREF
  float v20; // [esp+40Ch] [ebp-4h] BYREF

  v19 = 0;
  m_font = (vostok::ui::ui_font *)this->m_font;
  v8 = str;
  v20 = 0.0;
  v18 = 0.0;
  vostok::ui::parse_word(str, &v20, (int)&v19, m_font, &v19);
  v9 = v12;
  if ( width > v20 )
  {
    do
    {
      if ( !strlen(v8) )
        break;
      if ( v8 == v19 )
      {
        v11 = (vostok::ui::ui_font *)this->m_font;
        v18 = v18 + v20;
        vostok::ui::parse_word(v8, &v20, v9, v11, &v19);
        v9 = v13;
      }
      else
      {
        ++v8;
      }
    }
    while ( width > (float)(v18 + v20) );
  }
  strncpy_s(_Dst, 0x400u, str, strlen(str) - strlen(v8));
  ((void (__thiscall *)(vostok::ui::ui_text<vostok::ui::dynamic_text> *, char *, int, int, int))this->set_text)(
    this,
    _Dst,
    a3,
    a4,
    a2);
  *ret_str = &v19[strlen(v19) + 1] != v19 + 1 ? v8 : 0;
}
