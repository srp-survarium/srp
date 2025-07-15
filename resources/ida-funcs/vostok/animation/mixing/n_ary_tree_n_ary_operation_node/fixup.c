void __userpurge vostok::animation::mixing::n_ary_tree_n_ary_operation_node::fixup(
        vostok::animation::mixing::n_ary_tree_n_ary_operation_node *this@<eax>,
        const unsigned int size@<ecx>,
        unsigned int offset)
{
  char *v3; // esi
  char *v4; // edi
  int v5; // ecx

  v3 = (char *)this + size;
  v4 = (char *)&this->__vftable + 4 * this->m_operands_count + size;
  while ( v3 != v4 )
  {
    if ( *(_DWORD *)v3 )
      v5 = *(_DWORD *)v3 + offset;
    else
      v5 = 0;
    *(_DWORD *)v3 = v5;
    (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v5 + 56))(v5, offset);
    v3 += 4;
  }
}
