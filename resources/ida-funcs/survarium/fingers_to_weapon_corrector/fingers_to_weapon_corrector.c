void __usercall survarium::fingers_to_weapon_corrector::fingers_to_weapon_corrector(
        survarium::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<esi>)
{
  `vector constructor iterator'(
    (char *)a2,
    0x404u,
    2,
    (void *(__thiscall *)(void *))survarium::fingers_to_weapon_corrector::hand::hand);
  *(_DWORD *)(a2 + 2056) = &vostok::animation::linear_interpolator::`vftable';
  *(float *)(a2 + 2060) = FLOAT_0_1;
  *(_DWORD *)(a2 + 2064) = 0;
  *(_BYTE *)(a2 + 2068) = 0;
}
