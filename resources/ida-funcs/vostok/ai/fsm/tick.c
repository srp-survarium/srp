void __usercall vostok::ai::fsm::tick(vostok::ai::fsm *this@<ecx>, int a2@<esi>)
{
  boost::function0<bool> *v2; // ecx
  _DWORD *i; // edi
  int v4; // ecx
  int v5; // ecx

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 16) + 24))(*(_DWORD *)(a2 + 16)) )
  {
    for ( i = *(_DWORD **)(*(_DWORD *)(a2 + 16) + 16); i; i = (_DWORD *)i[9] )
    {
      if ( (unsigned __int8)boost::function0<void>::operator()(v2, i) )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 16) + 12))(*(_DWORD *)(a2 + 16));
        v4 = -(*(_DWORD *)(a2 + 24) != 0);
        if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
          boost::function1<void,boost::system::error_code>::operator()(
            (boost::function2<void,vostok::math::float4x4 *,unsigned int> *)v4,
            (_DWORD *)(a2 + 24),
            *(vostok::math::float4x4 **)(a2 + 16),
            i[8]);
        v5 = i[8];
        *(_DWORD *)(a2 + 16) = v5;
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(v5);
        break;
      }
    }
  }
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 16) + 8))(*(_DWORD *)(a2 + 16));
}
