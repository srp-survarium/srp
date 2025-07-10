stlp_std::money_base::pattern __thiscall stlp_std::moneypunct<wchar_t,1>::do_neg_format(
        stlp_std::moneypunct<wchar_t,0> *this,
        stlp_std::money_base::pattern *a2)
{
  stlp_std::money_base::pattern result; // eax

  result = (stlp_std::money_base::pattern)a2;
  *a2 = this->_M_neg_format;
  return result;
}
