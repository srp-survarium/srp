stlp_std::locale *__thiscall stlp_std::ios_base::imbue(
        stlp_std::ios_base *this,
        stlp_std::locale *result,
        stlp_std::locale *loc)
{
  const stlp_std::locale *v4; // ebx
  stlp_std::locale *p_M_locale; // esi
  stlp_std::locale *v6; // esi
  const stlp_std::locale *v8; // [esp-4h] [ebp-24h]

  v4 = loc;
  p_M_locale = &this->_M_locale;
  if ( stlp_std::locale::operator!=(loc, &this->_M_locale) )
  {
    stlp_std::locale::locale((stlp_std::locale *)&loc, p_M_locale);
    stlp_std::locale::operator=(p_M_locale, v4);
    stlp_std::ios_base::_M_invoke_callbacks(this, imbue_event);
    v6 = result;
    stlp_std::locale::locale(result, (const stlp_std::locale *)&loc);
    stlp_std::locale::~locale((stlp_std::locale *)&loc);
  }
  else
  {
    stlp_std::ios_base::_M_invoke_callbacks(this, imbue_event);
    v8 = p_M_locale;
    v6 = result;
    stlp_std::locale::locale(result, v8);
  }
  return v6;
}
