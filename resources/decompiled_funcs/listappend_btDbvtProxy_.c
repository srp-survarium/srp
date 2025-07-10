void __usercall listappend_btDbvtProxy_(btDbvtProxy *item@<eax>, btDbvtProxy **list@<ecx>)
{
  item->links[0] = 0;
  item->links[1] = *list;
  if ( *list )
    (*list)->links[0] = item;
  *list = item;
}
