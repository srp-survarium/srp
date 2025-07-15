char __thiscall vostok::input::platform::keyboard::translate_text(
        vostok::input::platform::keyboard *this,
        UINT dik,
        wchar_t *dest_text)
{
  HKL KeyboardLayout; // ebx
  UINT v5; // ecx
  int v6; // eax
  wchar_t v7; // cx
  wchar_t v9; // ax
  unsigned __int8 KeyState[256]; // [esp+8h] [ebp-118h] BYREF
  wchar_t DestStr[4]; // [esp+108h] [ebp-18h] BYREF
  wchar_t SrcStr[4]; // [esp+110h] [ebp-10h] BYREF
  wchar_t pwszBuff; // [esp+118h] [ebp-8h] BYREF
  int v14; // [esp+11Ah] [ebp-6h]

  KeyboardLayout = GetKeyboardLayout(0);
  if ( !GetKeyboardState(KeyState) )
    return 0;
  v5 = MapVirtualKeyExA(dik, 3u, KeyboardLayout);
  if ( !v5 )
    return 0;
  pwszBuff = 0;
  v14 = 0;
  v6 = ToUnicodeEx(v5, dik, KeyState, &pwszBuff, 3, 0, KeyboardLayout);
  if ( v6 == 1 )
  {
    v7 = pwszBuff;
    if ( !this->m_dead_key )
    {
      this->m_dead_key = 0;
      goto LABEL_7;
    }
    SrcStr[1] = this->m_dead_key;
    SrcStr[2] = 0;
    this->m_dead_key = 0;
    SrcStr[0] = v7;
    if ( FoldStringW(0x20u, SrcStr, 3, DestStr, 3) )
    {
      v7 = DestStr[0];
LABEL_7:
      *dest_text = v7;
      return 1;
    }
  }
  else if ( v6 == 2 )
  {
    switch ( pwszBuff )
    {
      case 0x5Eu:
        v9 = 770;
        break;
      case 0x60u:
        v9 = 768;
        break;
      case 0xA8u:
        v9 = 776;
        break;
      case 0xB4u:
        v9 = 769;
        break;
      case 0xB8u:
        v9 = 807;
        break;
      default:
        this->m_dead_key = pwszBuff;
        return 0;
    }
    this->m_dead_key = v9;
  }
  return 0;
}
