void __userpurge survarium::flash_movie::HandleMouseMove(
        survarium::flash_movie *this@<ecx>,
        int a2@<esi>,
        float x,
        float y,
        unsigned int scroll_delta)
{
  int v5; // ecx
  int v6; // ecx
  Scaleform::GFx::MouseEvent mevent; // [esp+4h] [ebp-38h] BYREF
  Scaleform::GFx::Event v8; // [esp+20h] [ebp-1Ch]
  _BYTE v9[12]; // [esp+28h] [ebp-14h]
  int v10; // [esp+34h] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 4);
  mevent.x = x;
  mevent.y = y;
  mevent.Modifiers.States = 0;
  mevent.Type = MouseMove;
  memset(&mevent.ScrollDelta, 0, 12);
  (*(void (__thiscall **)(int, Scaleform::GFx::MouseEvent *))(*(_DWORD *)v5 + 136))(v5, &mevent);
  v6 = *(_DWORD *)(a2 + 4);
  *(float *)v9 = x;
  *(_QWORD *)&v9[4] = __PAIR64__(scroll_delta, LODWORD(y));
  v8.Modifiers.States = 0;
  v8.Type = MouseWheel;
  mevent.Scaleform::GFx::Event = v8;
  *(_QWORD *)&mevent.x = *(_QWORD *)v9;
  v10 = 0;
  *(_QWORD *)&mevent.ScrollDelta = scroll_delta;
  mevent.MouseIndex = 0;
  (*(void (__thiscall **)(int, Scaleform::GFx::MouseEvent *))(*(_DWORD *)v6 + 136))(v6, &mevent);
}
