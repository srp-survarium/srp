void __userpurge boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::operator()(
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short> *this@<ecx>,
        _DWORD *eax0@<eax>,
        int a0,
        survarium::match_stats_events_dict_enum a1,
        int a2)
{
  const std::exception *v6; // eax
  stlp_std::out_of_range v7; // [esp+8h] [ebp-110h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v7);
    boost::throw_exception(v6);
    stlp_std::__Named_exception::~__Named_exception(&v7);
  }
  (*(void (__cdecl **)(_DWORD *, int, survarium::match_stats_events_dict_enum, int))((*eax0 & 0xFFFFFFFE) + 4))(
    eax0 + 2,
    a0,
    a1,
    a2);
}
