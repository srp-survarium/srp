void __usercall vostok::sound::encoded_sound_with_qualities::encoded_sound_with_qualities(
        vostok::sound::encoded_sound_with_qualities *this@<ecx>,
        int a2@<edi>)
{
  vostok::fixed_string<260> *v2; // ecx
  int v3; // edx
  _DWORD *v4; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_recursive_class);
  *(_DWORD *)a2 = &vostok::sound::encoded_sound_with_qualities::`vftable';
  vostok::fixed_string<260>::fixed_string<260>(v2, (vostok::buffer_string *)(a2 + 264), (char *)uri);
  v3 = 1;
  v4 = (_DWORD *)(a2 + 536);
  do
  {
    *v4 = 0;
    v4[1] = 0;
    v4 += 2;
    --v3;
  }
  while ( v3 >= 0 );
  *(_DWORD *)(a2 + 552) = 0;
  *(_DWORD *)(a2 + 556) = 0;
  *(_DWORD *)(a2 + 560) = 0;
  *(_BYTE *)(a2 + 564) = 0;
}
