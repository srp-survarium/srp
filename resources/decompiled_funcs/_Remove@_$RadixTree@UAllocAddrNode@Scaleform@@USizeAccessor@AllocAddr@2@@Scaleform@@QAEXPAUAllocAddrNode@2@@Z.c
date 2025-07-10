void __thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *v2; // eax
  Scaleform::HeapPT::DualTNode **v3; // esi
  Scaleform::HeapPT::DualTNode **AddrChild; // edx

  v2 = node->AddrChild[1];
  v3 = &node->AddrChild[1];
  if ( v2 || (v2 = node->AddrChild[0], v3 = node->AddrChild, v2) )
  {
    while ( 1 )
    {
      AddrChild = &v2->AddrChild[1];
      if ( !v2->AddrChild[1] )
      {
        AddrChild = v2->AddrChild;
        if ( !v2->AddrChild[0] )
          break;
      }
      v2 = *AddrChild;
      v3 = AddrChild;
    }
    *v3 = 0;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(this, node, v2);
}
