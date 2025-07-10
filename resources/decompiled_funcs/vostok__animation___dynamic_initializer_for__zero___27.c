int vostok::animation::_dynamic_initializer_for__zero___27()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero_27.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero_27.translation.x = 0;
  zero_27.translation.z = 0.0;
  zero_27.rotation.z = 0.0;
  *(_QWORD *)&zero_27.channels[6] = v1;
  LODWORD(zero_27.scale.z) = clear_value;
  return result;
}
