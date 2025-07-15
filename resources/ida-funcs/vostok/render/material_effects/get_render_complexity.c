unsigned int __usercall vostok::render::material_effects::get_render_complexity@<eax>(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // esi
  int v5; // ecx
  unsigned int v6; // edx
  int i; // edi
  int v9; // [esp+Ch] [ebp-Ch]
  unsigned int v10; // [esp+10h] [ebp-8h]
  unsigned int v11; // [esp+14h] [ebp-4h]

  v10 = 0;
  v2 = (int *)(a2 + 40);
  v9 = 28;
  do
  {
    v3 = *v2;
    if ( *v2
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v4 = *(_DWORD *)(v3 + 22052);
      v5 = *(_DWORD *)(v3 + 22056);
      v6 = 0;
      v11 = 0;
      if ( v4 != v5 )
      {
        do
        {
          for ( i = *(_DWORD *)(*(_DWORD *)v4 + 8); i != *(_DWORD *)(*(_DWORD *)v4 + 12); i += 4 )
          {
            if ( v11 <= *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 16) + 4) + 4) )
              v11 = *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 16) + 4) + 4);
          }
          v4 += 4;
        }
        while ( v4 != v5 );
        v6 = v11;
      }
      if ( v10 <= v6 )
        v10 = v6;
    }
    ++v2;
    --v9;
  }
  while ( v9 );
  return v10;
}
