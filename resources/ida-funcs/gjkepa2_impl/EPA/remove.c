void __usercall gjkepa2_impl::EPA::remove(gjkepa2_impl::EPA::sList *list@<edx>, gjkepa2_impl::EPA::sFace *face@<eax>)
{
  gjkepa2_impl::EPA::sFace *v2; // ecx
  gjkepa2_impl::EPA::sFace *v3; // ecx

  v2 = face->l[1];
  if ( v2 )
    v2->l[0] = face->l[0];
  v3 = face->l[0];
  if ( v3 )
    v3->l[1] = face->l[1];
  if ( face == list->root )
    list->root = face->l[1];
  --list->count;
}
