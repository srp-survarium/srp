void __thiscall SpeedTree::CDefaultCoordinateSystem::RotateUpAxis(
        SpeedTree::CDefaultCoordinateSystem *this,
        SpeedTree::Mat3x3 *a2,
        float a3)
{
  SpeedTree::Mat3x3::RotateZ(a2, a3);
}
