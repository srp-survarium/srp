stlp_std::fpos<int> *__thiscall stlp_std::priv::stdio_streambuf_base::seekpos(
        stlp_std::priv::stdio_streambuf_base *this,
        stlp_std::fpos<int> *result,
        stlp_std::fpos<int> pos,
        int __formal)
{
  _iobuf *M_file; // ecx
  stlp_std::fpos<int> *p_p; // ecx
  stlp_std::fpos<int> *v6; // eax
  int M_st; // edx
  int v8; // ecx
  __int64 p; // [esp+0h] [ebp-10h] BYREF
  int v10; // [esp+8h] [ebp-8h]

  M_file = this->_M_file;
  p = pos._M_pos;
  if ( fsetpos(M_file, &p) )
  {
    p = -1;
    v10 = 0;
    p_p = (stlp_std::fpos<int> *)&p;
  }
  else
  {
    p_p = &pos;
  }
  v6 = result;
  result->_M_pos = p_p->_M_pos;
  M_st = p_p->_M_st;
  v8 = *(&p_p->_M_st + 1);
  result->_M_st = M_st;
  *(&result->_M_st + 1) = v8;
  return v6;
}
