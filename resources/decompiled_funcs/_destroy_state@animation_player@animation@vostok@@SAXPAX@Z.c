void __usercall vostok::animation::animation_player::destroy_state(
        char *buffer@<eax>,
        vostok::animation::mixing::n_ary_tree *a2@<ecx>)
{
  _DWORD **v2; // esi
  _DWORD *v3; // esi

  *(_DWORD *)buffer = -4334115;
  v2 = (_DWORD **)(buffer + 8);
  vostok::animation::mixing::n_ary_tree::destroy(a2);
  v3 = *v2;
  if ( v3 )
    --*v3;
}
