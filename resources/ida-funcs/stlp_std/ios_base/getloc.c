stlp_std::locale *__thiscall stlp_std::ios_base::getloc(stlp_std::ios_base *this, stlp_std::locale *result)
{
  stlp_std::locale::locale(result, &this->_M_locale);
  return result;
}
