void __cdecl floating_point_handler(int signal, int error_code)
{
  const char *v2; // ecx
  char reason_string[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = uri;
  switch ( error_code )
  {
    case 129:
      v2 = "invalid instruction (SNaN, probably, uninitialized variable)";
      break;
    case 130:
      v2 = "denormal occured";
      break;
    case 131:
      v2 = "division by zero";
      break;
    case 132:
      v2 = "overflow";
      break;
    case 133:
      v2 = "underflow";
      break;
    case 134:
      v2 = "inexact result";
      break;
    case 135:
      v2 = "_FPE_UNEMULATED";
      break;
    case 136:
      v2 = "negative value passed to sqrt";
      break;
    case 138:
      v2 = "stack overflow";
      break;
    case 139:
      v2 = "stack underflow";
      break;
    case 140:
      v2 = "someone raised signal SIGFPE";
      break;
    default:
      break;
  }
  sprintf_s<256>((char (*)[256])reason_string, "floating point error ( %s ) ", v2);
  handler_base(reason_string);
}
