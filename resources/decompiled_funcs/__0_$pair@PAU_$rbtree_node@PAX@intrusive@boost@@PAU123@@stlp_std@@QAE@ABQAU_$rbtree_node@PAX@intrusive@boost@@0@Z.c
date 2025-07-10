void __userpurge stlp_std::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *>::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *>(
        stlp_std::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *> *this@<ecx>,
        int a2@<eax>,
        boost::intrusive::rbtree_node<void *> *const *__a,
        boost::intrusive::rbtree_node<void *> *const *__b)
{
  *(_DWORD *)a2 = this->first;
  *(boost::intrusive::rbtree_node<void *> **)(a2 + 4) = *__a;
}
