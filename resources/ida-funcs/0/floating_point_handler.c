void __cdecl floating_point_handler(int signal, int error_code)
{
  survarium::game_camera *v2; // ecx
  const char *description; // [esp+4h] [ebp-104h]
  char error[256]; // [esp+8h] [ebp-100h] BYREF

  description = (const char *)&buf;
  switch ( error_code )
  {
    case 129:
      sprintf_s<256>(
        (char (*)[256])error,
        "floating point error ( %s ) ",
        "invalid instruction (SNaN, probably, uninitialized variable)");
      break;
    case 130:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "denormal occured");
      break;
    case 131:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "division by zero");
      break;
    case 132:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "overflow");
      break;
    case 133:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "underflow");
      break;
    case 134:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "inexact result");
      break;
    case 135:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "_FPE_UNEMULATED");
      break;
    case 136:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "negative value passed to sqrt");
      break;
    case 138:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "stack overflow");
      break;
    case 139:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", "stack underflow");
      break;
    case 140:
      description = "someone raised signal SIGFPE";
      goto LABEL_13;
    default:
LABEL_13:
      sprintf_s<256>((char (*)[256])error, "floating point error ( %s ) ", description);
      break;
  }
  handler_base(v2);
}
