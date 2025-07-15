BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax

  result = 1;
  if ( drive )
  {
    LOBYTE(drive) = drive + 64;
    strcpy((char *)&drive + 1, ":\\");
    if ( GetDriveTypeA((LPCSTR)&drive) <= 1 )
      return 0;
  }
  return result;
}
