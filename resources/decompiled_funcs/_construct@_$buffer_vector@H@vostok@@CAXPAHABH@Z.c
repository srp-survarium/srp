void __usercall vostok::buffer_vector<int>::construct(int *p@<eax>, int *value@<ecx>)
{
  if ( p )
    *p = *value;
}
