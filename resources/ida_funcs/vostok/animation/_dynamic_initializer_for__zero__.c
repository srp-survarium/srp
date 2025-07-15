int vostok::animation::_dynamic_initializer_for__zero__()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero.translation.x = 0;
  zero.translation.z = 0.0;
  zero.rotation.z = 0.0;
  *(_QWORD *)&zero.channels[6] = v1;
  LODWORD(zero.scale.z) = clear_value;
  return result;
}
