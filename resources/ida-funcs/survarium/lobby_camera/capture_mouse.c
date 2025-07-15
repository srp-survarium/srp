void __userpurge survarium::lobby_camera::capture_mouse(survarium::lobby_camera *this@<ecx>, int a2@<esi>, bool on)
{
  int v3; // [esp-4h] [ebp-Ch]
  tagPOINT Point; // [esp+0h] [ebp-8h] BYREF

  if ( on )
  {
    *(_BYTE *)(a2 + 200) = 1;
    GetCursorPos(&Point);
    *(tagPOINT *)(a2 + 204) = Point;
  }
  else
  {
    v3 = *(_DWORD *)(a2 + 208);
    *(_BYTE *)(a2 + 200) = 0;
    SetCursorPos(*(_DWORD *)(a2 + 204), v3);
  }
}
