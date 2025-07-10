void __thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::DualTNode *rotor)
{
  Scaleform::HeapPT::DualTNode *AddrParent; // esi
  Scaleform::HeapPT::DualTNode *v4; // ecx
  Scaleform::HeapPT::DualTNode *v5; // ecx

  AddrParent = node->AddrParent;
  if ( AddrParent )
  {
    if ( node == this->Root )
      this->Root = rotor;
    else
      AddrParent->AddrChild[AddrParent->AddrChild[0] != node] = rotor;
    if ( rotor )
    {
      rotor->AddrParent = AddrParent;
      v4 = node->AddrChild[0];
      if ( v4 )
      {
        rotor->AddrChild[0] = v4;
        v4->AddrParent = rotor;
      }
      v5 = node->AddrChild[1];
      if ( v5 )
      {
        rotor->AddrChild[1] = v5;
        v5->AddrParent = rotor;
      }
    }
  }
  node->AddrChild[1] = 0;
  node->AddrChild[0] = 0;
  node->AddrParent = 0;
}
