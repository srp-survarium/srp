bool __thiscall stlp_std::_Filebuf_base::_M_open(stlp_std::_Filebuf_base *this, int file_no, int init_mode)
{
  void *osfhandle; // edi
  bool result; // al
  int osfflags; // eax
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+8h] [ebp-34h] BYREF

  if ( this->_M_is_open || file_no < 0 )
    return 0;
  osfhandle = (void *)_get_osfhandle(file_no);
  if ( osfhandle == (void *)-1 )
    return 0;
  osfflags = init_mode;
  if ( !init_mode )
    osfflags = stlp_std::_get_osfflags(file_no, osfhandle);
  this->_M_openmode = osfflags;
  this->_M_file_id = osfhandle;
  this->_M_is_open = 1;
  this->_M_should_close = 0;
  if ( !GetFileInformationByHandle(osfhandle, &FileInformation) || (FileInformation.dwFileAttributes & 0x10) != 0 )
  {
    result = 1;
    this->_M_regular_file = 0;
  }
  else
  {
    result = 1;
    this->_M_regular_file = 1;
  }
  return result;
}
