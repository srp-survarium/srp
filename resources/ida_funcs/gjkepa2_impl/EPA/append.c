void __usercall gjkepa2_impl::EPA::append(gjkepa2_impl::EPA::sList *list@<eax>, gjkepa2_impl::EPA::sFace *face@<ecx>)
{
  face->l[0] = 0;
  face->l[1] = list->root;
  if ( list->root )
    list->root->l[0] = face;
  ++list->count;
  list->root = face;
}
