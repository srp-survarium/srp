struct SpeedTree::Vec3 *__thiscall SpeedTree::CLHCS_Zup::ConvertToStd(
        SpeedTree::CLHCS_Zup *this,
        struct SpeedTree::Vec3 *__return_ptr retstr,
        float a3,
        float a4,
        float a5)
{
  retstr->x = a3;
  retstr->y = -a4;
  retstr->z = a5;
  return retstr;
}
