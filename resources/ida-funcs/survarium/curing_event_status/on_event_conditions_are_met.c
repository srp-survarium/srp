void __usercall survarium::curing_event_status::on_event_conditions_are_met(
        survarium::curing_event_status *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_WORD *)(a2 + 36) )
  {
    if ( *(_BYTE *)(a2 + 38) )
      return;
    *(_BYTE *)(a2 + 38) = 1;
  }
  boost::function0<void>::operator()((boost::function0<bool> *)this, (_DWORD *)a2);
}
