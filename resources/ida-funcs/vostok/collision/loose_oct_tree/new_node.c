vostok::collision::oct_node *__usercall vostok::collision::loose_oct_tree::new_node@<eax>(
        vostok::collision::loose_oct_tree *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v2; // edx
  int v3; // ecx

  v2 = *(_DWORD **)(a2 + 12);
  v3 = v2[8];
  ++*(_DWORD *)(a2 + 44);
  *(_DWORD *)(a2 + 12) = v3;
  if ( v2 )
  {
    v2[8] = 0;
    v2[9] = 0;
    memset(v2, 0, 0x20u);
  }
  return (vostok::collision::oct_node *)v2;
}
