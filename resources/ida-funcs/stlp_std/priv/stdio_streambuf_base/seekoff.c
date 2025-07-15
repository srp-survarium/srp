stlp_std::fpos<int> *__userpurge stlp_std::priv::stdio_streambuf_base::seekoff@<eax>(
        stlp_std::priv::stdio_streambuf_base *this@<ecx>,
        int a2@<ebx>,
        stlp_std::fpos<int> *result,
        __int64 off,
        int dir,
        int __formal)
{
  int v7; // eax
  stlp_std::fpos<int> *v8; // eax
  int v9; // edx

  switch ( dir )
  {
    case 1:
      v7 = 0;
      break;
    case 2:
      v7 = 1;
      break;
    case 4:
      v7 = 2;
      break;
    default:
      goto LABEL_9;
  }
  if ( !_fseeki64(this->_M_file, off, v7) )
  {
    fgetpos(a2, (int)this, this->_M_file, &off);
    v8 = result;
    v9 = HIDWORD(off);
    LODWORD(result->_M_pos) = off;
    HIDWORD(result->_M_pos) = v9;
    result->_M_st = 0;
    return v8;
  }
LABEL_9:
  v8 = result;
  result->_M_pos = -1;
  result->_M_st = 0;
  return v8;
}
