int __cdecl stlp_std::priv::__write_float(
        stlp_std::priv::__basic_iostring<char> *buf,
        __int16 flags,
        int precision,
        _CRT_DOUBLE x)
{
  return stlp_std::priv::__write_floatT_double_(buf, flags, precision, x);
}


int __cdecl stlp_std::priv::__write_float(
        stlp_std::priv::__basic_iostring<char> *buf,
        __int16 flags,
        int precision,
        _CRT_DOUBLE x)
{
  return stlp_std::priv::__write_floatT_long_double_(buf, flags, precision, x);
}
