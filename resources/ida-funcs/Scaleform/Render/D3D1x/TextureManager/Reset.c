void __usercall Scaleform::Render::D3D1x::TextureManager::Reset(
        Scaleform::Render::D3D1x::TextureManager *this@<ecx>,
        int a2@<esi>)
{
  Scaleform::Mutex *v2; // ebp
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int i; // ebx
  int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax
  unsigned int wrap; // [esp+8h] [ebp-4h]

  v2 = (Scaleform::Mutex *)(*(_DWORD *)(a2 + 36) + 36);
  Scaleform::Mutex::DoLock(v2);
  while ( 1 )
  {
    v3 = a2 == -64 ? 0 : a2 + 56;
    if ( *(_DWORD *)(a2 + 68) == v3 )
      break;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 68) + 36))(*(_DWORD *)(a2 + 68));
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 64))(a2);
  v4 = 0;
  wrap = 0;
  do
  {
    for ( i = 0; i < 2; ++i )
    {
      v6 = (unsigned __int8)(v4 | (2 * i));
      v7 = *(_DWORD *)(a2 + 4 * v6 + 256) == 0;
      v8 = (_DWORD *)(a2 + 4 * v6 + 256);
      if ( !v7 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 8))(*v8);
        v4 = wrap;
      }
    }
    wrap = ++v4;
  }
  while ( v4 < 2 );
  *(_QWORD *)(a2 + 256) = 0;
  *(_QWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  Scaleform::Mutex::Unlock(v2);
}
