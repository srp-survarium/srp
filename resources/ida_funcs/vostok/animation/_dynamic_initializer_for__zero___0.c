int vostok::animation::_dynamic_initializer_for__zero___0()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero_0.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero_0.translation.x = 0;
  zero_0.translation.z = 0.0;
  zero_0.rotation.z = 0.0;
  *(_QWORD *)&zero_0.channels[6] = v1;
  LODWORD(zero_0.scale.z) = clear_value;
  return result;
}
