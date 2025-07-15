DWORD __thiscall stlp_std::_Filebuf_base::_M_seek(stlp_std::_Filebuf_base *this, __int64 offset, int dir)
{
  unsigned int v3; // ebp
  __int64 v5; // rax
  DWORD v7; // eax
  DWORD v8; // eax
  void *M_file_id; // [esp-10h] [ebp-28h]
  int v10; // [esp+10h] [ebp-8h]

  v3 = HIDWORD(offset);
  v10 = -1;
  if ( dir == 1 )
  {
    if ( offset >= 0 )
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
  if ( -__SPAIR64__(v3, offset) > v5 )
    return -1;
  v7 = 2;
LABEL_11:
  M_file_id = this->_M_file_id;
  HIDWORD(offset) = v3;
  v8 = SetFilePointer(M_file_id, offset, (PLONG)&offset + 1, v7);
  if ( v8 != -1 )
    return v8;
  if ( !GetLastError() )
    return -1;
  return v10;
}
