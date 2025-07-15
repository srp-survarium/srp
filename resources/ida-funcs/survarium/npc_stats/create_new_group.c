vostok::ui::text *__userpurge survarium::npc_stats::create_new_group@<eax>(
        survarium::npc_stats *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        float *a4@<edi>,
        int a5@<esi>,
        survarium::npc_stats::column_types_enum column_number,
        unsigned int font_color,
        const char *text,
        const vostok::ui::window *upper_window,
        int a10,
        float a11)
{
  float v11; // xmm1_4
  int v13; // esi
  int v14; // eax
  float v15; // xmm0_4
  void (__thiscall ***v16)(_DWORD, float *); // eax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  float offsets[5]; // [esp+Ch] [ebp-14h] BYREF
  float *column_width; // [esp+30h] [ebp+10h]

  v11 = a4[6];
  offsets[1] = a4[5];
  offsets[2] = offsets[1] * 2.0;
  offsets[3] = v11 + (float)(offsets[1] * 2.0);
  v13 = (*(int (__thiscall **)(_DWORD, int, int, int))(**(_DWORD **)a4 + 16))(*(_DWORD *)a4, a5, a3, a2);
  v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 16))(v14, 1);
  if ( upper_window )
  {
    column_width = &upper_window->get_size(upper_window)->y;
    v15 = upper_window->get_position(upper_window)->y + *column_width;
  }
  else
  {
    v15 = 0.0;
  }
  offsets[1] = offsets[column_number + 3];
  offsets[2] = v15;
  v16 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13);
  (**v16)(v16, &offsets[1]);
  v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13);
  offsets[2] = a11;
  offsets[3] = a4[4];
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v17 + 8))(v17, &offsets[2]);
  (**(void (__thiscall ***)(int, _DWORD))v13)(v13, 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v13 + 20))(v13, 0);
  (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v13 + 4))(v13, font_color);
  v18 = **((_DWORD **)a4 + 1);
  v19 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v13 + 28))(v13, 1);
  (*(void (__thiscall **)(_DWORD, int))(v18 + 64))(*((_DWORD *)a4 + 1), v19);
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 8))(v13, text);
  return (vostok::ui::text *)v13;
}
