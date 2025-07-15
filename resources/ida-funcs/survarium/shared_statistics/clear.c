void __thiscall survarium::shared_statistics::clear(survarium::shared_statistics *this, int a2)
{
  _WORD *v2; // ebx
  int v3; // eax
  survarium::victory_item_event_manager *v4; // ecx
  _WORD *i; // esi

  v2 = (_WORD *)(a2 + 4240);
  v3 = a2 + 4272;
  v4 = (survarium::victory_item_event_manager *)(a2 + 5072);
  while ( (survarium::victory_item_event_manager *)v3 != v4 )
  {
    *(_DWORD *)(v3 + 32) = 0;
    *(_WORD *)(v3 + 36) = 0;
    *(_BYTE *)(v3 + 38) = 0;
    v3 += 40;
  }
  v4->m_event_callback.vtable = 0;
  survarium::victory_item_event_manager::clear(v4, (_DWORD *)(a2 + 5080));
  *(_DWORD *)(a2 + 6136) = 0;
  *(_BYTE *)(a2 + 6144) = 0;
  *(_BYTE *)(a2 + 6145) = 0;
  *(_DWORD *)(a2 + 6148) = 255;
  *(_BYTE *)(a2 + 6152) = 0;
  for ( i = (_WORD *)a2; i != v2; i += 106 )
  {
    memset(i, 0, 0x28u);
    i[20] = 0;
    survarium::intermediate_shared_statistics::clear(0, (int)(i + 22));
  }
  *(_DWORD *)(a2 + 6140) = 0;
}
