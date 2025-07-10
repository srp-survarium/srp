void __usercall vostok::animation::mixing::n_ary_tree::~n_ary_tree(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        _DWORD **a2@<esi>)
{
  vostok::animation::mixing::n_ary_tree::destroy(this, (int)a2);
  if ( *a2 )
    --**a2;
}
