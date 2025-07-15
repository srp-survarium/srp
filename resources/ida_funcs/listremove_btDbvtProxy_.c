void __usercall listremove_btDbvtProxy_(btDbvtProxy *item@<eax>, btDbvtProxy **list)
{
  btDbvtProxy *v2; // ecx
  btDbvtProxy *v3; // ecx

  v2 = item->links[0];
  if ( v2 )
    v2->links[1] = item->links[1];
  else
    *list = item->links[1];
  v3 = item->links[1];
  if ( v3 )
    v3->links[0] = item->links[0];
}
