int __usercall inc@<eax>(_iobuf *fileptr@<edx>, unsigned int a2@<ebx>)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(a2, fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}
