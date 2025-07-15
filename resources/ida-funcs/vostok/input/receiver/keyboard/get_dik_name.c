bool __thiscall vostok::input::receiver::keyboard::get_dik_name(
        vostok::input::receiver::keyboard *this,
        unsigned int dik,
        char *dest_str,
        unsigned int dest_sz)
{
  IDirectInputDevice8A *m_device; // eax
  unsigned int converted_size; // [esp+Ch] [ebp-21Ch] BYREF
  DIPROPSTRING keyname; // [esp+10h] [ebp-218h] BYREF

  keyname.diph.dwObj = dik;
  m_device = this->m_device;
  keyname.diph.dwSize = 536;
  keyname.diph.dwHeaderSize = 16;
  keyname.diph.dwHow = 1;
  if ( m_device->GetProperty(m_device, (const _GUID *)20, &keyname.diph) < 0 || !wcslen(keyname.wsz) )
    return 0;
  converted_size = 0;
  return wcstombs_s(&converted_size, dest_str, dest_sz, keyname.wsz, dest_sz) != 22;
}
