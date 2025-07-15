int __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_underflow_aux(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  int M_end_state; // eax
  unsigned __int8 *M_ext_buf_converted; // ecx
  char *M_ext_buf_end; // eax
  unsigned __int8 *M_ext_buf; // edx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  stlp_std::codecvt_base::result v11; // eax
  char *M_int_buf; // eax
  char *v13; // ecx
  char *v15; // eax
  char *v16; // ecx
  int v17; // [esp+1Ch] [ebp-Ch]
  char *v18; // [esp+20h] [ebp-8h] BYREF
  char *v19; // [esp+24h] [ebp-4h] BYREF

  M_end_state = this->_M_end_state;
  M_ext_buf_converted = (unsigned __int8 *)this->_M_ext_buf_converted;
  this->_M_state = M_end_state;
  M_ext_buf_end = this->_M_ext_buf_end;
  if ( M_ext_buf_end <= (char *)M_ext_buf_converted )
  {
    this->_M_ext_buf_end = this->_M_ext_buf;
  }
  else
  {
    M_ext_buf = (unsigned __int8 *)this->_M_ext_buf;
    v6 = M_ext_buf_end - (char *)M_ext_buf_converted;
    v7 = v6;
    if ( v6 )
    {
      memmove(M_ext_buf, M_ext_buf_converted, v6);
      this->_M_ext_buf_end = (char *)(v7 + v8);
    }
    else
    {
      this->_M_ext_buf_end = (char *)M_ext_buf;
    }
  }
  v9 = stlp_std::_Filebuf_base::_M_read(
         &this->_M_base,
         this->_M_ext_buf_end,
         this->_M_ext_buf_EOS - this->_M_ext_buf_end);
  v17 = v9;
  if ( v9 >= 0 )
  {
    while ( 1 )
    {
      this->_M_ext_buf_end += v9;
      v10 = this->_M_ext_buf_end;
      if ( this->_M_ext_buf == v10 )
        break;
      v11 = this->_M_codecvt->do_in(
              (stlp_std::codecvt<char,char,int> *)this->_M_codecvt,
              &this->_M_end_state,
              this->_M_ext_buf,
              v10,
              (const char **)&v19,
              this->_M_int_buf,
              this->_M_int_buf_EOS,
              &v18);
      if ( v11 == warning )
      {
        v15 = this->_M_ext_buf;
        v16 = this->_M_ext_buf_end;
        this->_M_ext_buf_converted = v16;
        this->_M_gbegin = v15;
        this->_M_gnext = v15;
        this->_M_gend = v16;
        return (unsigned __int8)*v15;
      }
      if ( v11 == error )
        return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_input_error(this);
      M_int_buf = this->_M_int_buf;
      v13 = v18;
      if ( v18 != M_int_buf && v19 == this->_M_ext_buf )
        return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_input_error(this);
      if ( this->_M_constant_width && this->_M_width * (v18 - M_int_buf) != v19 - this->_M_ext_buf )
        return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_input_error(this);
      if ( v18 != M_int_buf )
        goto LABEL_21;
      if ( v19 - this->_M_ext_buf >= this->_M_max_width )
        return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_input_error(this);
      if ( v18 != M_int_buf )
      {
LABEL_21:
        this->_M_ext_buf_converted = v19;
        this->_M_gbegin = M_int_buf;
        this->_M_gnext = M_int_buf;
        this->_M_gend = v13;
        return (unsigned __int8)*M_int_buf;
      }
      if ( v17 > 0 )
      {
        v9 = stlp_std::_Filebuf_base::_M_read(
               &this->_M_base,
               this->_M_ext_buf_end,
               this->_M_ext_buf_EOS - this->_M_ext_buf_end);
        v17 = v9;
        if ( v9 >= 0 )
          continue;
      }
      break;
    }
  }
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  return -1;
}


wchar_t __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_underflow_aux(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  int M_end_state; // eax
  unsigned __int8 *M_ext_buf_converted; // ecx
  char *M_ext_buf_end; // eax
  unsigned __int8 *M_ext_buf; // edx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  stlp_std::codecvt_base::result v11; // eax
  wchar_t *M_int_buf; // eax
  wchar_t *v13; // ecx
  int v15; // [esp+1Ch] [ebp-Ch]
  wchar_t *v16; // [esp+20h] [ebp-8h] BYREF
  char *v17; // [esp+24h] [ebp-4h] BYREF

  M_end_state = this->_M_end_state;
  M_ext_buf_converted = (unsigned __int8 *)this->_M_ext_buf_converted;
  this->_M_state = M_end_state;
  M_ext_buf_end = this->_M_ext_buf_end;
  if ( M_ext_buf_end <= (char *)M_ext_buf_converted )
  {
    this->_M_ext_buf_end = this->_M_ext_buf;
  }
  else
  {
    M_ext_buf = (unsigned __int8 *)this->_M_ext_buf;
    v6 = M_ext_buf_end - (char *)M_ext_buf_converted;
    v7 = v6;
    if ( v6 )
    {
      memmove(M_ext_buf, M_ext_buf_converted, v6);
      this->_M_ext_buf_end = (char *)(v7 + v8);
    }
    else
    {
      this->_M_ext_buf_end = (char *)M_ext_buf;
    }
  }
  v9 = stlp_std::_Filebuf_base::_M_read(
         &this->_M_base,
         this->_M_ext_buf_end,
         this->_M_ext_buf_EOS - this->_M_ext_buf_end);
  v15 = v9;
  if ( v9 >= 0 )
  {
    while ( 1 )
    {
      this->_M_ext_buf_end += v9;
      v10 = this->_M_ext_buf_end;
      if ( this->_M_ext_buf == v10 )
        break;
      v11 = this->_M_codecvt->do_in(
              (stlp_std::codecvt<wchar_t,char,int> *)this->_M_codecvt,
              &this->_M_end_state,
              this->_M_ext_buf,
              v10,
              (const char **)&v17,
              this->_M_int_buf,
              this->_M_int_buf_EOS,
              &v16);
      if ( v11 == warning )
        return -1;
      if ( v11 == error )
        return stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_input_error(this);
      M_int_buf = this->_M_int_buf;
      v13 = v16;
      if ( v16 != M_int_buf && v17 == this->_M_ext_buf )
        return stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_input_error(this);
      if ( this->_M_constant_width && this->_M_width * (v16 - M_int_buf) != v17 - this->_M_ext_buf )
        return stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_input_error(this);
      if ( v16 != M_int_buf )
        goto LABEL_21;
      if ( v17 - this->_M_ext_buf >= this->_M_max_width )
        return stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_input_error(this);
      if ( v16 != M_int_buf )
      {
LABEL_21:
        this->_M_ext_buf_converted = v17;
        this->_M_gbegin = M_int_buf;
        this->_M_gnext = M_int_buf;
        this->_M_gend = v13;
        return *M_int_buf;
      }
      if ( v15 > 0 )
      {
        v9 = stlp_std::_Filebuf_base::_M_read(
               &this->_M_base,
               this->_M_ext_buf_end,
               this->_M_ext_buf_EOS - this->_M_ext_buf_end);
        v15 = v9;
        if ( v9 >= 0 )
          continue;
      }
      break;
    }
  }
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  return -1;
}
