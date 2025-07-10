struct SpeedTree::Vec3 *__cdecl SpeedTree::CCoordSys::ConvertFromStd(
        struct SpeedTree::Vec3 *__return_ptr retstr,
        float a2,
        float a3,
        float a4)
{
  ((void (__thiscall *)(const struct SpeedTree::CCoordSysBase *const, struct SpeedTree::Vec3 *, _DWORD, _DWORD, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->ConvertFromStd)(
    SpeedTree::CCoordSys::m_pCoordSys,
    retstr,
    LODWORD(a2),
    LODWORD(a3),
    LODWORD(a4));
  return retstr;
}
