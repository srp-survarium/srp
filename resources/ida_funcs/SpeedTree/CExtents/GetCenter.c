struct SpeedTree::Vec3 *__thiscall SpeedTree::CExtents::GetCenter(
        SpeedTree::CExtents *this,
        struct SpeedTree::Vec3 *__return_ptr retstr)
{
  _BYTE v3[12]; // [esp+20h] [ebp-Ch] BYREF

  SpeedTree::Vec3::operator+(v3, &this->m_cMax);
  SpeedTree::Vec3::operator*((int)retstr, 0.5);
  return retstr;
}
