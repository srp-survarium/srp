void __userpurge survarium::recoil_calculator::deserialize(
        survarium::recoil_calculator *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>,
        unsigned int time_offset)
{
  int v4; // eax
  int *v5; // esi
  int v6; // xmm0_4
  _DWORD *v7; // ecx
  int *v8; // esi
  int v9; // xmm0_4
  unsigned int time_offseta; // [esp+14h] [ebp+8h]

  survarium::weapon_recoil_calculator::deserialize(&this->m_weapon_calculator, reader, time_offset);
  v5 = *(int **)(v4 + 4);
  v6 = *v5;
  *(_DWORD *)(v4 + 4) = v5 + 1;
  v7[14] = v6;
  v8 = *(int **)(v4 + 4);
  v9 = *v8;
  *(_DWORD *)(v4 + 4) = v8 + 1;
  v7[13] = v9;
  time_offseta = **(_DWORD **)(v4 + 4);
  *(_DWORD *)(v4 + 4) += 4;
  v7[17] = time_offset + time_offseta;
}
