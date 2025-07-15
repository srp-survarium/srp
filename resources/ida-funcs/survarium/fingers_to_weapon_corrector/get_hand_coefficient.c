float __userpurge survarium::fingers_to_weapon_corrector::get_hand_coefficient@<xmm0>(
        survarium::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<eax>,
        double a3@<st1>,
        float hand_transition_time,
        const bool hand_active)
{
  (**(void (__stdcall ***)(_DWORD))(a2 + 2056))(LODWORD(hand_transition_time));
  if ( hand_active )
    return 1.0 - a3;
  return a3;
}
