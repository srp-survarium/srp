void __userpurge vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(
        vostok::render::skeleton_combined_cook_data *this@<ecx>,
        int a2@<esi>,
        bool owner_cook)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 272;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 272) = 47;
  *(_DWORD *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 552) = 47;
  *(_DWORD *)(a2 + 280) = a2 + 292;
  *(_DWORD *)(a2 + 284) = a2 + 292;
  *(_DWORD *)(a2 + 288) = a2 + 552;
  *(_BYTE *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 556) = 0;
  *(_DWORD *)(a2 + 560) = 0;
  `vector constructor iterator'(
    (char *)(a2 + 564),
    0x34Cu,
    8,
    (void *(__thiscall *)(void *))vostok::render::skeleton_combined_cook_data::model_def::model_def);
  *(_BYTE *)(a2 + 7317) = owner_cook;
}
