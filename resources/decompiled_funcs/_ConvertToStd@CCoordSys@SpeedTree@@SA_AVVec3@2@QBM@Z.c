struct SpeedTree::Vec3 *__cdecl SpeedTree::CCoordSys::ConvertToStd(
        struct SpeedTree::Vec3 *__return_ptr retstr,
        const float *a2)
{
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->ConvertToStd)(
    (SpeedTree::CCoordSysBase *)SpeedTree::CCoordSys::m_pCoordSys,
    retstr,
    *a2,
    a2[1],
    a2[2]);
  return retstr;
}
