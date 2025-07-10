void __usercall boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  void (__cdecl *v3)(int *, int *, int); // eax

  v2 = *a2;
  if ( *a2 )
  {
    if ( (v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(int *, int *, int))(v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 2, a2 + 2, 2);
    }
    *a2 = 0;
  }
}
