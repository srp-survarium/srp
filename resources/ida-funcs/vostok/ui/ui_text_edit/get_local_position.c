void __userpurge vostok::ui::ui_text_edit::get_local_position(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<esi>,
        unsigned __int16 pos)
{
  int v3; // eax

  if ( pos )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4);
    vostok::ui::calc_string_length_n(v3, pos, *(vostok::ui::ui_font **)(a2 + 596));
  }
}
