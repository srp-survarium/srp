unsigned int __thiscall vostok::physics::calculate_bt_joint_size(vostok::configs::binary_config_value *config)
{
  unsigned int result; // eax

  switch ( (unsigned int)vostok::configs::binary_config_value::operator[](config, "type")->data.pointer )
  {
    case 0u:
      result = 160;
      break;
    case 1u:
    case 2u:
    case 3u:
      result = 176;
      break;
  }
  return result;
}
