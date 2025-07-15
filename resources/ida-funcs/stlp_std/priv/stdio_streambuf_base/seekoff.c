stlp_std::fpos<int> *__thiscall stlp_std::priv::stdio_streambuf_base::seekoff(
        stlp_std::priv::stdio_streambuf_base *this,
        stlp_std::fpos<int> *result,
        __int64 off,
        int dir,
        int __formal)
{
  int v6; // eax
  stlp_std::fpos<int> *v7; // eax
  int v8; // edx

  switch ( dir )
  {
    case 1:
      v6 = 0;
      break;
    case 2:
      v6 = 1;
      break;
    case 4:
      v6 = 2;
      break;
    default:
      goto LABEL_9;
  }
  if ( !_fseeki64(this->_M_file, off, v6) )
  {
    fgetpos(this->_M_file, &off);
    v7 = result;
    v8 = HIDWORD(off);
    LODWORD(result->_M_pos) = off;
    HIDWORD(result->_M_pos) = v8;
    result->_M_st = 0;
    return v7;
  }
LABEL_9:
  v7 = result;
  result->_M_pos = -1;
  result->_M_st = 0;
  return v7;
}
