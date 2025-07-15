int __thiscall stlp_std::_Filebuf_base::_M_seek(stlp_std::_Filebuf_base *this, _LARGE_INTEGER offset, int dir)
{
  int HighPart; // ebp
  __int64 v5; // rax
  DWORD v7; // eax
  DWORD v8; // eax
  void *M_file_id; // [esp-10h] [ebp-28h]
  int result; // [esp+10h] [ebp-8h]

  HighPart = offset.HighPart;
  result = -1;
  if ( dir == 1 )
  {
    if ( offset.HighPart >= 0 )
    {
      v7 = 0;
      goto LABEL_11;
    }
    return -1;
  }
  if ( dir == 2 )
  {
    v7 = 1;
    goto LABEL_11;
  }
  if ( dir != 4 )
    return -1;
  LODWORD(v5) = stlp_std::_Filebuf_base::_M_file_size(this);
  if ( -__SPAIR64__(HighPart, offset.LowPart) > v5 )
    return -1;
  v7 = 2;
LABEL_11:
  M_file_id = this->_M_file_id;
  offset.HighPart = HighPart;
  v8 = SetFilePointer(M_file_id, offset.LowPart, &offset.HighPart, v7);
  if ( v8 != -1 )
    return v8;
  if ( !GetLastError() )
    return -1;
  return result;
}
