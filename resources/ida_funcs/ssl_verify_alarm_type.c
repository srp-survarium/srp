int __cdecl ssl_verify_alarm_type(int type)
{
  int result; // eax

  switch ( type )
  {
    case 2:
    case 3:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 24:
    case 25:
    case 33:
      result = 48;
      break;
    case 4:
    case 5:
    case 6:
    case 9:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 27:
    case 28:
      result = 42;
      break;
    case 7:
    case 8:
      result = 51;
      break;
    case 10:
    case 12:
      result = 45;
      break;
    case 17:
      result = 80;
      break;
    case 23:
      result = 44;
      break;
    case 26:
      result = 43;
      break;
    case 50:
      result = 40;
      break;
    default:
      result = 46;
      break;
  }
  return result;
}
