void __usercall vostok::ui::ui_scroll_view::recalc(vostok::ui::ui_scroll_view *this@<ecx>, int a2@<edi>)
{
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // eax
  float v5; // xmm0_4
  float *v6; // eax
  int v7; // edx
  vostok::ui::ui_scroll_bar *v8; // ecx
  float size; // [esp+Ch] [ebp-24h]
  float v10; // [esp+10h] [ebp-20h]
  float *v11; // [esp+18h] [ebp-18h]
  unsigned int count; // [esp+1Ch] [ebp-14h]
  vostok::math::float2 pad_size; // [esp+20h] [ebp-10h] BYREF
  vostok::math::float2 pos; // [esp+28h] [ebp-8h] BYREF

  v2 = 0;
  count = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 20))(a2);
  pos = 0;
  pad_size = 0;
  if ( count )
  {
    do
    {
      v3 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)a2 + 24))(a2, v2);
      (**(void (__thiscall ***)(int, vostok::math::float2 *))v3)(v3, &pos);
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
      v5 = *(float *)(v4 + 4) + pos.y;
      pos.y = v5;
      if ( v5 > pad_size.y )
        pad_size.y = v5;
      v11 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
      v6 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 4))(v3);
      if ( (float)(*v11 + *v6) > pad_size.x )
        pad_size.x = *v11 + *v6;
      ++v2;
    }
    while ( v2 < count );
  }
  (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)(a2 + 72) + 8))(a2 + 72, &pad_size);
  v7 = *(_DWORD *)a2;
  *(_WORD *)(a2 + 68) &= ~1u;
  if ( (*(unsigned __int8 (__thiscall **)(int))(v7 + 12))(a2) )
  {
    size = -((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 320))(*(_DWORD *)(a2 + 320));
    vostok::ui::ui_scroll_bar::move(v8, a2, a2 + 136, size, v10);
  }
}
