void __usercall vostok::ai::fsm::add_state(vostok::ai::fsm *this@<ecx>, _DWORD *a2@<eax>)
{
  *(_DWORD *)&this->m_states.gap4 = 0;
  ++*a2;
  if ( a2[2] )
    *(_DWORD *)(a2[3] + 4) = this;
  else
    a2[2] = this;
  a2[3] = this;
}
