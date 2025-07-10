char __userpurge vostok::input::receiver::keyboard::get_dik_unicode@<al>(
        vostok::input::receiver::keyboard *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int dik,
        wchar_t *buff,
        unsigned int buff_size)
{
  IDirectInputDevice8A *m_device; // eax
  DIPROPSTRING keyname; // [esp+0h] [ebp-218h] BYREF

  keyname.diph.dwObj = dik;
  m_device = this->m_device;
  keyname.diph.dwSize = 536;
  keyname.diph.dwHeaderSize = 16;
  keyname.diph.dwHow = 1;
  if ( m_device->GetProperty(m_device, (const _GUID *)20, &keyname.diph) < 0 )
    return 0;
  wcscpy_s(a2, buff, buff_size, keyname.wsz);
  return 1;
}
