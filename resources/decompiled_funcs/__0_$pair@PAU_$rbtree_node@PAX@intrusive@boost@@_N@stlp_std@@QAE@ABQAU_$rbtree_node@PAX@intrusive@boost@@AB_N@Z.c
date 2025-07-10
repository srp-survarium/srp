void __userpurge stlp_std::pair<boost::intrusive::rbtree_node<void *> *,bool>::pair<boost::intrusive::rbtree_node<void *> *,bool>(
        stlp_std::pair<boost::intrusive::rbtree_node<void *> *,bool> *this@<ecx>,
        int a2@<eax>,
        boost::intrusive::rbtree_node<void *> *const *__a,
        const bool *__b)
{
  *(_DWORD *)a2 = this->first;
  *(_BYTE *)(a2 + 4) = *(_BYTE *)__a;
}
