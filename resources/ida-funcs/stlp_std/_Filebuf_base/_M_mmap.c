void *__thiscall stlp_std::_Filebuf_base::_M_mmap(stlp_std::_Filebuf_base *this, __int64 offset, __int64 len)
{
  HANDLE FileMappingA; // eax
  unsigned int v5; // esi
  int v6; // edx
  void *result; // eax
  const void *dwFileOffsetLow; // [esp+8h] [ebp+4h]

  FileMappingA = CreateFileMappingA(this->_M_file_id, 0, 2u, 0, 0, 0);
  this->_M_view_id = FileMappingA;
  if ( !FileMappingA )
    return 0;
  v5 = offset;
  dwFileOffsetLow = MapViewOfFile(FileMappingA, 4u, HIDWORD(offset), offset, len);
  if ( dwFileOffsetLow )
  {
    stlp_std::_Filebuf_base::_M_seek(this, len + __PAIR64__(HIDWORD(offset), v5), 1);
    if ( v6 >= 0 )
      return (void *)dwFileOffsetLow;
    UnmapViewOfFile(dwFileOffsetLow);
  }
  if ( this->_M_view_id )
    CloseHandle(this->_M_view_id);
  result = 0;
  this->_M_view_id = 0;
  return result;
}
