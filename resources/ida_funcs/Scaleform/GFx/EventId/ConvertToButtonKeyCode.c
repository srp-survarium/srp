int __thiscall Scaleform::GFx::EventId::ConvertToButtonKeyCode(Scaleform::GFx::EventId *this)
{
  int result; // eax
  unsigned __int8 AsciiCode; // cl

  result = 0;
  switch ( this->KeyCode )
  {
    case 8u:
      result = 8;
      break;
    case 9u:
      result = 18;
      break;
    case 0xDu:
      result = 13;
      break;
    case 0x1Bu:
      result = 19;
      break;
    case 0x21u:
      result = 16;
      break;
    case 0x22u:
      result = 17;
      break;
    case 0x23u:
      result = 4;
      break;
    case 0x24u:
      result = 3;
      break;
    case 0x25u:
      result = 1;
      break;
    case 0x26u:
      result = 14;
      break;
    case 0x27u:
      result = 2;
      break;
    case 0x28u:
      result = 15;
      break;
    case 0x2Du:
      result = 5;
      break;
    case 0x2Eu:
      result = 6;
      break;
    default:
      AsciiCode = this->AsciiCode;
      if ( AsciiCode >= 0x20u )
        result = AsciiCode;
      break;
  }
  return result;
}
