void __cdecl SpeedTree::CCoordSys::RotateOutAxis(struct SpeedTree::Mat4x4 *a1, float a2)
{
  ((void (__thiscall *)(const struct SpeedTree::CCoordSysBase *const, struct SpeedTree::Mat4x4 *, _DWORD))SpeedTree::CCoordSys::m_pCoordSys->RotateOutAxis)(
    SpeedTree::CCoordSys::m_pCoordSys,
    a1,
    LODWORD(a2));
}
