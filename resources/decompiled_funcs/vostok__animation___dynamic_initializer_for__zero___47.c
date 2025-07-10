int vostok::animation::_dynamic_initializer_for__zero___47()
{
  int result; // eax
  __int64 v1; // [esp+0h] [ebp-Ch]

  result = 0;
  *(_QWORD *)&zero_47.channels[3] = 0;
  LODWORD(v1) = clear_value;
  HIDWORD(v1) = clear_value;
  *(_QWORD *)&zero_47.translation.x = 0;
  zero_47.translation.z = 0.0;
  zero_47.rotation.z = 0.0;
  *(_QWORD *)&zero_47.channels[6] = v1;
  LODWORD(zero_47.scale.z) = clear_value;
  return result;
}
