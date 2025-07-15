double __cdecl SpeedTree::CCoordSys::OutComponent(const float *a1)
{
  double result; // st7

  result = *a1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->OutComponent)(
    (SpeedTree::CCoordSysBase *)SpeedTree::CCoordSys::m_pCoordSys,
    *a1,
    a1[1],
    a1[2]);
  return result;
}
