void __usercall survarium::damage_model_stats::damage_model_stats(
        survarium::damage_model_stats *this@<ecx>,
        survarium::damage_model_stats **a2@<esi>)
{
  int v2; // eax
  survarium::damage_model_stats *v3; // ecx
  survarium::damage_model_stats *v4; // ecx
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h]

  a2[4] = (survarium::damage_model_stats *)1101004800;
  a2[5] = (survarium::damage_model_stats *)1127481344;
  *a2 = this;
  a2[2] = (survarium::damage_model_stats *)-8323073;
  a2[3] = (survarium::damage_model_stats *)-128;
  a2[6] = (survarium::damage_model_stats *)1135869952;
  v2 = ((int (__thiscall *)(survarium::damage_model_stats *))this->m_ui_world[2].__vftable)(this);
  a2[1] = (survarium::damage_model_stats *)v2;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 16))(v2, 1);
  v3 = a2[1];
  v5 = 0;
  v6 = 0;
  ((void (__thiscall *)(survarium::damage_model_stats *, int *))v3->m_ui_world->__vftable)(v3, &v5);
  v4 = a2[1];
  v5 = 1151336448;
  v6 = 1144258560;
  ((void (__thiscall *)(survarium::damage_model_stats *, int *))v4->m_ui_world[2].__vftable)(v4, &v5);
}
