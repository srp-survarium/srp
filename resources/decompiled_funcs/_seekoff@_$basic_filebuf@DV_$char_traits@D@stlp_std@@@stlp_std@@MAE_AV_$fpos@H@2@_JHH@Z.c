stlp_std::fpos<int> *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::seekoff(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::fpos<int> *result,
        __int64 __eadj,
        int __whence,
        int __formal)
{
  stlp_std::fpos<int> *v6; // eax
  int v7; // ebp
  bool v8; // al
  _BYTE *M_mmap_base; // ecx
  char *M_gnext; // eax
  __int64 v11; // kr00_8
  stlp_std::_Filebuf_base *p_M_base; // ecx
  stlp_std::fpos<int> *p_cur; // eax
  __int64 v14; // rax
  char *M_ext_buf_end; // ecx
  __int64 v16; // kr08_8
  __int64 offset; // rax
  stlp_std::_Filebuf_base *v18; // ecx
  stlp_std::fpos<int> *v19; // eax
  __int64 v20; // rax
  char *M_ext_buf_converted; // edi
  char *M_ext_buf; // ebx
  int v23; // edi
  __int64 v24; // rax
  __int64 v25; // kr10_8
  stlp_std::fpos<int> *v26; // eax
  __int64 v27; // rax
  unsigned int v28; // [esp-4h] [ebp-34h]
  __int64 __cur; // [esp+10h] [ebp-20h] BYREF
  int v30; // [esp+18h] [ebp-18h]
  stlp_std::fpos<int> v31; // [esp+20h] [ebp-10h] BYREF

  if ( !this->_M_base._M_is_open )
  {
    v6 = result;
    result->_M_pos = -1;
    result->_M_st = 0;
    return v6;
  }
  v7 = __whence;
  if ( this->_M_constant_width )
  {
    if ( __eadj )
      goto LABEL_9;
  }
  else if ( __eadj )
  {
LABEL_5:
    v6 = result;
    result->_M_pos = -1;
    result->_M_st = 0;
    return v6;
  }
  if ( __whence == 2 )
  {
    v8 = 0;
    goto LABEL_10;
  }
LABEL_9:
  v8 = 1;
LABEL_10:
  if ( !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_init(this, v8) )
    goto LABEL_5;
  if ( v7 == 1 || v7 == 4 || !this->_M_in_input_mode )
  {
    v27 = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, this->_M_width * __eadj, v7);
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, result, v27, 0);
    return result;
  }
  else
  {
    M_mmap_base = this->_M_mmap_base;
    M_gnext = this->_M_gnext;
    if ( M_mmap_base )
    {
      v11 = this->_M_mmap_len - (M_gnext - M_mmap_base);
      p_M_base = &this->_M_base;
      if ( __eadj )
      {
        v14 = stlp_std::_Filebuf_base::_M_seek(p_M_base, __eadj - v11, 2);
        p_cur = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, &v31, v14, 0);
      }
      else
      {
        __cur = stlp_std::_Filebuf_base::_M_seek(p_M_base, 0, 2) - v11;
        v30 = 0;
        p_cur = (stlp_std::fpos<int> *)&__cur;
      }
      *result = *p_cur;
      return result;
    }
    else if ( this->_M_constant_width )
    {
      M_ext_buf_end = this->_M_ext_buf_end;
      v16 = this->_M_width * (M_gnext - this->_M_gbegin);
      if ( v16 > M_ext_buf_end - this->_M_ext_buf )
        goto LABEL_5;
      offset = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, &this->_M_ext_buf[v16], M_ext_buf_end);
      v18 = &this->_M_base;
      if ( __eadj )
      {
        v20 = stlp_std::_Filebuf_base::_M_seek(v18, __eadj - offset, 2);
        v19 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, &v31, v20, 0);
      }
      else
      {
        v30 = 0;
        __cur = stlp_std::_Filebuf_base::_M_seek(v18, 0, 2) - offset;
        v19 = (stlp_std::fpos<int> *)&__cur;
      }
      *result = *v19;
      return result;
    }
    else
    {
      M_ext_buf_converted = this->_M_ext_buf_converted;
      M_ext_buf = this->_M_ext_buf;
      v28 = M_gnext - this->_M_gbegin;
      __whence = this->_M_state;
      v23 = this->_M_codecvt->do_length(this->_M_codecvt, &__whence, M_ext_buf, M_ext_buf_converted, v28);
      __cur = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
      v24 = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, &this->_M_ext_buf[v23]);
      v25 = v24 - stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, this->_M_ext_buf_end);
      if ( (HIDWORD(__cur) & (unsigned int)__cur) == 0xFFFFFFFF
        || (((unsigned __int64)(__cur + v25) >> 32) & 0x80000000) != 0LL )
      {
        goto LABEL_5;
      }
      if ( __eadj )
      {
        v26 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
                this,
                &v31,
                __cur + v25,
                __whence);
      }
      else
      {
        v30 = 0;
        __cur += v25;
        v26 = (stlp_std::fpos<int> *)&__cur;
      }
      *result = *v26;
      return result;
    }
  }
}
