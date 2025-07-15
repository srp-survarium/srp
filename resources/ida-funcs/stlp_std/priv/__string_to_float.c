void __usercall stlp_std::priv::__string_to_float(
        double a1@<st0>,
        const stlp_std::priv::__basic_iostring<char> *v,
        float *val)
{
  stlp_std::priv::_Stl_string_to_double(v->_M_start_of_storage._M_data);
  *val = a1;
}


void __usercall stlp_std::priv::__string_to_float(
        long double a1@<st0>,
        const stlp_std::priv::__basic_iostring<char> *v,
        long double *val)
{
  stlp_std::priv::_Stl_string_to_double(v->_M_start_of_storage._M_data);
  *val = a1;
}
