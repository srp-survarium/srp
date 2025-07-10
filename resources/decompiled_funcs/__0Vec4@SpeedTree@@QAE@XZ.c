void __thiscall SpeedTree::Vec4::Vec4(SpeedTree::Vec4 *this)
{
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
  LODWORD(this->w) = clear_value;
}
