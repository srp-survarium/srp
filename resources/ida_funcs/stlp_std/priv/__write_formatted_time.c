// attributes: thunk
void __cdecl stlp_std::priv::__write_formatted_time(
        stlp_std::priv::__basic_iostring<char> *buf,
        const stlp_std::ctype<char> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_Time_Info *table,
        const tm *t)
{
  stlp_std::priv::__write_formatted_timeT<char,stlp_std::priv::_Time_Info>(buf, ct, format, modifier, table, t);
}


// attributes: thunk
void __cdecl stlp_std::priv::__write_formatted_time(
        stlp_std::priv::__basic_iostring<wchar_t> *buf,
        stlp_std::ctype<wchar_t> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_WTime_Info *table,
        const tm *t)
{
  stlp_std::priv::__write_formatted_timeT<wchar_t,stlp_std::priv::_WTime_Info>(buf, ct, format, modifier, table, t);
}
