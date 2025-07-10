void __thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::DualTNode *rotor)
{
  Scaleform::HeapPT::DualTNode *Parent; // esi
  Scaleform::HeapPT::DualTNode *v4; // ecx
  Scaleform::HeapPT::DualTNode *v5; // ecx

  Parent = node->Parent;
  if ( Parent )
  {
    if ( node == this->Root )
      this->Root = rotor;
    else
      Parent->Child[Parent->Child[0] != node] = rotor;
    if ( rotor )
    {
      rotor->Parent = Parent;
      v4 = node->Child[0];
      if ( v4 )
      {
        rotor->Child[0] = v4;
        v4->Parent = rotor;
      }
      v5 = node->Child[1];
      if ( v5 )
      {
        rotor->Child[1] = v5;
        v5->Parent = rotor;
      }
    }
  }
  node->Child[1] = 0;
  node->Child[0] = 0;
  node->Parent = 0;
}
