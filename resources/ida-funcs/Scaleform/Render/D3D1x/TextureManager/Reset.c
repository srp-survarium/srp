void __usercall Scaleform::Render::D3D1x::TextureManager::Reset(
        Scaleform::Render::D3D1x::TextureManager *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // eax
  unsigned int j; // ebx
  _DWORD *v4; // eax
  Scaleform::Mutex *v5; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v5 = (Scaleform::Mutex *)(a2[9] + 36);
  Scaleform::Mutex::DoLock(v5);
  while ( 1 )
  {
    v2 = a2 == (_DWORD *)-64 ? 0 : a2 + 14;
    if ( (_DWORD *)a2[17] == v2 )
      break;
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[17] + 36))(a2[17]);
  }
  (*(void (__thiscall **)(_DWORD *))(*a2 + 64))(a2);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < 2; ++j )
    {
      v4 = &a2[(unsigned __int8)(i | (2 * j)) + 64];
      if ( *v4 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v4 + 8))(*v4);
    }
  }
  a2[64] = 0;
  a2[65] = 0;
  a2[66] = 0;
  a2[67] = 0;
  a2[22] = 0;
  Scaleform::Mutex::Unlock(v5);
}
