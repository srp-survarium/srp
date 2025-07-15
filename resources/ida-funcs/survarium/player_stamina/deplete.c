bool __userpurge survarium::player_stamina::deplete@<al>(
        survarium::player_stamina *this@<ecx>,
        int a2@<eax>,
        int is_in_past)
{
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  const std::exception *v6; // eax
  survarium::player_stamina *v8; // [esp-4h] [ebp-120h]
  stlp_std::out_of_range v9; // [esp+8h] [ebp-114h] BYREF

  if ( !(_BYTE)is_in_past )
  {
    v4 = (_DWORD *)(a2 + 88);
    this = (survarium::player_stamina *)-(*(_DWORD *)(a2 + 88) != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & (unsigned int)this) != 0 )
      boost::function0<void>::operator()((boost::function0<bool> *)this, v4);
  }
  v5 = *(_DWORD **)(a2 + 36);
  *(float *)(a2 + 140) = *(float *)(a2 + 64);
  *(_BYTE *)(a2 + 152) = 1;
  HIBYTE(is_in_past) = 0;
  if ( !v5 )
    return 0;
  do
  {
    if ( !*v5 )
    {
      boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v9);
      boost::throw_exception(v6);
      stlp_std::__Named_exception::~__Named_exception(&v9);
    }
    (*(void (__cdecl **)(_DWORD *, char *))((*v5 & 0xFFFFFFFE) + 4))(v5 + 2, (char *)&is_in_past + 3);
    v5 = (_DWORD *)v5[8];
    this = v8;
  }
  while ( v5 );
  return HIBYTE(is_in_past) != 0;
}
