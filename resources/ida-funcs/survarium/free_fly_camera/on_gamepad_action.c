char __thiscall survarium::free_fly_camera::on_gamepad_action(
        survarium::free_fly_camera *this,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  vostok::input::gamepad *v4; // edi
  vostok::input::gamepad *v5; // ebx
  void (__thiscall **p_set_vibration)(_DWORD, _DWORD, _DWORD); // esi
  vostok::input::gamepad *v8; // edi
  vostok::input::gamepad *v9; // ebx
  void (__thiscall **v10)(vostok::input::gamepad *, int, _DWORD); // esi
  float v11; // [esp+Ch] [ebp-8h]
  float v12; // [esp+Ch] [ebp-8h]

  if ( button == gamepad_x )
  {
    v4 = input_world->get_gamepad(input_world);
    v5 = input_world->get_gamepad(input_world);
    p_set_vibration = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&v5->set_vibration;
    v11 = ((double (__thiscall *)(vostok::input::gamepad *, _DWORD))v4->get_vibration)(v4, 0) + 0.0099999998;
    (*p_set_vibration)(v5, 0, LODWORD(v11));
    return 1;
  }
  if ( button == gamepad_b )
  {
    v8 = input_world->get_gamepad(input_world);
    v9 = input_world->get_gamepad(input_world);
    v10 = (void (__thiscall **)(vostok::input::gamepad *, int, _DWORD))&v9->set_vibration;
    v12 = ((double (__thiscall *)(vostok::input::gamepad *, int))v8->get_vibration)(v8, 1) + 0.0099999998;
    (*v10)(v9, 1, LODWORD(v12));
    return 1;
  }
  return 0;
}
