unsigned int __usercall vostok::buffer_string::find@<eax>(vostok::buffer_string *this@<esi>, unsigned __int8 c@<cl>)
{
  int v2; // eax

  strchr((unsigned __int8 *)this->m_begin, c);
  if ( v2 )
    return v2 - (unsigned int)this->m_begin;
  else
    return -1;
}
