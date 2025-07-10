int vostok::animation::_dynamic_initializer_for__zero___38()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero_38.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero_38.translation.x = 0;
  zero_38.translation.z = 0.0;
  zero_38.rotation.z = 0.0;
  *(_QWORD *)&zero_38.channels[6] = v1;
  LODWORD(zero_38.scale.z) = clear_value;
  return result;
}
