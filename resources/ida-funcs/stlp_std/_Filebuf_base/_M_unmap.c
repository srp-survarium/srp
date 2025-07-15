void __thiscall stlp_std::_Filebuf_base::_M_unmap(stlp_std::_Filebuf_base *this, void *base, __int64 len)
{
  if ( base )
    UnmapViewOfFile(base);
  if ( this->_M_view_id )
    CloseHandle(this->_M_view_id);
  this->_M_view_id = 0;
}
