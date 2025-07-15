struct SpeedTree::Vec3 *__thiscall SpeedTree::CDefaultCoordinateSystem::ConvertFromStd(
        SpeedTree::CDefaultCoordinateSystem *this,
        struct SpeedTree::Vec3 *__return_ptr retstr,
        float a3,
        float a4,
        float a5)
{
  ((void (__thiscall *)(SpeedTree::CDefaultCoordinateSystem *, struct SpeedTree::Vec3 *, _DWORD, _DWORD, _DWORD))this->ConvertToStd)(
    this,
    retstr,
    LODWORD(a3),
    LODWORD(a4),
    LODWORD(a5));
  return retstr;
}
