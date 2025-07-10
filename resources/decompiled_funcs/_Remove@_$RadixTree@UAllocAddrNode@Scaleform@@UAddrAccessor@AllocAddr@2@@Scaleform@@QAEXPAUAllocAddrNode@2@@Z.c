void __thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *v2; // eax
  Scaleform::HeapPT::DualTNode **v3; // esi
  Scaleform::HeapPT::DualTNode **Child; // edx

  v2 = node->Child[1];
  v3 = &node->Child[1];
  if ( v2 || (v2 = node->Child[0], v3 = node->Child, v2) )
  {
    while ( 1 )
    {
      Child = &v2->Child[1];
      if ( !v2->Child[1] )
      {
        Child = v2->Child;
        if ( !v2->Child[0] )
          break;
      }
      v2 = *Child;
      v3 = Child;
    }
    *v3 = 0;
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(this, node, v2);
}
