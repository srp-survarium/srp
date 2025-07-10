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
