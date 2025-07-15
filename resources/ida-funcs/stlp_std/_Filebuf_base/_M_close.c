bool __thiscall stlp_std::_Filebuf_base::_M_close(stlp_std::_Filebuf_base *this)
{
  bool result; // al
  BOOL v3; // eax

  if ( !this->_M_is_open )
    return 0;
  if ( this->_M_should_close )
  {
    if ( this->_M_file_id == (void *)-1 )
    {
      result = 0;
      this->_M_should_close = 0;
      this->_M_is_open = 0;
      this->_M_openmode = 0;
    }
    else
    {
      v3 = CloseHandle(this->_M_file_id);
      this->_M_should_close = 0;
      this->_M_is_open = 0;
      this->_M_openmode = 0;
      return v3;
    }
  }
  else
  {
    this->_M_should_close = 0;
    this->_M_is_open = 0;
    this->_M_openmode = 0;
    return 1;
  }
  return result;
}
