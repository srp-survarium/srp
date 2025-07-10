int __cdecl ssl3_alert_code(int code)
{
  int result; // eax

  switch ( code )
  {
    case 0:
      result = 0;
      break;
    case 10:
      result = 10;
      break;
    case 20:
    case 21:
    case 22:
      result = 20;
      break;
    case 30:
      result = 30;
      break;
    case 40:
    case 49:
    case 50:
    case 51:
    case 60:
    case 70:
    case 71:
    case 80:
    case 90:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
      result = 40;
      break;
    case 41:
      result = 41;
      break;
    case 42:
    case 48:
      result = 42;
      break;
    case 43:
      result = 43;
      break;
    case 44:
      result = 44;
      break;
    case 45:
      result = 45;
      break;
    case 46:
      result = 46;
      break;
    case 47:
      result = 47;
      break;
    case 115:
      result = 115;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}
