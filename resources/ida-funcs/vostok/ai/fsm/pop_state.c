vostok::ai::fsm_state *__usercall vostok::ai::fsm::pop_state@<eax>(vostok::ai::fsm *this@<ecx>, _DWORD *a2@<eax>)
{
  int v3; // ecx
  int v4; // edx

  if ( !a2[2] )
    return 0;
  v3 = a2[2];
  --*a2;
  v4 = *(_DWORD *)(v3 + 4);
  a2[2] = v4;
  if ( !v4 )
    a2[3] = 0;
  *(_DWORD *)(v3 + 4) = 0;
  return (vostok::ai::fsm_state *)v3;
}
