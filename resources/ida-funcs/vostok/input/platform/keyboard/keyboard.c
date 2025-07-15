void __userpurge vostok::input::platform::keyboard::keyboard(
        vostok::input::platform::keyboard *this@<esi>,
        IDirectInput8A *direct_input@<eax>,
        HWND__ *window_handle,
        vostok::input::world *input_world)
{
  IDirectInputDevice8A **p_m_device; // edi
  IDirectInputDevice8A *m_device; // edi
  _DWORD v6[5]; // [esp+8h] [ebp-14h] BYREF

  this->m_dead_key = 0;
  p_m_device = &this->m_device;
  this->m_window_handle = window_handle;
  this->__vftable = (vostok::input::platform::keyboard_vtbl *)&vostok::input::platform::keyboard::`vftable';
  this->m_current_events_count = 0;
  this->m_modifiers = 0;
  this->m_device = 0;
  this->m_world = input_world;
  direct_input->CreateDevice(direct_input, &GUID_SysKeyboard, &this->m_device, 0);
  (*p_m_device)->SetDataFormat(*p_m_device, &c_dfDIKeyboard);
  (*p_m_device)->SetCooperativeLevel(*p_m_device, window_handle, 6u);
  m_device = this->m_device;
  v6[0] = 20;
  v6[1] = 16;
  v6[2] = 0;
  v6[3] = 0;
  v6[4] = 256;
  m_device->SetProperty(m_device, (const _GUID *)1, (const DIPROPHEADER *)v6);
  memset((int)this->m_current_key_state, 0, sizeof(this->m_current_key_state));
}
