bool __userpurge vostok::ui::base_edit_action::similar@<al>(
        vostok::ui::base_edit_action *this@<ecx>,
        int a2@<eax>,
        vostok::input::enum_keyboard_action action,
        unsigned __int8 *state,
        const vostok::ui::shift_state *a5)
{
  int v5; // ecx
  bool result; // al
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  char v9; // al
  char v10; // al
  char v11; // dl

  v5 = *(_DWORD *)(a2 + 12);
  if ( v5 && v5 != action )
    return 0;
  v7 = *(_BYTE *)(a2 + 16);
  v8 = *state;
  v9 = (v7 >> 2) & 3;
  result = 0;
  if ( ((*state >> 2) & 3) == v9 || v9 == 2 )
  {
    v10 = (v7 >> 4) & 3;
    if ( ((v8 >> 4) & 3) == v10 || v10 == 2 )
    {
      v11 = v7 & 3;
      if ( (v8 & 3) == v11 || v11 == 2 )
        return 1;
    }
  }
  return result;
}
