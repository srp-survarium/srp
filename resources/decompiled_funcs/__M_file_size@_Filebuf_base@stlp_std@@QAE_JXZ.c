DWORD __thiscall stlp_std::_Filebuf_base::_M_file_size(stlp_std::_Filebuf_base *this)
{
  DWORD result; // eax
  unsigned int FileSizeHigh; // [esp+Ch] [ebp-4h] BYREF

  result = GetFileSize(this->_M_file_id, &FileSizeHigh);
  if ( result == -1 )
  {
    if ( GetLastError() )
      return 0;
    else
      return -1;
  }
  return result;
}
