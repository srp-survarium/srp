stlp_std::fpos<int> *__userpurge stlp_std::priv::stdio_streambuf_base::seekpos@<eax>(
        stlp_std::priv::stdio_streambuf_base *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        stlp_std::fpos<int> *result,
        stlp_std::fpos<int> pos,
        int __formal)
{
  _iobuf *M_file; // ecx
  stlp_std::fpos<int> *p_posa; // ecx
  stlp_std::fpos<int> *v8; // eax
  int M_st; // edx
  int v10; // ecx
  __int64 posa; // [esp+0h] [ebp-10h] BYREF
  int v12; // [esp+8h] [ebp-8h]

  M_file = this->_M_file;
  posa = pos._M_pos;
  if ( fsetpos(a2, a3, M_file, &posa) )
  {
    posa = -1;
    v12 = 0;
    p_posa = (stlp_std::fpos<int> *)&posa;
  }
  else
  {
    p_posa = &pos;
  }
  v8 = result;
  result->_M_pos = p_posa->_M_pos;
  M_st = p_posa->_M_st;
  v10 = *(&p_posa->_M_st + 1);
  result->_M_st = M_st;
  *(&result->_M_st + 1) = v10;
  return v8;
}
