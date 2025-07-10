struct SpeedTree::Vec3 *__thiscall SpeedTree::CRHCS_Yup::ConvertToStd(
        SpeedTree::CRHCS_Yup *this,
        struct SpeedTree::Vec3 *__return_ptr retstr,
        float a3,
        float a4,
        float a5)
{
  retstr->x = a3;
  retstr->y = -a5;
  retstr->z = a4;
  return retstr;
}
