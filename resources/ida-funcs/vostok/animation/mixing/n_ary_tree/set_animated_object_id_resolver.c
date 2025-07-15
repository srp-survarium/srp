void __usercall vostok::animation::mixing::n_ary_tree::set_animated_object_id_resolver(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::animation::mixing::animation_state **v2; // edi

  v2 = (vostok::animation::mixing::animation_state **)a2[5];
  a2[7] = this;
  stlp_std::sort<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
    v2,
    &v2[a2[8]],
    (event_iterator_predicate)this);
}
