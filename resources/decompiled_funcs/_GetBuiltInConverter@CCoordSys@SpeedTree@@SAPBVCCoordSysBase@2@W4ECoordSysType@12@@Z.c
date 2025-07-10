const struct SpeedTree::CCoordSysBase *__cdecl SpeedTree::CCoordSys::GetBuiltInConverter(
        enum SpeedTree::CCoordSys::ECoordSysType a1)
{
  const struct SpeedTree::CCoordSysBase *result; // eax

  switch ( a1 )
  {
    case COORD_SYS_RIGHT_HANDED_Z_UP:
      result = (const struct SpeedTree::CCoordSysBase *)&dword_AA1568;
      break;
    case COORD_SYS_RIGHT_HANDED_Y_UP:
      result = (const struct SpeedTree::CCoordSysBase *)&dword_AA15AC;
      break;
    case COORD_SYS_LEFT_HANDED_Z_UP:
      result = (const struct SpeedTree::CCoordSysBase *)&dword_AA1590;
      break;
    case COORD_SYS_LEFT_HANDED_Y_UP:
      result = (const struct SpeedTree::CCoordSysBase *)&dword_AA15B0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
