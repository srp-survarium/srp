void __cdecl SpeedTree::CCoordSys::RotateUpAxis(struct SpeedTree::Mat3x3 *a1, float a2)
{
  ((void (__thiscall *)(const struct SpeedTree::CCoordSysBase *const, struct SpeedTree::Mat3x3 *, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->RotateUpAxis)(
    SpeedTree::CCoordSys::m_pCoordSys,
    a1,
    LODWORD(a2));
}


void __cdecl SpeedTree::CCoordSys::RotateUpAxis(struct SpeedTree::Mat4x4 *a1, float a2)
{
  ((void (__thiscall *)(const struct SpeedTree::CCoordSysBase *const, struct SpeedTree::Mat4x4 *, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->RotateUpAxis)(
    SpeedTree::CCoordSys::m_pCoordSys,
    a1,
    LODWORD(a2));
}
