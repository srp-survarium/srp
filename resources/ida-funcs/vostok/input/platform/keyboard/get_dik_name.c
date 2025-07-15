bool __thiscall vostok::input::platform::keyboard::get_dik_name(
        vostok::input::platform::keyboard *this,
        int dik,
        char *dest_str,
        unsigned int dest_sz)
{
  IDirectInputDevice8A *m_device; // eax
  unsigned int pConvertedChars; // [esp+Ch] [ebp-21Ch] BYREF
  _DWORD v7[4]; // [esp+10h] [ebp-218h] BYREF
  wchar_t src[260]; // [esp+20h] [ebp-208h] BYREF

  v7[2] = dik;
  m_device = this->m_device;
  v7[0] = 536;
  v7[1] = 16;
  v7[3] = 1;
  if ( m_device->GetProperty(m_device, (const _GUID *)20, (DIPROPHEADER *)v7) < 0 || !wcslen(src) )
    return 0;
  pConvertedChars = 0;
  return wcstombs_s(&pConvertedChars, dest_str, dest_sz, src, dest_sz) != 22;
}
