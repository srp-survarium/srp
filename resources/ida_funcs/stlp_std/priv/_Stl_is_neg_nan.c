BOOL __cdecl stlp_std::priv::_Stl_is_neg_nan(long double x)
{
  return _isnan(x) && _copysign(1.0, x) < 0.0;
}
