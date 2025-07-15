long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double v3; // [esp+0h] [ebp-8h]

  v3 = x;
  HIWORD(v3) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return v3;
}
