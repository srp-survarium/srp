void __usercall vostok::buffer_vector<long volatile>::resize(
        vostok::buffer_vector<long volatile > *this@<ecx>,
        _DWORD *a2@<edi>)
{
  if ( (a2[1] - *a2) >> 2 )
    a2[1] = *a2;
}
