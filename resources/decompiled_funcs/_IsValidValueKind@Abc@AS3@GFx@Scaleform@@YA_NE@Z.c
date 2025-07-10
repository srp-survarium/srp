bool __cdecl Scaleform::GFx::AS3::Abc::IsValidValueKind(unsigned __int8 vk)
{
  bool result; // al

  switch ( vk )
  {
    case 0u:
    case 1u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 8u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0x16u:
    case 0x17u:
    case 0x18u:
    case 0x19u:
    case 0x1Au:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
