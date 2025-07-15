btMatrix3x3 *__thiscall btMatrix3x3::btMatrix3x3(
        btMatrix3x3 *this,
        btMatrix3x3 *xx,
        float *xy,
        float *xz,
        float *yx,
        float *yy,
        float *yz,
        float *zx,
        float *zy,
        const float *zz)
{
  const float *savedregs; // [esp+0h] [ebp+0h]

  btMatrix3x3::setValue(this, (int)xx, xy, xz, yx, yy, yz, zx, zy, zz, savedregs);
  return xx;
}
