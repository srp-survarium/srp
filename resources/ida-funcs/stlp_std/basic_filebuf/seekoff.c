stlp_std::fpos<int> *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::seekoff(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::fpos<int> *result,
        __int64 __eadj,
        int __whence,
        int __formal)
{
  stlp_std::fpos<int> *v6; // eax
  unsigned int v7; // ebx
  int v8; // ebp
  unsigned int v9; // edi
  bool v10; // al
  _BYTE *M_mmap_base; // ecx
  char *M_gnext; // eax
  __int64 v13; // kr00_8
  stlp_std::_Filebuf_base *p_M_base; // ecx
  __int64 v15; // rax
  stlp_std::fpos<int> *v16; // eax
  __int64 v17; // rax
  char *M_ext_buf_end; // ecx
  __int64 v19; // kr08_8
  __int64 offset; // rax
  stlp_std::_Filebuf_base *v21; // ecx
  __int64 v22; // rax
  stlp_std::fpos<int> *v23; // eax
  __int64 v24; // rax
  char *M_ext_buf_converted; // edi
  char *M_ext_buf; // ebx
  int v27; // edi
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // kr10_8
  stlp_std::fpos<int> *v31; // eax
  __int64 v32; // rax
  unsigned int v33; // [esp-4h] [ebp-34h]
  __int64 v34; // [esp+10h] [ebp-20h] BYREF
  int v35; // [esp+18h] [ebp-18h]
  stlp_std::fpos<int> resulta; // [esp+20h] [ebp-10h] BYREF
  __int64 v37; // [esp+38h] [ebp+8h]

  if ( !this->_M_base._M_is_open )
  {
    v6 = result;
    result->_M_pos = -1;
    result->_M_st = 0;
    return v6;
  }
  v7 = HIDWORD(__eadj);
  v8 = __whence;
  v9 = __eadj;
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
    v10 = 0;
    goto LABEL_10;
  }
LABEL_9:
  v10 = 1;
LABEL_10:
  if ( !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_init(this, v10) )
    goto LABEL_5;
  if ( v8 == 1 || v8 == 4 || !this->_M_in_input_mode )
  {
    LODWORD(v32) = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, this->_M_width * __eadj, v8);
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, result, v32, 0);
    return result;
  }
  else
  {
    M_mmap_base = this->_M_mmap_base;
    M_gnext = this->_M_gnext;
    if ( M_mmap_base )
    {
      v13 = this->_M_mmap_len - (M_gnext - M_mmap_base);
      p_M_base = &this->_M_base;
      if ( __eadj )
      {
        LODWORD(v17) = stlp_std::_Filebuf_base::_M_seek(p_M_base, __eadj - v13, 2);
        v16 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, &resulta, v17, 0);
      }
      else
      {
        LODWORD(v15) = stlp_std::_Filebuf_base::_M_seek(p_M_base, 0, 2);
        v34 = v15 - v13;
        v35 = 0;
        v16 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v16;
      return result;
    }
    else if ( this->_M_constant_width )
    {
      M_ext_buf_end = this->_M_ext_buf_end;
      v19 = this->_M_width * (M_gnext - this->_M_gbegin);
      if ( v19 > M_ext_buf_end - this->_M_ext_buf )
        goto LABEL_5;
      offset = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, &this->_M_ext_buf[v19], M_ext_buf_end);
      v37 = offset;
      v21 = &this->_M_base;
      if ( v7 | v9 )
      {
        LODWORD(v24) = stlp_std::_Filebuf_base::_M_seek(v21, __PAIR64__(v7, v9) - offset, 2);
        v23 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, &resulta, v24, 0);
      }
      else
      {
        LODWORD(v22) = stlp_std::_Filebuf_base::_M_seek(v21, 0, 2);
        v35 = 0;
        v34 = v22 - v37;
        v23 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v23;
      return result;
    }
    else
    {
      M_ext_buf_converted = this->_M_ext_buf_converted;
      M_ext_buf = this->_M_ext_buf;
      v33 = M_gnext - this->_M_gbegin;
      __whence = this->_M_state;
      v27 = this->_M_codecvt->do_length(
              (stlp_std::codecvt<char,char,int> *)this->_M_codecvt,
              &__whence,
              M_ext_buf,
              M_ext_buf_converted,
              v33);
      LODWORD(v28) = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
      v34 = v28;
      v29 = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, &this->_M_ext_buf[v27]);
      v30 = v29 - stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, this->_M_ext_buf_end);
      if ( (HIDWORD(v34) & (unsigned int)v34) == 0xFFFFFFFF
        || (((unsigned __int64)(v34 + v30) >> 32) & 0x80000000) != 0LL )
      {
        goto LABEL_5;
      }
      if ( __eadj )
      {
        v31 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
                this,
                &resulta,
                v34 + v30,
                __whence);
      }
      else
      {
        v35 = 0;
        v34 += v30;
        v31 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v31;
      return result;
    }
  }
}


stlp_std::fpos<int> *__thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::seekoff(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::fpos<int> *result,
        __int64 __eadj,
        int __whence,
        int __formal)
{
  stlp_std::fpos<int> *v6; // eax
  unsigned int v7; // ebx
  int v8; // ebp
  unsigned int v9; // edi
  bool v10; // al
  _BYTE *M_mmap_base; // ecx
  wchar_t *M_gnext; // eax
  __int64 v13; // kr00_8
  stlp_std::_Filebuf_base *p_M_base; // ecx
  __int64 v15; // rax
  stlp_std::fpos<int> *v16; // eax
  __int64 v17; // rax
  char *M_ext_buf_end; // ecx
  __int64 v19; // kr08_8
  __int64 offset; // rax
  stlp_std::_Filebuf_base *v21; // ecx
  __int64 v22; // rax
  stlp_std::fpos<int> *v23; // eax
  __int64 v24; // rax
  char *M_ext_buf_converted; // edi
  char *M_ext_buf; // ebx
  int v27; // edi
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // kr10_8
  stlp_std::fpos<int> *v31; // eax
  __int64 v32; // rax
  unsigned int v33; // [esp-4h] [ebp-34h]
  __int64 v34; // [esp+10h] [ebp-20h] BYREF
  int v35; // [esp+18h] [ebp-18h]
  stlp_std::fpos<int> resulta; // [esp+20h] [ebp-10h] BYREF
  __int64 v37; // [esp+38h] [ebp+8h]

  if ( !this->_M_base._M_is_open )
  {
    v6 = result;
    result->_M_pos = -1;
    result->_M_st = 0;
    return v6;
  }
  v7 = HIDWORD(__eadj);
  v8 = __whence;
  v9 = __eadj;
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
    v10 = 0;
    goto LABEL_10;
  }
LABEL_9:
  v10 = 1;
LABEL_10:
  if ( !stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_seek_init(this, v10) )
    goto LABEL_5;
  if ( v8 == 1 || v8 == 4 || !this->_M_in_input_mode )
  {
    LODWORD(v32) = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, this->_M_width * __eadj, v8);
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
      (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)this,
      result,
      v32,
      0);
    return result;
  }
  else
  {
    M_mmap_base = this->_M_mmap_base;
    M_gnext = this->_M_gnext;
    if ( M_mmap_base )
    {
      v13 = this->_M_mmap_len - (((char *)M_gnext - M_mmap_base) >> 1);
      p_M_base = &this->_M_base;
      if ( __eadj )
      {
        LODWORD(v17) = stlp_std::_Filebuf_base::_M_seek(p_M_base, __eadj - v13, 2);
        v16 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
                (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)this,
                &resulta,
                v17,
                0);
      }
      else
      {
        LODWORD(v15) = stlp_std::_Filebuf_base::_M_seek(p_M_base, 0, 2);
        v34 = v15 - v13;
        v35 = 0;
        v16 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v16;
      return result;
    }
    else if ( this->_M_constant_width )
    {
      M_ext_buf_end = this->_M_ext_buf_end;
      v19 = this->_M_width * (M_gnext - this->_M_gbegin);
      if ( v19 > M_ext_buf_end - this->_M_ext_buf )
        goto LABEL_5;
      offset = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, &this->_M_ext_buf[v19], M_ext_buf_end);
      v37 = offset;
      v21 = &this->_M_base;
      if ( v7 | v9 )
      {
        LODWORD(v24) = stlp_std::_Filebuf_base::_M_seek(v21, __PAIR64__(v7, v9) - offset, 2);
        v23 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
                (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)this,
                &resulta,
                v24,
                0);
      }
      else
      {
        LODWORD(v22) = stlp_std::_Filebuf_base::_M_seek(v21, 0, 2);
        v35 = 0;
        v34 = v22 - v37;
        v23 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v23;
      return result;
    }
    else
    {
      M_ext_buf_converted = this->_M_ext_buf_converted;
      M_ext_buf = this->_M_ext_buf;
      v33 = M_gnext - this->_M_gbegin;
      __whence = this->_M_state;
      v27 = this->_M_codecvt->do_length(
              (stlp_std::codecvt<wchar_t,char,int> *)this->_M_codecvt,
              &__whence,
              M_ext_buf,
              M_ext_buf_converted,
              v33);
      LODWORD(v28) = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
      v34 = v28;
      v29 = stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, &this->_M_ext_buf[v27]);
      v30 = v29 - stlp_std::_Filebuf_base::_M_get_offset(&this->_M_base, this->_M_ext_buf, this->_M_ext_buf_end);
      if ( (HIDWORD(v34) & (unsigned int)v34) == 0xFFFFFFFF
        || (((unsigned __int64)(v34 + v30) >> 32) & 0x80000000) != 0LL )
      {
        goto LABEL_5;
      }
      if ( __eadj )
      {
        v31 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
                (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)this,
                &resulta,
                v34 + v30,
                __whence);
      }
      else
      {
        v35 = 0;
        v34 += v30;
        v31 = (stlp_std::fpos<int> *)&v34;
      }
      *result = *v31;
      return result;
    }
  }
}
