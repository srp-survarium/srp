void __userpurge vostok::input::receiver::keyboard::keyboard(
        vostok::input::receiver::keyboard *this@<esi>,
        IDirectInput8A *direct_input@<eax>,
        vostok::input::world *input_world@<ecx>,
        HWND__ *window_handle)
{
  IDirectInputDevice8A **p_m_device; // edi
  IDirectInputDevice8A *m_device; // edi
  DIPROPDWORD dipdw; // [esp+24h] [ebp-14h] BYREF

  p_m_device = &this->m_device;
  this->__vftable = (vostok::input::receiver::keyboard_vtbl *)&vostok::input::receiver::keyboard::`vftable';
  this->m_current_events_count = 0;
  this->m_window_handle = window_handle;
  this->m_device = 0;
  this->m_world = input_world;
  direct_input->CreateDevice(direct_input, &GUID_SysKeyboard, &this->m_device, 0);
  (*p_m_device)->SetDataFormat(*p_m_device, &c_dfDIKeyboard);
  (*p_m_device)->SetCooperativeLevel(*p_m_device, window_handle, 6u);
  m_device = this->m_device;
  dipdw.diph.dwSize = 20;
  dipdw.diph.dwHeaderSize = 16;
  dipdw.diph.dwObj = 0;
  dipdw.diph.dwHow = 0;
  dipdw.dwData = 256;
  m_device->SetProperty(m_device, (const _GUID *)1, &dipdw.diph);
  memset((int)this->m_current_key_state, 0, sizeof(this->m_current_key_state));
}
