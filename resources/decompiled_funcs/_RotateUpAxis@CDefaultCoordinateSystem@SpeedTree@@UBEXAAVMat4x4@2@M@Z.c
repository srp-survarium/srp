void __thiscall SpeedTree::CDefaultCoordinateSystem::RotateUpAxis(
        SpeedTree::CDefaultCoordinateSystem *this,
        SpeedTree::Mat4x4 *a2,
        float a3)
{
  SpeedTree::Mat4x4::RotateZ(a2, a3);
}
