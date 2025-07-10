int __cdecl tls1_alert_code(int code)
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
      result = 20;
      break;
    case 21:
      result = 21;
      break;
    case 22:
      result = 22;
      break;
    case 30:
      result = 30;
      break;
    case 40:
      result = 40;
      break;
    case 42:
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
    case 48:
      result = 48;
      break;
    case 49:
      result = 49;
      break;
    case 50:
      result = 50;
      break;
    case 51:
      result = 51;
      break;
    case 60:
      result = 60;
      break;
    case 70:
      result = 70;
      break;
    case 71:
      result = 71;
      break;
    case 80:
      result = 80;
      break;
    case 90:
      result = 90;
      break;
    case 100:
      result = 100;
      break;
    case 110:
      result = 110;
      break;
    case 111:
      result = 111;
      break;
    case 112:
      result = 112;
      break;
    case 113:
      result = 113;
      break;
    case 114:
      result = 114;
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
