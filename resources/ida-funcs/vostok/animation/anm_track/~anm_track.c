void __usercall vostok::animation::anm_track::~anm_track(vostok::animation::anm_track *this@<ecx>, int *a2@<eax>)
{
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // ebp
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int i; // [esp+20h] [ebp-4h]

  v3 = 0;
  for ( i = 0; v3 < a2[4]; i = v3 )
  {
    v4 = *a2 + 4 * v3;
    if ( *(_DWORD *)v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = a2[3];
      v7 = *(_DWORD *)(*(_DWORD *)v4 + 68);
      if ( v7 )
        (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(v5 + 76) + 24))(
          *(_DWORD *)(v5 + 76),
          v7,
          "vostok::detail::std_allocator<struct vostok::animation::EtKey>::deallocate",
          "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
          102);
      (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v6 + 24))(
        v6,
        v5,
        "vostok::animation::anm_track::~anm_track",
        ".\\anim_track.cpp",
        192);
      *(_DWORD *)v4 = 0;
      v3 = i;
      *(_DWORD *)(*a2 + 4 * i) = 0;
    }
    ++v3;
  }
  v8 = a2[3];
  v9 = *a2;
  if ( v9 )
    (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v8 + 24))(
      v8,
      v9 - 8,
      "vostok::animation::anm_track::~anm_track",
      ".\\anim_track.cpp",
      196);
}
