int vostok::animation::_dynamic_initializer_for__zero___45()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero_45.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero_45.translation.x = 0;
  zero_45.translation.z = 0.0;
  zero_45.rotation.z = 0.0;
  *(_QWORD *)&zero_45.channels[6] = v1;
  LODWORD(zero_45.scale.z) = clear_value;
  return result;
}
