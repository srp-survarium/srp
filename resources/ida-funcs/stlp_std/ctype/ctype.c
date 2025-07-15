void __thiscall stlp_std::ctype<char>::ctype<char>(
        stlp_std::ctype<char> *this,
        const stlp_std::ctype_base::mask *__tab,
        bool __del,
        unsigned int __refs)
{
  const stlp_std::ctype_base::mask *v4; // edx

  this->_M_ref_count = __refs != 0;
  this->__vftable = (stlp_std::ctype<char>_vtbl *)&stlp_std::ctype<char>::`vftable';
  v4 = __tab;
  if ( !__tab )
    v4 = (const stlp_std::ctype_base::mask *)&dword_8167B0;
  this->_M_ctype_table = v4;
  this->_M_delete = __tab && __del;
}
