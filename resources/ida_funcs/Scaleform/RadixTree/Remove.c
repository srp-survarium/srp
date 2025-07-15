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


void __thiscall Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *this,
        Scaleform::HeapMH::NodeMH *node,
        Scaleform::HeapMH::NodeMH *rotor)
{
  Scaleform::HeapMH::NodeMH *Parent; // esi
  Scaleform::HeapMH::NodeMH *v4; // ecx
  Scaleform::HeapMH::NodeMH *v5; // ecx

  Parent = node->Parent;
  if ( node->Parent )
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


void __thiscall Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *this,
        Scaleform::HeapMH::NodeMH *node)
{
  Scaleform::HeapMH::NodeMH *v2; // eax
  Scaleform::HeapMH::NodeMH **v3; // esi
  Scaleform::HeapMH::NodeMH **Child; // edx

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
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(this, node, v2);
}
