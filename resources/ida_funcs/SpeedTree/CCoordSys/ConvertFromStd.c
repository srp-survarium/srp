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


struct SpeedTree::Vec3 *__cdecl SpeedTree::CCoordSys::ConvertFromStd(
        struct SpeedTree::Vec3 *__return_ptr retstr,
        const float *a2)
{
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->ConvertFromStd)(
    (SpeedTree::CCoordSysBase *)SpeedTree::CCoordSys::m_pCoordSys,
    retstr,
    *a2,
    a2[1],
    a2[2]);
  return retstr;
}
