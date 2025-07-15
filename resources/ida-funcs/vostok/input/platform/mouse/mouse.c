void __userpurge vostok::input::platform::mouse::mouse(
        vostok::input::platform::mouse *this@<esi>,
        IDirectInput8A *direct_input@<eax>,
        vostok::input::world *input_world@<edx>,
        HWND__ *window_handle)
{
  IDirectInputDevice8A *m_device; // edi

  this->__vftable = (vostok::input::platform::mouse_vtbl *)&vostok::input::platform::mouse::`vftable';
  this->m_window_handle = window_handle;
  this->m_device = 0;
  this->m_world = input_world;
  this->m_busy = 0;
  direct_input->CreateDevice(direct_input, &GUID_SysMouse, &this->m_device, 0);
  this->m_device->SetDataFormat(this->m_device, &c_dfDIMouse2);
  m_device = this->m_device;
  this->m_exclusive_mode = 0;
  m_device->SetCooperativeLevel(m_device, window_handle, 6u);
  this->m_current_state.x = 0;
  this->m_current_state.y = 0;
  this->m_current_state.z = 0;
  *(_DWORD *)&this->m_current_state.buttons = 0;
  this->m_previous_state.x = 0;
  this->m_previous_state.y = 0;
  this->m_previous_state.z = 0;
  *(_DWORD *)&this->m_previous_state.buttons = 0;
}
