void __usercall vostok::input::receiver::gamepad::execute(vostok::input::receiver::gamepad *this@<ecx>, int a2@<esi>)
{
  bool v2; // al
  int bRightTrigger; // eax
  __int16 sThumbLY; // dx
  float v5; // xmm1_4
  __int16 sThumbLX; // cx
  vostok::math::float2 *v7; // eax
  __int16 sThumbRX; // cx
  __int16 sThumbRY; // dx
  vostok::math::float2 v10; // [esp+Ch] [ebp-20h] BYREF
  _XINPUT_STATE input_state; // [esp+14h] [ebp-18h] BYREF

  if ( *(_BYTE *)(a2 + 92) )
  {
    v2 = XInputGetState(*(_DWORD *)(a2 + 88), &input_state) == 0;
    *(_BYTE *)(a2 + 92) = v2;
    *(_BYTE *)(a2 + 94) = !v2;
    *(_BYTE *)(a2 + 93) = 0;
    if ( v2 )
    {
      memcpy((unsigned __int8 *)(a2 + 60), (unsigned __int8 *)(a2 + 32), 0x1Cu);
      bRightTrigger = input_state.Gamepad.bRightTrigger;
      sThumbLY = input_state.Gamepad.sThumbLY;
      v5 = (float)input_state.Gamepad.bLeftTrigger * 0.0039215689;
      *(_DWORD *)(a2 + 56) = input_state.Gamepad.wButtons;
      sThumbLX = input_state.Gamepad.sThumbLX;
      *(float *)(a2 + 48) = v5;
      *(float *)(a2 + 52) = (float)bRightTrigger * 0.0039215689;
      v7 = convert_stick_values(sThumbLY, &v10, sThumbLX, 0x1EA9u);
      sThumbRX = input_state.Gamepad.sThumbRX;
      *(float *)(a2 + 32) = v7->x;
      sThumbRY = input_state.Gamepad.sThumbRY;
      *(float *)(a2 + 36) = v7->y;
      *(vostok::math::float2 *)(a2 + 40) = *convert_stick_values(sThumbRY, &v10, sThumbRX, 0x21F1u);
    }
  }
}
